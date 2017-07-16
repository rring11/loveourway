<?php
class obj_platforms
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

        $sql = "SELECT p.*,
              (SELECT count(1) FROM social_media_sessions sms WHERE sms.user = '1' AND sms.server = p.name) AS connected
            FROM platforms p
            ORDER BY p.name ASC";
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
    function getItem($item_id)
    {
        for ($i = 0; $i < count($this->listing); $i++)
        {
            if ( strval($this->listing[$i]->platform_id) == strval($item_id) )
            {
                return $this->listing[$i];
            }
        }
        return null;
    }
    //***********************************************
    //***********************************************
    function getItemByName($item_name)
    {
        for ($i = 0; $i < count($this->listing); $i++)
        {
            if ( strval($this->listing[$i]->name) == $item_name )
            {
                return $this->listing[$i];
            }
        }
        return null;
    }
    //***********************************************
    //***********************************************
    function getDataForPlatform($item_id)
    {
        $sql = "SELECT data
            FROM channel_platform_data
            WHERE channel_paltform_id = '" . $item_id . "'
            ORDER BY data ASC";
        return $GLOBALS['db']->getSQLResults($sql);
    }

}
?>