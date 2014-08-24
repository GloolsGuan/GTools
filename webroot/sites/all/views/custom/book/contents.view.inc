<?php
/*
 * Created on 7 Dec, 2011
 *
 * To change the template for this generated file go to
 * Window - Preferences - PHPeclipse - PHP - Code Templates
 */
Lib_Glools_Load::loadFile('glools/view/abstract', 'lib');

class View_Custom_Book_Contents extends Lib_Glools_View_Abstract{
    
    public function init(){
        
    }
    
    protected function setBasePath(){
        $this->basePath = dirname(__FILE__);
    }
    
    public function beforeBuild(){
        if (!empty($this->options['global']['bookId'])) {
        	$bookId = $bookId = $this->options['global']['bookId'];
        }
        $this->data = $this->loadContents($bookId);
    }
    
    public function afterBuild(){
        //drupal_add_css(path_to_theme() . '/css/views/View_Book_Contents.view.css');
    }
    
    protected function loadContents($bookId){
        $contents = NULL;
        $book_list = array();
        foreach (book_get_books() as $book) {
            $book_list[] = l($book['title'], $book['href'], $book['options']);
        }
        return book_block_view();
        //return theme('item_list', array('items' => $book_list));
    }
}