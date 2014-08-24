<div id='<?php print $this->baseStyleName;?>' class='block block-<?php print $this->baseStyleName;?> block-<?php print $this->baseStyleName;?>-<?php print $this->view['private_key'];?> feature-<?php print $this->feature.' '; if(!empty($this->view['class'])): print $this->view['class']; endif;?>' >
    <div class='block-title'><a name='<?php if(!empty($this->view['class'])): print($this->view['class']); endif;?>'><?php print $this->blockTitle;?></a></div>
    <div class='block-content slideContainer clearfix'>
         <div class='slideContent'>
            <?php print render($this->buildNodes);?>
        </div>
        <div class='clearfix'></div>
    </div>
    <div class='handlers'>
        <span class='bA'><img src='/misc/xf1996/icon-corner-right.png' /></span>
        <span class='bB'><img src='/misc/xf1996/icon-corner-left.png' /></span>
        <span class='tabsMap'></span>
    </div>
</div>