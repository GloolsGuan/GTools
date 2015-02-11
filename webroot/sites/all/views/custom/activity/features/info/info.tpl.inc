<div id='<?php print $this->baseStyleName;?>' class='block block-<?php print $this->baseStyleName;?> block-<?php print $this->baseStyleName;?>-<?php print $this->view['private_key'];?> feature-<?php print $this->feature;?>'>
    <div class='block-title'></div>
    <div class='block-content'>
        <?php //debug_record_data(__FILE__, $this->node);?>
        <div class='item'>分类：<?php print $this->node->field_activity_type['und'][0]['taxonomy_term']->name;?></div>
        <!--div class='item'>已预定：30（50剩余）</div-->
        <div class='item book-duration'>预订：活动开始前<?php print $this->node->field_deadline['und'][0]['value'];?></div>
        <div class='item'>时间：<?php print date('m/d/Y', $this->node->field_latest_period_time['und'][0]['value']); ?>&nbsp;-&nbsp;<?php print date('m/d/Y', $this->node->field_activity_endtime['und'][0]['value']); ?></div>
        <div class='item'>费用：￥<?php print $this->node->field_activity_fee['und'][0]['value']?>/<?php print empty($this->node->field_activity_fee_unit['und'][0]['value'])? '人':$this->node->field_activity_fee_unit['und'][0]['value'];?></div>
        <div class='item'>地点：<?php print $this->node->field_assembling_place['und'][0]['value']; ?></div>
        <?php if(($this->node->field_activity_endtime['und'][0]['value']-time())<=10):?>
        <div class='item book activity-expired'>
        <span>该活动已过期</span>
        <?php else:?>
        <div class='item book <?php print $this->bookStyle;?>'>
        <?php if(false==$this->booked):?>
        <a href='<?php print url('activity/'.$this->node->nid.'/book');?>'>预定活动</a>
        <?php else:?>
        <span >您已预订该活动<a href='<?php print url('activity/' . $this->node->nid) . '/debook'?>'>（取消）</a></span>
        <?php endif;?>
        <?php endif;?>
        </div>
    </div>
</div>