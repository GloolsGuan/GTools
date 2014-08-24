<?php
/*
 * Created on 14 Dec, 2011
 *
 * To change the template for this generated file go to
 * Window - Preferences - PHPeclipse - PHP - Code Templates
 */
Lib_Glools_Load::loadFile('glools/model', 'lib');

class Model_Vocabulary_City extends Lib_Glools_Model{
    
    protected $table = 'term_data';
    
    protected $vocabularyName = '城市与地区';
    
    protected $vocabularyMachineName = 'city_area';
    
    protected $vocabularyId = 5;
    
    public function loadMostViewedCities($rows=null){
        if (!empty($rows) && is_numeric($rows)) {
        	$sqlLimit = 'limit '.$rows;
        }else{
        	$sqlLimit = '';
        }
        $sql = "select a.*,count(nid) as nodes  from {taxonomy_term_data} as a left join ({taxonomy_index} as b) on (b.tid=a.tid) " .
                "where a.vid=:vid group by a.tid order by nodes desc ".$sqlLimit;
        
        $cities = $this->db->query($sql, array(':vid'=>$this->vocabularyId))->fetchAllAssoc('tid');
        
        return $cities;
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