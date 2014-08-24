<div id='<?php print $this->baseStyleName;?>' class='block block-<?php print $this->baseStyleName;?> block-<?php print $this->baseStyleName;?>-<?php print $this->view['private_key'];?> feature-<?php print $this->feature.' '; if(!empty($this->view['class'])): print $this->view['class']; endif;?>'>
    <div class='block-title'><a name='<?php if(!empty($this->view['class'])): print($this->view['class']); endif;?>'><?php print $this->blockTitle?></a></div>
    <div class='block-content clearfix'>
        <?php print render($this->newsNode);?>
    </div>
</div>