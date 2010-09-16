<?php
// $Id$

/**
 * @file
 * Drush integration functions for the admin_only_mode module.
 */

/**
 * Implements hook_drush_command().
 */
function admin_only_mode_drush_command() {
  $items['admin-only-mode'] = array(
    'callback' => 'admin_only_mode_drush_set_mode',
    'description' => dt('Put the site in admin-only mode'),
    'drupal dependencies' => array('admin_only_mode'),
    'arguments' => array(
      'setting' => dt('1 to enable admin_only mode, 0 to disable'),
    ),
    'examples' => array(
      'drush admin-only-mode 1' => dt('Put site in admin-only mode with last-used message'),
      'drush admin-only-mode 1 --message="Go away"' => dt('Put site in admin-only mode with message "Go Away"'),
      'drush admin-only-mode 1 --message=""' => dt('Put site in admin-only mode with no message'),
    ),
    'options' => array(
      '--message' => dt('The message to show logged in users. Default value is the last message used.'),
    ),
  );
  return $items;
}

/**
 * Set or unset admin_only_mode
 */
function admin_only_mode_drush_set_mode($setting) {
  $message = drush_get_option('message');
  $setting = empty($setting) ? 0 : 1;

  if (isset($message)) {
    variable_set('admin_only_mode_message',$message);
  }
  variable_set('admin_only_mode',$setting);
  drush_print(dt("Admin-only mode set to $setting"));
}
