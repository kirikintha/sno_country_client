<?php
/**
 * This is the template file for all sno country clients.
 * More documentation to come.
 */
?>
<div id="<?php print $widget['id']; ?>">
  <?php foreach ($widget['report'] as $id => $row): ?>
    <div id="<?php print $id; ?>">
      <strong><?php print $id; ?>: </strong>
      <span class="information"><?php print $row; ?></span>
    </div>
  <?php endforeach; ?>
  <?php foreach ($widget['cumulativesnowfall'] as $id => $row): ?>
    <div id="<?php print $id; ?>">
      <strong><?php print $id; ?>: </strong>
      <span class="information">
        <?php foreach ($row as $title => $info): ?>
          <div id="<?php print $title; ?>">
            <strong><?php print $title; ?>: </strong>
            <span class="information"><?php print $info; ?></span>
          </div>
        <?php endforeach; ?>
      </span>
    </div>
  <?php endforeach; ?>
</div>