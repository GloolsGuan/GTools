<?php


Lib_Glools_Load::loadFile('glools/view/abstract', 'lib');

class View_Custom_Node_Readpromote extends Lib_Glools_View_Abstract{
    
    protected $user = null;
    
    protected $activity = null;
    
    protected $defaultFeature = 'icons';
    
    
    protected $buildNodes = array();
    
    protected $books = array();
    
    /**
     * Checking presettings and set the parameters for the view
     * */
    public function init(){
        
        
        if (empty($this->view['rows']) || !is_numeric($this->view['rows'])) {
            $this->view['rows'] = 12;
        }
        
        if (empty($this->view['title'])) {
            $this->view['title'] = '读书推荐';
        }
    }
    
    /**
     * Prepare data for the view
     * */
    public function beforeBuild(){
    
        $node = $this->loadActivities(1, $this->view['rows']);
        
        if (!empty($node)) {
            $this->buildNodes = node_view_multiple($node, 'detail');
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
                       ->condition('n.type', 'promoted_reading')
                       ->condition('n.promote', $promoted)
                       ->orderby('n.changed', 'DESC')
                       ->orderby('n.sticky', 'DESC')
                       ->range(0, $rows)
                       ->addTag('node_access')
                       ->execute()
                       ->fetchCol();
        
        return node_load_multiple($nids);
    }
}