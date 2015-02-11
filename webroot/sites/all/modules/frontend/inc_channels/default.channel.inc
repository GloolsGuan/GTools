<?php
/*
 * Created on Jan 16, 2013
 *
 * To change the template for this generated file go to
 * Window - Preferences - PHPeclipse - PHP - Code Templates
 */
function frontend_channel_default_info(){
    // Do not need to register any menu
}

function frontend_channel_default(){
    //drupal_add_css(path_to_theme() . '/css/layouts/xf1996.layout.css');
    return 'Coffee Channel';
}

function frontend_channel_default_viewPreset(&$vars, $path){
    
    $re = new stdClass();
    $re->section = 'default';
    $re->data = array();
    
    $re->data['options'] = array();
    
    return $re;
}


function frontend_channel_default_layout_alter(&$layout){
    
    $layout = '2ca';
}