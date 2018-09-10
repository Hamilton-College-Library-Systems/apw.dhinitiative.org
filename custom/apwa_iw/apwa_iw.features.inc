<?php
/**
 * @file
 * apwa_iw.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function apwa_iw_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "apwa_iw" && $api == "apwa_iw.features") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function apwa_iw_node_info() {
  $items = array(
    'webform' => array(
      'name' => t('Webform'),
      'base' => 'node_content',
      'description' => t('Create a new form or questionnaire accessible to users. Submission results and statistics are recorded and accessible to privileged users.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
