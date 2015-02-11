<div id='<?php print $this->baseStyleName;?>' class='block block-<?php print $this->baseStyleName;?> block-<?php print $this->baseStyleName;?>-<?php print $this->view['private_key'];?> feature-<?php print $this->feature;?>'>
    <div class='block-title'></div>
    <div class='block-content slideContainer clearfix'>
    <div class='slideContent'>
        <?php if(''==request_path()): ?>
        <div class='frontpage-photo'><img src='/misc/xf1996/frontpage.jpg' /></div>
        <?php else:?>
        <?php print render($this->buildNodes);?>
        <?php endif;?>
    </div>
    <div class='clearfix'></div>
    </div>
    <!--div class='handlersBG'></div-->
    <div class='handlers'>
        <div class="tabsMap">
           <?php foreach($this->tabMapPhotos as $key=>$photo):?>
               <div class='tabsMap_item tabsMap_item_<?php print $key;?>'><?php print $photo;?></div>
           <?php endforeach;?> 
        </div>
        <div class='bA'></div>
        <div class='bB'></div>
    </div>
</div>