<?php


Lib_Glools_Load::loadFile('glools/view/abstract', 'lib');

class View_Share_gallery_Slideshow extends Lib_Glools_View_Abstract{
    
    protected $user = null;
    
    protected $activity = null;
    
    protected $defaultFeature = 'photowindow';
    
    protected $activities = array();
    
    protected $buildPhotos = array();
    
    public function init(){
        $this->buildPhotos = $this->options['private'];
    }
    
    public function beforeBuild(){
        ;
    }
    
    public function afterBuild(){
        ;
    }
}