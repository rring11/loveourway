<?php
    if ($api_name == "channel-create")
    {
        $request_data = $_POST['request'];
        $req = json_decode($request_data);

        $name = $GLOBALS['db']->filterString($req->name);
        $description = $GLOBALS['db']->filterString($req->description);

        require_once "app_objects/channels.inc";
        $channels_obj = new obj_channels();

        // add the channel
        $channel_id = $channels_obj->createChannel($name, $description);

        // process platforms
        for ($p = 0; $p < count($req->platforms); $p++)
        {
            $platform = $req->platforms[$p];
            $channel_platform_id = $channels_obj->addChannelPlatform($channel_id, $platform->id);

            // add hastags
            for ($h = 0; $h < count($platform->hashtags); $h++)
            {
                $hashtag = $platform->hashtags[$h];
                $channels_obj->addChannelPlatformHashtag($channel_platform_id, $hashtag->id);

            }

            // add folders
            for ($f = 0; $f < count($platform->folders); $f++)
            {
                $folder = $platform->folders[$f];
                $channels_obj->addChannelPlatformFolder($channel_platform_id, $folder->id, $folder->name);
            }
        }

        // setup return
        $code = "0";
        $data = "";
        $message = "Success";
        return;
    }
?>