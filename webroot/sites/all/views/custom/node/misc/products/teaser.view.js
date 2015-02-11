(function(){
	var $=jQuery;
    function attachOrderClassToElements(selector, classPrefix){
		
		var elements = $(selector).children();
		if (1>elements.length) {
			return false;
		}
	
		var n=1;
		for(var i=0;i<elements.length; i++) {
			var c = classPrefix + '-'+(i+1);
			$(elements[i]).addClass(c);
			n++;
		}
	}
    jQuery(document).ready(function(){
		
		
		attachOrderClassToElements('.block-view_custom_node_products-design .block-content .slideContent', 'order');
		
		
	});	
})();
