<div id='<?php print $this->baseStyleName;?>' class='block block-<?php print $this->baseStyleName;?> block-<?php print $this->baseStyleName;?>-<?php print $this->view['private_key'];?> feature-<?php print $this->feature;?>'>
    <div class='block-title'><?php print t('Recommended activity');?></div>
    <div class='block-content'>
    <?php 
        if(is_string($this->data)) {
        	print t($this->data);
        }else{
        	print drupal_render($this->data);
        }
    ?>
    <div class='clearfix'></div>
    </div>
</div>