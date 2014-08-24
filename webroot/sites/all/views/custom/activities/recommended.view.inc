<?php
/*
 * Created on 7 Dec, 2011
 *
 * To change the template for this generated file go to
 * Window - Preferences - PHPeclipse - PHP - Code Templates
 */
Lib_Glools_Load::loadFile('glools/view/abstract', 'lib');

class View_Custom_Activities_Recommended extends Lib_Glools_View_Abstract{
    
    
    // City term object
    protected $city = null;
    
    public function init(){
        $cacheCity = cache_get('current_city_term');
        if (!empty($cacheCity->data)) {
        	$this->city = $cacheCity->data;
        }
        
    }
    
    public function beforeBuild(){
        if (!empty($this->options['private'])) {
            $this->data = $this->options['private'];
        }else{
            $this->data = 'There is no activity in current city.';
        }
    }
    
    public function afterBuild(){
        
    }
}