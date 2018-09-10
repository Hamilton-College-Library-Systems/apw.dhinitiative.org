<?php


/**
 * Utility function
 *
 * @param $vars
 *
 * @throws \Exception
 */
function apwa_iw_process_all_object_view(&$vars) {

  // Compound objects recursively call object view without the islandora_object
  // being loaded, so try to load it now. If unsuccessful, exit.
  global $user;

  // Deal with finding the islandora object if not in the usual variable.
  if (empty($vars['islandora_object'])) {
    // Compound objects recursively call object view without the islandora_object
    // being loaded, so try to load it now. If unsuccessful, exit.
    if (!empty($vars['params']['pid'])) {
      $vars['islandora_object'] = islandora_object_load($vars['params']['pid']);
    }
    // Other solution packs sometimes use 'object' for the islandora object.
    elseif (!empty($vars['object'])) {
      $vars['islandora_object'] = $vars['object'];
    }
  }
  // If still not found, we can't continue.
  if (empty($vars['islandora_object'])) {
    return;
  }

  $vars['cmodel_class_prefix'] = drupal_html_class($vars['theme_hook_original']);
  $vars['cmodel_id_prefix'] = drupal_html_id($vars['theme_hook_original']);


  if (empty($vars['parent_collections']) && !empty($vars['islandora_object'])) {
    $vars['parent_collections'] = islandora_get_parents_from_rels_ext($vars['islandora_object']);

  }
  if (!empty($vars['parent_collections'][0]->id)) {
    $title = $vars['parent_collections'][0]->label;
    $path = 'islandora/object/' . $vars['parent_collections'][0]->id;
    $vars['parent_collection_link'] = l($title, $path);
  }


  $vars['webform_links'] = $vars['webform_target'] = NULL;
  if (module_load_include('inc', 'islandora_webform', 'includes/utilities')) {
    $webforms = islandora_webform_object_get_webforms($vars['islandora_object']);
    $vars['webform_links'] = theme('islandora_webform_links', array(
      'webform_data' => $webforms,
      'islandora_object' => $vars['islandora_object'],
    ));

    $vars['webform_target'] = array(
      '#type' => 'container',
      '#attributes' => array(
        'id' => APWA_INLINE_WEBFORM_DOM_ID,
        'class' => array(),
      )
    );
  }
  $apwa_iw_js_settings = array('pid' => $vars['islandora_object']->id, 'target' => '#' . APWA_INLINE_WEBFORM_DOM_ID, 'transcript_ds' => apwa_iw_get_transcription_ds($vars['islandora_object']));
  drupal_add_js(drupal_get_path('module', 'apwa_iw') . '/js/resize-transcription-window.js');
  drupal_add_js(drupal_get_path('module', 'apwa_iw') . '/js/transcript.js');
  drupal_add_js(array('apwa_iw' => $apwa_iw_js_settings), 'setting');
  drupal_add_library('apwa_iw', 'drag-resize');
}
