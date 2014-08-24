<?php
/**
 * 
 * Slide Icons
 * 
 * @Requirement parameters(options.private)
 * nodes : array
 * title : string
 * 
 * */
Lib_Glools_Load::loadFile('glools/view/abstract', 'lib');

class View_Custom_Activities_Sicons extends Lib_Glools_View_Abstract{
    
    protected $viewName = __CLASS__;
    
    protected $nodes = array();
    
    
    public function init(){
        drupal_add_js(path_to_theme() . '/js/tabScroller.js');
        
        //$this->cities = $this->loadEnlightCities();
        
        if (!empty($this->options['private']) && @empty($this->options['nodes'])) {
            $this->data = $this->options['private']['nodes'];
        }else{
            $this->data = 'There is no activity.';
        }
        
        if (!empty($this->options['private']['title'])) {
        	$this->view['title'] = $this->options['private']['title'];
        }
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