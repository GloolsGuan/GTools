<div id='<?php print $this->baseStyleName;?>' class='block block-<?php print $this->baseStyleName;?> block-<?php print $this->baseStyleName;?>-<?php print $this->view['private_key'];?> feature-<?php print $this->feature;?>'>
    <div class='block-title'><a name='<?php if(!empty($this->view['class'])): print($this->view['class']); endif;?>'><img src='/misc/xf1996/block-title-laoqian.jpg' /></a></div>
    <div class='block-content clearfix'>
        <div class='node-title'>
            <img src='/misc/xf1996/block-title-laoqianjianjie.jpg' />
        </div>
        <?php print render($this->newsNode);?>
    </div>
</div>