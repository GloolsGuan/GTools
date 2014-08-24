<?php
/*
 * Created on 15 Dec, 2011
 *
 * To change the template for this generated file go to
 * Window - Preferences - PHPeclipse - PHP - Code Templates
 */
Lib_Glools_Load::loadFile('glools/view/abstract', 'lib');

class View_Lasooo_About extends Lib_Glools_View_Abstract{
    
    protected $viewName = __CLASS__;
    
    protected $defaultFeature = 'about';
    
    protected $menubar = '';
    
    public function init(){}
    
    protected function setBasePath(){
        $this->basePath = dirname(__FILE__);
    }
    
    public function beforeBuild(){
    	
        $this->data['cities'] = $this->loadEnlightCities();
        $this->data['tags']   = $this->loadEnlightTags();
    }
    
    public function afterBuild(){
    	drupal_add_css(path_to_theme() . '/css/views/view_lasooo_about.view.css');
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
    
    protected function loadEnlightTags(){
    	$modelTags = Lib_Glools_Load::load('vocabulary/tag', 'model');
        
        $tags = $modelTags->loadMostViewedTags(12);
        
        if (empty($tags)) {
            $tags=array();
            return $tags;
        }
        
        foreach ($tags as $k=>$tag) {
            $tags[$k]->url = drupal_get_path_alias('taxonomy/term/'.$tag->tid);
        }
        
        return $tags;
    }
}