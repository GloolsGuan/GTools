<?php
/*
 * Created on 11 Dec, 2011
 *
 * Description:
 *   Display current login user avatar information.
 * 
 * 
 */
Lib_Glools_Load::loadFile('glools/view/abstract', 'lib');

class View_Custom_Members_Levelprocess extends Lib_Glools_View_Abstract{
    
    protected $user = null;
    
    protected $viewName = __CLASS__;
    
    protected $defaultFeature = 'levelprocess';
    
    protected $gUser = null;
    
    
    
    public function init(){
        global $user;
        
        $this->user = $this->options['private'];
        
        $this->point = member_load_point($this->user->uid);
        $this->coin = member_load_coin($this->user->uid);
        $this->level = member_load_level($this->user->uid);
        $this->defaultLevels = member_load_defaultLevels();
        
        
    }
    
    public function beforeBuild(){
        
        if ( 0 == $this->user->uid ) {
            $this->data = t('There is no user information.');
            return ;
        }
        
        if (empty($this->user->signature)) {
            $this->user->signature = 'You can write your signature here.';
        }
        
    }
    
    public function afterBuild(){
        drupal_add_css(path_to_theme().'/css/views/view-members-avatar.view.css');
    }
    
    protected function setBasePath(){
        $this->basePath = dirname(__FILE__);
    }
}