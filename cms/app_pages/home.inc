<?php
    require_once "app_objects/home.inc";
    $home_obj = new obj_home();

    // get viewing
    $listing = "";
    $listing .= '<tr>
            <td>April 28, 2017</td>
            <td>7:10am</td>
            <td>Album</td>
            <td>Family Vacations</td>
            <td></td>
            <td>16 minutes</td>
        </tr>';
    $listing .= '<tr>
            <td>April 28, 2017</td>
            <td>7:27am</td>
            <td>Channel</td>
            <td>Channel #1</td>
            <td>Bobby</td>
            <td>5 minutes</td>
        </tr>';

    $start_record = 0;
    $record_count = 1;
    $total_records = 1;

    // setup viewing/paging record
    require_once "app_objects/paging.inc";
    $paging_obj = new obj_paging($start_record, $record_count, $total_records);
    $paging_navigation = $paging_obj->getPagingNavigation();
?>
<div class="row page_row">
    <div class="col-lg-6 col-md-6 col-sm-12 col-xs-12">

        <div class="row">
            <div class="col-lg-12">
                <div class="ibox">
                    <div class="ibox-title"><h2><i class="fa fa-check"></i> Getting Started</h2></div>
                    <div class="ibox-content">
<?php
if ($_SESSION['is_admin'])
{
    ?>
    <div style="font-weight:bold;">[ADMIN TASKS - TASK SHOULD DISAPPEAR AFTER COMPLETION]</div>
    <div>1. Make sure the Chroecast device is connected and configured.</div>
    <div>2. Add the information about the Viewer.</div>
    <div>3. Add users who can share content with Viewer.</div>
    <div>4. Connect Love Our Way to your Social Media networks.</div>
    <div>5. Create a channel that pulls content from your desired networks.</div>
    <div>6. Post to your networks as nornally do with the hastag #LOWY and content will appear in the channel.</div>
    <?php
}
else
{
    ?>

    <div><br></div>
    <div style="font-weight:bold;">[USER - TASK SHOULD DISAPPEAR AFTER COMPLETION]</div>
    <div>1. Connect Love Our Way to your Social Media networks.</div>
    <div>2. Create a channel that pulls content from your desired networks.</div>
    <div>3. Post to your networks as nornally do with the hastag #LOWY and content will appear in the channel.</div>

    <?php
}
?>
                        <div><br></div>
                        <div style="font-weight:bold;">[HOW TO VIDEOS]</div>
                    </div>
                </div>
            </div>
        </div>

        <div class="row">
            <div class="col-lg-12">
                <div class="ibox">
                    <div class="ibox-title"><h2><i class="fa fa-question"></i> Need Help?</h2></div>
                    <div class="ibox-content">
                        <div>[LINK TO FAQ MODAL]</div>
                        <div>[CUSTOMER SERVICE - PHONE #]</div>
                        <div>[CUSTOMER SERVICE - EMAIL ADDRESS]</div>
                    </div>
                </div>
            </div>
        </div>
    </div>

    <div class="col-lg-6 col-md-6 col-sm-12 col-xs-12">
        <div class="ibox">
            <div class="ibox-title"><h2><i class="fa fa-newspaper-o"></i> News and Announcemens from LOWY</h2></div>
            <div class="ibox-content">
                [NEWS LISTING]
            </div>
        </div>
    </div>
</div>


<div class="row page_row">
    <div class="col-lg-12 col-md-12 col-sm-12 col-xs-12">
        <div class="ibox">
            <div class="ibox-title"><h2><i class="fa fa-th-list"></i> Making Memories</h2></div>
            <div class="ibox-content">
                <table class="table table-striped">
                    <thead>
                    <tr>
                        <th>Date</th>
                        <th>Start Time</th>
                        <th>Type</th>
                        <th>Name</th>
                        <th>User</th>
                        <th>Viewing Time</th>
                    </tr>
                    </thead>
                    <tbody id="list_records">
                    <?php print($listing); ?>
                    </tbody>
                </table>
            </div>
            <div class="ibox-footer"><?php print($paging_navigation); ?></div>
        </div>
    </div>
</div>
