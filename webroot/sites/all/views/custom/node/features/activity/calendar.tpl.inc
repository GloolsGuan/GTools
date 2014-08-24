<div id='<?php print $this->baseStyleName;?>' class='block block-<?php print $this->baseStyleName;?> block-<?php print $this->baseStyleName;?>-<?php print $this->view['private_key'];?> feature-<?php print $this->feature;?>'>
    <div class='block-title'><?php print $this->view['title'];?></div>
    <div class='block-content clearfix'>
        <div class='calendar-map-header'>周一</div>
        <div class='calendar-map-header'>周二</div>
        <div class='calendar-map-header'>周三</div>
        <div class='calendar-map-header'>周四</div>
        <div class='calendar-map-header'>周五</div>
        <div class='calendar-map-header'>周六</div>
        <div class='calendar-map-header'>周日</div>
        <?php
            
            if (empty($this->activityNodes['#dayMap'])) {
                echo '本月没有活动';
            }else{
                $m = date('m', time());
                
                $class = '';
            	foreach($this->activityNodes['#dayMap'] as $dt=>$co) {
            		if ($m!=date('m', $co['timestamp'])) {
            			//$class = 'disable';
            		}
                    
                    //debug_rdata(__FUNCTION__, array_keys($co));
                    
                    echo '<div class=" calendar-map-item ' .$co['class']. '">';
                    if (isset($co['nodes'])) {
                        //debug_rdata(__FUNCTION__, $co);
                    	print render($co['nodes']);
                    }else{
                    	//print date('m-d', $co['timestamp']);
                    }
                    
                    echo '<div class="day-img"><img src="/misc/xf1996/date/'. $co['dayPhoto'] .'"></div>';
                    echo '</div>';
            	}
            }
            
        ?>
    </div>
</div>