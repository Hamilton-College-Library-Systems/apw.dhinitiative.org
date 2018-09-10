<?php
/**
 * @file
 * apwa_iw.apwa_iw.features.inc
 */

/**
 * Implements hook_default_apwa_iw_workflow_state_preset().
 */
function apwa_iw_default_apwa_iw_workflow_state_preset() {
  $export = array();

  $preset = new stdClass();
  $preset->disabled = FALSE; /* Edit this to true to make a default preset disabled initially */
  $preset->api_version = 1;
  $preset->wsid = '1';
  $preset->uid = 1;
  $preset->label = 'Pending Review';
  $preset->color = 'amber';
  $preset->permissions = array(
    'view' => array(
      2 => '2',
    ),
    'edit' => array(),
    'from' => array(),
    'to' => array(),
  );
  $preset->created = 1493404346;
  $preset->changed = 1494503568;
  $export['1'] = $preset;

  $preset = new stdClass();
  $preset->disabled = FALSE; /* Edit this to true to make a default preset disabled initially */
  $preset->api_version = 1;
  $preset->wsid = '2';
  $preset->uid = 1;
  $preset->label = 'Approved for Ingestion';
  $preset->color = 'green';
  $preset->permissions = array(
    'view' => array(),
    'edit' => array(),
    'from' => array(),
    'to' => array(),
  );
  $preset->created = 1493404346;
  $preset->changed = 1493404368;
  $export['2'] = $preset;

  $preset = new stdClass();
  $preset->disabled = FALSE; /* Edit this to true to make a default preset disabled initially */
  $preset->api_version = 1;
  $preset->wsid = '3';
  $preset->uid = 1;
  $preset->label = 'Declined';
  $preset->color = 'red';
  $preset->permissions = array(
    'view' => array(),
    'edit' => array(),
    'from' => array(),
    'to' => array(),
  );
  $preset->created = 1493404346;
  $preset->changed = 1493404346;
  $export['3'] = $preset;

  $preset = new stdClass();
  $preset->disabled = FALSE; /* Edit this to true to make a default preset disabled initially */
  $preset->api_version = 1;
  $preset->wsid = '4';
  $preset->uid = 1;
  $preset->label = 'Ingested';
  $preset->color = 'purple';
  $preset->permissions = array(
    'view' => array(),
    'edit' => array(),
    'from' => array(),
    'to' => array(),
  );
  $preset->created = 1493404346;
  $preset->changed = 1493404346;
  $export['4'] = $preset;

  return $export;
}
