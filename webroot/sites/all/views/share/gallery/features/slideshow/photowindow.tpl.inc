<div id='<?php print $this->baseStyleName;?>' class='block block-<?php print $this->baseStyleName;?> block-<?php print $this->baseStyleName;?>-<?php print $this->view['private_key'];?> feature-<?php print $this->feature;?>'>
    <div class='block-title'></div>
    <div class='block-content slideContainer clearfix'>
    <div class='slideContent'>
        <?php print render($this->buildPhotos);?>
    </div>
    <div class='clearfix'></div>
    </div>
    <div class='handlers'>
        <div class='bA'>&gt;&gt;</div>
        <div class='bB'>&lt;&lt;</div>
    </div>
</div>