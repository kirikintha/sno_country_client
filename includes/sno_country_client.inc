<?php
/**
 * @file sno_country_client.inc
 * Sno Country Client Module Functions
 * Handles all the settings for the Sno Country Client Module
 * Version: 1.0
 */

function _snow_country_client_process_url($vars) {
  if (empty($vars['resort'])) {
    return FALSE;
  } else {
    $url   = 'http://' .$vars['resort']['hub_url'] .'/' .$vars['resort']['resort_id'] .'/' .$vars['resort']['accumulation_days'];
    $reply = drupal_http_request($url);
    $xml   = simplexml_load_string($reply->data);
    foreach ($xml->report->children() as $element => $value) {
      $vars['widget']['report'][$element] = (string)$value;
    }
    //Cumulative Snowfall.
    $i = 0;
    foreach ($xml->cumulativesnowfall->children() as $element => $value) {
      $vars['widget']['cumulativesnowfall'][$element.$i] = (array)$value;
      $i++;
    }
    return $vars;
  }
}