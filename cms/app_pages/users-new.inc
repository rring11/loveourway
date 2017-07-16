<?php
    // setup page header
    $page_header = $page_obj->setupPageHeader("Users - Add a new user", "users", "/users/list", null, null, null, null);
    $page_footer = $page_obj->setupPageFooter(
        array
        (
            array("color"=>"primary", "target"=>"addUser", "text"=>"Add User", "icon"=>"save")
        )
    );
?>
<div class="ibox">
    <div class="ibox-title"><?php print($page_header); ?></div>
    <div class="ibox-content">
        <div class="row">
            <div class="col-lg-6 col-md-6">
                <div class="form-group">
                    <div class="row">
                        <div class="col-lg-6">
                            <label>First name:</label>
                            <input type="text" id="first_name" class="form-control" value="f">
                        </div>
                        <div class="col-lg-6">
                            <label>Last name:</label>
                            <input type="text" id="last_name" class="form-control" value="l">
                        </div>
                    </div>
                </div>
                <div class="form-group">
                    <label>Email Address:</label>
                    <input type="text" id="email" class="form-control" value="el">
                </div>
            </div>
            <div class="col-lg-6 col-md-6">
                <label>What happen's next?</label>
                <div>An email will be sent thte new user with instructions on how to
                verify their account and get all setup.</div>
            </div>
        </div>
    </div>
    <div class="ibox-footer"><?php print($page_footer); ?></div>
</div>
