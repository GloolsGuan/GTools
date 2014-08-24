<?php


Lib_Glools_Load::loadFile('glools/view/abstract', 'lib');

class View_Custom_Node_Photowall extends Lib_Glools_View_Abstract{
    
    protected $user = null;
    
    protected $activity = null;
    
    protected $defaultFeature = 'gallery';
    
    protected $blockTitle = '';
    
    protected $buildNodes = array();
    
    /**
     * Checking presettings and set the parameters for the view
     * */
    public function init(){
        //debug_rdata(__METHOD__, array($this->options, $this->view));
        if (empty($this->view['rows']) || !is_numeric($this->view['rows'])) {
            $this->view['rows'] = 12;
        }
        
        if (empty($this->view['title'])) {
            $this->view['title'] = '独立先锋书店摄影展';
        }
        drupal_add_js(path_to_theme() . '/js/tabScroller.js');
    }
    
    /**
     * Prepare data for the view
     * */
    public function beforeBuild(){
    
        $nodes = $this->loadGallery(1, $this->view['rows']);
        
        if (!empty($nodes)) {
            $this->buildNodes = node_view_multiple($nodes, 'photo');
        }
        
        switch($this->view['category']) {
        	case '老钱爱拍照':
                $this->blockTitle = theme_image(array(
                    'path'  => '/misc/xf1996/block-title-laoqianaipaizhao.jpg',
                    'title' => '老钱爱拍照',
                    'attributes' => array()
                ));
                break;
            case '先锋人':
                $this->blockTitle = theme_image(array(
                    'path'  => '/misc/xf1996/block-title-xianfengren.jpg',
                    'title' => '先锋人',
                    'attributes' => array()
                ));
                break;
            case '读者眼中的先锋':
                $this->blockTitle = theme_image(array(
                    'path'  => '/misc/xf1996/block-title-duzhedexianfeng.jpg',
                    'title' => '读者眼中的先锋',
                    'attributes' => array()
                ));
                break;
            case '门店简介':
                $this->blockTitle = theme_image(array(
                    'path'  => '/misc/xf1996/block-title-mendianjianjie.jpg',
                    'title' => '门店简介',
                    'attributes' => array()
                ));
                break;
             case '先锋艺术咖啡馆':
                $this->blockTitle = theme_image(array(
                    'path'  => '/misc/xf1996/coffee-blocktitle-3.jpg',
                    'title' => '先锋艺术咖啡馆',
                    'attributes' => array()
                ));
                break;
            case '咖啡新品':
                $this->blockTitle = theme_image(array(
                    'path'  => '/misc/xf1996/coffee-blocktitle-1.jpg',
                    'title' => '咖啡新品',
                    'attributes' => array()
                ));
                break;
            case '先锋活动':
                 $this->blockTitle = theme_image(array(
                    'path'  => '/misc/xf1996/block-title-hdxc.jpg',
                    'title' => '活动相册',
                    'attributes' => array()
                ));
                break;
            case '创意馆':
                 $this->blockTitle = theme_image(array(
                    'path'  => '/misc/xf1996/block-title-cyg.jpg',
                    'title' => '独立先锋创意馆',
                    'attributes' => array()
                ));
        }
    }
    
    /**
     * Execute event (after render the view hook)
     * */
    public function afterBuild(){
        
    }
    
    protected function loadGallery($promoted=1, $rows=12){
        
        if (!empty($this->view['category'])) {
        	$category = $this->view['category'];
        }else{
        	$category = '先锋影廊';
        }
        
        return $this->loadGalleryBYCategory($category);
    }
    
    protected function loadGalleryByCategory($category=null, $rows='10'){
        
        $term = taxonomy_get_term_by_name($category);
        
        if (!empty($term)) {
            $galleryTerm = array_pop($term);
        }else{
            return '';
        }
        $query = db_query_range('select * from {field_data_field_gallery_class} where field_gallery_class_tid=:categoryId order by entity_id DESC',0, $rows, array(':categoryId'=>$galleryTerm->tid));
        $nids = $query->fetchAllAssoc('entity_id');
        
        //debug_rdata(__FUNCTION__, $nids);
        $nids = array_keys($nids);
        
        return node_load_multiple($nids);
    }
}