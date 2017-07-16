<?php
    // get channels
    $channel_data = "";
    $album_data = "";

    print('<script>var channel_contents = [];</script>');
    print('<script>var album_contents = [];</script>');

    // channels
    require_once "app_objects/channels.inc";
    $channels_obj = new obj_channels();
    $channels = $channels_obj->getListing();
    for ($c = 0; $c < count($channels); $c++)
    {
        if ($c == 0) { $channel_style = ""; }
        else {  $channel_style = "display:none;"; }
        $channel_data .= '
        <div id="channel_' . ($c+1) . '" class="content_holder" style="height:100%; ' . $channel_style . '">
            <div style="height:10%;">
                <div class="row" style="margin-top:5%;">
                    <div class="col-lg-12 col-md-12 col-sm-12 col-xs-12 text-center">
                        <div class="album_title" style="width:100%; font-size:2vw; padding:2%; ">The "' . $channels[$c]->name . '" channel</div>
                    </div>
                </div>
            </div>

            <div style="height:60%; margin-top:5%;">
                <div class="text-center" style="height:50%;">
                    <img src="/imgs/content/' . $channels[$c]->image . '" class="album_cover" style="max-height:300px;">
                </div>
                <div class="" style="height:60%;">
                    <div style="width:100%; font-size:24px; text-align:left;">
                        ' . $channels[$c]->description . '
                    </div>
                </div>
            </div>

            <div style="height:10%; margin-top:5%;">
                <div class="album_title btn_channel_view" style="font-size:24px; margin-top:100px; cursor:pointer;" data-id="' . ($c+1) . '">Tap to Watch Now</div>
            </div>
        </div>';

        // get the channel content
        $content = [];
        $channel_content = $channels_obj->getChannelContent($channels[$c]->channel_id);
        for ($cc = 0; $cc < count($channel_content); $cc++)
        {
            $content_obj = new stdClass();
            $content_obj->image = "/imgs/content/" . $channel_content[$cc]->image;
            $content_obj->caption = $channel_content[$cc]->title;
            $content[] = $content_obj;
        }
        print('<script>channel_contents.push(' . json_encode($content). ');</script>');
    }
    print('<script>var total_channels = ' . count($channels) . ';</script>');


    // albums
    require_once "app_objects/albums.inc";
    $albums_obj = new obj_albums();
    $albums = $albums_obj->getListing();
//print_r($albums);
    for ($a = 0; $a < count($albums); $a++)
    {
        if ($a == 0) { $album_style = ""; }
        else {  $album_style = "display:none;"; }

        // get the channel content
        $content = [];
        $album_content = $albums_obj->getAlbumContent($albums[$a]->album_id);
        for ($ac = 0; $ac < count($album_content); $ac++)
        {
            $content_obj = new stdClass();
            $content_obj->image = "/imgs/content/" . $album_content[$ac]->image;
            $content_obj->caption = $album_content[$ac]->title;
            $content[] = $content_obj;
        }
        $total_album_content = count($album_content);
        print('<script>album_contents.push(' . json_encode($content). ');</script>');

        // setup album
        $album_data .= '
            <div id="album_' . ($a+1) . '" class="content_holder" style="height:100%; ' . $album_style . '">
                <div class="album_title" style="position:absolute; top:6%; left:7%; width:85%; font-size:3vw; padding:2% ">' . $albums[$a]->name . '</div>
                <img src="/imgs/frame-bg.png" style="position:absolute; top:22%; left:7%; max-width:100%; max-height:400px;">
                <img src="/imgs/frame-img-holder-bg.png" style="position:absolute; top:32%; left:28%; width:62%; height:42%;">
                <img src="/imgs/content/sample-photo-2.jpg" class="album_cover" style="position:absolute; top:34%; left:30%; max-width:58%; max-height:44%; cursor:pointer;">
                <div style="position:absolute; bottom:10%; width:100%; font-size:2vw;">' . $total_album_content . ' pictures</div>                
            </div>';
    }
    print('<script>var total_albums = ' . count($albums) . ';</script>');
?>

