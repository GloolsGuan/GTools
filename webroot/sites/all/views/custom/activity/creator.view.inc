<?php

Lib_Glools_Load::loadFile('glools/view/abstract', 'lib');

class View_Activity_Creator extends Lib_Glools_View_Abstract{
    
    protected $user = null;
    
    protected $node = null;
    
    protected $activities = array();
    
    public function init(){
    	if (!empty($this->options['global']['node'])) {
    		$this->node = $this->options['global']['node'];
    	}
        drupal_add_css(path_to_theme().'/css/block-view_activity_creator.block.css');
    }
    
    public function beforeBuild(){
        
        $this->view['title'] = '';
        
        
        $this->data = '';
    }
    
    public function afterBuild(){
        
    }
}