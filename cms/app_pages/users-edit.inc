<?php
    // setup page header
    $page_header = $page_obj->setupPageHeader("Users - Edit User", "users", "/users/list", null, null, null, null);
    $page_footer = $page_obj->setupPageFooter(
        array
        (
            array("color"=>"primary", "target"=>"updateUser", "text"=>"Update User", "icon"=>"save")
        )
    );

    require_once "app_objects/users.inc";
    $users_obj = new obj_users();
    $user_id = $GLOBALS['db']->filterString( $page_data[3] );
    $user = $users_obj->getItem($user_id);

    if ($user->avatar == "") { $avatar = '<i class="fa fa-user" style="font-size:128px;"></i>'; }
    else { $avatar = '<img src="/imgs/users/' . $user->avatar . '" style="max-width:200px; max-height:200px;">'; }

    $platforms = "";
    for ($i = 0; $i < count($user->platforms); $i++)
    {
        $platform = $user->platforms[$i];
        $icon = "";
        if ($platform == "Facebook") { $icon .= '<i class="fa fa-facebook fa-5x"></i><br>Facebook'; }
        else if ($platform == "Pinterest") { $icon .= '<i class="fa fa-pinterest fa-5x"></i><br>Pinterest'; }
        else if ($platform == "Dropbox") { $icon .= '<i class="fa fa-dropbox fa-5x"></i><br>Dropbox'; }
        else if ($platform == "YouTube") { $icon .= '<i class="fa fa-youtube fa-5x"></i><br>YouTube'; }

        $platforms .= '<div class="col-lg-3 text-center">
            <div class="platform_holder">' . $icon . '</div>
        </div>';
    }

    if ($platforms == "")
    {
        $platforms = '<div class="col-lg-12 ">No Social Media Networks connected yet.</div>';
    }
?>

<?php if ($user == null) { ?>
    <div class="ibox">
        <div class="ibox-title"><?php print($page_header); ?></div>
        <div class="ibox-content">
            <h2 style="text-align:center; margin:25px 0px 25px 0px;">Oops, it looks like we cannot locate this user.</h2>
        </div>
    </div>
<?php return; } ?>

<div class="ibox">
    <div class="ibox-title"><?php print($page_header); ?></div>
    <div class="ibox-content">
        <div class="row">
            <div class="col-lg-6 col-md-6">
                <div class="form-group">
                    <div class="row">
                        <div class="col-lg-6">
                            <label>First name:</label>
                            <input type="text" id="first_name" class="form-control" value="<?php print($user->first_name); ?>">
                        </div>
                        <div class="col-lg-6">
                            <label>Last name:</label>
                            <input type="text" id="last_name" class="form-control" value="<?php print($user->last_name); ?>">
                        </div>
                    </div>
                </div>
                <div class="form-group">
                    <label>Nickname:</label>
                    <input type="text" id="nickname" class="form-control" value="<?php print($user->nickname); ?>">
                </div>
                <div class="form-group">
                    <label>Email Address:</label>
                    <input type="text" id="email" class="form-control" value="<?php print($user->email); ?>">
                </div>

                <div class="form-group">
                    <div class="row">
                        <div class="col-lg-6">
                            <label>Address:</label>
                            <input type="text" id="address_1" class="form-control" value="<?php print($user->address_1); ?>">
                        </div>
                        <div class="col-lg-6">
                            <label>Address 2:</label><br>
                            <input type="text" id="address_2" class="form-control" value="<?php print($user->address_2); ?>">
                        </div>
                    </div>
                </div>

                <div class="form-group">
                    <div class="row">
                        <div class="col-lg-4">
                            <label>City:</label>
                            <input type="text" id="city" class="form-control" value="<?php print($user->city); ?>">
                        </div>
                        <div class="col-lg-4">
                            <label>State:</label><br>
                            <input type="text" id="state" class="form-control" value="<?php print($user->state); ?>">
                        </div>
                        <div class="col-lg-4">
                            <label>Zip:</label><br>
                            <input type="text" id="zip" class="form-control" value="<?php print($user->zip); ?>">
                        </div>
                    </div>
                </div>

                <div class="form-group">
                    <div class="row">
                        <div class="col-lg-4">
                            <label>Phone Number:</label>
                            <input type="text" id="phone" class="form-control" value="<?php print($user->phone); ?>">
                        </div>
                        <div class="col-lg-4">
                            <label>Gender:</label><br>
                            <input type="radio" id="gender" name="gender" value="F" class="form-control-inline">&nbsp;&nbsp;Female&nbsp;&nbsp;
                            <input type="radio" id="gender" name="gender" value="M" class="form-control-inline">&nbsp;&nbsp;Male
                        </div>
                        <div class="col-lg-4">
                            <label>Date of Birth:</label><br>
                            <select id="dob_month" class="form-control-inline"></select>
                            <select id="dob_day" class="form-control-inline"></select>
                            <select id="dob_year" class="form-control-inline"></select>
                        </div>
                    </div>
                </div>
            </div>
            <div class="col-lg-6 col-md-6">
                <style>
                    .platform_holder{width:100%; border:1px solid #d7d7d7; border-radius:10px; margin:10px; padding:20px;}
                </style>
                <div class="row">
                    <div class="col-lg-12">
                        <div class="form-group">
                            <label>Profile Image:</label>
                            <div><?php print($avatar); ?>'</div>
                        </div>
                    </div>
                    <div class="col-lg-12">
                        <div class="form-group">
                            <label>Platforms connected:</label>
                            <div class="row"><?php print($platforms); ?></div>
                        </div>
                    </div>
                </div>
            </div>
        </div>
    </div>
    <div class="ibox-footer"><?php print($page_footer); ?></div>
</div>