<style>
    .page_holder{background-color: #e53b4a; width:100%; height:100%; display:none;}

    .button_holder{background-color:#e53b4c; color:#fff; margin:10px 0px 10px 0px; font-size:18px; border-radius:20px;}
    .button_holder_white{background-color:#FFF; color:#e53b4c; margin:10px 0px 10px 0px; font-size:18px; border-radius:10px;}
    .button_image{width:90%; cursor:pointer;}
    .button_image_large{width:80%; cursor:pointer;}
    .back_btn{position:absolute; top:20px; right:20px; font-size:12px;}

    #page_start{background-color:#fff; height:100%;}

    .page_title_icon{text-align:center; margin:0 auto; padding-top:15px;}
    .page_content_holder{width:90%; height:85%; margin-left:5%; margin-right:5%; background-color:#d42f43;  border:1px solid #e58fbd; border-radius:2%; text-align:center; color:#fff; padding:0px;}

    .album_title{background-color:#c53574; color:#fff; border:1px solid #fff; border-radius:10px; text-align:center; font-size:18px; }
    #page_album_contents{display:none; width:90%; height:80%; margin-left:5%; margin-right:5%; text-align:center; color:#fff; padding:0px;}
    #page_album_content_holder{height:100%;}

    #page_channel_content_holder{height:100%;}
    #page_channel_contents{display:none; width:90%; height:80%; margin-left:5%; margin-right:5%; text-align:center; color:#fff; padding:0px;}
    #page_channel_content_holder{height:100%; background-color:#d42f43;}
</style>
<div style="position:relative; width:100%; height:100%; background-color:#e53b4a; border:1px solid #c0c0c0;">
    <div id="page_start">
        <div style="height:20%;"></div>
        <div style="height:70%;" class="text-center">
            <div class="btn_start"><img src="/imgs/homepage_logo.png" style="cursor:pointer; max-height:50%; max-width:40%;"></div>
            <div class="btn button_holder " style="margin-top:30px; padding-left:60px; padding-right:60px;">Tap the Heart to Begin</div>
        </div>
        <div style="height:10%;"></div>
    </div>

    <div id="page_landing" class="page_holder">
        <div class="page_title_icon"><img src="/imgs/home-button.png" style="height:60px;"></div>
        <div class="page_content_holder">
            <div style="height:15%;">
                <div style="font-size:3vw; padding-top:2%;">We Love You, Nana!</div>
            </div>
            <div style="height:75%; padding-top:5%;">
                <div class="row">
                    <div class="col-lg-1 col-md-1 col-sm-1-hidden col-xs-1-hidden"></div>
                    <div class="col-lg-5 col-md-5 col-sm-12 col-xs-12"><img src="/imgs/Albums.png" class="button_image btn_albums"></div>
                    <div class="col-lg-5 col-md-5 col-sm-12 col-xs-12"><img src="/imgs/Channels.png" class="button_image btn_channels" style="margin-top:20px;"></div>
                    <div class="col-lg-1 col-md-1 col-sm-1-hidden col-xs-1-hidden"></div>
                </div>
            </div>
            <div style="height:25%;">
                <div class="row">
                    <div class="col-lg-3 col-md-3 col-sm-3 col-xs-3"></div>
                    <div class="col-lg-6 col-md-6 col-sm-6 col-xs-6"><img src="/imgs/special_messages.png" class="button_image btn_messages"></div>
                    <div class="col-lg-3 col-md-3 col-sm-3 col-xs-3"></div>
                </div>
            </div>
        </div>
    </div>


    <div id="page_albums" class="page_holder">
        <div class="page_title_icon"><img src="/imgs/home-button.png" style="height:60px;"></div>
        <div id="album_title" style="position:absolute; top:40px; left:60px; color:#fff; font-size:22px;">Jenkins Family Albums</div>
        <div class="page_content_holder">
            <div id="page_album_content_holder">
                <div class="row" style="height:100%;">
                    <div class="col-lg-2 col-md-2 col-sm-2 col-xs-2 text-center" style="height:100%;">
                        <div style="height:40%;">&nbsp;</div>
                        <div style="height:20%;"><img src="/imgs/left-arrow.png" class="button_image_large btn_albums_prev"></div>
                        <div style="height:40%;">&nbsp;</div>
                    </div>
                    <div class="col-lg-8 col-md-8 col-sm-8 col-xs-8 text-center" style="height:100%;">
                        <?php print($album_data); ?>
                    </div>
                    <div class="col-lg-2 col-md-2 col-sm-2 col-xs-2 text-center" style="height:100%;">
                        <div style="height:40%;">&nbsp;</div>
                        <div style="height:20%;"><img src="/imgs/right-arrow.png" class="button_image_large btn_albums_next"></div>
                        <div style="height:40%;">&nbsp;</div>
                    </div>
                </div>
                <img src="/imgs/button_return.png" class="btn_back_channels btn_landing" style="position:absolute; bottom:3%; right:3%; width:8%; cursor:pointer;">
            </div>
            <div id="page_album_contents">
                <div style="position:absolute; top:10%; left:5%; width:90%; height:80%; overflow:hidden;">
                    <div style="width:100%; height:100%; overflow:hidden;">
                        <div id="album_content_image" style="width:100%; height:100%; border-radius:10px; background-size: cover; background-repeat:no-repeat; background-position: center; overflow:hidden;"></div>
                    </div>
                </div>
                <div id="album_content_title" class="album_title" style="position:absolute; bottom:5%; left:5%; width:90%; padding:1%; ">
                    [CAPTION]
                </div>
                <audio id="album_bg_music" >
                    <source src="/music/bensound-straight.mp3" controls="controls" loop="loop">
                </audio>
                <img src="/imgs/button_return.png" class="btn_back_channels btn_back_albums" style="position:absolute; bottom:3%; right:3%; width:8%; cursor:pointer;">
            </div>
        </div>
    </div>


    <div id="page_channels" class="page_holder">
        <div class="page_title_icon"><img src="/imgs/home-button.png" style="height:60px;"></div>
        <div id="album_title" style="position:absolute; top:40px; left:60px; color:#fff; font-size:22px;">Jenkins Family Channels</div>
        <div class="page_content_holder text-left">
            <div id="page_channel_content_holder">
                <div class="row" style="height:100%;">
                    <div class="col-lg-2 col-md-2 col-sm-2 col-xs-2 text-center" style="height:100%;">
                        <div style="height:40%;">&nbsp;</div>
                        <div style="height:20%;"><img src="/imgs/left-arrow.png" class="button_image_large btn_channels_prev"></div>
                    </div>
                    <div class="col-lg-8 col-md-8 col-sm-8 col-xs-8 text-center">
                        <?php print($channel_data); ?>
                    </div>
                    <div class="col-lg-2 col-md-2 col-sm-2 col-xs-2 text-center" style="height:100%;">
                        <div style="height:40%;">&nbsp;</div>
                        <div style="height:20%;"><img src="/imgs/right-arrow.png" class="button_image_large btn_channels_next"></div>
                    </div>
                </div>
                <img src="/imgs/button_return.png" class="btn_landing" style="position:absolute; bottom:3%; right:3%; width:8%; cursor:pointer;">
            </div>

            <div id="page_channel_contents">
                <div style="position:absolute; top:10%; left:5%; width:90%; height:80%; overflow:hidden;">
                    <div style="width:100%; height:100%; overflow:hidden;">
                        <div id="channel_content_image" style="width:100%; height:100%; border-radius:10px; background-size: cover; background-repeat:no-repeat; background-position: center; overflow:hidden;"></div>
                    </div>
                </div>
                <div id="channel_content_title" class="album_title" style="position:absolute; bottom:5%; left:5%; width:90%; padding:1%; ">
                    [CAPTION]
                </div>
                <audio id="channel_bg_music" >
                    <source src="/music/bensound-straight.mp3" controls="controls" loop="loop">
                </audio>
                <img src="/imgs/button_return.png" class="btn_back_channels btn_content_viewing" style="position:absolute; bottom:3%; right:3%; width:8%; cursor:pointer;">
            </div>
        </div>
    </div>


    <div id="page_messages" class="page_holder">
        <div class="page_title_icon"><img src="/imgs/home-button.png" style="height:60px;"></div>
        <div class="page_content_holder">
            <div>MESSAGES PAGE</div>
            <div>[LIST OF MESSAGES]</div>
            <div class="back_btn btn btn-xs button_holder_white btn_landing">GO BACK</div>
        </div>
    </div>

</div>
