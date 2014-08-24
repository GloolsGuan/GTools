<?php
/*
 * Created on 14 Dec, 2011
 *
 * To change the template for this generated file go to
 * Window - Preferences - PHPeclipse - PHP - Code Templates
 */
Lib_Glools_Load::loadFile('glools/model', 'lib');

class Model_Activity extends Lib_Glools_Model{
    
    protected $table = 'node';
    
    protected $nodeType = 'activity';
    
    protected $cacheTime = 10;
    
    protected static $loadedNodes = array();
    
    /*
    public function disabled_loadPromotedActivities($rows=10){
    	$cacheKey = $this->buildCacheKey(__METHOD__, func_get_args());
        
        $cached = cache_get($cacheKey);
        
        if (!empty($cached->data) && $cached->expire>time()) {
        	$nodes = $cached->data;
        }else{
        	$query = db_query('select n.nid from {node} as n where n.type=:activityType and n.status=1 and n.promote=1 order by created DESC LIMIT '.$rows, array(':activityType'=>'activity'));
            $nodes = $query->fetchAllAssoc('nid');
            cache_set($cacheKey, $nodes, 'cache', time()+$this->cacheTime);
        }
        
        $nodeIds = array_keys($nodes);
        
        return node_load_multiple($nodeIds);
    }
    */
    
    public function loadPromotedActivitiesInCity($rows, $cityTerm, $sticky=false){
        
        $cacheKey = $this->buildCacheKey(__METHOD__, func_get_args());
        
        $sticky = (true===$sticky) ? '1' : '0';
        
        $cached = cache_get($cacheKey);
        
        if (!empty($cached->data) && $cached->expire>time()) {
            $nodeIds = $cached->data;
        }else{
            $query = db_query('select n.nid from {node} as n left join ({taxonomy_index} as t, {field_data_field_activity_logo} as l) on (n.nid=t.nid and n.nid=l.entity_id) where n.type=:activityType and n.status=1 and t.tid=:termid and n.sticky=:sticky and l.field_activity_logo_fid is not null order by n.created DESC limit '.$rows, 
                 array(':activityType'=>'activity', ':sticky'=>$sticky, ':termid'=>$cityTerm->tid));
        
            $nodes = $query->fetchAllAssoc('nid');
            
            $nodeIds = array_keys($nodes);
            
            cache_set($cacheKey, $nodeIds, 'cache', time()+$this->cacheTime);
        }
        
        return node_load_multiple($nodeIds);
    }
    
    public function loadPromotedActivities($categoryId=null, $cityId=null, $rows=20, $sticky=false){
    	
        return $this->loadLatestActivities($categoryId, true, $sticky, $cityId, $rows, true);
    }
    
    public function loadPromotedWithPager($categoryId=null, $cityId=null, $rows=20){
        return $this->loadLatestActivitiesWithPager($categoryId, true, false, $cityId, $rows, true);
    }
    
    public function loadLatestWithPager($categoryId=null, $cityId=null, $rows=20){
        return $this->loadLatestActivitiesWithPager($categoryId, false, false, $cityId, $rows, true);
    }
    
