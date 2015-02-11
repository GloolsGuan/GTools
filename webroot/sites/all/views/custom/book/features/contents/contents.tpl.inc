<div id='<?php print $this->baseStyleName;?>' class='block block-<?php print $this->baseStyleName;?> block-<?php print $this->baseStyleName;?>-<?php print $this->view['private_key'];?> feature-<?php print $this->feature;?>'>
    <div class='block-title'><h2><?php print t('Book Contents');?></h2></div>
    <div class='block-content'>
    <?php
        print drupal_render($this->data);
    ?>
    <div class='clearfix'></div>
    </div>
</div>