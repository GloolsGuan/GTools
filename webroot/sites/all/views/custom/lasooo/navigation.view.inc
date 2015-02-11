<?php
/**
 * Description:
 * The view used to show a navigation bar for control others block by javascript.
 * Generally the javascript file should be path_to_theme().'/js/views/view-lasooo-navigation.view.js'
 */
Lib_Glools_Load::loadFile('glools/view/abstract', 'lib');

class View_Custom_Lasooo_Navigation extends Lib_Glools_View_Abstract{
    
    //protected $viewName = __CLASS__;
    
    //protected $defaultFeature = 'navigation';
    
    protected $menubar = '';
     
    public function init(){}
    
    protected function setBasePath(){
        $this->basePath = dirname(__FILE__);
    }
    
    public function beforeBuild(){
        //drupal_add_js(path_to_theme().'/js/views/view-lasooo-navigation.view.js');
    	$this->data = array(
            array('title'=>'如何使用乐书', 'name'=>'use-lasooo', 'target'=>'#view_custom_lasooo_uselasooo'),
            array('title'=>'分享你的快乐', 'name'=>'share', 'target'=>'#view_custom_lasooo_share'),
            //array('title'=>'你可以成为乐书人', 'name'=>'join', 'target'=>'#view_lasooo_join'),
            array('title'=>'乐书公益', 'name'=>'public-welfare', 'target'=>'#view_custom_lasooo_welfare'),
            //array('title'=>'我们的生活', 'name'=>'ourlife', 'target'=>'#view_custom_lasooo_ourlife'),
            //array('title'=>'推荐给你的朋友', 'name'=>'tellyourfriends', 'target'=>'#view_custom_lasooo_tellyourfriends'),
            //array('title'=>'发现你身边的资源', 'name'=>'resource', 'target'=>'#view_custom_lasooo_resource'),
            //array('title'=>'和乐书一起成长', 'name'=>'growingup', 'target'=>'#view_custom_lasooo_growingup'),
            //array('title'=>'我们的地球，我们的家', 'name'=>'earth', 'target'=>'#view_custom_lasooo_earth')
        );
    }
    
    public function afterBuild(){
    	
    }
}