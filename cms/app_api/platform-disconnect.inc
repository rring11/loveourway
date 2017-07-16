<?php
    if ($api_name == "platform-disconnect")
    {
//        $request_data = $_POST['request'];
//        $req = json_decode($request_data);
//        $platform = $GLOBALS['db']->filterString($req->platform);

        $platform = $_POST['platform'];

        require_once "app_objects/socialmedia.inc";
        $socialmedia_obj = new obj_socialmedia();

        // clear the session
        $socialmedia_obj->disconnectFromChannel($platform);

        // setup return
        $code = "0";
        $data = "";
        $message = "Success";
        return;
    }
?>