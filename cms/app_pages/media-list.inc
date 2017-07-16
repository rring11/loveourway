<?php
    // setup page header
    $page_header = $page_obj->setupPageHeader("Media Gallery", "image", null, null, null, null, null);

    // get channels
    require_once "app_objects/media.inc";
    $media_obj = new obj_media();
    $media = $media_obj->getListing();

    $media_list = "";
    for ($i = 0; $i < count($media); $i++)
    {
        $media_list .= '<div class="col-lg-3 col-md-4 media_holder">
                <div class="media_holder_content shadow">
                    <div class="media_name">' . $media[$i]->user_name . '</div>
                    <div class="media_profile_holder">
                        <div class="media_profile"><img src="/imgs/content/' . $media[$i]->image . '" style="max-width:100%; max-height:100%;"></div>
                    </div>
                    <div class="media_options">
                        <div class="row">
                            <div class="col-lg-7 pull-right text-right">
                                <i class="fa fa-trash media_option_item" data-option="delete" data-id="' . $media[$i]->channel_content_id . '"></i>
                            </div>
                        </div>
                    </div>
                </div>
            </div>';
    }
?>
<style>
    .media_holder{padding:10px;}
    .media_new_holder_content{height:250px; background-color:#e7e7e7; border:1px solid #d7d7d7; border-radius:10px; text-align:center; overflow:hidden; cursor:pointer;}

    .media_holder_content{height:250px; border:1px solid #d7d7d7; border-radius:10px;  overflow:hidden;}
    .media_name{background-color:#c7c7c7; color:#fff; overflow:hidden; padding:5px; text-align:center; font-size:20px;}
    .media_profile_holder{padding:0px; height:165px; text-align:center;}
    .media_profile{ width:100%; height:165px; padding:5px; margin:0 auto;}
    .media_options{background-color:#d7d7d7; color:#fff; overflow:hidden; padding:10px; text-align:center; }
    .media_option_item{font-size:24px; margin:5px; cursor:pointer;}
</style>

<div class="ibox">
    <div class="ibox-title"><?php print($page_header); ?></div>
    <div class="ibox-content">
        <h2 style="text-align:center; margin:25px 0px 25px 0px;">On this page you can manage the content added to LOWY.</h2>
        <div class="row">
            <div class="col-lg-3 col-md-4 media_holder">
                <div class="media_new_holder_content shadow">
                    <i class="fa fa-plus" style="margin-top:50px; font-size:128px;"></i><br>
                    Upload media
                </div>
            </div>
            <?php print($media_list); ?>
        </div>
    </div>
</div>
