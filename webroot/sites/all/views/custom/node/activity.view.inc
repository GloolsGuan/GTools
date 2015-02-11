<?php


Lib_Glools_Load::loadFile('glools/view/abstract', 'lib');

class View_Custom_Node_Activity extends Lib_Glools_View_Abstract{
    
    protected $user = null;
    
    protected $activity = null;
    
    protected $defaultFeature = 'icons';
    
    protected $allowedSearchMode = array('currentMonth', 'latest', 'promoted');
    
    protected $searchMode = '';
    
    protected $activityNodes = array();
    
    /**
     * Checking presettings and set the parameters for the view
     * */
    public function init(){
        //debug_rdata(__METHOD__, array($this->options, $this->view));
        if (empty($this->view['rows']) || !is_numeric($this->view['rows'])) {
        	$this->view['rows'] = 12;
        }
        
        if (empty($this->view['title'])) {
        	$this->view['title'] = '最新活动';
        }
        
    }
    
    /**
     * Prepare data for the view
     * */
    public function beforeBuild(){
        
        if (!empty($this->view['searchMode']) && in_array($this->view['searchMode'], $this->allowedSearchMode)) {
        	$this->searchMode = $this->view['searchMode'];
        }else{
        	$this->searchMode = 'latest';
        }
        
        $viewMode = $this->view['feature'];
        
        $activities = $this->loadActivities(null, $this->view['rows'], $this->searchMode, false);
        
        $this->activityNodes = $this->buildNodes($activities, $viewMode, true);
    }
    
    /**
     * Execute event (after render the view hook)
     * */
    public function afterBuild(){
        
    }
    
    protected function buildNodes($nodes, $viewMode='teaser', $pager=true){
        if (empty($nodes)) {
        	return null;
        }
        
        $nodes = node_load_multiple(array_keys($nodes));
        $build = node_view_multiple($nodes, $viewMode);
        $dayMap = $this->getCurrentMonthRange();
        
        foreach($build['nodes'] as $nid=>$node) {
            if (!is_numeric($nid)) {
                continue;
            }
            $node = $build['nodes'][$nid];
            //debug_rdata(__FUNCTION__, array($node['#node'], $node['#node']->field__date_time));
            $activityStartTime = $node['#node']->field__date_time[$node['#node']->language][0]['value'];
            //debug_rdata(__FUNCTION__, array($activityStartTime, $node['#node']->field__date_time));
            $dateTime = date('Ymd', $activityStartTime);
            
            if (array_key_exists($dateTime, $dayMap)) {
            	if (!isset($dayMap[$dateTime]['nodes'])) {
            		$dayMap[$dateTime]['nodes'] = array();
            	}
                $dayMap[$dateTime]['nodes'][]  = $node;
            }
        }

        foreach($dayMap as $time=>$co) {
            $dayPhoto = date('d', $co['timestamp']) . '.png';
            $class = $time==date('Ymd', time())? 'today' : '';
            $class .= date('m', $co['timestamp'])!=date('m', time())? 'dayDisable' : '';
        	$dayMap[$time]['dayPhoto'] = $dayPhoto;
            $dayMap[$time]['class']    = $class;
        }
        
        
        $build['#dayMap'] = $dayMap;
        $build['pager'] = array(
            '#theme' => 'glools_pager',
            '#weight' => 5,
            '#element' => $this->view['view'] .'/'. $this->view['feature']
        );
        
        return $build;
    }
    
