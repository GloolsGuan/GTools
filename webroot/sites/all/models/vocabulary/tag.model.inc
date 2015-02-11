<?php
/*
 * Created on 14 Dec, 2011
 *
 * To change the template for this generated file go to
 * Window - Preferences - PHPeclipse - PHP - Code Templates
 */
Lib_Glools_Load::loadFile('glools/model', 'lib');

class Model_Vocabulary_Tag extends Lib_Glools_Model{
    
    protected $table = 'term_data';
    
    protected $vocabularyName = 'Tags';
    
    protected $vocabularyMachineName = 'tags';
    
    protected $vocabularyId = 1;
    
    public function loadMostViewedTags($rows=null){
        if (!empty($rows) && is_numeric($rows)) {
        	$sqlLimit = 'limit '.$rows;
        }else{
        	$sqlLimit = '';
        }
        $sql = "select a.*,count(nid) as nodes  from {taxonomy_term_data} as a left join ({taxonomy_index} as b) on (b.tid=a.tid) " .
                "where a.vid=:vid group by a.tid order by nodes desc ".$sqlLimit;
        
        $tags = $this->db->query($sql, array(':vid'=>$this->vocabularyId))->fetchAllAssoc('tid');
        
        return $tags;
    }
    
    public function loadTagsByName($tagNames){
    	if (empty($tagNames)) {
    		return false;
    	}
        
        $namesQuery = implode('\',\'', $tagNames);
        
        $sql = 'select * from {taxonomy_term_data} where vid=:tagsVocabularyId and name in (:tagNames)';
        $tags = $this->db->query($sql, array(':tagsVocabularyId'=>$this->vocabularyId,':tagNames'=>$namesQuery))->fetchAllAssoc('tid');
        
        return $tags;
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