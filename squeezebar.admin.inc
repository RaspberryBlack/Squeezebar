<?php
/** 
  * @file 
  * Administration page callbacks for the Squeezebar module. 
  */
  
/** 
  * Form builder. Configure the Squeezebar. 
  * 
  * @ingroup forms 
  * @see system_settings_form(). 
  */
function squeezebar_admin_settings() { 

	$form['squeezebar_text'] = array( 
		'#type' => 'textfield',
		'#title' => t('Squeeze text'),
		'#description' => t('The text in front of the link.'),
		'#default_value' => variable_get('squeezebar_text', 'Hey look at'),
		'#size' => 60,
		'#maxlength' => 64,
	);
	
	$form['squeezebar_link'] = array(	
		'#type' => 'textfield',
		'#title' => t('Squeeze link'),
		'#description' => t('The link text.'),
		'#default_value' => variable_get('squeezebar_link', 'this'),
		'#size' => 60,
		'#maxlength' => 64,
	);
	
	$form['squeezebar_linktarget'] = array(	
		'#type' => 'textfield',
		'#title' => t('Link target'),
		'#description' => t('The page you want the link to go (relative link).'),
		'#default_value' => variable_get('squeezebar_linktarget', 'node'),
		'#size' => 60,
		'#maxlength' => 64,
	);
	
	$form['squeezebar_bgcolor'] = array(	
		'#type' => 'textfield',
		'#title' => t('Link target'),
		'#description' => t('The page you want the link to go (relative link).'),
		'#default_value' => variable_get('squeezebar_linktarget', 'node'),
		'#size' => 60,
		'#maxlength' => 64,
	);
		
	$form['#submit'][] = 'squeezebar_admin_settings_submit'; 
	
	return system_settings_form($form);
}

/** 
  * Process annotation settings submission. 
  */
function squeezebar_admin_settings_submit($form, $form_state) {
	// Loop through each of the content type checkboxes shown on the form. 
	dpm($form_state['values']);
	
	//foreach ($form_state['values'] as $key => $value) 
				
}