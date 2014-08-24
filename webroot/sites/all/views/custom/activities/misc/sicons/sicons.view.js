(function(){
    
    //var frontApp = LF.appNameSpace('front.frontApp','app');
    
    var nodeInfo = function(){
        
        var nodeSelector = jQuery('#view_custom_activities_sicons .node');
        
        jQuery(nodeSelector).each(function(){
            jQuery(this).bind('mouseover', function(e){
                var infoSelector = jQuery(this).find('.info');
                jQuery(this).find('.info-background').show();
                jQuery(this).find('.info').show();
            }).bind('mouseout', function(e){
                jQuery(this).find('.info-background').hide();
                jQuery(this).find('.info').hide();
            });
        });
    }
    
    var siconsSlideShow = function(){
        var options = {
            'autoScroll' : 'no'
        };
        
        jQuery('#view_custom_activities_sicons').tabScroller(options);
    }

    LF.pluginNameSpace('front.sicons.nodeInfo', nodeInfo);
    LF.pluginNameSpace('front.sicons.slideshow', siconsSlideShow);
})();
