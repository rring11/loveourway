<?php
    // setup page header
    $page_header = $page_obj->setupPageHeader("Channels - Edit channel", "share-alt", "/channels/list", null, null, null, null);
    $page_footer = $page_obj->setupPageFooter(
        array
        (
            array("color"=>"primary", "target"=>"updateChannel", "text"=>"Update Channel", "icon"=>"save")
        )
    );

    // get channel
    require_once "app_objects/channels.inc";
    $channels_obj = new obj_channels();
    $channel = $channels_obj->getItem( $page_data[3] );
    print("<script>var channel_id = " . $channel->channel_id . ";</script>");

    // get music
    require_once "app_objects/music.inc";
    $music_obj = new obj_music();
    $music = $music_obj->getListing();
    $music_list = "";
    for ($t = 0; $t < count($music); $t++)
    {
        $music_list .= '<div class="col-lg-2 col-md-3 col-sm-6 col-xs-6 text-center">
                <div class="theme_holder">
                    <div class="theme_holder_content">
                        <div class="theme_title">' . $music[$t]->name . '</div>
                        <div class="theme_sample_holder">
                            <div><i class="fa fa-play fa-4x"></i></div>
                        </div>
                    </div>
                </div>
            </div>';
    }

    require_once "app_objects/socialmedia.inc";

    // get platforms
    require_once "app_objects/platforms.inc";
    $platforms_obj = new obj_platforms();
    $platforms = $platforms_obj->getListing();
    $platform_list = "";
    for ($p = 0; $p < count($platforms); $p++)
    {
        // connected?
        $folder_list = "";
        $hashtags = "";

        if ($platforms[$p]->connected == "1")
        {
            $channel_platform_id = $channels_obj->getChannelPlatformID($channel->channel_id, $platforms[$p]->platform_id);


            // get folder listing?
            $folders = [];
            $channel_folders = $channels_obj->getChannelPlatformFolders($channel_platform_id);
            if ($platforms[$p]->name == "Dropbox")
            {
                $dropbox_social_object = new obj_socialmedia();
                $dropbox_social_object->setupPlatform("Dropbox");
                $folders = $dropbox_social_object->getDropboxFolders($platforms[$p]->platform_id);
            }
            else if ($platforms[$p]->name == "Pinterest")
            {
                $pinterest_social_object = new obj_socialmedia();
                $pinterest_social_object->setupPlatform("Pinterest");
                $folders = $pinterest_social_object->getPinterestBoards($platforms[$p]->platform_id);
            }
            if ( count($folders) > 0)
            {
                $folder_list = "<div><br><label>Available Folders</label></div>";
                for ($f = 0; $f < count($folders); $f++)
                {
                    $selected = "";
                    for ($cf = 0; $cf < count($channel_folders); $cf++)
                    {
                        if ($channel_folders[$cf]->data_id == $folders[$f]->id) { $selected = " checked "; }
                    }
                    $folder_list .= '<input type="checkbox" class="fldr-' . $platforms[$p]->platform_id .'" value="' . $folders[$f]->id. '" data-name="' . $folders[$f]->name . '" ' . $selected . '> ' . $folders[$f]->name . '<br>';
                }
            }

            // setup hastags
            if ( ($platforms[$p]->name == "Facebook") || ($platforms[$p]->name == "Pinterest") || ($platforms[$p]->name == "Twitter") )
            {
                // get platform hashtags
                $hashtags = '<div style="margin-top:20px;"><label>Custom Hashtags</label><div class="row">';
                $channel_hashtags = $channels_obj->getChannelPlatformHashtags($channel_platform_id);
                for ($h = 0; $h < count($channel_hashtags); $h++)
                {
                    $hashtags .= '<div class="col-lg-3 col-md-3"><input type="text" class="form-control" value="' . $channel_hashtags[$h]->hashtag . '" id="ht-' . $platforms[$p]->platform_id . '-' . ($h+1) . '"></div>';
                }
                for ($h = count($channel_hashtags); $h <= 3; $h++)
                {
                    $hashtags .= '<div class="col-lg-3 col-md-3"><input type="text" class="form-control" value="" id="ht-' . $platforms[$p]->platform_id . '-' . ($h+1) . '"></div>';
                }
                $hashtags .= '</div></div>';
            }

            // is configured?
            $configured = "";
            for ($cp = 0; $cp < count($channel->platforms); $cp++)
            {
                if ($channel->platforms[$cp] == $platforms[$p]->name)
                {
                    $configured = "checked";
                    break;
                }
            }

            $platform_list .= '<div class="col-lg-12">
                <div class="ibox">
                    <div class="ibox-title">
                        <div class="row">
                            <div class="col-lg-8">
                                <h2><i class="fa fa-' . $platforms[$p]->icon . '"></i> ' . $platforms[$p]->name . '</h2>
                            </div>
                            <div class="col-lg-4 text-right">
                                OFF&nbsp;&nbsp;<input type="checkbox" id="platforms_active" value="' . $platforms[$p]->platform_id . '" class="platform_active js-switch" ' . $configured . '/>&nbsp;&nbsp;ON
                            </div>
                        </div>
                    </div>
                    <div class="ibox-content">
                        <div class="font-bold">' . $platforms[$p]->share_title . '</div>
                        <div>' . $platforms[$p]->share_instructions . '</div>
                        ' . $folder_list . '
                        ' . $hashtags . '
                    </div>
                </div>
            </div>';
        }
    }
