<?php
/*
 * Created on 30 Nov, 2011
 *
 * To change the template for this generated file go to
 * Window - Preferences - PHPeclipse - PHP - Code Templates
 */
 if (0===$this->user->uid) {
 	//return;
 }
?>
<div id='<?php print $this->baseStyleName;?>' class='block block-<?php print $this->baseStyleName;?> block-<?php print $this->baseStyleName;?>-<?php print $this->view['private_key'];?> feature-<?php print $this->feature;?>'>
    <div class='block-title'></div>
    <div class='block-content clearfix'>
        <div class='profile-info'>
            <div class='field user-pic'><?php print member_load_member_photo($this->user);?></div>
            <div class='field user-name'><?php print $this->user->name;?></div>
            <div class='field user-created'><?php print 'Joined on ' . date("m/d Y", $this->user->created);?></div>
            <div class='field user-signature'><?php print truncate_utf8($this->user->signature, 100, true);?></div>
        </div>
        <div class='profile-link'>
            <div class='link-item item-profile'><a title='账户设置' href='<?php print url('member/' . urlencode($this->user->name));?>'>简介</a></div>
            <?php if($this->gUser->uid==$this->user->uid):?><div class='link-item item-account'><a title='账户设置' href='<?php print url('user/'.$this->gUser->uid . '/edit')?>'><span>设置</span></a></div><?php endif;?>
        </div>
    </div>
</div>