<div id='<?php print $this->baseStyleName;?>' class='block block-<?php print $this->baseStyleName;?> block-<?php print $this->baseStyleName;?>-<?php print $this->view['private_key'];?> feature-<?php print $this->feature.' '; if(!empty($this->view['class'])): print $this->view['class']; endif;?>'>
    <div class='block-title'></div>
    <div class='block-content clearfix'>
        <div class='node-title'>
        <?php print $this->blockTitle;?>
        </div>
        <?php print render($this->newsNode);?>
    </div>
</div>