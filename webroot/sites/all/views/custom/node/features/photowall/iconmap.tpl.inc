<div id='<?php print $this->baseStyleName;?>' class='block block-<?php print $this->baseStyleName;?> block-<?php print $this->baseStyleName;?>-<?php print $this->view['private_key'];?> feature-<?php print $this->feature;?>'>
    <div class='block-title'><a name='<?php if(!empty($this->view['class'])): print($this->view['class']); endif;?>'><img src='/misc/xf1996/block-title-xianfengjieshao.jpg' height='35'/></a></div>
    <div class='block-content slideContainer clearfix'>
         <div class='slideContent'>
            <?php print render($this->buildNodes); ?>
            
        </div>
        <div class='clearfix'></div>
    </div>
    <div class='handlers'>
        <span class='bB'>&lt;&lt;</span>
        <span class='bA'>&gt;&gt;</span>
    </div>
</div>