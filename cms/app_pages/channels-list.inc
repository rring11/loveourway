<?php
    // setup page header
    $page_header = $page_obj->setupPageHeader("Channels", "share-alt", null, null, null, null, null);

    // get channels
    require_once "app_objects/channels.inc";
    $channels_obj = new obj_channels();
    $channels = $channels_obj->getListing();

    $channel_list = "";
    for ($c = 0; $c < count($channels); $c++)
    {
        $channel = $channels[$c];
        $platforms = "";
        for ($p = 0; $p < count($channel->platforms); $p++)
        {
            if ($channel->platforms[$p] == "Facebook") { $platforms .= '<i class="fa fa-facebook channel_option_platform"></i>'; }
            else if ($channel->platforms[$p] == "Pinterest") { $platforms .= '<i class="fa fa-pinterest channel_option_platform"></i>'; }
            else if ($channel->platforms[$p] == "Dropbox") { $platforms .= '<i class="fa fa-dropbox channel_option_platform"></i>'; }
            else if ($channel->platforms[$p] == "YouTube") { $platforms .= '<i class="fa fa-youtube channel_option_platform"></i>'; }
            else if ($channel->platforms[$p] == "Twitter") { $platforms .= '<i class="fa fa-twitter channel_option_platform"></i>'; }
        }

        if ($channel->image == "0") { $cover = '<i class="fa fa-image" style="font-size:128px;"></i>'; }
        else { $cover = '<img src="/imgs/content/' . $channel->image . '" style="max-width:100%; max-height:100%;">'; }

        $channel_list .= '<div class="col-lg-3 col-md-4 channel_holder">
                <div class="channel_holder_content shadow">
                    <div class="channel_name">' . $channel->name . '</div>
                    <div class="channel_profile_holder">
                        <div class="channel_profile">' . $cover . '</div>
                    </div>
                    <div class="channel_options">
                        <div class="row">
                            <div class="col-lg-5 pull-left text-left">
                            ' . $platforms . '
                            </div>
                            <div class="col-lg-7 pull-right text-right">
                                <i class="fa fa-eye channel_option_item" data-option="view" data-id="' . $channel->channel_id . '"></i>
                                <i class="fa fa-pencil channel_option_item" data-option="edit" data-id="' . $channel->channel_id . '"></i>
                                <i class="fa fa-trash channel_option_item" data-option="delete" data-id="' . $channel->channel_id . '"></i>
                            </div>
                        </div>
                    </div>
                </div>
            </div>';
    }
?>
<style>
    .channel_holder{padding:10px;}
    .channel_new_holder_content{height:350px; background-color:#e7e7e7; border:1px solid #d7d7d7; border-radius:10px; text-align:center; overflow:hidden; cursor:pointer;}

    .channel_holder_content{height:350px; border:1px solid #d7d7d7; border-radius:10px;  overflow:hidden;}
    .channel_name{background-color:#c7c7c7; color:#fff; overflow:hidden; padding:10px; text-align:center; font-size:20px;}
    .channel_profile_holder{padding:0px; height:250px; text-align:center;}
    .channel_profile{ width:100%; height:200px; padding:5px; margin:0 auto;}
    .channel_options{background-color:#d7d7d7; color:#fff; overflow:hidden; padding:10px; text-align:center; }
    .channel_option_item{font-size:24px; margin:5px; cursor:pointer;}
    .channel_option_platform{font-size:20px; margin:5px;}
</style>

<div class="ibox">
    <div class="ibox-title"><?php print($page_header); ?></div>
    <div class="ibox-content">
        <h2 style="text-align:center; margin:25px 0px 25px 0px;">On this page you can manage your channels for sharing content.<br>New content
        is automatically added to a channel using simple hashtags.</h2>


        <div class="row">

            <div class="col-lg-3 col-md-4 channel_holder">
                <div class="channel_new_holder_content shadow">
                    <i class="fa fa-plus" style="margin-top:110px; font-size:128px;"></i><br>
                    Create a channel
                </div>
            </div>

            <?php print($channel_list); ?>
        </div>
    </div>
</div>
