<?php


Lib_Glools_Load::loadFile('glools/view/abstract', 'lib');

class View_Custom_Node_Products extends Lib_Glools_View_Abstract{
    
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
        
        if ('cycptop'==$this->view['class']) {
        	$this->blockTitle = 'block-title-hdtj.jpg';
        }else{
        	$this->blockTitle = 'block-title-cpfl.jpg';
        }
        
        if (empty($this->view['title'])) {
            $this->view['title'] = '独立先锋创意产品馆';
        }
        drupal_add_js(path_to_theme() . '/js/tabScroller.js');
    }
    
    /**
     * Prepare data for the view
     * */
    public function beforeBuild(){
    
        $nodes = $this->loadActivities(1, $this->view['rows']);
        
        if (!empty($nodes)) {
            $viewMode = empty($this->view['feature'])? 'iconwithteaser' : $this->view['feature'];
            $this->buildNodes = node_view_multiple($nodes, $viewMode);
        }
    }
    
    /**
     * Execute event (after render the view hook)
     * */
    public function afterBuild(){
        
    }
    
    protected function loadActivities($promoted=1, $rows=12){
        
        $query = db_select('node', 'n');
        $nids  = $query->fields('n', array('nid'))
                       ->condition('n.type', 'products')
                       //->condition('n.promote', $promoted)
                       ->orderby('n.changed', 'DESC')
                       ->orderby('n.sticky', 'DESC')
                       ->range(0, $rows)
                       ->addTag('node_access')
                       ->execute()
                       ->fetchCol();
        //debug_rdata(__FUNCTION__, $nids);
        
        return node_load_multiple($nids);
    }
}