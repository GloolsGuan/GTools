<?php


Lib_Glools_Load::loadFile('glools/view/abstract', 'lib');

class View_Custom_Node_Promotebooks extends Lib_Glools_View_Abstract{
    
    protected $user = null;
    
    protected $activity = null;
    
    protected $defaultFeature = 'icons';
    
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
        	$this->view['title'] = '新书推荐';
        }
        
        if (!isset($this->view['searchMode']) || empty($this->view['searchMode'])) {
        	$this->view['searchMode'] = 'latest';
        }
    }
    
    /**
     * Prepare data for the view
     * */
    public function beforeBuild(){
    
        if ('latest'==$this->view['searchMode']) {
        	$bookIds = $this->loadLatestBooks($this->view['rows']);
            $this->blockTitle = theme_image(array(
                    'path'  => '/misc/xf1996/block-title-xinshusangjia.jpg',
                    'title' => '新书上架',
                    'attributes' => array()
                ));
        }
        
        if ('promoted'==$this->view['searchMode']) {
        	$bookIds = $this->loadPromotedBooks($this->view['rows']);
            $this->blockTitle = theme_image(array(
                    'path'  => '/misc/xf1996/block-title-haoshutuijian.jpg',
                    'title' => '好书推荐',
                    'attributes' => array()
                ));
        }
        
        
        if (!empty($bookIds)) {
            $this->buildNodes = node_view_multiple($bookIds, 'icons');
        }
        
        
    }
    
    /**
     * Execute event (after render the view hook)
     * */
    public function afterBuild(){
        
    }
    
    
    protected function loadPromotedBooks($rows){
    	return $this->loadBooks(1, 1, $rows);
    }
    
    protected function loadLatestBooks($rows){
    	return $this->loadBooks(0, 1, $rows);
    }
    
    protected function loadBooks($promoted, $sticky, $rows){
    	static $nids = array();
        $conditions = array();
        
        if (true == $promoted) {
        	$conditions['n.promote'] = 1;
        }
        
        
        $query = db_select('node', 'n');
        $query->fields('n', array('nid'));
        $query->condition('n.type', 'promotedbooks');
        
        foreach($conditions as $k=>$v) {
        	$query->condition($k, $v);
        }
        
        if (!empty($nids)) {
        	$query->condition('n.nid', $nids, 'not in');
        }
        
        $query->orderby('n.created', 'DESC');
        $query->orderby('n.sticky', 'DESC');
        $query->range(0, $rows);
        $query->addTag('node_access');
        $nids = $query->execute()->fetchCol();
        
        
        
        return node_load_multiple($nids);
    }
}