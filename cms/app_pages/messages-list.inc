<?php
    // setup page header
    $page_header = $page_obj->setupPageHeader("Messages", "play", null, null, null, null, null);

    // get messages
    require_once "app_objects/messages.inc";
    $messages_obj = new obj_messages();
    $messages = $messages_obj->getListing();
    $message_list = "";
    $row_1 = true;
    for ($m = 0; $m < count($messages); $m++)
    {
        // change rows
        if ($row_1) { $row_1 = false; $row_color = "message_row_1"; }
        else { $row_1 = true; $row_color = "message_row_2"; }

        // determine from status
        if ($messages[$m]->from_user == "1") { $name = "YOU "; }
        else { $name = "[CLIENT] "; }

        // add audi/video icons?
        $message = $messages[$m]->text;
        if ($messages[$m]->audio_id > "0")
        {
            $message .= '<i class="fa fa-play" data-type="audio" data-id="' . $messages[$m]->audio_id . '"></i>';
        }
        else if ($messages[$m]->video_id > "0")
        {
            $message .= '<i class="fa fa-play" data-type="video" data-id="' . $messages[$m]->video_id . '"></i>';
        }

        $date = date_create($messages[$m]->dt_sent);
        $date_str = "Sent at " . date_format($date, 'H:i a');
        $date_str .= " on " . date_format($date, 'M, d Y');

        $message_list .= '<div class="message_row ' . $row_color . '">
            <div><strong>' . $name . ':</strong> ' . $message . '</div>
            <div class="message_info">' . $date_str . '</div>
        </div>';
    }
?>
<style>
    .message_holder{padding:10px;}
    .message_holder_content{border:1px solid #d7d7d7; border-radius:10px;  overflow:hidden;}
    .message_name{background-color:#c7c7c7; color:#fff; overflow:hidden; padding:10px; text-align:center; font-size:20px;}
    .message_profile_holder{padding:10px; font-size:18px; }
    .message_info{font-size:12px;}
    .message_control_item{padding:20px; border:1px solid #d7d7d7; border-radius:10px; cursor:pointer;}
    .message_row{margin-bottom:15px; padding:10px;}
    .message_row_1{background-color:#fff;}
    .message_row_2{background-color:#e7e7e7;}
</style>

<div class="ibox">
    <div class="ibox-title"><?php print($page_header); ?></div>
    <div class="ibox-content">
        <h2 style="text-align:center; margin:25px 0px 25px 0px;">On this page you can view and send messages.</h2>


        <div class="row">
            <div class="col-lg-4 message_holder">
                <div class="message_holder_content shadow">
                    <div class="message_name">Send a Text Message</div>
                    <div class="message_profile_holder">
                        <textarea class="form-control" style="height:200px;" placeholder="Enter your message"></textarea>
                        <div class="text-right" style="padding-top:20px;">
                            <button class="btn btn-xs btn-primary"><i class="fa fa-reply"></i> Send now</button>
                        </div>
                    </div>
                </div>

                <div><br></div>

                <div class="message_holder_content shadow">
                    <div class="message_name">Record an Audio Message</div>
                    <div class="message_profile_holder">
                        <div class="row">
                            <div class="col-lg-4 col-md-4 col-sm-4 col-xs-4">
                                <i class="fa fa-pause fa-3x message_control_item"></i>
                            </div>
                            <div class="col-lg-4 col-md-4 col-sm-4 col-xs-4">
                                <i class="fa fa-stop fa-3x message_control_item"></i>
                            </div>
                            <div class="col-lg-4 col-md-4 col-sm-4 col-xs-4">
                                <i class="fa fa-play fa-3x message_control_item"></i>
                            </div>
                        </div>
                        <div class="text-right" style="padding-top:20px;">
                            <button class="btn btn-xs btn-primary"><i class="fa fa-reply"></i> Send now</button>
                        </div>
                    </div>
                </div>

                <div><br></div>

                <div class="message_holder_content shadow">
                    <div class="message_name">Record a Video Message</div>
                    <div class="message_profile_holder">
                        <div class="row">
                            <div class="col-lg-4 col-md-4 col-sm-4 col-xs-4">
                                <i class="fa fa-pause fa-3x message_control_item"></i>
                            </div>
                            <div class="col-lg-4 col-md-4 col-sm-4 col-xs-4">
                                <i class="fa fa-stop fa-3x message_control_item"></i>
                            </div>
                            <div class="col-lg-4 col-md-4 col-sm-4 col-xs-4">
                                <i class="fa fa-play fa-3x message_control_item"></i>
                            </div>
                        </div>
                        <div class="text-right" style="padding-top:20px;">
                            <button class="btn btn-xs btn-primary"><i class="fa fa-reply"></i> Send now</button>
                        </div>
                    </div>
                </div>
            </div>

            <div class="col-lg-8 message_holder">
                <div class="message_holder_content shadow">
                    <div class="message_name">Message History</div>
                    <div class="message_profile_holder">
                        <?php print($message_list); ?>
<!--
                        <div><strong>YOU:</strong> Hi Grandma! Just wanted to say I love You!</div>
                        <div class="message_info">Sent at April 28, 2017 @ 8:00am</div>
                        <div><br></div>

                        <div><strong>MARY:</strong> Thank you sweetie. I love you too.</div>
                        <div class="message_info">Sent at April 28, 2017 @ 8:25am</div>
                        <div><br></div>

                        <div><strong>YOU:</strong> Audio message <i class="fa fa-play"></i></div>
                        <div class="message_info">Sent at April 28, 2017 @ 8:30am</div>
                        <div><br></div>

                        <div><strong>YOU:</strong> Video message <i class="fa fa-play"></i></div>
                        <div class="message_info">Sent at April 28, 2017 @ 9:14am</div>
                        <div><br></div>
-->
                    </div>
                </div>
            </div>
        </div>
    </div>
</div>
