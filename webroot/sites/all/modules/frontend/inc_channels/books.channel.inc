<?php
/*
 * Created on Jan 16, 2013
 *
 * To change the template for this generated file go to
 * Window - Preferences - PHPeclipse - PHP - Code Templates
 */
function frontend_channel_books_info(){
    // Do not need to register any menu
}

function frontend_channel_books(){
    //drupal_add_css(path_to_theme() . '/css/layouts/xf1996.layout.css');
    return 'Books Channel';
}

function frontend_channel_books_viewPreset(&$vars, $path){
    
    $re = new stdClass();
    $re->section = 'books';
    $re->data = array();
    
    $re->data['options'] = array();
    
    return $re;
}


function frontend_channel_books_layout_alter(&$layout){
    
    if ('books'==request_path()) {
        $layout = '2ca';
    }
}