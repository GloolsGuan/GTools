<?php
/*
 * Created on 7 Dec, 2011
 *
 * To change the template for this generated file go to
 * Window - Preferences - PHPeclipse - PHP - Code Templates
 */
Lib_Glools_Load::loadFile('glools/view/abstract', 'lib');

class View_Custom_Activities_List extends Lib_Glools_View_Abstract{
    
    //protected $viewName = __CLASS__;
    
    //protected $defaultFeature = 'list';
    
    protected $nodes = null;
    // City term object
    protected $city = null;
    
    public function init(){
        $cacheCity = cache_get('current_city_term');
        
        if (!empty($cacheCity->data)) {
        	$this->city = $cacheCity->data;
        }
        
        if (!empty($this->options['private'])) {
        	$this->data = $this->options['private'];
        }else{
        	$this->data = 'There is no activity in current city.';
        }
    }
    
    public function beforeBuild(){
        
    }
    
    public function afterBuild(){
        
    }
}