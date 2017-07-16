<?php
    if ($api_name == "albums-new-content")
    {
        $request_data = $_POST['request'];
        $req = json_decode($request_data);

        $album_id = $GLOBALS['db']->filterString($req->album_id);

        require_once "app_objects/albums.inc";
        $albums_obj = new obj_albums();
        $content = $albums_obj->getAlbumChannelContent(0, $album_id);

        require_once "app_objects/channels.inc";
        $channels_obj = new obj_channels();
        $channels = $channels_obj->getListing();

        // sort channels by user name
        usort($channels, function($a,$b)
        {
            if($a->user_name === $b->user_name) return 0;
            return ($a->user_name < $b->user_name) ? -1 : 1;
        });

        // setup return
        $code = "0";
        $data = '[{"content":' . json_encode($content) . ',"channels":' . json_encode($channels) . '}]';

        $message = "Success";
        return;
    }



?>