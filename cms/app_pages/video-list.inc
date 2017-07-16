<?php
    // setup page header
    $page_header = $page_obj->setupPageHeader("Video Calls", "video-camera", null, null, null, null, null);

    // get videos
    require_once "app_objects/videos.inc";
    $videos_obj = new obj_videos();
    $videos = $videos_obj->getListing();

    $video_list = "";
    $video_list .= '<div class="col-lg-3 col-md-4 video_holder">
                <div class="video_new_holder_content shadow">
                    <i class="fa fa-plus" style="margin-top:110px; font-size:128px;"></i><br>
                    Start a call
                </div>
            </div>';

    for ($v = 0; $v < count($videos); $v++)
    {
        $video = $videos[$v];

        $video_list .= '<div class="col-lg-3 col-md-4 video_holder">
                <div class="video_holder_content shadow">
                <div class="video_date">' . $video->date . '</div>
                <div class="video_profile_holder">
                    <div class="video_profile"><i class="fa fa-play" style="font-size:128px;"></i></div>
                </div>
                <div class="video_options">
                    <div class="row">
                        <div class="col-lg-6 pull-left text-left">
                            <span class="video_option_text">' . $video->minutes . ' minutes<br>
                            ' . $video->users . ' users</span>
                        </div>
                        <div class="col-lg-6 pull-right text-right">
                            <i class="fa fa-eye video_option_item" data-option="call" data-id="' . $video->id . '"></i>
                            <i class="fa fa-trash video_option_item" data-option="delete" data-id="' . $video->id . '"></i>
                        </div>
                    </div>
                </div>
                </div>
            </div>';
    }

?>
<style>
    .video_holder{padding:10px;}
    .video_new_holder_content{height:350px; background-color:#e7e7e7; border:1px solid #d7d7d7; border-radius:10px; text-align:center; overflow:hidden; cursor:pointer;}

    .video_holder_content{height:350px; border:1px solid #d7d7d7; border-radius:10px;  overflow:hidden;}
    .video_date{background-color:#c7c7c7; color:#fff; overflow:hidden; padding:10px; text-align:center; font-size:16px; line-height:1em;}
    .video_profile_holder{padding:20px; height:255px; text-align:center;}
    .video_profile{ width:100%; height:200px; border:1px solid #d7d7d7; padding:20px; margin:0 auto;}
    .video_options{background-color:#d7d7d7; color:#fff; overflow:hidden; padding:10px; text-align:center; }
    .video_option_text{font-size:16px; line-height:1em;}
    .video_option_item{font-size:24px; margin:5px; cursor:pointer;}
</style>

<div class="ibox">
    <div class="ibox-title"><?php print($page_header); ?></div>
    <div class="ibox-content">
        <h2 style="text-align:center; margin:25px 0px 25px 0px;">On this page you can hold video calls and view recorded calls.</h2>
        <div class="row">
            <?php print($video_list); ?>
        </div>
    </div>
</div>
