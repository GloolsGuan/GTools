(function($){
	
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
	
    $(document).ready(function(){
		var selString = '.block-view_custom_node_photowall-coffee.kafeixinpin .node .field-name-field-photos .field-items';
	    attachOrderClassToElements(selString, 'order');
	    
	    
	    //TabScroller settings
		var options = {
			'autoScroll' : 'no'
		};
		if ($('.block-view_custom_node_photowall-activities.hdxc').length>0) {
			jQuery('.block-view_custom_node_photowall-activities.hdxc').tabScroller(options);
		}
		if ($('.block-view_custom_node_photowall-xf1996.xianfengren').length>0) {
		    jQuery('.block-view_custom_node_photowall-xf1996.xianfengren').tabScroller(options);
		}
		if ($('.block-view_custom_node_photowall-xf1996.duzhedexianfeng').length>0) {
		    jQuery('.block-view_custom_node_photowall-xf1996.duzhedexianfeng').tabScroller(options);
		}
		if ($('.block-view_custom_node_photowall-xf1996.mdjj').length>0) {
		    jQuery('.block-view_custom_node_photowall-xf1996.mdjj').tabScroller(options);
		}
		if ($('.block-view_custom_node_photowall-coffee.xfyskf').length>0) {
		    jQuery('.block-view_custom_node_photowall-coffee.xfyskf').tabScroller(options);
		}
                if ($('.block-view_custom_node_photowall-design.xfcy').length>0) {
		    jQuery('.block-view_custom_node_photowall-design.xfcy').tabScroller(options);
		}
		
	});
	
	
})(jQuery);
