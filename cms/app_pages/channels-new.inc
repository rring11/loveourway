<?php
    // setup page header
    $page_header = $page_obj->setupPageHeader("Channels - Create a new channel", "share-alt", "/channels/list", null, null, null, null);
    $page_footer = $page_obj->setupPageFooter(
        array
        (
            array("color"=>"primary", "target"=>"createChannel", "text"=>"Create Channel", "icon"=>"save")
        )
    );

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
        if ($platforms[$p]->connected == "1")
        {
            // get folder listing?
            if ($platforms[$p]->name == "Dropbox")
            {
                $dropbox_social_object = new obj_socialmedia();
                $dropbox_social_object->setupPlatform("Dropbox");
                $folder_list = '<br>' . $dropbox_social_object->getDropboxFolders($platforms[$p]->platform_id);
            }
            else if ($platforms[$p]->name == "Pinterest")
            {
                $pinterest_social_object = new obj_socialmedia();
                $pinterest_social_object->setupPlatform("Pinterest");
                $folder_list = '<br>' . $pinterest_social_object->getPinterestBoards($platforms[$p]->platform_id);
            }
            else
            {
                $folder_list = '';
            }

            // setup hastags
            $hastags = "";
            if ( ($platforms[$p]->name == "Facebook") || ($platforms[$p]->name == "Pinterest") || ($platforms[$p]->name == "Twitter") )
            {
                $hastags = '<div style="margin-top:20px;">
                    <label>Custom Hashtags</label>
                    <div class="row">
                        <div class="col-lg-3 col-md-3"><input type="text" class="form-control" value="" id="ht-' . $platforms[$p]->platform_id . '-1"></div>
                        <div class="col-lg-3 col-md-3"><input type="text" class="form-control" value="" id="ht-' . $platforms[$p]->platform_id . '-2"></div>
                        <div class="col-lg-3 col-md-3"><input type="text" class="form-control" value="" id="ht-' . $platforms[$p]->platform_id . '-3" ></div>
                        <div class="col-lg-3 col-md-3"><input type="text" class="form-control" value="" id="ht-' . $platforms[$p]->platform_id . '-4"></div>
                    </div>
                </div>';
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
                        ' . $hastags . '

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
        <h2 style="text-align:center; margin:25px 0px 25px 0px;">On this page you can create a new channel.</h2>
        <div class="row">
            <div class="col-lg-12">
                <div class="ibox">
                    <div class="ibox-title">
                        <h2><i class="fa fa-hashtag"></i> 1 - Channel Information</h2>
                    </div>
                    <div class="ibox-content">

                        <h3 style="margin-bottom:20px;">Enter the basic information about this channel.</h3>

                        <div class="row">
                            <div class="col-lg-6 col-md-6">
                                <div class="form-group">
                                    <label>Name of the channel:</label>
                                    <input type="text" id="name" class="form-control">
                                </div>
                            </div>
                            <div class="col-lg-6 col-md-6">
                                <div class="form-group">
                                    <label>Short description of the channel:</label>
                                    <input type="text" id="description" class="form-control">
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
                    <div class="ibox-title">
                       <h2> <i class="fa fa-hashtag"></i> 2 - Music Selection</h2>
                    </div>
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
