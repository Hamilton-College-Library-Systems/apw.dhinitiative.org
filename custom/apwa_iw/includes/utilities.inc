<?php

/**
 * @file
 * This file contains the functions to render the transcript tab.
 */

/**
 * Renders the transcription page.
 *
 * @pararm AbstractObject $object
 *   The object the TRANSCRIPT belongs to.
 *
 * @return array
 *   A renderable array representing the tab.
 */
function apwa_transcript_view(AbstractObject $object, $ds) {
  $transcript = $object[$ds]->content;
  return array(
    'transcript' => array(
      '#markup' => '<pre>' . wordwrap($transcript) . '</pre>',
    ),
  );
}

function apwa_transcript_getajax(AbstractObject $object, $ds) {
  $return = array(
    '#type' => 'container',
    '#attributes' => array(
      'class' => array('inline-webform-target'),
      'id' => 'webform-ajax-wrapper-transcript'
    ),
    'title' => array(
      '#theme' => 'html_tag',
      '#tag' => 'h2',
      '#value' => t('Transcription'),
    ),
    'body' => array(
      '#type' => 'container',
      '#attributes' => array(
        'class' => array(),
      ),
      array(
        '#markup' => $object[$ds]->content,
      ),

    ),
  );

  return $return;
}

function apwa_transcript_ajax_callback($page_callback_result) {
  // Only render content
  $content = $page_callback_result;
  print(render($content));
  return;

  // Add CSS and JS files, add some markup
  $html = '<html><head><title></title>' . drupal_get_css() . drupal_get_js() . '</head><body class="jquery-ajax-load">' . $content . '</body></html>';
  print $html;

  // Perform end-of-request tasks.
  drupal_page_footer();
}