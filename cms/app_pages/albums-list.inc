<?php
    // setup page header
    $page_header = $page_obj->setupPageHeader("Albums", "trophy", null, null, null, null, null);

    // get users
    require_once "app_objects/albums.inc";
    $albums_obj = new obj_albums();
    $albums = $albums_obj->getListing();

    $album_list = "";
    for ($a = 0; $a < count($albums); $a++)
    {
        $album = $albums[$a];

        if ($album->image == "0") { $cover = '<i class="fa fa-image" style="font-size:128px;"></i>'; }
        else { $cover = '<img src="/imgs/content/' . $album->image . '" style="max-width:100%; max-height:100%;">'; }

        $album_list .= '<div class="col-lg-3 col-md-4 albums_holder">
            <div class="albums_holder_content shadow">
                <div class="albums_name">' . $album->name . '</div>
                <div class="albums_profile_holder">
                    <div class="albums_profile">' . $cover . '</div>
                </div>
                <div class="albums_options">
                    <div class="row">
                        <div class="col-lg-5 pull-left text-left">
                            <div class="albums_info">' . $album->items . ' items</div>
                        </div>
                        <div class="col-lg-7 pull-right text-right">
                            <i class="fa fa-eye albums_option_item" data-option="view" data-id="' . $album->album_id . '"></i>
                            <i class="fa fa-pencil albums_option_item" data-option="edit" data-id="' . $album->album_id . '"></i>
                            <i class="fa fa-trash albums_option_item" data-option="delete" data-id="' . $album->album_id . '"></i>
                        </div>
                    </div>
                </div>
            </div>
        </div>';
    }
?>

<style>
    .albums_holder{padding:10px;}
    .albums_new_holder_content{height:350px; background-color:#e7e7e7; border:1px solid #d7d7d7; border-radius:10px; text-align:center; overflow:hidden; cursor:pointer;}

    .albums_holder_content{height:350px; border:1px solid #d7d7d7; border-radius:10px;  overflow:hidden;}
    .albums_name{background-color:#c7c7c7; color:#fff; overflow:hidden; padding:10px; text-align:center; font-size:20px;}
    .albums_profile_holder{padding:0px; height:250px; text-align:center;}
    .albums_profile{ width:100%; height:200px; padding:5px; margin:0 auto;}
    .albums_options{background-color:#d7d7d7; color:#fff; overflow:hidden; padding:10px; text-align:center; }
    .albums_option_item{font-size:24px; margin:5px; cursor:pointer;}
    .albums_option_platform{font-size:24px; margin:5px;}
    .albums_info{font-size:16px; line-height:1.2em;}
</style>

<div class="ibox">
    <div class="ibox-title"><?php print($page_header); ?></div>
    <div class="ibox-content">
        <h2 style="text-align:center; margin:25px 0px 25px 0px;">On this page you can manage albums.<br>Albums are collections of content chosen from Channels.</h2>


        <div class="row">

            <div class="col-lg-3 col-md-4 albums_holder">
                <div class="albums_new_holder_content shadow">
                    <i class="fa fa-plus" style="margin-top:110px; font-size:128px;"></i><br>
                    Create an album
                </div>
            </div>

            <?php print($album_list); ?>
        </div>
    </div>
</div>
