(function($){
	$(document).ready(function(){
	    var pItems = $('.block-view_custom_node_photowall-xf1996.feature-iconmap .node .field-name-field-photos .field-item');
		
		pItems.each(function(index){
			if (0==index) {
			    $(this).addClass('level-1');
			}
			
			switch(index) {
			    case 0:
			        $(this).addClass('level-1 order-'+index);
			        break;
			    case 1:
			        $(this).addClass('level-2 order-'+index);
			        break;
			    default:
			        $(this).addClass('level-3 order-'+index);
			}
		});
	});
})(jQuery);
