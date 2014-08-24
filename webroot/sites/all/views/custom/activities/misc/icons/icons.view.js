(function(){
    
    //var frontApp = LF.appNameSpace('front.frontApp','app');
    
    var nodeInfo = function(){
        
        var nodeSelector = jQuery('#view_custom_activities_icons .node');
        
        jQuery(nodeSelector).each(function(){
            jQuery(this).bind('mouseover', function(e){
                var infoSelector = jQuery(this).find('.info');
                /*
                if ('-214px'==jQuery(infoSelector).css('margin-top') && 'block'==jQuery(infoSelector).css('display')){
                    return;
                }
                */
                jQuery(this).find('.info-background').show();
                jQuery(this).find('.info').show();
            }).bind('mouseout', function(e){
                jQuery(this).find('.info-background').hide();
                jQuery(this).find('.info').hide();
            });
        });
        
        /*
        jQuery(nodeSelector).bind('mouseover', function(e){
            jQuery(nodeSelector).find('.info-background').slideUp();
            jQuery(nodeSelector).find('.info').slideUp();
        });
        
        jQuery(nodeSelector).bind('mouseout', function(e){
            jQuery(this).find('.info-background').slideDown();
            jQuery(this).find('.info').slideDown();
        });
        */
        
    }

    
    LF.pluginNameSpace('front.nodeInfo', nodeInfo);
    
})();
