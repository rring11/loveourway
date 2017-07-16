<?php
    // setup page header
    $page_header = $page_obj->setupPageHeader("Connections", "gears", null, null, null, null, null);

    // get data
    require_once "app_objects/platforms.inc";
    $platforms_obj = new obj_platforms();
    $platforms = $platforms_obj->getListing();

    $platform_list = "";
    for ($p = 0; $p < count($platforms); $p++)
    {
        // connected?
        if ($platforms[$p]->connected == "1")
        {
            $color = $platforms[$p]->color;
            $connected = '<span style="color:' . $color . ';"><i class="fa fa-check"></i>&nbsp;Connected</span>';
            $connected = '<button class="btn btn-danger btn-xs channel_disconnect" data-platform="' . $platforms[$p]->name . '"><i class="fa fa-unlink"></i>&nbsp;Disconnect</button>';
        }
        else
        {
            $color = "#d7d7d7";
            $connected = '<button class="btn btn-primary btn-xs channel_connect" data-platform="' . $platforms[$p]->name . '"><i class="fa fa-link"></i>&nbsp;Connect</button>';
        }

        $platform_list .= '<div class="col-lg-3 col-md-4 col-sm-6 text-center">
                    <div class="platform_holder">
                        <div class="platform_holder_content shadow">
                            <div class="platform_title" style="background-color:' . $color . ';">' . $platforms[$p]->name . '</div>
                            <div class="platform_icon_holder" style="color:' . $color . ';"><i class="fa fa-' . $platforms[$p]->icon . ' fa-5x"></i></div>
                            <div class="platform_option_holder">' . $connected . '</div>
                        </div>
                    </div>
                </div>';
    }

?>
<style>
    .platform_holder{padding:0px; margin-bottom:15px;}
    .platform_holder_content{width:100%; border:1px solid #d7d7d7; border-radius:10px; margin:5px; padding:0px; overflow:hidden;}
    .platform_title{background-color:#c7c7c7; color:#fff; overflow:hidden; padding:10px; text-align:center; font-size:20px;}
    .platform_icon_holder{padding:20px;}
    .platform_option_holder{padding:10px; height:50px;}
</style>

<div class="ibox">
    <div class="ibox-title"><?php print($page_header); ?></div>
    <div class="ibox-content">
        <h2 style="text-align:center; margin:25px 0px 25px 0px;">On this page you can manage the social media platforms<br>that you want LoveOurWay to pull content from.</h2>
        <div class="row">
            <?php print($platform_list); ?>
        </div>
    </div>
</div>
