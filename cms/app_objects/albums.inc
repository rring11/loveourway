<?php
class obj_albums
{
    var $listing = [];
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

        $sql = "SELECT a.*, coalesce(cc.image,0) as image, 
              (SELECT count(1) FROM album_contents ac WHERE ac.album_id = a.album_id) AS items
            FROM albums a
            LEFT JOIN channel_content cc ON cc.channel_content_id = a.cover_id 
            ORDER BY a.dt_added DESC";
        $results = $GLOBALS['db']->getSQLResults($sql);
        for ($u = 0; $u < count($results); $u++)
        {
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
    function getItem($album_id)
    {
        for ($i = 0; $i < count($this->listing); $i++)
        {
            if ( strval($this->listing[$i]->album_id) == strval($album_id) )
            {
                return $this->listing[$i];
            }
        }
        return null;
    }
    //***********************************************
    //***********************************************
    function getAlbumContent($album_id)
    {
        $sql = "SELECT cc.*
            FROM album_contents ac
            LEFT JOIN channel_content cc ON cc.channel_content_id = ac.content_id
            WHERE ac.album_id = '" . $album_id . "'
            ORDER BY ac.display_order ASC";
        return $GLOBALS['db']->getSQLResults($sql);
    }
    //***********************************************
    //***********************************************
    function getAlbumChannelContent($channel_id, $album_id)
    {
        if ($channel_id == "0") { $channel_clause = ""; }
        else { $channel_clause = " WHERE channel_id = '" . $channel_id . "'"; }
        $sql = "SELECT *
            FROM channel_content
            " . $channel_clause . "
            ORDER BY dt_added DESC";
        return $GLOBALS['db']->getSQLResults($sql);
    }
}
?>