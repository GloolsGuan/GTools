<?php
/*
 * Created on 11 Dec, 2011
 *
 * To change the template for this generated file go to
 * Window - Preferences - PHPeclipse - PHP - Code Templates
 */
Lib_Glools_Load::loadFile('glools/view/abstract', 'lib');

class View_Custom_Members_Creator extends Lib_Glools_View_Abstract{
	
    protected $user = null;
    
    protected $viewName = __CLASS__;
    
    protected $defaultFeature = 'navigator';
                
    public function init(){
        if (!empty($this->options['global']) && !empty($this->options['global']['user'])) {
        	$this->user = $this->options['global']['user'];
        }
        //$this->user = $this->options['user'];
    }
    
    public function beforeBuild(){
    	
        if (empty($this->user->signature)) {
        	$this->user->signature = 'You can write your signature here.';
        }
        
    }
    
    public function afterBuild(){
    	//drupal_add_css(path_to_theme().'/css/views/view_members_creator.css');
        //drupal_add_js(path_to_theme().'/js/views/view_members_creator.view.js');
    }
    
    protected function setBasePath(){
        $this->basePath = dirname(__FILE__);
    }
}