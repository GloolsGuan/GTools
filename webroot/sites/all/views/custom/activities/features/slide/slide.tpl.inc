<div id='<?php print $this->baseStyleName;?>' class='block block-<?php print $this->baseStyleName;?> block-<?php print $this->baseStyleName;?>-<?php print $this->view['private_key'];?> feature-<?php print $this->feature;?>'>
    <div class='block-title'></div>
    <div class='block-content slideContainer'>
        <?php if (empty($this->data)):?>
        <div class='mes'><?php print t('There is no valid activity in current city.');?></div>
        <?php else:?>
        <div class='slideContent'>
            <?php foreach($this->data as $activity):?>
            <div class='item'>
                <div class='logo'><?php print l(theme('image', array('path'=>$activity->field_activity_logo['und'][0]['uri'], 'title'=>$activity->title, 'alt'=>$activity->title)), 'activity/'.$activity->nid, array('html'=>true, 'attributes'=>array('class'=>'activity_logo')));?></div>
                <div class='introbg'></div>
                <div class='intro'>
                    <div class='title'><?php print l($activity->title, 'activity/'.$activity->nid);?></div>
                    <div class='time'>本期活动时间：<?php print date('Y-m-d H:i', $activity->field_latest_period_time['und'][0]['value']); ?></div>
                    <div class='location'>所在城市：<?php $term = taxonomy_term_load($activity->field_city['und'][0]['tid']); print l($term->name, 'city/'.$term->name);?></div>
                    <div class='fee'>活动费用：<?php print $activity->field_activity_fee['und'][0]['value'];?>&nbsp;RMB</div>
                    <!--div class='participant-follower'></div-->
                    <div class='desc'><?php print truncate_utf8($activity->body['und'][0]['safe_summary'], 100, true, '...');?></div>
                    <div class='icons'></div>
                </div>
            </div>
            <?php endforeach;?>
        </div>
        <?php endif;?>
    <div class='clearfix'></div>
    </div>
    <div class='handlers'>
        <div class='bA'>&lt;&lt;</div>
        <div class='bB'>&gt;&gt;</div>
    </div>
</div>