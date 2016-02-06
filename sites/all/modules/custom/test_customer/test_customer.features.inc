<?php
/**
 * @file
 * test_customer.features.inc
 */

/**
 * Implements hook_node_info().
 */
function test_customer_node_info() {
  $items = array(
    'customer' => array(
      'name' => t('customer'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
