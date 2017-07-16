<?php
class obj_users
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

        $sql = "SELECT * FROM users ORDER BY dt_added DESC";
        $results = $GLOBALS['db']->getSQLResults($sql);
        for ($u = 0; $u < count($results); $u++)
        {
            $results[$u]->platforms = [];
            $platform_sql = "SELECT * FROM social_media_sessions WHERE user = '" . $results[$u]->user_id . "' ORDER BY server ASC";
            $platform_results = $GLOBALS['db']->getSQLResults($platform_sql);
            for ($p = 0; $p < count($platform_results); $p++)
            {
                $results[$u]->platforms[] = $platform_results[$p]->server;
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
            if ( strval($this->listing[$i]->user_id) == strval($item_id) )
            {
                return $this->listing[$i];
            }
        }
        return null;
    }
}
?>