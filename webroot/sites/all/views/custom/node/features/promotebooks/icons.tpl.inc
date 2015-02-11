<div id='<?php print $this->baseStyleName;?>' class='block block-<?php print $this->baseStyleName;?> block-<?php print $this->baseStyleName;?>-<?php print $this->view['private_key'];?> feature-<?php print $this->feature.' '; if(!empty($this->view['class'])): print $this->view['class']; endif;?>'>
    <div class='block-title'><?php print $this->blockTitle;?></div>
    <div class='block-content clearfix'>
        <?php print render($this->buildNodes);?>
    </div>
</div>