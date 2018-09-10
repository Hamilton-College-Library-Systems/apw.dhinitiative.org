<?php

function apwa_iw_webform_link_states() {
  $link_states = &drupal_static(__FUNCTION__);
  if(!isset($link_states)) {
    $link_states = array(
      'is draft' => array(
        'priority' => 10,
        'link-text' => t('Transcription in process'),
        'link-text-single' => t('transcription in process'),
        'link-text-plural' => t('transcriptions in process'),
      ),
      1 => array(
        'priority' => 1,
        'link-text' => t('Transcription pending review'),
        'link-text-single' => t('transcription pending review'),
        'link-text-plural' => t('transcriptions pending review'),
      ),
      2 => array(
        'priority' => 0,
        'link-text' => t('Transcription pending review'),
        'link-text-single' => t('transcription pending review'),
        'link-text-plural' => t('transcriptions pending review'),
      ),
    );
    uasort($link_states, function($a, $b) {return $a['priority'] < $b['priority'];});
  }
  return $link_states;
}