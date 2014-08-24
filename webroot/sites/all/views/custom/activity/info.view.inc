<?php

Lib_Glools_Load::loadFile('glools/view/abstract', 'lib');

class View_Custom_Activity_Info extends Lib_Glools_View_Abstract{
    
    protected $user = null;
    
    protected $node = null;
    
    protected $activities = array();
    
    protected $booked = false;
    
    protected $bookStyle = '';
    
    public function init(){
        global $user;
    	if (!empty($this->options['global']['node'])) {
            $this->node = $this->options['global']['node'];
    		$this->data = node_view($this->options['global']['node']);
    	}
        $members = _activity_members($this->node->nid);
        
        if (isset($members[$user->uid])) {
            $this->bookStyle = 'booked';
        	$this->booked = true;
        }else{
        	$this->bookStyle='book';
        }
        
        drupal_add_css(path_to_theme().'/css/views/activity/info.view.css');
    }
    
    public function beforeBuild(){
        
        $this->view['title'] = '';
        
        $this->data = '';
    }
    
    public function afterBuild(){
        
    }
}