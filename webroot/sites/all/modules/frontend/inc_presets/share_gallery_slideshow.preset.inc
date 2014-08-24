<?php
/*
 * Created on Apr 27, 2014
 *
 * To change the template for this generated file go to
 * Window - Preferences - PHPeclipse - PHP - Code Templates
 */
function _frontend_preset_share_gallery_slideshow($view){
	//debug_rdata(__FUNCTION__, $view);
    if (!empty($view['private_key'])) {
    	$hook = __FUNCTION__ . '_' .$view['private_key'];
        
        if (function_exists($hook)) {
        	return $hook();
        }
    }
}

function _frontend_preset_share_gallery_slideshow_xfboard(){
	
    $query = db_query_range('select * from {node} where type=:type order by created DESC', 0, 6, array(':type'=>'drawingboard'));
    $nids = $query->fetchAllAssoc('nid');
    
    if (!empty($nids)) {
    	$nodes = node_load_multiple(array_keys($nids));
        return node_view_multiple($nodes, 'slideshow');
        
    }
    
    return '';
}

