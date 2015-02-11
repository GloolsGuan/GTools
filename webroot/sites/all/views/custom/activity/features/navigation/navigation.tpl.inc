<div id='<?php print $this->baseStyleName;?>' class='block block-<?php print $this->baseStyleName;?> block-<?php print $this->baseStyleName;?>-<?php print $this->view['private_key'];?> feature-<?php print $this->feature;?>'>
    <div class='block-title'><h2><?php print t($this->view['title']);?></h2></div>
    <div class='block-content'>
        <div class=''><a href='/activity/<?php print $this->activity->nid?>'>活动</a></div>
        <div class=''><a href='/activity/<?php print $this->activity->nid?>/blogs'>日志</a></div>
        <!--div class=''>相册</div-->
        <div class=''><a href='/activity/<?php print $this->activity->nid?>/reviews'>点评</a></div>
        <div class=''><a href='/activity/<?php print $this->activity->nid?>/forum'>论坛</a></div>
        <!--div class=''>公益</div-->
    </div>
</div>