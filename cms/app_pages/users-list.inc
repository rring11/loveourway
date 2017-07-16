<?php
    // setup page header
    $page_header = $page_obj->setupPageHeader("Users", "users", null, null, null, null, null);

    // get users
    require_once "app_objects/users.inc";
    $users_obj = new obj_users();
    $users = $users_obj->getListing();

    $user_list = "";

    for ($u = 0; $u < count($users); $u++)
    {
        $user = $users[$u];
        $platforms = "";
        for ($p = 0; $p < count($user->platforms); $p++)
        {
            if ($user->platforms[$p] == "Facebook") { $platforms .= '<i class="fa fa-facebook user_option_platform"></i>'; }
            else if ($user->platforms[$p] == "Pinterest") { $platforms .= '<i class="fa fa-pinterest user_option_platform"></i>'; }
            else if ($user->platforms[$p] == "Dropbox") { $platforms .= '<i class="fa fa-dropbox user_option_platform"></i>'; }
            else if ($user->platforms[$p] == "YouTube") { $platforms .= '<i class="fa fa-youtube user_option_platform"></i>'; }
        }

        if ($user->avatar == "") { $avatar = '<i class="fa fa-user" style="font-size:128px;"></i>'; }
        else { $avatar = '<img src="/imgs/users/' . $user->avatar . '" style="max-width:100%; max-height:100%;">'; }

        $delete = '<i class="fa fa-trash user_option_item" data-option="delete" data-id="' . $user->user_id . '"></i>';
        if ($user->is_admin) { $delete = "";}

        $user_list .= '<div class="col-lg-3 col-md-4 user_holder">
            <div class="user_holder_content shadow">
            <div class="user_name">' . $user->first_name . ' ' . $user->last_name . '</div>
            <div class="user_profile_holder">
                <div class="user_profile">' . $avatar . '</div>
            </div>
            <div class="user_options">
                <div class="row">
                    <div class="col-lg-6 pull-left text-left">' . $platforms . '</div>
                    <div class="col-lg-6 pull-right text-right">
                        <i class="fa fa-pencil user_option_item" data-option="edit" data-id="' . $user->user_id . '"></i>
                        ' . $delete . '
                    </div>
                </div>
            </div>
            </div>
        </div>';
    }
?>
<style>
    .user_holder{padding:10px;}
    .user_new_holder_content{height:350px; background-color:#e7e7e7; border:1px solid #d7d7d7; border-radius:10px; text-align:center; overflow:hidden; cursor:pointer;}

    .user_holder_content{height:350px; border:1px solid #d7d7d7; border-radius:10px;  overflow:hidden;}
    .user_name{background-color:#c7c7c7; color:#fff; overflow:hidden; padding:10px; text-align:center; font-size:20px;}
    .user_profile_holder{padding:20px; height:250px; text-align:center;}
    .user_profile{ width:100%; height:200px; border:1px solid #d7d7d7; padding:10px; margin:0 auto;}
    .user_options{background-color:#d7d7d7; color:#fff; overflow:hidden; padding:10px; text-align:center; }
    .user_option_item{font-size:24px; margin:5px; cursor:pointer;}
    .user_option_platform{font-size:24px; margin:5px;}
</style>

<div class="ibox">
    <div class="ibox-title"><?php print($page_header); ?></div>
    <div class="ibox-content">
        <h2 style="text-align:center; margin:25px 0px 25px 0px;">On this page you can manage the users who can share photos, videos, and send messages.</h2>

        <div class="row">
            <div class="col-lg-3 col-md-4 user_holder">
                <div class="user_new_holder_content shadow">
                    <i class="fa fa-plus" style="margin-top:110px; font-size:128px;"></i><br>
                    Add a user
                </div>
            </div>

            <?php print($user_list); ?>
        </div>
    </div>
</div>
