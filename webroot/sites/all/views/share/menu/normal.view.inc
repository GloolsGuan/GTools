<?php
/*
 * Created on Nov 16, 2012
 *
 * To change the template for this generated file go to
 * Window - Preferences - PHPeclipse - PHP - Code Templates
 */

Lib_Glools_Load::loadFile('glools/view/abstract', 'lib');

class View_Share_Menu_Normal extends Lib_Glools_View_Abstract{
    
    
    protected $title = null;
    
    protected $viewTitle = '';
    
    
    public function init(){
        $this->title = 'Member Navigator';
        
    }
    
    public function beforeBuild(){
        if (!empty($this->options['private'])) {
        	$this->data = $this->options['private'];
        }
        
    }
    
    public function afterBuild(){
        
    }
    
    protected function getContentsByBookId($bookId){
        
    }
    
}
