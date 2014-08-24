<?php
/*
 * Created on 12 Dec, 2011
 *
 * To change the template for this generated file go to
 * Window - Preferences - PHPeclipse - PHP - Code Templates
 */
Lib_Glools_Load::loadFile('glools/view/abstract', 'lib');

class View_Custom_Activities_Icons extends Lib_Glools_View_Abstract{
    
    protected $user = null;
    
    
    protected $activities = array();
    
    protected $cities = array();
    
    public function init(){}
    
    
    public function beforeBuild(){
        
        $this->view['title'] = t('最新活动');
        
        $this->cities = $this->loadEnlightCities();
        
        if (!empty($this->options['private'])) {
            $this->data = $this->options['private'];
        }else{
            $this->data = 'There is no activity.';
        }
    }
    
    public function afterBuild(){
    	
    }
    
    protected function loadEnlightCities(){
        $modelCity = Lib_Glools_Load::load('vocabulary/city', 'model');
        
        $cities = $modelCity->loadMostViewedCities(5);
        
        if (empty($cities)) {
            $cities = array();
            return $cities;
        }
        
        foreach ($cities as $k=>$city) {
            $cities[$k]->url = drupal_get_path_alias('taxonomy/term/'.$city->tid);
        }
        
        return $cities;
    }
}