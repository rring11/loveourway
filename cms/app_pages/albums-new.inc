<?php
    // setup page header
    $page_header = $page_obj->setupPageHeader("Albums - Create a new album", "trophy", "/albums/list", null, null, null, null);
    $page_footer = $page_obj->setupPageFooter(
        array
        (
            array("color"=>"primary", "target"=>"createAlbum", "text"=>"Create Album", "icon"=>"save")
        )
    );

    // get themes
    require_once "app_objects/themes.inc";
    $themes_obj = new obj_themes();
    $themes = $themes_obj->getListing();
    $theme_list = "";
    for ($t = 0; $t < count($themes); $t++)
    {
        $theme_list .= '<div class="col-lg-2 text-center">
                <div class="theme_holder">
                    <div class="theme_holder_content">
                        <div class="theme_title">' . $themes[$t]->name . '</div>
                        <div class="theme_sample_holder">
                            <div style="height:60px;">
                            <img src="/imgs/' . $themes[$t]->cover_file . '" style="max-width;100%; max-height:100%;"></div>
                        </div>
                    </div>
                </div>
            </div>';
    }

    // get music
    require_once "app_objects/music.inc";
    $music_obj = new obj_music();
    $music = $music_obj->getListing();
    $music_list = "";
    for ($t = 0; $t < count($music); $t++)
    {
        $music_list .= '<div class="col-lg-2 text-center">
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

    print("<script>var album_id = 0; </script>");
?>
<style>
    .theme_holder{padding:0px;}
    .theme_holder_content{width:100%; border:1px solid #d7d7d7; border-radius:10px; margin:5px; padding:0px;}
    .theme_title{background-color:#c7c7c7; color:#fff; overflow:hidden; padding:10px; text-align:center; font-size:20px;}
    .theme_sample_holder{ margin:10px; border:1px solid #d7d7d7; padding:5px;}
    .lowytag{font-weight:bold; color:#ff0000;}

    .albums_holder{padding:10px;}
    .albums_new_holder_content{height:210px; background-color:#e7e7e7; border:1px solid #d7d7d7; border-radius:10px; text-align:center; overflow:hidden; cursor:pointer;}

    .albums_holder_content{height:210px; border:1px solid #d7d7d7; border-radius:10px;  overflow:hidden;}
    .albums_name{background-color:#c7c7c7; color:#fff; overflow:hidden; padding:10px; text-align:left; font-size:10px;}
    .albums_profile_holder{padding:0px; height:170px; text-align:center; overflow:hidden;}
    .albums_profile{ width:100%; height:170px; padding:5px; margin:0 auto;}
    .albums_options{background-color:#d7d7d7; color:#fff; overflow:hidden; padding:10px; text-align:center; }
    .albums_option_item{font-size:24px; margin:5px; cursor:pointer;}
    .albums_option_platform{font-size:24px; margin:5px;}
</style>
<div class="ibox">
    <div class="ibox-title"><?php print($page_header); ?></div>
    <div class="ibox-content">
        <h2 style="text-align:center; margin:25px 0px 25px 0px;">On this page you can create a new album.</h2>

        <div class="row">
            <div class="col-lg-12">
                <div class="ibox">
                    <div class="ibox-title"><h2><i class="fa fa-info"></i> Album Information</h2></div>
                    <div class="ibox-content">

                        <div class="row">
                            <div class="col-lg-6 col-md-6">
                                <div class="form-group">
                                    <label>Enter the name of the album:</label>
                                    <input type="text" id="fan_email" class="form-control">
                                </div>
                            </div>
                            <div class="col-lg-6 col-md-6">
                                <div class="form-group">
                                    <label>Enter a short description of the album:</label>
                                    <input type="text" id="fan_email" class="form-control">
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
                    <div class="ibox-title"><h2><i class="fa fa-info"></i> Theme</h2></div>
                    <div class="ibox-content">
                        <div class="form-group">
                            <label>Select a theme for this album:</label>
                            <div class="row">
                                <?php print($theme_list); ?>
                            </div>
                        </div>
                    </div>
                </div>
            </div>
            <div class="col-lg-12">
                <div class="ibox">
                    <div class="ibox-title"><h2><i class="fa fa-info"></i> Music</h2></div>
                    <div class="ibox-content">
                        <div class="form-group">
                            <label>Select music to play when viewing this album:</label>
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
                    <div class="ibox-title"><h2><i class="fa fa-heart"></i> Album Content</h2></div>
                    <div class="ibox-content">
                        <h2 style="text-align:center; margin:25px 0px 25px 0px;">Drag content to change the display order.</h2>

                        <div class="row">
                            <div class="col-lg-3 col-md-4 albums_holder">
                                <div class="albums_new_holder_content">
                                    <i class="fa fa-plus" style="margin-top:50px; font-size:96px;"></i><br>
                                    Add content
                                </div>
                            </div>

                        </div>
                    </div>
                </div>
            </div>
        </div>
    </div>
    <div class="ibox-footer"><?php print($page_footer); ?></div>
</div>
