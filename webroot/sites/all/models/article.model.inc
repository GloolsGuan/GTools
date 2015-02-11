<?php

Lib_Glools_Load::loadFile('glools/model', 'lib');

class Model_Article extends Lib_Glools_Model
{
    
    
    public function loadArticleCategories(){
    	
    }
    public function loadCities(){
        
        $query = $this->db->query('select * from la_chinese_city where area_level in (1, 2);');
        
        $cities = $query->fetchAll(PDO::FETCH_ASSOC);
        
        return $cities;
    }
    
    public function loadCity($cityId, $cityName){
        $where = array();
        
        $where[] = is_numeric($cityId) ? "area_id='{$cityId}'" : "area_name='{$cityName}'";
        $where[] = "status=1";
        $whereSql = implode(' and ', $where);
        $sql = 'select * from la_chinese_city where ' . $whereSql . ' limit 1;';
        $query = $this->db->query($sql);
        $city = $query->fetch(PDO::FETCH_ASSOC);
        return $city;
    }
    
    public function loadCitybyName($cityName){
        if (!preg_match('/[\x{4e00}-\x{9fa5}]{2,10}/u', $cityName, $matched)) {
            return false;
        }
        
        $sql = str_replace(':cityName', $cityName, 'select * from la_chinese_city where area_level in (1, 2) and area_name like \':cityName%\';');
        $query = $this->db->query($sql);
        
        $city = $query->fetch(PDO::FETCH_ASSOC);
        
        return $city;
    }
    
    public function loadAreaByCity($cityName){
        
        $city = $this->loadCityByName($cityName);
        
        $sql = str_replace(':cityId', $city['area_id'], 'select * from la_chinese_city where parent_id=\':cityId\';');
        $query = $this->db->query($sql);
        $areas = $query->fetchAll(PDO::FETCH_ASSOC);
        $reAreas = array();
        foreach($areas as $area) {
            $reAreas[$area['area_id']] = $area;
        }
        return $reAreas;
    }
    
    public function loadProvince($provinceId, $provinceName=''){
        
        $where = array();
        
        $where[] = is_numeric($provinceId) ? "area_id='{$provinceId}'" : "area_name='{$provinceName}'";
        $where[] = "area_level=1";
        $where[] = "status=1";
        $whereSql = implode(' and ', $where);
        $sql = 'select * from la_chinese_city where ' . $whereSql . ' limit 1;';
        $query = $this->db->query($sql);
        $province = $query->fetch(PDO::FETCH_ASSOC);
        return $province;
    }
    
    public function loadProvinceByCity($cityName){
        $city = $this->loadCityByName($cityName);
        if ('0'==$city['parent_id'] && '1'=='area_level') {
            return $city;
        }
        $province = $this->loadProvince($city['parent_id']);
        return $province;
    }
    
    public function loadFullAddress($objAddress){
        if (!empty($objAddress->province)) {
            $objAddress->province = $this->loadProvince($objAddress->province);
        }
        
        if (!empty($objAddress->city)) {
            $objAddress->city = $this->loadCity($objAddress->city);
        }
        
        $areas = $this->loadAreaByCity($objAddress->city['area_name']);
        $objAddress->area = $areas[$objAddress->area];
        return $objAddress;
    }
    
}