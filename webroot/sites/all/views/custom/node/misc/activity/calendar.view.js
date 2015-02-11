(function(jQuery){
    var $ = jQuery;
    
    $(document).ready(function(){
	    var sel = '.block-view_custom_node_activity-activities.feature-calendar';
	    
	    var nodeBoxes = $(sel).find('.node');
	    nodeBoxes.each(function(e){
	        var pa = $(this).parent();
	        pa.find('.day-img').addClass('withNode');	
		});
    });
})(jQuery);
