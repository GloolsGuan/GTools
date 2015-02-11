<div id='<?php print $this->baseStyleName;?>' class='block block-<?php print $this->baseStyleName;?> block-<?php print $this->baseStyleName;?>-<?php print $this->view['private_key'];?> feature-<?php print $this->feature;?>'>
    <div class='block-title'></div>
    <div class='block-content'>
        <div class='flags'>
            <?php print flag_create_link('like', $this->node->nid); ?>
        </div>
        <div class="state"><?php print t('Participants members')?>:&nbsp;<?php print count($this->members);?>&nbsp;人</div>
        <div class='newbies-content'>
            <div class='title'>参加该活动的会员</div>
            <div class='newbies'>
                <?php 
                    for($i=0; $i<10; $i++):
                    if(empty($this->members)) {
                    	break;
                    } 
                    $newbie = array_shift($this->members); 
                ?>
                <div class='newbie'><a href='<?php print url('user/'.$newbie->uid);?>'><?php print member_load_member_photo($newbie);?></a></div>
                <?php endfor;?>
            </div>
            <div class='more'></div>
        </div>
    </div>
</div>