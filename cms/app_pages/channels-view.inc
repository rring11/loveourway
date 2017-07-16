<?php
    // setup page header
    $page_header = $page_obj->setupPageHeader("Channels - View channel", "share-alt", "/channels/list", null, null, null, null);
    $page_footer = "";

    require_once "app_objects/channels.inc";
    $channels_obj = new obj_channels();
    $channel = $channels_obj->getItem( $page_data[3] );

    // get channel content
    $content = $channels_obj->getChannelContent( $channel->channel_id) ;
    print("<script>var content = " . json_encode($content) . ";</script>");
?>
<div class="ibox">
    <div class="ibox-title"><?php print($page_header); ?></div>
    <div class="ibox-content">
        <h2 style="text-align:center; margin:25px 0px 25px 0px;">Viewing channel "<?php print($channel->name); ?>"</h2>
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