    protected function loadActivities($tags=null, $rows=12, $searchMode='latest', $pager=false) {
        
        $query = db_select('node', 'n')->extend('GloolsPagerDefault');
        
        if (!empty($tags)) {
            $vNames = taxonomy_vocabulary_get_names();
            $tagTerms = array();
            foreach($tags as $tag) {
            	$tagTerm  = taxonomy_get_term_by_name($tag, $vNames['tags']->vid);
                if (!empty($tagTerm)) {
                	$tagTerms[$tagTerm->tid] = $tagTerm;
                }
            }
            
            if (!empty($tagTerms) && count($tagTerms)>0) {
                $query->leftJoin('taxonomy_index', 't', 't.nid=n.nid');
                $query->condition('t.tid', array_keys($tagTerms), 'in');
            }
        }
        
        switch($searchMode) {
        	case 'latest':
                $query->orderBy('n.created', 'DESC');
                break;
                
            case 'currentMonth':
                //$betweenTimes = $this->getCurrentMonthTime();
                $bTimes = $this->getCurrentMonthRange();
                $startTime = array_shift($bTimes);
                $endTime   = array_pop($bTimes);
                $query->leftJoin('field_data_field__date_time', 't', 't.entity_id=n.nid');
                $query->condition('t.field__date_time_value', $startTime['timestamp'], '>=');
                $query->condition('t.field__date_time_value', $endTime['timestamp']+(3600*24)-1, '<=');
                break;
                
            case 'promoted':
                $query->orderBy('n.created', 'DESC');
                $query->condition('n.promote', 1);
                break;
                
            default:
                $query->orderBy('n.created', 'DESC');
        }
        
        $query->condition('n.status', '1');
        $query->condition('n.type', 'activity');
        $query->fields('n', array('nid', 'title', 'created'));
        $query->orderBy('sticky', 'DESC');
        $query->limit($rows);
        $query->addMetaData('page-owner', $this->view['view'] .'/'. $this->view['feature']);
        
        $selected = $query->execute();
        $nids = $selected->fetchAllAssoc('nid');
        
        if (!empty($nids)) {
        	foreach($nids as $id=>$node) {
        		$nids[$id]->dateTime = date('Y-m-d H:i:s', $node->created);
        	}
        }
        
        return $nids;
    }
    
    /*
        @param $startWeekDay, int, allowed value enum(1, 7) 
    */
    protected function getCurrentMonthRange($startWeekDay=1){
        static $dayMap;
        
        if (!empty($dayMap)) {
        	return $dayMap;
        }
        
    	$m = date('m', time());
        $d = date('d', time());
        $y = date('Y', time());
        $t = date('t', time());
        $n = date('N', time());
        $d1= date('N', mktime(0,0,0, $m, 1, $y));
        //$dt= date('Y-m-d', mktime(0,0,0, $m, 1, $y));
        //debug_rdata(__FUNCTION__, array($d1, $dt));
        if (1==$startWeekDay) {
            $preDays = $d1-1;
        }else{
        	$preDays = $n;
        }
        
        $days = $preDays + $t;
        
        $suffixDays = 7-($days % 7);
        
        if ($suffixDays!==7) {
        	$days += $suffixDays;
        }
        
        $dayMap = array();
        
        if (!empty($preDays) && $preDays>0) {
        	while($preDays>0) {
                $timestamp = mktime(0,0,0, $m, 0-$preDays, $y);
        		$key = date('Ymd', $timestamp);
                $dayMap[$key] = array(
                    'timestamp' => $timestamp,
                    'datetime'  => date('Y-m-d H:i:s', mktime(0,0,0, $m, 0-$preDays, $y))
                );
                $preDays--;
        	}
        }
        
        for($i=0; $i<$t; $i++) {
            $timestamp = mktime(0,0,0, $m, $i+1, $y);
            $key = date('Ymd', $timestamp);
        	$dayMap[$key] = array(
                'timestamp' => $timestamp,
                'datetime'  => date('Y-m-d H:i:s', mktime(0,0,0, $m, $i+1, $y))
            );
        }
        
        if (7!==$suffixDays && $suffixDays>0) {
            
        	for($i=0; $suffixDays>$i; $i++) {
                $timestamp = mktime(0,0,0, $m, $t+($i+1), $y);
                $key = date('Ymd', $timestamp);
        		$dayMap[$key] = array(
                    'timestamp' => $timestamp,
                    'datetime'  => date('Y-m-d H:i:s', mktime(0,0,0, $m, $t+($i+1), $y))
                );
        	}
        }
        //debug_rdata(__FUNCTION__, $dayMap);
        return $dayMap;
        //debug_rdata(__METHOD__, array('month'=>$m, 'day'=>$d, 'year'=>$y, 'lastDay'=>$t, 'weekNumber'=>$n, 'preDays'=>$preDays, 'days'=>$days, 'suffixDays'=>$suffixDays));
    }
    protected function getCurrentMonthTime(){
    	
        $m = date('m', time());
        $d = date('d', time());
        $y = date('Y', time());
        $t = date('t', time());
        
        $t1 = mktime('0', '0', '0', $m, '1', $y);
        $t2 = mktime('23', '59', '59', $m, $t, $y);
        
        return array('startTime'=>$t1, 'endTime'=>$t2);
    }
}