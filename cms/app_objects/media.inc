<?php
class obj_media
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

        $sql = "SELECT cc.*, u.first_name as user_name
            FROM channel_content cc
            LEFT JOIN channels c ON c.channel_id = cc.channel_id
            LEFT JOIN users u ON u.user_id = c.user_id
            ORDER BY cc.dt_added DESC";
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
    function getItem($id)
    {
        for ($i = 0; $i < count($this->listing); $i++)
        {
            if ( strval($this->listing[$i]->channel_content_id) == strval($id) )
            {
                return $this->listing[$i];
            }
        }
        return null;
    }
}
?>