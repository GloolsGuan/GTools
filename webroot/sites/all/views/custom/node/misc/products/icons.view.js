jQuery(document).ready(function(){
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
    
    attachOrderClassToElements('.block-view_custom_node_products-design .block-content .slideContent', 'order');
    var options = {
        'autoScroll' : 'no'
    };
    jQuery('.block-view_custom_node_products-frontpage').tabScroller(options);
});
