<?php
/*
 * Created on 14 Dec, 2011
 *
 * To change the template for this generated file go to
 * Window - Preferences - PHPeclipse - PHP - Code Templates
 */
Lib_Glools_Load::loadFile('glools/model/entity', 'lib');

class Model_Member extends Lib_Glools_Model_Entity{
	
    protected $table = 'user';
    
    public function loadMember($mid){
    	$mTables = array('contact');
        $re = array();
        foreach ($mTables as $table) {
            $func = 'loadMember'.ucfirst($table);
        	$re[$table] = $this->$func($mid);
        }
        return $re;
    }
    
    public function loadMemberPoints($mid){
    	$query = db_query("select * from {users_points} where uid=:mid limit 1;", array(':mid'=>$mid));
        return $query->fetchAssoc();
    }
    
    public function loadMemberContact($mid){
        $query = db_query("select * from {users_contact} where uid=:mid limit 1", array(':mid'=>$mid));
        return $query->fetchAssoc();
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