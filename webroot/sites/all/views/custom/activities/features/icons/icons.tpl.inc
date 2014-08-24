<div id='<?php print $this->baseStyleName; ?>' class='block block-<?php print $this->baseStyleName; ?> block-<?php print $this->baseStyleName;?>-<?php print $this->view['private_key'];?> feature-<?php print $this->feature;?>'>
    <div class='block-title'>
        <?php print $this->view['title']; ?>
        <?php foreach($this->cities as $city): ?>
        <a href='<?php print $city->url; ?>' title='<?php print $city->name; ?>'><?php print $city->name;?><?php //print '('.$city->nodes.')';?></a>
        <?php endforeach;?>
        <!--span class='publish'><a href='<?php print url('activity/create')?>' title='发布旅游活动'>发布活动</a></span-->
    </div>
    <div class='block-content'>
        <?php 
           print render($this->data);
        ?>
        <div class='clearfix'></div>
    </div>
</div>