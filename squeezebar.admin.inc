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
		'#type' => 'textarea',
		'#title' => t('Squeeze text'),
		'#description' => t('The text in your squeezebar. Include links via html.'),
		'#default_value' => variable_get('squeezebar_text', 'Hey look at'),
		'#rows' => 1,
		'#wysiwyg' => false,
	);
	
	$form['squeezebar_bgcolor'] = array(	
		'#type' => 'textfield',
		'#title' => t('Background Color'),
		'#description' => t('The main color of your Squeezebar as hexcode.'),
		'#default_value' => variable_get('squeezebar_bgcolor', '#0779BF'),
		'#size' => 60,
		'#maxlength' => 64,
	);
	
	$form['squeezebar_font'] = array(	
		'#type' => 'textfield',
		'#title' => t('Font Family'),
		'#description' => t('Specify a font family like after "font-family:" in css'),
		'#default_value' => variable_get('squeezebar_font', 'inherit'),
		'#size' => 60,
		'#maxlength' => 64,
	);
	
	$form['squeezebar_textcolor'] = array(	
		'#type' => 'textfield',
		'#title' => t('Text Color'),
		'#description' => t('The color of your text as hexcode.'),
		'#default_value' => variable_get('squeezebar_textcolor', '#FFFFFF'),
		'#size' => 60,
		'#maxlength' => 64,
	);
	
	$form['squeezebar_linkcolor'] = array(	
		'#type' => 'textfield',
		'#title' => t('Link Color'),
		'#description' => t('The color of your link as hexcode.'),
		'#default_value' => variable_get('squeezebar_linkcolor', '#FFFFFF'),
		'#size' => 60,
		'#maxlength' => 64,
	);
	
	$form['squeezebar_bordercolor'] = array(	
		'#type' => 'textfield',
		'#title' => t('Border Color'),
		'#description' => t('The color of the bottom-border as hexcode.'),
		'#default_value' => variable_get('squeezebar_bordercolor', '#FFFFFF'),
		'#size' => 60,
		'#maxlength' => 64,
	);
		
	$form['#submit'][] = 'squeezebar_admin_settings_submit'; 
	
	return system_settings_form($form);
}

/** 
  * Process squeezebar settings submission:
  * Saves color values to squeezebar-settings.less.  
  */
function squeezebar_admin_settings_submit($form, $form_state) {
	//dpm($form_state['values']);
	
	//foreach ($form_state['values'] as $key => $value) 
	
	$data  = "//This files stores the Squeezebar-settings; \n"; 
	$data .= "//Do not edit directly but via tha admin interface only (admin/config/user-interface/squeezebar).\n";
	$data .= "\n @bgcolor: " . $form_state['values']['squeezebar_bgcolor'] . ";";
	$data .= "\n @textcolor: " . $form_state['values']['squeezebar_textcolor'] . ";";
	$data .= "\n @linkcolor: " . $form_state['values']['squeezebar_linkcolor'] . ";";
	$data .= "\n @bordercolor: " . $form_state['values']['squeezebar_bordercolor'] . ";";
	$data .= "\n @font: " . $form_state['values']['squeezebar_font'] . ";";
	
	$destination = drupal_get_path('module', 'squeezebar') . '/squeezebar-settings.less';
	
	$file = file_unmanaged_save_data($data, $destination, FILE_EXISTS_REPLACE);
	if (!$file) {
    	drupal_set_message(t('Failed to save the file'), 'error');
	}		
}