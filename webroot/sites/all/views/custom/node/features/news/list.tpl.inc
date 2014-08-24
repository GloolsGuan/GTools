<div id='<?php print $this->baseStyleName;?>' class='block block-<?php print $this->baseStyleName;?> block-<?php print $this->baseStyleName;?>-<?php print $this->view['private_key'];?> feature-<?php print $this->feature;?>'>
    <div class='block-title'><?php print $this->view['title'];?></div>
    <div class='block-content clearfix'>
        <?php print render($this->newsNode);?>
    </div>
</div>