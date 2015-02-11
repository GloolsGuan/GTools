<?php


Lib_Glools_Load::loadFile('glools/view/abstract', 'lib');

class View_Custom_Node_Video extends Lib_Glools_View_Abstract{
    
    protected $user = null;
    
    protected $activity = null;
    
    //protected $defaultFeature = '';
    
    protected $buildNodes = array();
    
    /**
     * Checking presettings and set the parameters for the view
     * */
    public function init(){
        //debug_rdata(__METHOD__, array($this->options, $this->view));
        if (empty($this->view['rows']) || !is_numeric($this->view['rows'])) {
            $this->view['rows'] = 12;
        }
        
        if (empty($this->view['title'])) {
            $this->view['title'] = '视频';
        }
        
    }
    
    /**
     * Prepare data for the view
     * */
    public function beforeBuild(){
        
        if (empty($this->view['feature'])) {
        	$viewMode = 'teaser';
        }else{
        	$viewMode = $this->view['feature'];
        }
        
        $videos = $this->loadVideos($this->view['rows'], false);
        
        $this->buildNodes = $this->buildNodes($videos, $viewMode, true);
        
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
        foreach($nodes as $nid=>$node) {
        	$node->field_video_code[$node->language][0]['format']='full_html';
            $nodes[$nid] = $node;
        }
        $build = node_view_multiple($nodes, $viewMode);
        
        $build['pager'] = array(
            '#theme' => 'glools_pager',
            '#weight' => 5,
            '#element' => $this->view['view']
        );
        
        return $build;
    }
    
    protected function loadVideos($rows=5, $pager=false) {
        
        $query = db_select('node', 'n')->extend('GloolsPagerDefault');
        $query->fields('n', array('nid', 'title', 'created'));
        $query->condition('n.status', '1');
        $query->condition('n.type', 'activity_video');
        
        $query->orderBy('n.created', 'DESC');
        $query->orderBy('sticky', 'DESC');
        $query->limit($rows);
        $query->addMetaData('page-owner', $this->view['view']);
        
        $selected = $query->execute();
        //debug_rdata(__FUNCTION__, $selected);
        $nids = $selected->fetchAllAssoc('nid');
        
        return $nids;
    }
}