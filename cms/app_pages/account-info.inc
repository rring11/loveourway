<?php
    // setup page header
    $page_header = $page_obj->setupFormHeader("Account - Information", "info-circle");
    $page_footer = $page_obj->setupPageFooter(
    array
    (
        array("color"=>"primary", "target"=>"updateInfo", "text"=>"Update", "icon"=>"save")
    )
    );

    $no_display = "display:none;";
    $viewer_info = $no_display;
    $usage_info = $no_display;
    $billing_info = $no_display;
    if ($_SESSION['is_admin'])
    {
        $viewer_info = "";
        $usage_info = "";
        $billing_info = "";
    }
?>
<div class="row">
    <div class="col-lg-6 col-md-6">
        <div class="ibox">
            <div class="ibox-title"><?php print($page_header); ?></div>
            <div class="ibox-content">
                <div class="row">
                    <div class="col-lg-6 col-md-6">
                        <div class="form-group">
                            <label>First name:</label>
                            <input type="text" id="account_first_name" class="form-control">
                        </div>
                    </div>
                    <div class="col-lg-6 col-md-6">
                        <div class="form-group">
                            <label>Last name:</label>
                            <input type="text" id="account_last_name" class="form-control">
                        </div>
                    </div>
                </div>
                <div class="form-group">
                    <label>Email Address:</label>
                    <input type="text" id="account_email" class="form-control">
                </div>

                <div class="form-group">
                    <label>Street Address:</label>
                    <input type="text" id="account_address" class="form-control">
                </div>
                <div class="form-group">
                    <label>City:</label>
                    <input type="text" id="account_city" class="form-control">
                </div>

                <div class="row">
                    <div class="col-lg-4">
                        <div class="form-group">
                            <label>State:</label>
                            <input type="text" id="account_state" class="form-control">
                        </div>
                    </div>
                    <div class="col-lg-4">
                        <div class="form-group">
                            <label>Zip Code:</label>
                            <input type="text" id="account_zip" class="form-control">
                        </div>
                    </div>
                    <div class="col-lg-4">
                        <div class="form-group">
                            <label>Phone Number:</label>
                            <input type="text" id="account_phone" class="form-control">
                        </div>
                    </div>
                </div>

                <div class="form-group">
                    <label class="checkbox-inline"><input type="checkbox" value="account_optin"> I would like to receive the LOWY newsletter </label>
                </div>


                <div class="row">
                    <div class="col-lg-6 col-md-6">
                        <div>[CURRENT IMAGE]</div>
                    </div>
                    <div class="col-lg-6 col-md-6">
                        <div>[DROP ZONE]</div>
                    </div>
                </div>
            </div>
            <div class="ibox-footer"><?php print($page_footer); ?></div>
        </div>
    </div>
    <div class="col-lg-6 col-md-6" style="<?php print($viewer_info); ?>">
        <div class="ibox">
            <div class="ibox-title"><h2><i class="fa fa-user"></i> Viewer Information</h2></div>
            <div class="ibox-content">
                <div class="row">
                    <div class="col-lg-6 col-md-6 col-sm-12">
                        <label>Current Image</label><br>
                        <img src="/imgs/elderly_woman.jpg" style="max-height:200px;">
                    </div>
                    <div class="col-lg-6 col-md-6 col-sm-12">
                        <label>Upload Image</label><br>
                        [DROPZONE]
                        <div><br></div>
                    </div>
                </div>

                <div><br></div>
                <div class="row">
                    <div class="col-lg-6 col-md-6 col-sm-12">
                        <h3>Mary Jenkins</h3>
                        <div>Sunrise Assisted Living</div>
                        <div>Room #14</div>
                        <div>555-555-1212</div>

                        <div><br></div>
                        <div>Born May 1, 1927</div>
                        <div>89 years young</div>
                        <div><br></div>
                    </div>
                    <div class="col-lg-6 col-md-6 col-sm-12">
                        <h3>Device IDs:</h3>
                        <div>Android: ######</div>
                        <div>Chromecast: ######</div>
                        <div>T.V.: ######</div>
                        <div><br></div>
                    </div>
                </div>
                <br>
                <div><a href="/preview/show" target="_blank"><i class="fa fa-eye menu-item-icon"></i> <span class="nav-label">Preview</span></a></div>
                <div><a href="/process/show" target="_blank"><i class="fa fa-filter menu-item-icon"></i> <span class="nav-label">Process</span></a></div>
            </div>
            <div class="ibox-footer">
                <button class="btn btn-primary btn-small"><i class="fa fa-save"></i> Update</button>
            </div>
        </div>
    </div>
</div>

<div class="row">
    <div class="col-lg-6 col-md-6" style="<?php print($billing_info); ?>">
        <div class="ibox">
            <div class="ibox-title"><h2><i class="fa fa-dollar"></i> Billing</h2></div>
            <div class="ibox-content">
                <div>[CREDIT CARD INFORMATION]</div>
                <div>[NEXT PAYMENT]</div>
                <div>[LAST PAYMENT]</div>
                <div>[LINK TO PAYMENT HISTORY]</div>
                <div>[CONTACT BILLING]</div>
            </div>
        </div>
    </div>

    <div class="col-lg-6 col-md-6" style="<?php print($usage_info); ?>">
        <div class="ibox">
            <div class="ibox-title"><h2><i class="fa fa-bookmark"></i> Usage</h2></div>
            <div class="ibox-content">
                <div>[USAGE GRAPH]</div>
                <div>[LINK TO DETAILS]</div>
            </div>
        </div>
    </div>

</div>
