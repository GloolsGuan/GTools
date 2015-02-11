<?php

Lib_Glools_Load::loadFile('glools/view/abstract', 'lib');

class View_Custom_Activity_Navigation extends Lib_Glools_View_Abstract{
    
    protected $user = null;
    
    protected $activity = null;
    
    protected $defaultFeature = 'navigation';
    
    protected $activities = array();
    
    public function init(){
        if (!empty($this->options['global']['node'])) {
            $this->node = $this->options['global']['node'];
        }
    	drupal_add_css(path_to_theme().'/css/views/view_activity_navigation.view.css');
    }
    
    public function beforeBuild(){
    
        $this->activity = $this->options['global']['node'];      

        $this->view['title'] = '活动导航';
    }
    
    public function afterBuild(){
        
    }
}