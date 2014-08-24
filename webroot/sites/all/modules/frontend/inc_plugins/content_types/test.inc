<?php
/*
 * Created on Apr 10, 2014
 *
 * To change the template for this generated file go to
 * Window - Preferences - PHPeclipse - PHP - Code Templates
 */
$plugin = array(
    'title'     => t('Testing CTools plugin for frontend module'),
    'single'    => true,
    'category'  => array('Widgets', -9),
    'edit form' => 'frontend_test_content_type_edit_form',
    'admin title'     => 'frontend_content_type_test_admin_title',
    'render callback' => 'frontend_content_type_render',
    'default'   => array()
);


function frontend_content_type_render($subtype, $conf, $args, $context = NULL) {
  $block = new stdClass;
  $block->title = 'My Test Display View';
  
  $block->content = 'Hello,world, This is test display view for Frontend module.';
  
  debug_rdata(__FUNCTION__, array('subtype'=>$subtype, 'conf'=>$conf, 'args'=>$args, 'context'=>$context));
  
  return $block;
}

/**
 * 'Edit form' callback for the content type.
 */
function frontend_test_content_type_edit_form($form, &$form_state) {
  // No settings beyond context, which has already been handled.
  $names = node_type_get_names();
  $conf = $form_state['conf'];
  
  $form['contenttype'] =  array(
      '#title' => t('Content Type'),
      '#type'  => 'select',
      '#options' => node_type_get_names(),
      '#default_value' => $conf['contenttype']
  );
  return $form;
}

function frontend_test_content_type_edit_form_validate($form, &$form_state){
	
}

function frontend_test_content_type_edit_form_submit($form, $form_state){
    
    foreach (element_children($form) as $key) {
    if (!empty($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}