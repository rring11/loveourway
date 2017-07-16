<?php
class obj_messages
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

        $sql = "SELECT * FROM messages ORDER BY dt_sent DESC";
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
            if ( strval($this->listing[$i]->message_id) == strval($item_id) )
            {
                return $this->listing[$i];
            }
        }
        return null;
    }
}
?>