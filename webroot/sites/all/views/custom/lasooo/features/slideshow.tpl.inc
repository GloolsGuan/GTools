<div id='<?php print strtolower($this->viewName)?>' class='block block-<?php print strtolower($this->viewName);?> feature-<?php print $this->view['feature'];?>'>
    <div class='block-title'></div>
    <div class='block-content'>
    <?php print render($this->data);?>
    <div class='handlers-shade'></div>
    <div class='handlers' id='handlers'>
        <div id='bB' class='bB'>&gt;&gt;</div>
        <div class='tabsMap'></div>
        <div id='bA' class='bA'>&lt;&lt;</div>
    </div>
    <div class='clearfix'></div>
    </div>
</div>
<script type='text/javascript'>
jQuery(document).ready(function(){
    jQuery('.block-view_lasooo_slideshow').tabScroller({'autoScroll':'no'});
});

</script>