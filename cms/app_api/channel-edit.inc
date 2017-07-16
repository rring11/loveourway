<?php
    if ($api_name == "channel-edit")
    {
        $request_data = $_POST['request'];
        $req = json_decode($request_data);

        $channel_id = $GLOBALS['db']->filterString($req->channel_id);
        $name = $GLOBALS['db']->filterString($req->name);
        $description = $GLOBALS['db']->filterString($req->description);

        require_once "app_objects/channels.inc";
        $channels_obj = new obj_channels();

        // update the channel
        $channels_obj->updateChannel($channel_id, $name, $description);

        // process platforms
        $used_platform_ids = [];
        $used_hashtag_ids = [];
        $used_folder_ids = [];
        for ($p = 0; $p < count($req->platforms); $p++)
        {
            // add/update platforms
            $platform = $req->platforms[$p];
            $channel_platform_id = $channels_obj->updateChannelPlatform($channel_id, $platform->id);
            $used_platform_ids[] = $channel_platform_id;

            // add/update hastags
            for ($h = 0; $h < count($platform->hashtags); $h++)
            {
                $hashtag = $platform->hashtags[$h];
                $channel_platform_hashtag_id = $channels_obj->updateChannelPlatformHashtag($channel_platform_id, $hashtag->id);
                $used_hashtag_ids[] = $channel_platform_hashtag_id;
            }

            // add/update folders
            for ($f = 0; $f < count($platform->folders); $f++)
            {
                $folder = $platform->folders[$f];
                $channel_platform_folder_id = $channels_obj->updateChannelPlatformFolder($channel_platform_id, $folder->id, $folder->name);
                $used_folder_ids[] = $channel_platform_folder_id;
            }

            // clear unused hastags
            $channels_obj->clearUnusedPlatformHashtags($channel_platform_id, $used_hashtag_ids);

            // clear unused folders
            $channels_obj->clearUnusedPlatformFolders($channel_platform_id, $used_folder_ids);

            // clear unused platforms
            $channels_obj->clearUnusedPlatforms($channel_id, $used_platform_ids);
        }

        // setup return
        $code = "0";
        $data = "";
        $message = "Success";
        return;
    }
?>