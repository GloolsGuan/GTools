<?php
/*
  -- Page Channel --
  All page and book was routed and control by page channel
**/

function frontend_channel_page_viewPreset(&$vars, $path){
    
    $re = new stdClass();
    $re->data = array();
    
    $reMatch = preg_match('/^page\/([a-z0-9\-\_]+)/i', $path, $matched);
    
    debug_rdata(__FUNCTION__, array($path, $reMatch, $matched));
    
    $re->data['options'] = array();
    
    return $re;
}

