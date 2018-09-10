<?php

/**
 * Make webform workflow states exportable.
 *
 * @param $schema
 */
function apwa_iw_schema_alter( &$schema ) {
  $schema['webform_workflow_state']['export'] = array(
    // Unique key to identify an object
    'key' => 'wsid',
    'key name' => 'Webform workflow state id',
    'admin_title' => 'label',
    'identifier' => 'preset',
    // Function hook name in Features dump
    'default hook' => 'default_apwa_iw_workflow_state_preset',
    'api' => array(
      // Which module "owns" these objects?
      'owner' => 'apwa_iw',
      // Base name for Features include file
      'api' => 'features',
      // Exportables API version numbers: black magic; woowoo
      'minimum_version' => 1,
      'current_version' => 1,
    ),
  );
}

///**
// * Implementation of hook_ctools_plugin_api().
// *
// * Tell CTools that we support the default_mymodule_presets API.
// */
//function apwa_iw_ctools_plugin_api($owner, $api) {
//  if ($owner == 'apwa_iw' && $api == 'default_apwa_iw_workflow_state_preset') {
//    return array('version' => 1);
//  }
//}

/**
 * Implementation of hook_default_mymodule_preset().
 *
 * Provide a couple of default presets.
 */
function apwa_iw_default_apwa_iw_workflow_state_preset() {
  $export = array();

  $preset = new stdClass;
  $preset->api_version = 1;
  $preset->name = 'ww_state_preset';
  $preset->admin_title = 'Webform workflow state preset';
  $preset->mydata = NULL;
  $export['ww_state_preset'] = $preset;

  return $export;
}

