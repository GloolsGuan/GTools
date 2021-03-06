<?php
/*
 * Created on 25 Nov, 2011
 *
 * To change the template for this generated file go to
 * Window - Preferences - PHPeclipse - PHP - Code Templates
 */

Lib_Glools_Load::loadFile('glools/base', 'lib');
Lib_Glools_Load::loadFile('glools/misc', 'lib');

abstract class Lib_Glools_View_Abstract extends Lib_Glools_Base{
	
    protected $data = null;
    
    protected $defaultFeature = '';
    
    protected $output = '';
    
    protected $baseDir = '';
    
    protected $nameSpace = '';
    
    protected $options = array();
    
    protected $view = array();
    
    protected $featureSuffix = '';
    
    protected $viewPath = '';
    
    protected $baseViewPath = '';
    
    protected $category = '';
    
    protected $package = '';
    
    protected $viewName = '';
    
    protected $miscPath = '';
    
    private $feature = '';
    
    /**
     baseStyleName used for the ID and CLASS name in style sheet.
     The full name in html element should be block-[BASE STYLE NAME]
     */
    protected $baseStyleName = '';
    
    public function __construct($options=array()){
        
        if (!empty($options['view'])) {
        	$this->setNameSpace($options['view']);
            $this->view = $options['view'];
            unset($options['view']);
        }
        
        $this->setOptions($options);
        
        $this->baseViewPath = 'sites/all/views';
        
        $this->viewPath = $this->getViewPath();
        
        
        
        $names = explode('/', $this->nameSpace);
        
        list($this->category, $this->package, $this->viewName) = $names;
        
        if (empty($this->defaultFeature)) {
        	$this->defaultFeature = $this->viewName;
        }
        
        $this->baseStyleName = strtolower(get_class($this));
        
        $this->setBaseDir();
        
        if (!empty($this->view['feature']) && is_string($this->view['feature'])) {
            $this->feature = $this->view['feature'];
            //$this->feature .= '-' . $this->view['featureSuffix'];
        }else{
            $this->feature = empty($this->defaultFeature) ? $this->viewName : $this->defaultFeature;
        }
        
        $this->miscPath = $this->baseViewPath . '/' . $this->category .'/'. $this->package . '/misc/' . $this->viewName;
        
        $this->init();
    }
    
    /**
     * event methods basic settings
     * */
    protected function setBaseDir(){
    	$this->baseDir = GLOOLS_DIR_VIEWS . '/' . $this->category . '/' . $this->package;
    }
    
    protected function init(){}
    
    public function beforeBuild(){}
    
    public function afterBuild(){}
    
    protected function buildView(){
        //echo $this->getFeatureDir() .'<br />';
        ob_start();
        
        include($this->getFeatureDir());
        $output = ob_get_contents();
        ob_end_clean();
        $this->output = $output;
    }
    
    protected function setFeatureSuffix($suffix){
    	if(!is_string($suffix)) {
    		$this->exception("Provided invalid parameter for ".__METHOD__.', The parameter must be string.');
            return false;
    	}
        $this->featureSuffix = $suffix;
        
    }
    
    public function setNameSpace($view){
    	
        if (is_array($view) && !empty($view) && isset($view['view'])) {
    		$this->nameSpace = strtolower($view['view']);
            return $this;
    	}
        
        $this->exception('Error, Provided view settings is invalid in '.__METHOD__.'.');
    }
    
    public function setOptions($options){
        $this->options = $options;
    }
    
    public function fetchView(){
        
        $this->beforeBuild();
        $this->buildView();
        $this->afterBuild();
        
        $this->addStyle();
        $this->addScript();
        
        return array('#children'=>$this->output);
    }
    
    public function getFeatureDir(){
        
        $files = array();
        
        $feature = empty($this->view['feature']) ? $this->defaultFeature : $this->view['feature'];
        
        $files[] = $this->baseDir . '/features/'.$this->viewName .'/'.$feature . '.tpl.inc';
        
        $files[] = $this->baseDir . '/features/' . $this->viewName . '/' . $this->defaultFeature . '.tpl.inc'; 
        
        $featureFile = false;
        
        foreach($files as $file) {
        	//debug_rdata(__FUNCTION__, $file);
            if (file_exists($file)) {
            	$featureFile = $file;
                break;
            }
        }
        if (!empty($featureFile)) {
            $this->exception('Error, View feature does not exists, ('.$featureFile.').');
        }
        
        return $featureFile;
    }
    
    public function getBaseViewPath(){
    	return $this->baseViewPath;
    }
    
    public function getViewPath(){
    	$viewClassName = get_class($this);
        return '/'.$this->nameSpace;
    }
    
    public function addStyle(){
        $paths = array();        
        $viewPath = $this->category.'/'.$this->package;
        
        
        $paths[] = $this->baseViewPath . '/' . $viewPath . '/misc/' . $this->viewName.'/'.$this->feature.'.view.css';
        $paths[] = path_to_theme() . '/css/views/' . $viewPath . '/' . $this->feature.'.view.css';
        $paths[] =  path_to_theme() . '/css/views/' . $viewPath . '/' . $this->viewName.'.view.css';
        $paths[] = $this->baseViewPath . '/' . $viewPath . '/misc/' . $this->viewName.'/'.$this->viewName.'.view.css';
        //echo '<pre>';
        //var_dump($paths);
        //echo '</pre>';
        foreach($paths as $path) {
            
        	if (file_exists($path)) {
                //echo $path;
                drupal_add_css(theme_lasooo_importCSS('/'.$path), 'inline');
                
                break;
        	}else{
                //debug_record_data(__METHOD__, $path);
            }
        }
    }
    
    public function addScript(){
        $paths = array();
        $viewPath = $this->category.'/'.$this->package;
        
        if(!empty($this->featureSuffix)) {
            
        }
        $paths[] = path_to_theme() . '/js/views/' . $viewPath . '/' . $this->feature.'.view.js';
        $paths[] = path_to_theme() . '/js/views/' . $viewPath . '/' . $this->viewName.'.view.js';
        $paths[] = $this->baseViewPath.'/'.$viewPath.'/misc/'.$this->viewName.'/'.$this->feature.'.view.js';
        $paths[] = $this->baseViewPath.'/'.$viewPath.'/misc/'.$this->viewName.'/'.$this->viewName.'.view.js';
        //echo '<pre>';
        //var_dump($paths);
        //echo '</pre>';
        foreach($paths as $path) {
            if (file_exists($path)) {
                //debug_record_data(__METHOD__, 'Script file exist: ' . $path);
                drupal_add_js($path);
                break;
            }else{
            	//debug_record_data(__METHOD__, $path);
            }
        }
    }
}