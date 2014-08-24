<?php

return array(
    'frontpage' => array(
        'xf1996_background' => array(
            array('view' => 'custom/node/drawingboard', 'private_key'=>'xfboard', 'feature'=>'fpscreen'),
        ),        
        'main' => array(
            array('weight'=>0, 'view'=>'custom/xf1996/logo', 'private_key'=>'frontpage',  'feature'=>'muke'),
            array('weight'=>0, 'view'=>'custom/xf1996/menu', 'private_key'=>'frontpage', 'feature'=>'enter'),
            //array('weight'=>0, 'view'=>'custom/xf1996/menu', 'private_key'=>'frontpage', 'feature'=>'link-icons'),
        ),
    ),
    'channels'    => array(
        'xf1996_background' => array(
            array('view' => 'custom/node/drawingboard', 'private_key'=>'xfboard', 'feature'=>'screen'),
        ),        
        'main' => array(
            array('weight'=>0, 'view'=>'custom/xf1996/menu', 'private_key'=>'channels', 'feature'=>'channels'),
            array('weight'=>0, 'view'=>'custom/xf1996/menu', 'private_key'=>'channels', 'feature'=>'link-icons'),
        ),
    ),
    'activities'=>array(
        'sidebar_first' => array(
            array('weight'=>0, 'view'=>'custom/xf1996/logo', 'private_key'=>'logo',  'feature'=>'logo'),
            array('weight'=>0, 'view'=>'custom/xf1996/menu', 'private_key'=>'activities', 'title'=>'频道', 'feature'=>'menu'),
        ),        
        'main' => array(
            array('weight'=>0, 'view'=>'custom/node/activity', 'private_key'=>'activities', 'feature'=>'calendar', 'searchMode'=>'currentMonth', 'class'=>'byhd'),
            array('weight'=>0, 'view'=>'custom/node/activity', 'private_key'=>'activities', 'feature'=>'xf1996_teaser', 'searchMode'=>'latest', 'rows'=>'3', 'class'=>'zxhd'),
            array('weight'=>0, 'view'=>'custom/node/photowall', 'private_key'=>'activities', 'category'=>'先锋活动', 'feature'=>'icons', 'class'=>'hdxc'),
            array('weight'=>0, 'view'=>'custom/node/video', 'private_key'=>'activities', 'category'=>'先锋视频', 'class'=>'xfsp')
        )
    ),
    'xf1996'=>array(
        'sidebar_first' => array(
            array('weight'=>0, 'view'=>'custom/xf1996/logo', 'private_key'=>'logo',  'feature'=>'logo'),
            array('weight'=>0, 'view'=>'custom/xf1996/menu', 'private_key'=>'activities', 'title'=>'频道', 'feature'=>'menu'),
        ),        
        'main' => array(
            //array('weight'=>0, 'view'=>'custom/node/salelist', 'private_key'=>'promotebook-channel', 'feature'=>'icons', 'rows'=>'12'),
            array('weight'=>0, 'view'=>'custom/node/photowall', 'private_key'=>'xf1996', 'category'=>'先锋简介', 'title'=>'先锋简介', 'feature'=>'iconmap', 'class'=>'xfjj'),
            array('view' => 'custom/node/news', 'private_key'=>'xf1996', 'category'=>'关于先锋/书店', 'title'=>'关于先锋', 'feature'=>'whitewall', 'class'=>'gyxf'),
            array('weight'=>0, 'view'=>'custom/node/photowall', 'private_key'=>'xf1996', 'title'=>'门店简介','category'=>'门店简介', 'feature'=>'icons', 'class'=>'mdjj'),
            array('view' => 'custom/node/news', 'private_key'=>'xf1996', 'category'=>'关于先锋/钱总', 'title'=>'老钱简介', 'feature'=>'singleArticle_A', 'class'=>'lqjj'),
            array('view' => 'custom/node/news', 'private_key'=>'xf1996', 'category'=>'老钱文章', 'title'=>'关于先锋', 'feature'=>'whitewall_logo', 'class'=>'lqwz'),
            array('weight'=>0, 'view'=>'custom/node/photowall', 'private_key'=>'xf1996', 'category'=>'老钱爱拍照', 'feature'=>'icons', 'class'=>'laoqianaipaizhao'),
            array('weight'=>0, 'view'=>'custom/node/photowall', 'private_key'=>'xf1996', 'category'=>'先锋人', 'feature'=>'icons', 'class'=>'xianfengren'),
            array('weight'=>0, 'view'=>'custom/node/photowall', 'private_key'=>'xf1996', 'category'=>'读者眼中的先锋', 'feature'=>'icons', 'class'=>'duzhedexianfeng'),
            array('view' => 'custom/node/news', 'private_key'=>'xf1996', 'category'=>'先锋印象', 'title'=>'关于先锋', 'feature'=>'whitewall_logo', 'class'=>'gyxf'),
            array('view' => 'custom/node/news', 'private_key'=>'xf1996', 'category'=>'先锋公告', 'title'=>'先锋公告', 'feature'=>'whitewall', 'class'=>'gonggao'),
        )
    ),
    'books'=>array(
        'sidebar_first' => array(
            array('weight'=>0, 'view'=>'custom/xf1996/logo', 'private_key'=>'logo',  'feature'=>'logo'),
            array('weight'=>0, 'view'=>'custom/xf1996/menu', 'private_key'=>'activities', 'title'=>'频道', 'feature'=>'menu'),
        ),        
        'main' => array(
            //array('weight'=>0, 'view'=>'custom/node/salelist', 'private_key'=>'promotebook-channel', 'feature'=>'icons', 'rows'=>'12'),
            array('weight'=>0, 'view'=>'custom/node/promotebooks', 'private_key'=>'books', 'title'=>'新书上架', 'searchMode'=>'latest', 'feature'=>'icons', 'rows'=>'5', 'class'=>'latestBooks'),
            array('weight'=>0, 'view'=>'custom/node/promotebooks', 'private_key'=>'books', 'title'=>'好书推荐', 'searchMode'=>'promoted', 'feature'=>'icons', 'rows'=>'6', 'class'=>'promotedBooks'),
            array('weight'=>0, 'view' =>'custom/node/news', 'private_key'=>'books', 'category'=>'读书笔记', 'title'=>'读书笔记', 'feature'=>'whitewall_logo', 'class'=>'dushubiji', 'rows'=>'3'),
            array('weight'=>0, 'view'=>'custom/node/bookstore',    'private_key'=>'books', 'title'=>'世界独立书店风景', 'feature'=>'icons', 'rows'=>'18')
            //array('view' => 'custom/node/news', 'private_key'=>'promotedbooks', 'category'=>'先锋书讯', 'title'=>'先锋书讯', 'rows'=>'10'),
            //array('weight'=>0, 'view'=>'custom/node/readlist', 'private_key'=>'promotebook-channel'),
            
        )
    ),
    'design'=>array(
        'sidebar_first' => array(
            array('weight'=>0, 'view'=>'custom/xf1996/logo', 'private_key'=>'logo',  'feature'=>'logo'),
            array('weight'=>0, 'view'=>'custom/xf1996/menu', 'private_key'=>'activities', 'title'=>'频道', 'feature'=>'menu'),
        ),        
        'main' => array(
            array('weight'=>0, 'view'=>'custom/node/products', 'private_key'=>'design', 'searchMode'=>'latest', 'feature'=>'teaser', 'title'=>'先锋创意产品', 'class'=>'cycptop'),
            array('weight'=>0, 'view'=>'custom/node/news', 'private_key'=>'design', 'category'=>'创意馆活动', 'title'=>'创意馆活动', 'feature'=>'whitewall_logo', 'rows'=>'8', 'class'=>'cyhd'),
            array('weight'=>0, 'view' => 'custom/node/photowall', 'private_key'=>'design', 'category'=>'创意馆', 'title'=>'独立先锋创意馆', 'feature'=>'icons', 'class'=>'xfcy'),
            array('weight'=>0, 'view'=>'custom/node/products', 'private_key'=>'design', 'searchMode'=>'latest', 'feature'=>'teaser', 'title'=>'先锋创意产品', 'class'=>'list'),
            
        )
    ),
    'coffee'=>array(
        'sidebar_first' => array(
            array('weight'=>0, 'view'=>'custom/xf1996/logo', 'private_key'=>'logo',  'feature'=>'logo'),
            array('weight'=>0, 'view'=>'custom/xf1996/menu', 'private_key'=>'activities', 'title'=>'频道', 'feature'=>'menu'),
        ),        
        'main' => array(
            array('weight'=>0, 'view'=>'custom/node/photowall', 'private_key'=>'coffee', 'category'=>'咖啡新品', 'feature'=>'icons', 'class'=>'kafeixinpin'),
            array('weight'=>0, 'view' => 'custom/node/news', 'private_key'=>'coffee', 'category'=>'咖啡文化', 'title'=>'咖啡文化', 'feature'=>'whitewall_logo'),
            array('weight'=>0, 'view'=>'custom/node/photowall', 'private_key'=>'coffee', 'category'=>'先锋艺术咖啡馆', 'feature'=>'icons', 'class'=>'xfyskf')
            
        )
    ),
    'member'=>array(
        'sidebar_first' => array(
            array('weight'=>0, 'view'=>'custom/xf1996/logo', 'private_key'=>'logo',  'feature'=>'logo'),
            array('weight'=>0, 'view'=>'custom/xf1996/menu', 'private_key'=>'activities', 'title'=>'频道', 'feature'=>'menu'),
        ),        
        'main' => array(
            //array('weight'=>0, 'view'=>'custom/node/salelist', 'private_key'=>'promotebook-channel', 'feature'=>'icons', 'rows'=>'12'),
            //array('weight'=>0, 'view'=>'custom/node/promotebooks', 'private_key'=>'promotebooks', 'title'=>'一周新书推荐', 'feature'=>'icons', 'rows'=>'18'),
            //array('view' => 'custom/node/news', 'private_key'=>'promotedbooks', 'category'=>'先锋书讯', 'title'=>'先锋书讯', 'rows'=>'10'),
            //array('weight'=>0, 'view'=>'custom/node/readlist', 'private_key'=>'promotebook-channel'),
            
        )
    ),
    'default'=>array(
        'sidebar_first' => array(
            array('weight'=>0, 'view'=>'custom/xf1996/logo', 'private_key'=>'logo',  'feature'=>'logo'),
            array('weight'=>0, 'view'=>'custom/xf1996/menu', 'private_key'=>'activities', 'title'=>'频道', 'feature'=>'menu'),
        )
    ),
);