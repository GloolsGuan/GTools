<?php
/*
 * Created on 15 Dec, 2011
 *
 * To change the template for this generated file go to
 * Window - Preferences - PHPeclipse - PHP - Code Templates
 */
Lib_Glools_Load::loadFile('glools/view/abstract', 'lib');

class View_Lasooo_Earth extends Lib_Glools_View_Abstract{
    
    protected $viewName = __CLASS__;
    
    protected $defaultFeature = 'earth';
    
    protected $menubar = '';
    
    public function init(){}
    
    protected function setBasePath(){
        $this->basePath = dirname(__FILE__);
    }
    
    public function beforeBuild(){}
    
    public function afterBuild(){
    	drupal_add_css(path_to_theme() . '/css/views/lasooo/earth.view.css');
    }
}