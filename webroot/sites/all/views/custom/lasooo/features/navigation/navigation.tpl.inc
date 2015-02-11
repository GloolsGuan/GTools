<div id='<?php print $this->baseStyleName;?>' class='block block-<?php print $this->baseStyleName;?> block-<?php print $this->baseStyleName;?>-<?php print $this->view['private_key'];?> feature-<?php print $this->feature;?>'>
    <div class='block-title'><span>DISCOVERY</span></div>
    <div class='block-content'>
        <?php foreach($this->data as $k=>$nav): ?>
        <div id='<?php print strtolower(str_replace(' ', '-', $nav['name']))?>:<?php print $nav['target']; ?>' class='item nav-<?php print $k;?> <?php print strtolower(str_replace(' ', '-', $nav['name']))?>' title='<?php print $nav['title'];?>'><!--<?php print $nav['title'];?>--></div>
        <?php endforeach;?>
        <div class='clearfix'></div>
    </div>
</div>