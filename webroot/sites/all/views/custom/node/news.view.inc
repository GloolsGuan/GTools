<?php


Lib_Glools_Load::loadFile('glools/view/abstract', 'lib');

class View_Custom_Node_News extends Lib_Glools_View_Abstract{
    
    protected $user = null;
    
    protected $activity = null;
    
    protected $defaultFeature = 'list';
    
    protected $activities = array();
    
    protected $newsNode = array();
    
    protected $newsCategory = null;
    
    protected $termInfo = null;
    
    protected $titlePhotos = array();
    
    protected $blockTitle = '';
    
    /**
     * Checking presettings and set the parameters for the view
     * */
    public function init(){
        //debug_rdata(__METHOD__, array($this->options, $this->view));
        $this->view['rows'] = !isset($this->view['rows']) ? 20 : $this->view['rows'];
        
        if (!isset($this->view['feature'])) {
        	$this->view['feature'] = 'list';
        }
    }
    
    /**
     * Prepare data for the view
     * */
    public function beforeBuild(){
    
        $this->activity = $this->options['global']['node'];
        
        if (strpos($this->view['category'], '/')){
        	$this->newsCategory = explode('/', $this->view['category']);
        }else{
        	$this->newsCategory = $this->view['category'];
        }
        
        
        $this->getTermInfo($this->newsCategory);
        
        if ('xf1996'==$this->view['private_key'] && is_array($this->newsCategory) && in_array('关于先锋', $this->newsCategory)) {
        	$news = $this->loadXF1996NewsByCategory();
        }
        elseif('先锋公告'==$this->newsCategory) {
        	$news = $this->loadXF1996NewsByCategory();
        }
        elseif('读书笔记'==$this->newsCategory){
        	$this->newsNode = $this->loadNewsByCategoryWithPager($this->view['category'], $this->view['rows']);
        }
        elseif (!empty($this->view['category'])) {
            
        	$news = $this->loadNewsByCategory($this->view['category'], $this->view['rows']);
        }
        else{
        	$news = $this->loadNews(1, 10);
        }
        
        if (!empty($news) && empty($this->newsNode)) {
        	$this->newsNode = node_view_multiple($news, $this->view['feature']);
        }
        
        $this->setBlockTitle();
    }
    
    /**
     * Execute event (after render the view hook)
     * */
    public function afterBuild(){
        
    }
    
    protected function setBlockTitle(){
    	   switch($this->view['category']) {
            case '老钱文章':
                $this->blockTitle = theme_image(array(
                    'path'  => '/misc/xf1996/block-title-laoqianwenzhang.jpg',
                    'title' => '老钱文章',
                    'attributes' => array()
                ));
                break;
            case '先锋印象':
                $this->blockTitle = theme_image(array(
                    'path'  => '/misc/xf1996/block-title-xianfengyinxiang.jpg',
                    'title' => '先锋印象',
                    'attributes' => array()
                ));
                break;
            case '先锋公告':
                $this->blockTitle = theme_image(array(
                    'path'  => '/misc/xf1996/block-title-gonggao.jpg',
                    'title' => '先锋公告',
                    'attributes' => array()
                ));
                break;
            case '读书笔记':
                $this->blockTitle = theme_image(array(
                    'path'  => '/misc/xf1996/block-title-dushubiji.jpg',
                    'title' => '读书笔记',
                    'attributes' => array()
                ));
                break;
            case '咖啡文化':
                $this->blockTitle = theme_image(array(
                    'path'  => '/misc/xf1996/coffee-blocktitle-2.jpg',
                    'title' => '咖啡文化',
                    'attributes' => array()
                ));
                break;
            case '创意馆活动':
                /*
                $this->blockTitle = theme_image(array(
                    'path'  => '/misc/xf1996/block-title-hdtj.jpg',
                    'title' => '创意馆活动',
                    'attributes' => array()
                ));
                */
                break;
            default:
                $this->blockTitle='';
            
        }
    }
    
    
    protected function getTermInfo($category){
        
        if (is_string($category)) {
            $topCategory = $category;
        }else{
        	$topCategory = $category[0];
        }
    	$topTerms = taxonomy_get_term_by_name($topCategory, 'news_category');
        
        if (!empty($topTerms)) {
        	$topTerm = array_pop($topTerms);
        }
        
        if (is_string($category)) {
            
        	$this->termInfo = $topTerm;
            return;
        }
        
        $cTerms = taxonomy_get_children($topTerm->tid, $topTerm->vid);
        
        foreach($cTerms as $k=>$v) {
            $cTerms[$v->name] = $v;
        }
        
        $this->termInfo = $cTerms[$category[1]];
        return;
    }
    
    
    protected function loadNews($promoted=1, $rows){
    	$query = db_select('node', 'n');
        $nids  = $query->fields('n', array('nid'))
                       ->condition('n.type', 'article')
                       ->condition('n.promote', $promoted)
                       ->orderby('n.changed', 'DESC')
                       ->orderby('n.sticky', 'DESC')
                       ->range(0, $rows)
                       ->addTag('node_access')
                       ->execute()
                       ->fetchCol();
        
        debug_rdata(__FUNCTION__, $nids);
        
        return node_load_multiple($nids);
    }
    
    
    protected function loadXF1996NewsByCategory($rows=5){
        
        $query = db_query_range('select * from {field_data_field_article_category} where field_article_category_tid=:categoryId order by entity_id ASC',0, $rows, array(':categoryId'=>$this->termInfo->tid));
        $nids = $query->fetchAllAssoc('entity_id');
        $nids = array_keys($nids);
        return node_load_multiple($nids);
    }
    
    
    protected function loadNewsByCategory($category=null, $rows='10'){
    	
        $term = taxonomy_get_term_by_name($category, 'news_category');
        if (!empty($term)) {
        	$newsTerm = array_pop($term);
        }else{
        	return '';
        }
        $query = db_query_range('select * from {field_data_field_article_category} where field_article_category_tid=:categoryId order by entity_id DESC',0, $rows, array(':categoryId'=>$newsTerm->tid));
        $nids = $query->fetchAllAssoc('entity_id');
        $nids = array_keys($nids);
        return node_load_multiple($nids);
    }
    
    
    protected function loadNewsByCategoryWithPager($category=null, $rows='10'){
    	$build = array();
        $query = db_select('node', 'n')->extend('GloolsPagerDefault');
        $query->leftJoin('field_data_field_article_category', 'fc', 'fc.entity_id=n.nid');
        $query->fields('n', array('nid'));
        $query->condition('fc.field_article_category_tid', $this->termInfo->tid);
        $query->condition('n.status', 1);
        $query->orderBy('n.created', 'DESC');
        $query->limit($rows);
        $query->addMetaData('page-owner', 'news/'.$category);
        $nids = $query->execute()->fetchAllAssoc('nid');
        
        if (!empty($nids)) {
        	$nids = array_keys($nids);
        }
        
        $nodes = node_load_multiple($nids);
        $buildNodes = node_view_multiple($nodes, $this->view['feature']);
        $build['nodes'] = $buildNodes;
        $build['pager'] = array(
            '#theme' => 'glools_pager',
            '#weight' => 5,
            '#element' => 'news/'.$category
        );
        return $build;
    }
}