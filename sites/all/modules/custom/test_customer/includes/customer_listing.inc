<?php

/**
 * @file
 * Preprocessing for the customer listing.
 *
 * @see test_customer_theme()
 */

/**
 * Implements hook_preprocess_customer_listing().
 */
function test_customer_preprocess_customer_listing(&$variables) {
  $customer_nodes = customer_listing_get_customer_nodes();
  $headers = array(
    'Name',
    'Email',
    'Phone Number',
    'Date of Birth',
    'Address',
  );
  $rows = array();
  foreach ($customer_nodes as $customer_node) {
    $rows[] = array(
      'name' => $customer_node->title,
      'email' => $customer_node->field_email[LANGUAGE_NONE][0]['email'],
      'phone_number' => $customer_node->field_phone_number[LANGUAGE_NONE][0]['value'],
      'date_of_birth' => customer_listing_format_date_of_birth($customer_node->field_date_of_birth[LANGUAGE_NONE][0]['value']),
      'address' => customer_listing_format_address($customer_node->field_address[LANGUAGE_NONE][0]),
    );
  }

  $variables['customers'] = theme(
    'table',
    array(
      'header' => $headers,
      'rows' => $rows,
      'empty' => t('No customers found.'),
    )
  );
}

/**
 * Helper function to format date of birth date.
 *
 * @param $datetime
 * @return string
 *   Formatted date of birth.
 */
function customer_listing_format_date_of_birth($datetime) {
  $date = date_create($datetime);
  return date_format($date, 'm/d/Y');
}

/**
 * Helper function to format the addressfield object.
 *
 * @param $address
 *   An addressfield object.
 * @return string
 *   Formatted address.
 */
function customer_listing_format_address($address) {
  $handlers = array('address' => 'address');
  $context = array('mode' => 'render');
  $address_render_array = addressfield_generate($address, $handlers, $context);
  // Hide country in display.
  $address_render_array['country'] = array();
  return render($address_render_array);
}

/**
 * Helper method to retrieve customer node objects.
 *
 * @return array
 *   An array of customer node objects.
 */
function customer_listing_get_customer_nodes() {
  $customer_node_ids = db_query("select nid from {node} where type = 'customer'")->fetchCol();
  $customer_nodes = node_load_multiple($customer_node_ids);

  return $customer_nodes;
}