<?php

function frontend_city_search($city, $query){
	
    if (module_exists('city')) {
		return city_search($city, $query);
	}else{
		watchdog('error', 'City module is disabled.');
        return t('System error happened, we are sorry for the error and we would solve the problem as soon as passible.');
	}
}