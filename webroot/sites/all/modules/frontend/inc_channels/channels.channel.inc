<?php
/*
 * Created on Jan 16, 2013
 *
 * To change the template for this generated file go to
 * Window - Preferences - PHPeclipse - PHP - Code Templates
 */
function frontend_channel_channels_info(){
    // Do not need to register any menu
}

function frontend_channel_channels(){
    drupal_add_css(path_to_theme() . '/css/layouts/xf1996.layout.css');
    drupal_add_js(path_to_theme() . '/js/xf1996.page.js');
    return '';
}

function frontend_channel_channels_viewPreset(&$vars, $path){
    
    $re = new stdClass();
    $re->section = 'channels';
    $re->data = array();
    
    $re->data['options'] = array();
    
    return $re;
}


function frontend_channel_channels_layout_alter(&$layout){
    
    if ('channels'==request_path()) {
        $layout = 'xf1996';
    }
}