?>
<style>
    .theme_holder{padding:0px;}
    .theme_holder_content{width:100%; border:1px solid #d7d7d7; border-radius:10px; margin:5px; padding:0px;}
    .theme_title{background-color:#c7c7c7; color:#fff; overflow:hidden; padding:10px; text-align:center; font-size:20px;}
    .theme_sample_holder{ margin:10px; border:1px solid #d7d7d7; padding:5px;}
    .lowytag{font-weight:bold; color:#ff0000;}
</style>
<div class="ibox">
    <div class="ibox-title"><?php print($page_header); ?></div>
    <div class="ibox-content">

        <h2 style="text-align:center; margin:25px 0px 25px 0px;">On this page you can edit the channel.</h2>

        <div class="row">
            <div class="col-lg-12">
                <div class="ibox">
                    <div class="ibox-title"><h2><i class="fa fa-info"></i> Channel Information</h2></div>
                    <div class="ibox-content">

                        <div class="row">
                            <div class="col-lg-6 col-md-6">
                                <div class="form-group">
                                    <label>Enter the name of the channel:</label>
                                    <input type="text" id="name" class="form-control" value="<?php print($channel->name); ?>">
                                </div>
                            </div>
                        </div>
                        <div class="row">
                            <div class="col-lg-6 col-md-6">
                                <div class="form-group">
                                    <label>Enter a short description of the channel:</label>
                                    <textarea id="description" class="form-control"><?php print($channel->description); ?></textarea>
                                </div>
                            </div>
                        </div>
                    </div>
                </div>
            </div>
        </div>

        <div class="row">
            <div class="col-lg-12">
                <div class="ibox">
                    <div class="ibox-title"><h2><i class="fa fa-info"></i> Music Selection</h2></div>
                    <div class="ibox-content">
                        <div class="form-group">
                            <label>Select music to play when viewing this channel:</label>
                            <div class="row">
                                <div class="col-lg-2 col-md-3 col-sm-6 col-xs-12 text-center">
                                    <div class="theme_holder">
                                        <div class="theme_holder_content">
                                            <div class="theme_title">No music</div>
                                            <div class="theme_sample_holder">
                                                <div><i class="fa fa-times fa-4x"></i></div>
                                            </div>
                                        </div>
                                    </div>
                                </div>
                                <div class="col-lg-2 col-md-3 col-sm-6 col-xs-12 text-center">
                                    <div class="theme_holder">
                                        <div class="theme_holder_content">
                                            <div class="theme_title">Upload</div>
                                            <div class="theme_sample_holder">
                                                <div><i class="fa fa-upload fa-4x"></i></div>
                                            </div>
                                        </div>
                                    </div>
                                </div>
                                <?php print($music_list); ?>
                            </div>
                        </div>
                    </div>
                </div>
            </div>
        </div>

        <div class="row">
            <div class="col-lg-12">
                <div class="ibox">
                    <div class="ibox-title">
                        <h2> <i class="fa fa-hashtag"></i> 3 - Content to add to channel</h2>
                    </div>
                    <div class="ibox-content">
                        <div class="row">
                            <?php print($platform_list); ?>
                        </div>
                    </div>
                </div>
            </div>
        </div>

    </div>
    <div class="ibox-footer"><?php print($page_footer); ?></div>
</div>
