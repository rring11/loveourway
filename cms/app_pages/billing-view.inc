<?php
    // setup page header
    $page_header = $page_obj->setupPageHeader("Account Billing - View", "archive", "/account/billing/list", null, null, null, null);
    $page_footer = $page_obj->setupPageFooter(
        array
        (
            array("color"=>"primary", "target"=>"downloadInvoice", "text"=>"Download Invoice", "icon"=>"download")
        )
    );
?>
<div class="ibox">
    <div class="ibox-title"><?php print($page_header); ?></div>
    <div class="ibox-content">
        <div class="form-group">
            <label>Date Period:</label>
            <div>Feb. 1, 2017 - Feb. 28, 2017</div>
        </div>
        <div class="form-group">
            <label>Invoice Amount:</label>
            <div>$ ###</div>
        </div>
        <div class="form-group">
            <label>Status:</label>
            <div>PAID</div>
        </div>

    </div>
    <div class="ibox-footer"><?php print($page_footer); ?></div>
</div>
