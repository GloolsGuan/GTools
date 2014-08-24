<?php
/*
 * Created on 15 Dec, 2011
 *
 * To change the template for this generated file go to
 * Window - Preferences - PHPeclipse - PHP - Code Templates
 */
Lib_Glools_Load::loadFile('glools/view/abstract', 'lib');

class View_Lasooo_Slideshow extends Lib_Glools_View_Abstract{
    
    protected $viewName = __CLASS__;
    
    protected $defaultFeature = 'slideshow';
    
    protected $menubar = '';
    
    public function init(){}
    
    protected function setBasePath(){
        $this->basePath = dirname(__FILE__);
    }
    
    public function beforeBuild(){
        $topSlide = array(
            array('/misc/lasooo/slidebox/lasooo-major-ads-1.jpg', 'book/60'),
            array('/misc/lasooo/slidebox/lasooo-major-ads-2.JPG', 'book/61'),
            array('/misc/lasooo/slidebox/lasooo-major-ads-3.JPG', 'book/63'),
            /*array('/misc/lasooo/slidebox/sample-04.jpg', 'http://www.glools.com'),
            array('/misc/lasooo/slidebox/sample-01.jpg', 'http://www.glools.com')*/
        );
        
        $links = array();
        foreach($topSlide as $p){
            $image = theme('image',array(
                'path' => $p[0],
                'width' => '300',
                'alt' => 'GLOOLS MAIGOR PROJECT',
                'title' => 'GLOOLS MAIGOR PROJECT'
            ));
            $links[] = l($image, $p[1], array('html'=>true, 'attributes'=>array('target'=>'_blank')));
        }
        
        $itemListVariables = array(
            'items'=>$links,
            'type'=>'ul',
            'attributes'=>array(
                'class' => 'slideContent'
            ),
            'containerAttributes'=>array(
                'class' => 'slideContainer'
            )
        );
        drupal_add_js(path_to_theme().'/js/tabScroller.js');
        
        $this->data = theme('glools_item_list', $itemListVariables);
    }
    
    public function afterBuild(){
        
    }
}