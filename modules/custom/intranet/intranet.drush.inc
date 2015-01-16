<?php
/**
 * @file
 * Drush plugin to mess with the Intranet.
 */

/**
 * Implements hook_drush_command().
 */
function intranet_drush_command() {
  $items['intranet-fix'] = array(
    'aliases' => array('intranet', 'if'),
    'callback' => 'drush_intranet_fix',
    'description' => dt('Fix intranet content.'),
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
  );

  return $items;
}

/**
 * Command callback.
 */
function drush_intranet_fix() {
/*
  // Original nodes not in the current mapping.
  $result = db_query('SELECT nid FROM {node} WHERE nid NOT IN (SELECT destid1 FROM {migrate_map_staffintranetpage}) AND changed < :changed', array(':changed' => 1371560400));
  foreach ($result as $row) {
    $node = node_load($row->nid, NULL, TRUE);
    // DELETE THE NODE! KILL IT!
    node_delete($row->nid);
    drush_print(t('Deleted node @title', array('@title' => $node->title)));
  }

  // Any nodes not in the current mapping.
  $nids = array();
  $result = db_query('SELECT nid,title FROM {node} WHERE nid NOT IN (SELECT destid1 FROM {migrate_map_staffintranetpage})');
  foreach ($result as $row) {
    drush_print(t('     New: @nid: @title', array('@nid' => $row->nid, '@title' => $row->title)));
  }

  $result = db_query('SELECT nid,COUNT(nid) as num,title FROM {node} GROUP BY title HAVING num > 1 ORDER BY title ASC');
  foreach ($result as $row) {
    drush_print(t('Match (@count) @nid: @title', array('@count' => $row->num, '@nid' => $row->nid, '@title' => $row->title)));
  }

  // Import nids that needs remapping, with the original node deleted.
  $remap = array(
    1542 => 1664,   // Advertising booking
    1472 => 995,    // Emergency Management
    1601 => 1124,   // Environment, Health and Safety
    1557 => 1655,   // Research
    1375 => 1662,   // Staff services
  );

  foreach ($remap as $orig => $new) {
    db_query('UPDATE {migrate_map_staffintranetpage} SET destid1 = :new WHERE destid1 = :orig', array(':new' => $new, ':orig' => $orig));
    drush_print(t('  Migrate @orig: ==> @new', array('@new' => $new, '@orig' => $orig)));

    $node = node_load($orig, NULL, TRUE);
    // DELETE THE NODE! KILL IT!
    node_delete($orig);
    drush_print(t('Deleted node @title', array('@title' => $node->title)));
  }
*/

  $result = db_query('SELECT title,COUNT(title) as num FROM {node} GROUP BY title HAVING num > 1 ORDER BY title ASC');
  foreach ($result as $row) {
    $result2  = db_query('SELECT nid, title FROM {node} WHERE title = :title', array(':title' => $row->title));
    foreach ($result2 as $node) {
      $alias = db_query('SELECT alias FROM {url_alias} WHERE source = :source', array(':source' => 'node/' . $node->nid))->fetchField();
      drush_print(t('"/node/@nid","/@alias","@title"', array('@nid' => $node->nid, '@alias' => $alias, '@title' => $node->title)));
    }
  }
}
