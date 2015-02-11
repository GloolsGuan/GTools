<?php
/*
 * Created on 7 Dec, 2011
 *
 * To change the template for this generated file go to
 * Window - Preferences - PHPeclipse - PHP - Code Templates
 */
Lib_Glools_Load::loadFile('glools/view/abstract', 'lib');

class View_Custom_Tag_Activity extends Lib_Glools_View_Abstract{
    
    
    protected $city = null;
    
    public function init(){
        $cacheCity = cache_get('current_city_term');
        
        if (!empty($cacheCity->data)) {
            $this->city = $cacheCity->data;
        }
    }
    
    public function beforeBuild(){
        
        $cityTerms = $this->loadActivityTerms();
        
        if (!empty($cityTerms)) {
            $this->data = $cityTerms;
        }else{
            $this->data = NULL;
        }
    }
    
    public function afterBuild(){
        
    }
    
    public function loadActivityTerms(){
    	
        $vocabulary = taxonomy_vocabulary_load_multiple(null, array('machine_name'=>'tags'));
        $vo = array_pop($vocabulary);
        
        $queryString = "select a.*,count(b.nid) as cnid from {taxonomy_term_data} as a left join {taxonomy_index} as b on (a.tid=b.tid) where a.vid=:vocabularyId and b.nid in (select nid from {taxonomy_index} where tid=:cityId) group by a.tid;";//where b.nid in (select nid from {taxonomy_index} where tid=:cityId)
        foreach(array(':vocabularyId'=>$vo->vid, ':cityId'=>$this->city->tid) as $k=>$v) {
            $queryString = str_replace($k, $v, $queryString);
        }
        
        if ($cached=cache_get(md5($queryString))) {
        	//debug_record_data(__METHOD__, $cached);
            return $cached->data;
        }
        
        $query = db_query($queryString);
        $cityTerms = $query->fetchAllAssoc('tid');
        
        cache_set(md5($queryString), $cityTerms, 'cache', time()+3600);
        
        return $cityTerms;
    }
}