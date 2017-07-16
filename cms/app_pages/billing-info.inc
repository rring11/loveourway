<?php
    // setup page header
    $page_header = $page_obj->setupPageHeader("Billing", "archive", null, "search", null, null, null);

    // get listing

    $listing = "";
    $listing = '<tr>
        <td>Feb. 23, 2017</td>
        <td>Monthly Invoice</td>
        <td>PAID</td>
        <td>
            <i class="fa fa-download fa-lg action_icon " data-target="/billing/view/[ID]"></i>
        </td>
    </tr>';

    $start_record = 0;
    $record_count = 10;
    $total_records = 20;

    // setup viewing/paging record
    require_once "app_objects/paging.inc";
    $paging_obj = new obj_paging($start_record, $record_count, $total_records);
    $paging_navigation = $paging_obj->getPagingNavigation();
?>
<div class="ibox">
    <div class="ibox-title"><?php print($page_header); ?></div>
    <div class="ibox-content">
        <div class="table-responsive">
            <table class="table table-striped">
                <thead>
                <tr>
                    <th>Date</th>
                    <th>Description</th>
                    <th>Status</th>
                    <th>Actions</th>
                </tr>
                </thead>
                <tbody id="list_records">
                    <?php print($listing); ?>
                </tbody>
            </table>
        </div>
    </div>
    <div class="ibox-footer"><?php print($paging_navigation); ?></div>
</div>
