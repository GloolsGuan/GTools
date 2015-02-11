<?php
/*
 * Created on 30 Nov, 2011
 *
 * To change the template for this generated file go to
 * Window - Preferences - PHPeclipse - PHP - Code Templates
 */
 //
 //;
?>
<div id='<?php print $this->baseStyleName;?>' class='block block-<?php print $this->baseStyleName;?> block-<?php print $this->baseStyleName;?>-<?php print $this->view['private_key'];?> feature-<?php print $this->feature;?>'>
    <div class='block-title'></div>
    <div class='block-content clearfix'>
        <div class='item guide'></div>
        <div class='item summary'><span class='photo'><?php print member_load_member_photo($this->user)?></span><span class='creator'><?php print $this->user->name;?></span><span class='level'></span></div>
        <div class='item photo'><?php print member_load_member_photo($this->user)?></div>
        <div class='item name'><?php print $this->user->name;?></div>
        <div class='item level'></div>
        <div class='item signature'><?php print strip_tags(truncate_utf8($this->user->signature, 180, true)); ?></div>
    </div>
</div>