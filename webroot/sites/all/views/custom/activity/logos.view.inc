<?php

Lib_Glools_Load::loadFile('glools/view/abstract', 'lib');

class View_Custom_Activity_Logos extends Lib_Glools_View_Abstract{
    
    protected $user = null;
    
    protected $node = null;
    
    protected $activities = array();
    
    protected $logosElement = array();
    
    public function init(){
        
    	if (!empty($this->options['private']['logos'])) {
    		$this->logosElement = $this->options['private']['logos'];
    	}
    }
    
    public function beforeBuild(){
        
        $this->view['title'] = 'Activity photos';
        
    }
    
    public function afterBuild(){
        drupal_add_js(path_to_theme() . '/js/tabScroller.js');
    }
}