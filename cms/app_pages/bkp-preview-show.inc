<?php
    $albums = [];
    $albums[] = array("Ring Family",
        array("/imgs/sample-photo-2.png","/imgs/sample-photo-1.png")
    );
    $albums[] = array("Ring Vacation",
        array("/imgs/sample-photo-1.png","/imgs/sample-photo-2.png")
    );
    print("<script>var albums = " . json_encode($albums) . ";</script>");
?>
<style>
    .tablet_bg{position:absolute; top:0px; left:0px; width:600px;}
    #app_holder{position:absolute; top:58px; left:56px; width:488px; height:322px;  background-color: #c53574;}
    #app_preview{position:absolute; top:84px; left:160px; width:488px; height:322px; background-color:#c53574; display:none;}
    .tv_bg{position:absolute; top:450px; left:0px; width:600px;}

    #page_start{background-color:#fff;}
    .page_holder{background-color: #c53574; width:100%; height:100%; display:none;}
    .button_holder{background-color:#c53574; color:#fff; margin:10px 0px 10px 0px; font-size:18px; border-radius:10px;}
    .button_holder_white{background-color:#FFF; color:#c53574; margin:10px 0px 10px 0px; font-size:18px; border-radius:10px;}

    .album_title{background-color:#c53574; color:#fff; border:1px solid #fff; border-radius:10px; text-align:center; margin:0 auto; position:absolute; top:40px; left:110px;  width:200px; height:20px; }
    #page_album_contents{display:none; color:#fff;}

    #page_landing_icon{text-align:center; margin:0 auto; padding-top:25px;}
    #page_landing_content_holder{width:100%; height:200px; border:1px solid #e33ebc; border-radius:10px; margin:0 auto; text-align:center; color:#fff; padding:50px 10px 0px 10px;}
    .button_image{width:100%; cursor:pointer;}
    .button_image_large{width:80%; padding-top:140px; cursor:pointer;}
    .back_btn{position:absolute; top:280px; right:10px; font-size:12px;}
</style>
<div class="container">
    <div class="row">
        <div class="col-lg-12">
            <div style="position:relative; width:600px;">
                <div class="tablet_bg">
                    <img src="/imgs/tablet.png" style="max-width:100%;">
                    <div id="app_holder">
                        <div id="page_start">
                            <div style="text-align:center; padding-top:5px;">
                                <div style="color:#A154A1; font-size:32px; font-weight:bold;">Love Our Way</div>
                                <div><img src="/imgs/logo.png" style="width:200px;"></div>
                                <div style="margin-top:20px;"><h3>Sharing Memories is Ageless</h3></div>
                                <div class="btn button_holder btn_start">Press here to start</div>
                            </div>
                        </div>
                        <div id="page_landing" class="page_holder">
                            <div id="page_landing_icon">
                                <img src="/imgs/home-button.png" style="height:60px;">
                            </div>
                            <div class="row">
                                <div class="col-lg-1 col-md-1 col-sm-1 col-xs-1"></div>
                                <div class="col-lg-10 col-md-10 col-sm-10 col-xs-10">
                                    <div id="page_landing_content_holder">
                                        <div class="row">
                                            <div class="col-lg-3 col-md-3 col-sm-3 col-xs-3">
                                                <img src="/imgs/button.png" class="button_image btn_albums"><br>
                                                Albums
                                            </div>
                                            <div class="col-lg-3 col-md-3 col-sm-3 col-xs-3">
                                                <img src="/imgs/button.png" class="button_image btn_channels"><br>
                                                Channels
                                            </div>
                                            <div class="col-lg-3 col-md-3 col-sm-3 col-xs-3">
                                                <img src="/imgs/button.png" class="button_image btn_messages"><br>
                                                Messages
                                            </div>
                                            <div class="col-lg-3 col-md-3 col-sm-3 col-xs-3">
                                                <img src="/imgs/button.png" class="button_image btn_settings"><br>
                                                Settings
                                            </div>
                                        </div>
                                    </div>
                                </div>
                            </div>
                        </div>
                        <div id="page_albums" class="page_holder">
                            <div class="row">
                                <div class="col-lg-12">
                                    <div id="page_album_content_holder">
                                        <div class="row">
                                            <div class="col-lg-2 col-md-2 col-sm-2 col-xs-2 text-center">
                                                <img src="/imgs/left-arrow.png" class="button_image_large btn_albums_prev">
                                            </div>
                                            <div class="col-lg-8 col-md-8 col-sm-8 col-xs-8 text-center">
                                                <img src="/imgs/frame-bg.png" style="position:absolute; top:30px; left:0px; width:100%;">
                                                <div class="album_title" id="album_title" >Ring Family</div>
                                                <img src="/imgs/frame-img-holder-bg.png" style="position:absolute; top:80px; left:90px;  width:240px; height:170px;">
                                                <img src="/imgs/sample-photo-2.png" id="album_cover" style="position:absolute; top:90px; left:100px;  width:220px; height:150px; cursor:pointer;">
                                            </div>
                                            <div class="col-lg-2 col-md-2 col-sm-2 col-xs-2 text-center">
                                                <img src="/imgs/right-arrow.png" class="button_image_large btn_albums_next">
                                            </div>
                                        </div>
                                    </div>
                                    <div id="page_album_contents">
                                        [ALBUM CONTENTS]
                                    </div>
                                </div>
                                <div class="back_btn btn btn-xs button_holder_white btn_landing">GO BACK</div>
                            </div>
                        </div>
                        <div id="page_channels" class="page_holder">
                            <div>CHANNELS PAGE</div>
                            <div>[LIST OF CHANNELS]</div>
                            <div class="back_btn btn btn-xs button_holder_white btn_landing">GO BACK</div>
                        </div>
                        <div id="page_messages" class="page_holder">
                            <div>MESSAGES PAGE</div>
                            <div>[LIST OF MESSAGES]</div>
                            <div class="back_btn btn btn-xs button_holder_white btn_landing">GO BACK</div>
                        </div>
                        <div id="page_settings" class="page_holder">
                            <div>SETTINGS PAGE</div>
                            <div class="back_btn btn btn-xs button_holder_white btn_landing">GO BACK</div>
                        </div>
                    </div>
                </div>
            </div>
        </div>
    </div>
</div>