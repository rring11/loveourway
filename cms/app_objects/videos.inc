<?php
class obj_videos
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

        $item = new stdClass();
        $item->id = 1;
        $item->date = "Apr. 29, 2017 @ 8:15am";
        $item->minutes = "6";
        $item->users = 2;
        $this->listing[] = $item;

        $item = new stdClass();
        $item->id = 2;
        $item->date = "Apr. 29, 2017 @ 9:30am";
        $item->minutes = "10";
        $item->users = 3;
        $this->listing[] = $item;
    }
    //***********************************************
    //***********************************************
    function getListing()
    {
        return $this->listing;
    }
    //***********************************************
    //***********************************************
    function getItem($music_id)
    {
        for ($i = 0; $i < count($this->listing); $i++)
        {
            if ( strval($this->listing[$i]->id) == strval($music_id) )
            {
                return $this->listing[$i];
            }
        }
        return null;
    }
}
?>