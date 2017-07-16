<?php
    require_once "app_objects/page.inc";
    $page_obj = new obj_page();

    // include page
    $include_name = "app_pages/";
    if ($page_data[1]) { $include_name .= $page_data[1]; }
    if ($page_data[2]) { $include_name .= "-" . $page_data[2]; }
    $include_name .= ".inc";

?>
<div class="row page_row">
    <div class="col-lg-12 col-md-12 col-sm-12 col-xs-12"><?php include_once $include_name; ?></div>
</div>


