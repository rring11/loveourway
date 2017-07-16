<?php
class obj_channels
{
    var $listing = [];
    var $where_clause = "";
    //***********************************************
    //***********************************************
    function __construct()
    {
        $this->initListing();
    }
    //***********************************************
    //***********************************************
    function initListing()
    {
        $this->listing = [];

        $sql = "SELECT c.*, coalesce(cc.image,0) as image, u.first_name as user_name
            FROM channels c 
            LEFT JOIN channel_content cc ON cc.channel_content_id = c.cover_id
            LEFT JOIN users u ON u.user_id = c.user_id
             " . $this->where_clause . "
            ORDER BY c.dt_added DESC";
        $results = $GLOBALS['db']->getSQLResults($sql);
        for ($u = 0; $u < count($results); $u++)
        {
            $results[$u]->platforms = [];
            $platform_sql = "SELECT cp.*, p.name as platform_name
                FROM channel_platforms cp
                LEFT JOIN platforms p ON p.platform_id = cp.platform_id
                WHERE channel_id = '" . $results[$u]->channel_id . "'";
            $platform_results = $GLOBALS['db']->getSQLResults($platform_sql);
            for ($p = 0; $p < count($platform_results); $p++)
            {
                $results[$u]->platforms[] = $platform_results[$p]->platform_name;
                $results[$u]->platform_ids[] = $platform_results[$p]->channel_platform_id;
            }
            $this->listing[] = $results[$u];
        }
    }
    //***********************************************
    //***********************************************
    function getListing()
    {
        return $this->listing;
    }
    //***********************************************
    //***********************************************
    function getItem($item_id)
    {
        for ($i = 0; $i < count($this->listing); $i++)
        {
            if ( strval($this->listing[$i]->channel_id) == strval($item_id) )
            {
                return $this->listing[$i];
            }
        }
        return null;
    }
    //***********************************************
    //***********************************************
    function getChannelContent($channel_id)
    {
        $sql = "SELECT * FROM channel_content  WHERE channel_id = '" . $channel_id . "' ORDER BY channel_content_id DESC";
        return $GLOBALS['db']->getSQLResults($sql);
    }
    //***********************************************
    //***********************************************
    function createChannel($name, $description)
    {
        $sql = "INSERT INTO channels(client_id, user_id, name, description, theme_id, music_id, cover_id, dt_added)
          VALUES('" . $_SESSION['client_id'] . "','" . $_SESSION['user_id'] . "','" . $name . "','" . $description . "','0','0','0',now())";
        $results = $GLOBALS['db']->executeSQL($sql);
        return $GLOBALS['db']->getLastId();
    }
    //***********************************************
    //***********************************************
    function updateChannel($channel_id, $name, $description)
    {
        $sql = "UPDATE channels SET
            name = '" . $name . "',
            description = '" . $description . "'
            WHERE client_id = '" . $_SESSION['client_id'] . "'
            AND user_id = '" . $_SESSION['user_id'] . "'
            AND channel_id = '" . $channel_id . "'";
        $results = $GLOBALS['db']->executeSQL($sql);
    }
    //***********************************************
    //***********************************************
    function addChannelPlatform($channel_id, $platform_id)
    {
        $sql = "INSERT INTO channel_platforms(channel_id, platform_id)
          VALUES('" . $channel_id . "','" . $platform_id . "')";
        $results = $GLOBALS['db']->executeSQL($sql);
        return $GLOBALS['db']->getLastId();
    }
    //***********************************************
    //***********************************************
    function updateChannelPlatform($channel_id, $platform_id)
    {
        $sql = "SELECT channel_platform_id FROM channel_platforms WHERE channel_id = '" . $channel_id . "' AND platform_id = '" . $platform_id . "'";
        $result = $GLOBALS['db']->getSQLResults($sql);
        if ($result[0])
        {
            return $result[0]->channel_platform_id;
        }
        else
        {
            $sql = "INSERT INTO channel_platforms(channel_id, platform_id)
                VALUES('" . $channel_id . "','" . $platform_id . "')";
            $results = $GLOBALS['db']->executeSQL($sql);
            return $GLOBALS['db']->getLastId();
        }
    }
    //***********************************************
    //***********************************************
    function getChannelPlatformID($channel_id, $platform_id)
    {
        $sql = "SELECT channel_platform_id FROM channel_platforms WHERE channel_id = '" . $channel_id . "' AND platform_id = '" . $platform_id . "'";
        $result = $GLOBALS['db']->getSQLResults($sql);
        return $result[0]->channel_platform_id;
    }
    //***********************************************
    //***********************************************
    function getChannelPlatformHashtags($channel_platform_id)
    {
        $sql = "SELECT * FROM channel_platform_hashtags WHERE channel_platform_id = '" . $channel_platform_id . "'";
        return $GLOBALS['db']->getSQLResults($sql);
    }
    //***********************************************
    //***********************************************
    function addChannelPlatformHashtag($channel_platform_id, $hashtag)
    {
        $sql = "INSERT INTO channel_platform_hashtags(channel_platform_id, hashtag)
            VALUES('" . $channel_platform_id . "','" . $hashtag . "')";
        $results = $GLOBALS['db']->executeSQL($sql);
    }
    //***********************************************
    //***********************************************
    function updateChannelPlatformHashtag($channel_platform_id, $hashtag)
    {
        $sql = "SELECT channel_platform_hasttag_id FROM channel_platform_hashtags WHERE channel_platform_id = '" . $channel_platform_id . "' AND hashtag = '" . $hashtag . "'";
        $result = $GLOBALS['db']->getSQLResults($sql);
        if ($result[0])
        {
            return $result[0]->channel_platform_hasttag_id;
        }
        else
        {
            $sql = "INSERT INTO channel_platform_hashtags(channel_platform_id, hashtag)
                VALUES('" . $channel_platform_id . "','" . $hashtag . "')";
            $results = $GLOBALS['db']->executeSQL($sql);
            return $GLOBALS['db']->getLastId();
        }
    }
    //***********************************************
    //***********************************************
    function getChannelPlatforms($channel_id)
    {
        $sql = "SELECT cp.*, p.* 
          FROM channel_platforms cp
           LEFT JOIN platforms p ON p.platform_id = cp.platform_id
          WHERE cp.channel_id = '" . $channel_id . "'";
        return $GLOBALS['db']->getSQLResults($sql);
    }
    //***********************************************
    //***********************************************
    function getChannelPlatformFolders($channel_platform_id)
    {
        $sql = "SELECT * FROM channel_platform_data WHERE channel_platform_id = '" . $channel_platform_id . "'";
        return $GLOBALS['db']->getSQLResults($sql);
    }
    //***********************************************
    //***********************************************
    function addChannelPlatformFolder($channel_platform_id, $id, $name)
    {
        $sql = "INSERT INTO channel_platform_data(channel_platform_id, data_id, data_name)
            VALUES('" . $channel_platform_id . "','" . $id . "','" . $name . "')";
        $results = $GLOBALS['db']->executeSQL($sql);
    }
    //***********************************************
    //***********************************************
    function updateChannelPlatformFolder($channel_platform_id, $id, $name)
    {
        $sql = "SELECT channel_platform_data_id FROM channel_platform_data WHERE channel_platform_id = '" . $channel_platform_id . "' AND data_id = '" . $id . "'";
        $result = $GLOBALS['db']->getSQLResults($sql);
        if ($result[0])
        {
            return $result[0]->channel_platform_data_id;
        }
        else
        {
            $sql = "INSERT INTO channel_platform_data(channel_platform_id, data_id, data_name)
                VALUES('" . $channel_platform_id . "','" . $id . "','" . $name . "')";
            $results = $GLOBALS['db']->executeSQL($sql);
            return $GLOBALS['db']->getLastId();
        }
    }
    //***********************************************
    //***********************************************
    function clearUnusedPlatformHashtags($channel_platform_id, $list)
    {
        $ids = "";
        for ($i = 0; $i < count($list); $i++)
        {
            if ($i > 0) { $ids .= ","; }
            $ids .= $list[$i];
        }
        $sql = "DELETE FROM channel_platform_hashtags WHERE channel_platform_hashtag_id NOT IN (" . $ids . ") AND channel_platform_id = '" . $channel_platform_id . "'";
        $results = $GLOBALS['db']->executeSQL($sql);
    }
    //***********************************************
    //***********************************************
    function clearUnusedPlatformFolders($channel_platform_id, $list)
    {
        $ids = "";
        for ($i = 0; $i < count($list); $i++)
        {
            if ($i > 0) { $ids .= ","; }
            $ids .= $list[$i];
        }
        $sql = "DELETE FROM channel_platform_data WHERE channel_platform_data_id NOT IN (" . $ids . ") AND channel_platform_id = '" . $channel_platform_id . "'";
        $results = $GLOBALS['db']->executeSQL($sql);
    }
    //***********************************************
    //***********************************************
    function clearUnusedPlatforms($channel_id, $list)
    {
        $ids = "";
        for ($i = 0; $i < count($list); $i++)
        {
            if ($i > 0) { $ids .= ","; }
            $ids .= $list[$i];
        }
        $sql = "DELETE FROM channel_platforms WHERE channel_platform_id NOT IN (" . $ids . ") AND channel_id = '" . $channel_id . "'";
        $results = $GLOBALS['db']->executeSQL($sql);
    }
    //***********************************************
    //***********************************************
    function channelContentExists($channel_id, $channel_platform_id, $file)
    {
        $sql = "SELECT COUNT(1) AS cnt FROM channel_content WHERE channel_id = '" . $channel_id . "' AND channel_platform_id = '" . $channel_platform_id . "' AND image = '" . $file . "'";
        $result = $GLOBALS['db']->getSQLResults($sql);
        if ($result[0])
        {
            return $result[0]->cnt;
        }
        return 0;
    }
    //***********************************************
    //***********************************************
    function createContentRecord($channel_id, $channel_platform_id, $title, $summary, $image)
    {
        $sql = "INSERT INTO channel_content(channel_id, channel_platform_id, title, summary, image, dt_added, active)
            VALUES('" . $channel_id . "','" . $channel_platform_id . "','" . $title . "','" . $summary . "','" . $image . "',now(),0)";
        $GLOBALS['db']->executeSQL($sql);
    }
}
?>