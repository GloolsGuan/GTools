<?php
/*
 * Created on 7 Jan, 2012
 *
 * To change the template for this generated file go to
 * Window - Preferences - PHPeclipse - PHP - Code Templates
 */
defined('THEME_LASOOO_DIR')      || define('THEME_LASOOO_DIR', dirname(__FILE__));
defined('THEME_LASOOO_PATH')     || define('THEME_LASOOO_PATH', '/themes/lasooo');
defined('THEME_LASOOO_PATH_IMG') || define('THEME_LASOOO_PATH_IMG', THEME_LASOOO_PATH . '/images');
defined('THEME_LASOOO_PATH_CSS') || define('THEME_LASOOO_PATH_CSS', THEME_LASOOO_PATH . '/css');

/**
 * Load default stylesheet
 * */
function _theme_lasooo_load_DefaultCSS(&$vars) {
    
    $style = '';
    $style .= _theme_lasooo_importCSS(THEME_LASOOO_PATH_CSS . '/960/960.css');
    $style .= _theme_lasooo_importCSS(THEME_LASOOO_PATH_CSS . '/960/reset.css');
    $style .= _theme_lasooo_importCSS(THEME_LASOOO_PATH_CSS . '/960/fonts.css');
    $style .= _theme_lasooo_importCSS(THEME_LASOOO_PATH_CSS . '/block-layouts.css');
    $style .= _theme_lasooo_importCSS(THEME_LASOOO_PATH_CSS . '/glayout.css');
    $style .= _theme_lasooo_importCSS(THEME_LASOOO_PATH_CSS . '/gstyle.css');
    
    drupal_add_css($style, 'inline');
}

function _theme_lasooo_load_LayoutCSS(&$vars){
	if (!isset($vars['layout'])) {
		return false;
	}
    
    $layout = $vars['layout'];
    //$layout = 'user';
    if (file_exists(THEME_LAS_DIR_CSS . '/layouts/' . $layout.'.layout.css')) {
    	//drupal_add_css(path_to_theme() . '/css/layouts/' . $layout.'.layout.css');
        
        drupal_add_css(_theme_lasooo_importCSS(THEME_LASOOO_PATH_CSS . '/layouts/'. $layout .'.layout.css'), 'inline');
    }
}

function _theme_lasooo_process_layout(&$vars){
    
    if ($vars['is_front']) {
        $layout = 'frontpage';
    }else{
    	if (preg_match('/^[a-z]+/', request_path(), $matched)) {
    		$layout = $matched[0];
    	}
    }
    
    $layoutTemplate = dirname(__FILE__) . '/templates/layouts/' . $layout . '.layout.php';
    
    if (file_exists($layoutTemplate)) {
    	$vars['layout'] = $layout;
    }else{
    	$vars['layout'] = 'default';
    }
    
    drupal_alter('layout', $vars['layout']);
}

function _theme_lasooo_load_layoutJS(&$vars){
    $layout = $vars['layout'];
    drupal_add_js(path_to_theme() . '/js/light-framework.js', array('weight'=>-100));
    if (file_exists(dirname(__FILE__).'/js/layouts/'.$layout.'.layout.js')) {
        drupal_add_css(path_to_theme().'/js/layouts/'.$layout.'.layout.js');
    }
}

function _theme_lasooo_show_breadcrumb($breadcrumb){
    if (!is_array($breadcrumb) || 1>count($breadcrumb)) {
        return null;
    }
    $re = '';
    foreach ($breadcrumb as $link) {
        $re .= empty($re) ? $link : '&nbsp;»&nbsp;'.$link;
    }
    return $re;
}

function _theme_lasooo_preset_usermenus(&$vars){
    global $user;
    
    $forum = array(
        'attributes'=> array('title'=>'Forum'),
        'href'=> 'http://forum.lasooo.com',
        'title' => t('Forum'),
        'html' => true,
    );
    
    if( true==$vars['logged_in'] ){
        $userAccount = array(
            'attributes'=> array('title'=>'My Account'),
            'href'=> '/member/'.strtolower(str_replace(' ', '-', $user->name)),
            'title' => '<span class="username">'.strip_tags($user->name).'</span>' . member_load_member_photo($user),
            'html' => true,
        );
        $myMessages = array(
            'attributes'=> array('title'=>'Messages'),
            'href'=> '/home/messages',
            'title' => '消息(0)'
        );
        $userHome = array(
            'attributes'=> array('title'=>'我的主页'),
            'href'=> '/home/message',
            'title' => t('我的书屋')
        );
        
        $myActivities = array(
            'attributes' => array('title'=>'我的活动'),
            'href' => '/home/myactivity',
            'title' => t('我的活动')
        );
        
        $publishActivities = array(
            'attributes' => array('title'=>'发布活动'),
            'href' => '/activity/create',
            'title' => t('发布活动'),
            'weight' => 2
        );
        
        $activityCommunity = array(
            'attributes' => array('title'=>'活动圈'),
            'href' => '/community',
            'title' => t('活动圈'),
            'weight' => 3
        );
        
        $organizer = array(
            'attributies' => array('title'=>'成为活动组织者'),
            'href' => url('member/apply/organizer'),
            'title' => t('Apply for Organizer'),
            'weight' => 3
        );
        
        $logout = array(
            'attributes' => array('title'=>'退出'),
            'href' => '/user/logout',
            'title' => t('退出')
        );
        
        if (!in_array('organizer', $user->roles)) {
            array_unshift($vars['main_menu'], $organizer);
        }else{
        	array_unshift($vars['main_menu'], $publishActivities);
        }
        
        array_unshift($vars['main_menu'], $logout, $userAccount, $userHome, $forum); //, $userHome, $myActivities, $publishActivities
        
    }else{
        $login = array(
            'attributes'=> array('title'=>'Login'),
            'href'=> '/user/login',
            'title' => t('登陆')
        );
        $register = array(
            'attributes'=> array('title'=>'Register'),
            'href'=> '/user/register',
            'title' => t('注册')
        );
        array_unshift($vars['main_menu'], $forum, $login, $register);
    }
}

function _theme_lasooo_showBlocks($regionContent){
    $blockNames = element_children($regionContent, true);
    $blocks =array();
    foreach($blockNames as $block) {
        $blocks[$block] = $regionContent[$block];
    }
    return render($blocks);
}