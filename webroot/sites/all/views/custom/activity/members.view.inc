<?php

Lib_Glools_Load::loadFile('glools/view/abstract', 'lib');

class View_Custom_Activity_Members extends Lib_Glools_View_Abstract{
    
    protected $members = null;
    
    protected $node = null;
    
    protected $activities = array();
    
    public function init(){
    	if (!empty($this->options['global']['node'])) {
    		$this->node = $this->options['global']['node'];
    	}
        
        $this->retrieveParticipants($this->node->nid);
        
        drupal_add_css(path_to_theme().'/css/views/activity/members.view.css');
    }
    
    public function beforeBuild(){
        
        $this->view['title'] = '';
        
        
        $this->data = '';
    }
    
    public function afterBuild(){
        
    }
    
    protected function retrieveParticipants($activityInstanceId){
    	$query = db_query("select user_id from {activity_participant} where instance_id=$activityInstanceId");
        $userIds = $query->fetchAllAssoc('user_id');
        
        if (!empty($userIds)) {
        	$this->members = user_load_multiple(array_keys($userIds));
        }
        //debug_record_data(__FUNCTION__, $this->members);
    }
    
    protected function retrieveFollower($activityInstanceId){
    	
    }
}