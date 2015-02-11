<div id='<?php print $this->baseStyleName;?>' class='block block-<?php print $this->baseStyleName;?> block-<?php print $this->baseStyleName;?>-<?php print $this->view['private_key'];?> feature-<?php print $this->feature;?>'>
    <div class='block-title'><?php print $this->title;?></div>
    <div class='block-content'>
        <?php print render($this->data);?>
        <div class='clearfix'></div>
    </div>
</div>