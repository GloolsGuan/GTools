<?php
/*
 * Created on 7 Dec, 2011
 *
 * To change the template for this generated file go to
 * Window - Preferences - PHPeclipse - PHP - Code Templates
 */
Lib_Glools_Load::loadFile('glools/view/abstract', 'lib');

class View_Share_Sample_Sample extends Lib_Glools_View_Abstract{
	
    protected $viewName = __CLASS__;
    
    public function init(){
        
    }
    
    protected function setBasePath(){
        $this->basePath = dirname(__FILE__);
    }
    
    public function beforeBuild(){
    	
        if (!empty($this->options['sample data'])) {
        	$this->data = $this->options['sample data'];
        }else{
        	$this->data = 'hi, hello world.';
        }
    }
    
    public function afterBuild(){
    	
    }
}