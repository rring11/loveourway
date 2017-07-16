<?php
    $pd = "";

    require_once "app_objects/channels.inc";
    $channels_obj = new obj_channels();

    require_once "app_objects/socialmedia.inc";
    $socialmedia_obj = new obj_socialmedia();

    require_once "app_objects/platforms.inc";
    $platforms_obj = new obj_platforms();
    $platforms = $platforms_obj->getListing();

    // get channels
    $channels = $channels_obj->getListing();
    for ($c = 0; $c < count($channels); $c++)
    {
        $pd .= "Channel: " . $channels[$c]->name . "<br>";
        $pd .= "<ul>";
        $channel_platforms = $channels_obj->getChannelPlatforms($channels[$c]->channel_id);
        for ($cp = 0; $cp < count($channel_platforms); $cp++)
        {
            $pd .= "  Platform: " . $channel_platforms[$cp]->name . "<br>";

            if ($channel_platforms[$cp]->name == "Dropbox")
            {
                $pd .= "<ul>";
                $channel_platform_folders = $channels_obj->getChannelPlatformFolders($channel_platforms[$cp]->channel_platform_id);
                for ($cpf = 0; $cpf < count($channel_platform_folders); $cpf++)
                {
                    $pd .= "Folder: " . $channel_platform_folders[$cpf]->data_name . "<br>";
                    $pd .= "<ul>";
                    $pd .= "ID: " . $channel_platform_folders[$cpf]->data_id . "<br>";

                    $socialmedia_obj = new obj_socialmedia();
                    $socialmedia_obj->setupPlatform("Dropbox");
                    $channel_platform_folder_files = $socialmedia_obj->getDropboxFolderFiles($channel_platform_folders[$cpf]->data_name);
                    for ($cpff = 0; $cpff < count($channel_platform_folder_files); $cpff++)
                    {
                        $pd .= "COUNT: " . count($channel_platform_folder_files) . "<br>";
                        $pd .= "<ul>";
                        $pd .= "File: " . $channel_platform_folder_files[$cpff]->name . "<br>";
                        $pd .= "<ul>";
                        $pd .= "ID: " . $channel_platform_folder_files[$cpf]->id . "<br>";

                        // do we already have this file
                        $content_exists = $channels_obj->channelContentExists($channels[$c]->channel_id, $channel_platforms[$cp]->channel_platform_id, $channel_platform_folder_files[$cpff]->name);
                        $pd .= "EXISTS: " . $content_exists . "<br>";
                        if ($content_exists == 0)
                        {
                            // download file
                            $socialmedia_obj->getDropboxFile($channel_platform_folders[$cpf]->data_name . "/" . $channel_platform_folder_files[$cpff]->name, $channel_platform_folder_files[$cpff]->name);

                            // add channel_content record
                            $title = $channel_platform_folder_files[$cpff]->name;
                            $summary = $channel_platform_folder_files[$cpff]->name;
                            $channels_obj->createContentRecord($channels[$c]->channel_id, $channel_platforms[$cp]->channel_platform_id, $title, $summary, $channel_platform_folder_files[$cpff]->name);
                        }

                        $pd .= "</ul>";
                        $pd .= "</ul>";
                    }
                    $pd .= "</ul>";
                }
                $pd .= "</ul>";
            }
            else if ($channel_platforms[$cp]->name == "Pinterest")
            {
                $channel_platform_folders = $channels_obj->getChannelPlatformFolders($channel_platforms[$cp]->id);
                $pd .= "<ul>";
                $pd .= "NOT IMPLEMENTED<br>";
                $pd .= "</ul>";
            }
            if ($channel_platforms[$cp]->name == "Facebook")
            {
                $pd .= "<ul>";
                $pd .= "NOT IMPLEMENTED<br>";
                $pd .= "</ul>";
            }
            if ($channel_platforms[$cp]->name == "Instagram")
            {
                $pd .= "<ul>";
                $pd .= "NOT IMPLEMENTED<br>";
                $pd .= "</ul>";
            }
        }
        $pd .= "</ul>";
        $pd .= "<br>";
    }
?>
<div style="padding:20px;">
    <h3>LoveOurWay - Process Content Retrieval: BEGIN</h3>
    <br>
    <?php print($pd); ?>
    <h3>LoveOurWay - Process Content Retrieval: END</h3>
</div>
