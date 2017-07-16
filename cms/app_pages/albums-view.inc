<?php
    // setup page header
    $page_header = $page_obj->setupPageHeader("Albums - View album", "trophy", "/albums/list", null, null, null, null);
    $page_footer = "";

    require_once "app_objects/albums.inc";
    $albums_obj = new obj_albums();
    $album = $albums_obj->getItem( $page_data[3] );

    // get channel content
    $content = $albums_obj->getAlbumContent( $album->album_id) ;
    print("<script>var content = " . json_encode($content) . ";</script>");

?>
<div class="ibox">
    <div class="ibox-title"><?php print($page_header); ?></div>
    <div class="ibox-content">
        <h2 style="text-align:center; margin:25px 0px 25px 0px;">Viewing album "<?php print($album->name); ?>"</h2>
        <div class="row">
            <div class="col-lg-12">
                <div class="row">
                    <div class="col-lg-6 col-lg-offset-3">
                        <div id="content_title" style="text-align:center; margin-top:10px;  margin-bottom:15px; padding:5px; font-size:16px; font-weight:bold;  border-radius:10px; border:1px solid #fff; color:#fff; background-color:#c53574"></div>
                        <div><img id="content_image" src="" style="width:100%;"></div>
                    </div>
                </div>
                <div>
                </div>
            </div>
        </div>
        <div><br></div>
        <div class="row">
            <div class="col-lg-2 col-lg-offset-4 text-center">
                <div id="pause_content" style="border:1px solid #fff; background-color:#c53574; border-radius:10px; color:#fff; padding:10px; cursor:pointer;"><i class="fa fa-pause fa-2x"></i></div>
            </div>
            <div class="col-lg-2 text-center">
                <div id="play_content" style="border:1px solid #fff; background-color:#c53574; border-radius:10px; color:#fff; padding:10px; cursor:pointer;"><i class="fa fa-play fa-2x"></i></div>
            </div>
        </div>
    </div>
</div>
