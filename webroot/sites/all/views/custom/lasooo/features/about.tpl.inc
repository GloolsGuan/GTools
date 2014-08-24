<div id="<?php print $this->viewName; ?>" class="block <?php print 'block-'.$this->viewName; ?>">
    <div class='block-title'></div>
    <div class="block-content">
        <div class='heart'>心之路，体验别致旅途！</div>
        <span></span>
        <div class='enlight-cities'>
            <ul>
                <li class='city_title'>热门城市:</li>
                <?php foreach($this->data['cities'] as $city) :?>
                <li class='city_<?php print $city->tid;?>'><a href='<?php print $city->url;?>' title='<?php print $city->name;?>'><?php print $city->name;?></a>(<?php print $city->nodes;?>)</li>
                <?php endforeach;?>
            </ul>
        </div>
        <div class='enlight-tags'>
            <ul>
                <li class='tag_title'>热门标签:</li>
                <?php foreach($this->data['tags'] as $tag) :?>
                <li class='city_<?php print $tag->tid;?>'><a href='<?php print $tag->url;?>' title='<?php print $tag->name;?>'><?php print $tag->name;?></a>(<?php print $tag->nodes;?>)</li>
                <?php endforeach;?>
            </ul>
        </div>
        <div class='register'>加入乐书</div>
        <div class='clearfix'></div>
    </div>
</div>