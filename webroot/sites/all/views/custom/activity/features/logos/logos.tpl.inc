<div id='<?php print $this->baseStyleName;?>' class='block block-<?php print $this->baseStyleName;?> block-<?php print $this->baseStyleName;?>-<?php print $this->view['private_key'];?> feature-<?php print $this->feature;?>'>
    <div class='block-title'></div>
    <div class='block-content slideContainer'>
        <?php if (!empty($this->logosElement)):?>
        <div class='slideContent'>
            <?php foreach(element_children($this->logosElement) as $logoKey):?>
            <div class='item'>
                <?php print render($this->logosElement[$logoKey]);?>
            </div>
            <?php endforeach;?>
        </div>
        <?php endif;?>
    <div class='clearfix'></div>
    </div>
    <div class='handlers'>
        <div class='bB'>&gt;&gt;</div>
        <div class='bA'>&lt;&lt;</div>
        <div class='tabsMap'></div>
    </div>
</div>