    public function loadLatestActivitiesWithPager($categoryId=null, $promoted=false, $sticky=false, $cityId=null, $rows=20, $status=true){
        
        $cacheKey = $this->buildCacheKey(__METHOD__, func_get_args());
        $pagerKey = md5($cacheKey);
        
        /*
        $cached = cache_get($cacheKey, 'cache');
        if (!empty($cached->data) && $cached->expire>time()) {
        	$nIds = $cached->data;
            return array(
                'nodes'    => node_load_multiple($nIds),
                'pagerKey' => $pagerKey
            );
        }
        */
        
        $query = db_select('node', 'n')->extend('GloolsPagerDefault');
        $query->fields('n', array('nid'));
        $query->condition('n.type', 'activity');
        $query->condition('n.status', (true===$status) ? '1' : '0');
        $query->limit($rows);
        $query->orderBy('n.created', 'DESC');
        
        
        
        if (!empty($cityId) && is_numeric($cityId)) {
            $query->join('field_data_field_city', 'c', 'c.entity_id =n.nid');
            $query->condition('c.field_city_tid', $cityId);
        }
        
        if (!empty($categoryId) && is_numeric($categoryId)) {
        	$query->join('field_data_field_activity_term', 'g', 'g.entity_id=n.nid');
            $query->condition('g.field_activity_term_tid', $categoryId);
        }
        
        if (true===$promoted) {
        	$query->condition('n.promote', '1');
        }
        
        if (true===$sticky) {
        	$query->condition('n.sticky', '1');
        }
        $query->addMetaData('page-owner', $pagerKey);
        $fetched = $query->execute()->fetchAllAssoc('nid');
        
        if (empty($fetched)) {
        	$nIds = null;
        }else{
        	$nIds = array_keys($fetched);
        }
        
        //cache_set($cacheKey, $nIds, 'cache', time()+$this->cacheTime);
        
        return array(
            'nodes'    => node_load_multiple($nIds),
            'pagerKey' => $pagerKey
        );
    }
    
    
    public function loadLatestActivities($categoryId=null, $promoted=false, $sticky=false, $cityId=null, $rows=20, $status=true){
        
        $cacheKey = $this->buildCacheKey(__METHOD__, func_get_args());
        $pagerKey = md5($cacheKey);
        
        
        $cached = cache_get($cacheKey, 'cache');
        if (!empty($cached->data) && $cached->expire>time()) {
            $nIds = $cached->data;
            return node_load_multiple($nIds);
        }
        
        
        $query = db_select('node', 'n')->extend('GloolsPagerDefault');
        $query->fields('n', array('nid'));
        $query->condition('n.type', 'activity');
        $query->condition('n.status', (true===$status) ? '1' : '0');
        if (!empty(self::$loadedNodes)) {
        	$query->condition('n.nid', self::$loadedNodes, 'not in');
        }
        $query->limit($rows);
        $query->orderBy('n.created', 'DESC');
        
        
        
        if (!empty($cityId) && is_numeric($cityId)) {
            $query->join('field_data_field_city', 'c', 'c.entity_id =n.nid');
            $query->condition('c.field_city_tid', $cityId);
        }
        
        if (!empty($categoryId) && is_numeric($categoryId)) {
            $query->join('field_data_field_activity_term', 'g', 'g.entity_id=n.nid');
            $query->condition('g.field_activity_term_tid', $categoryId);
        }
        
        if (true===$promoted) {
            $query->condition('n.promote', '1');
        }
        
        if (true===$sticky) {
            $query->condition('n.sticky', '1');
        }
        
        $fetched = $query->execute()->fetchAllAssoc('nid');//cache_clear_all($cacheKey, 'cache');
        
        if (empty($fetched)) {
            $nIds = null;
        }else{
            $nIds = array_keys($fetched);
            self::$loadedNodes = $nIds;
        }
        
        cache_set($cacheKey, $nIds, 'cache', time()+$this->cacheTime);
        
        return node_load_multiple($nIds);
    }
    
    
    /*
    public function loadMostViewedCities($num=10){
        
        $limit = !empty($num) && is_numeric($num) ? 'limit '.$num : ''; 
        
        $sql = "select * from `{".$this->table."}` where `status`=1 order by `viewed` desc $limit;";
        
        return $this->db->query($sql)->fetchAllAssoc('id');
    }
    
    public function loadCitiesByAlphabetical($num=20){
        
        $limit = !empty($num) && is_numeric($num) ? 'limit '.$num : ''; 
        
        $sql = "select * from `{". $this->table ."}` where `status`=1 order by `pinyin` ASC $limit;";
        
        return $this->db->query($sql)->fetchAllAssoc('id');
    }
    
    public function loadPromotedCities($rows=20){
        $limit = !empty($num) && is_numeric($num) ? 'limit '.$num : ''; 
        
        $sql = "select * from `{". $this->table ."}` where `status`=1 and `promote`=1 order by `pinyin` ASC $limit;";
        
        return $this->db->query($sql)->fetchAllAssoc('id');
    }
    */
}