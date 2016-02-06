<?php
/**
 * @file
 * test_customer.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function test_customer_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer users'.
  $permissions['administer users'] = array(
    'name' => 'administer users',
    'roles' => array(),
    'module' => 'user',
  );

  return $permissions;
}
