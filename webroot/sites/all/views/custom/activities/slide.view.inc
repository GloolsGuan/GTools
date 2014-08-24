<?php
/**
 * 
 * This is a photos advertisement block, The block will be show as a slideshow, User can control the 
 * block to show last or next photo. 
 * 
 * */
Lib_Glools_Load::loadFile('glools/view/abstract', 'lib');

class View_Custom_Activities_Slide extends Lib_Glools_View_Abstract{
    
    protected $viewName = __CLASS__;
    
    
    public function init(){
        drupal_add_js(path_to_theme() . '/js/tabScroller.js');
    }
    
    protected function setBasePath(){
        $this->basePath = dirname(__FILE__);
    }
    
    public function beforeBuild(){
        $this->data = $this->options['private'];
        //debug_record_data(__FUNCTION__, $this->data);
    }
    
    public function afterBuild(){
        
    }
}