<div id='<?php print $this->baseStyleName;?>' class='block block-<?php print $this->baseStyleName;?> block-<?php print $this->baseStyleName;?>-<?php print $this->view['private_key'];?> feature-<?php print $this->feature;?>'>
    <div class='block-title'><h2>tags</h2></div>
    <div class='block-content'>
    <?php 
        if (null==$this->data) {
        	print t('There is activity tags in '.$this->city->name);
        }else{
            foreach ($this->data as $term) {
            	print l($term->name."({$term->cnid})", 'city/'.$this->city->name.'/tag:'.$term->name);
            }
        }
    ?>
    <div class='clearfix'></div>
    </div>
</div>