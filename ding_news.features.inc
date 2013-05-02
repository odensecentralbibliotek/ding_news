<?php
/**
 * @file
 * ding_news.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ding_news_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function ding_news_views_api() {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function ding_news_image_default_styles() {
  $styles = array();

  // Exported image style: oc_news_main_image.
  $styles['oc_news_main_image'] = array(
    'name' => 'oc_news_main_image',
    'effects' => array(
      9 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 240,
          'height' => 240,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function ding_news_node_info() {
  $items = array(
    'ding_news' => array(
      'name' => t('News'),
      'base' => 'node_content',
      'description' => t('A content type for news concerning libraries.'),
      'has_title' => '1',
      'title_label' => t('Heading'),
      'help' => '',
    ),
  );
  return $items;
}
