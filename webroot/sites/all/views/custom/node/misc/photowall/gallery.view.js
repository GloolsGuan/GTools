(function($){
	//var $ = jQuery;
	$(document).ready(function(){
		var photoNodeSelector = $('#view_custom_node_photowall .node');
		var itemClass='';
		photoNodeSelector.each(function(){
			var pItems = $(this).find('.field-name-field-photos .field-items');
			
			for(i=0; i<pItems.children().length; i++) {
			    itemClass = 'item-index-'+i;
			    if (i==0) {
				    itemClass += ' item-level-1';
				}
				
				if (i<5 && i>0) {
				    itemClass += ' item-level-2';
				}
				
				if (i>4){
				    itemClass += ' item-level-3';
				}
				
				$(pItems).find('.field-item:eq('+ i +')').addClass(itemClass);
		    }
		    
		});
		
		//TabScroller settings
		var options = {
			'autoScroll' : 'no'
		};
		jQuery('#view_custom_node_photowall').tabScroller(options);
		
	});
})(jQuery);
