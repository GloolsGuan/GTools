<?php
/*
 * Created on Nov 16, 2012
 *
 * To change the template for this generated file go to
 * Window - Preferences - PHPeclipse - PHP - Code Templates
 */

Lib_Glools_Load::loadFile('glools/view/abstract', 'lib');

class View_Share_Books_Book extends Lib_Glools_View_Abstract{
	
    protected $bookName = '';
    
    protected $books = null;
    
    protected $viewTitle = '';
    
    protected $bookInfo = null;
    
    protected $bookTitle = '';
    
    public function init(){
    	
        if (!isset($this->options['private']['bookName']) || empty($this->options['private']['bookName'])) {
        	$this->data = t('There is no contents of some book.');
        } else {
        	$this->bookName = $this->options['private']['bookName'];
            $this->bookInfo = $this->getBookInfoByName($this->bookName);
        }
        
        $this->books = book_get_books();
        
        if (empty($this->bookInfo)) {
        	$this->data = t('There is no contents of some book.');
        }
    }
    
    public function beforeBuild(){
        
        $bookNode = node_load($this->bookInfo->nid);
        $bookMenus = menu_tree_all_data($bookNode->book['menu_name'], $bookNode->book);
        
        foreach($bookMenus as $k=>$book) {
        	if (!empty($bookMenus[$k]['below'])) {
        		$subjects = $bookMenus[$k]['below'];
                unset($bookMenus[$k]['below']);
        	}
            
            $bookTitle = $bookMenus[$k];
            //debug_record_data(__FUNCTION__, $bookTitle);
            break;
        }
        /*
        $contents = menu_tree_output($bookMenus);
        $bookMenu[$this->bookInfo->nid] = $contents;
        $this->data = $this->bookName;
        $bookMenu['#theme'] = 'book_all_books_block';
        */
        
        $builtContents = array();
        
        $builtContents[$this->bookInfo->nid] = menu_tree_output($subjects);
        $builtContents['#theme'] = 'book_all_books_block';
        
        $this->bookTitle = !empty($bookTitle) ? l(t($bookTitle['link']['link_title']), $bookTitle['link']['link_path']) : '...';
        $this->data = $builtContents;
    }
    
    public function afterBuild(){
    	
    }
    
    protected function getContentsByBookId($bookId){
    	
    }
    
    protected function getBookInfoByName($bookName){
    	$nodes = node_load_multiple(array(), array('title'=>$bookName), FALSE);
        
        if (!empty($nodes)) {
        	return array_pop($nodes);
        }
        return null;
    }
}
