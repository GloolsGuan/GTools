<?php


Lib_Glools_Load::loadFile('glools/view/abstract', 'lib');

class View_Custom_Node_Drawingboard extends Lib_Glools_View_Abstract{
    
    protected $user = null;
    
    protected $activity = null;
    
    protected $defaultFeature = 'board';
    
    protected $tabMapPhotos = array();
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
            $this->view['title'] = '先锋板报';
        }
        drupal_add_js(path_to_theme() . '/js/tabScroller.js');
    }
    
    /**
     * Prepare data for the view
     * */
    public function beforeBuild(){
    
        $nodes = $this->loadNodes(1, $this->view['rows']);
        $this->tabMapPhotos = $this->buildTabMapPhotos($nodes);
        
        if (!empty($nodes)) {
            $this->buildNodes = node_view_multiple($nodes, 'slideshow');
        }
        
    }
    
    /**
     * Execute event (after render the view hook)
     * */
    public function afterBuild(){
        
    }
    
    protected function buildTabMapPhotos($nodes){
    	
        $photos = array();
        foreach($nodes as $node) {
        	$photos[] = theme_image(array(
                'attributes' => array(),
                'path'       => $node->field_image['und'][0]['uri'],
                'title'      => $node->title
            ));
        }
        
        return $photos;
    }
    
    protected function loadNodes($promoted=1, $rows=6){
        
        $query = db_select('node', 'n');
        $nids  = $query->fields('n', array('nid'))
                       ->condition('n.type', 'drawingboard')
                       //->condition('n.promote', $promoted)
                       ->orderby('n.created', 'DESC')
                       ->orderby('n.sticky', 'DESC')
                       ->range(0, $rows)
                       ->addTag('node_access')
                       ->execute()
                       ->fetchCol();
        //debug_rdata(__FUNCTION__, $nids);
        
        return node_load_multiple($nids);
    }
}