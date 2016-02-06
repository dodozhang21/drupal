<?php

/**
 * @file
 * Customer listing template.
 *
 * Variables available:
 * - $customers
 *   A theme table containing customer data.
 */
?>

<?php
if (!empty($customers)) {
  print render($customers);
}
?>
