<div id='<?php print $this->baseStyleName;?>' class='block block-<?php print $this->baseStyleName;?> block-<?php print $this->baseStyleName;?>-<?php print $this->view['private_key'];?> feature-<?php print $this->feature;?>'>
    <div class='block-title'><?php print $this->view['title']; ?></div>
    <div class='block-content slideContainer'>
        <?php if (empty($this->data)):?>
        <div class='mes'><?php print t('There is no valid activity in current city.');?></div>
        <?php else:?>
        <div class='slideContent'>
       <?php print render($this->data);?>
        </div>
        <?php endif;?>
    <div class='clearfix'></div>
    </div>
    <div class='handlers'>
        <div class='bA'></div>
        <div class='bB'></div>
        <div class='tabsMap'></div>
    </div>
</div>