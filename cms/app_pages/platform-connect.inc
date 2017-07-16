<?php
    require_once "app_objects/socialmedia.inc";
    $social_object = new obj_socialmedia();

    if (!$social_object->setupPlatform( ucfirst($page_data[2]) ) )
    {
        print("Platform not implemented");
        return;

    }

    // get autho
    if (!$social_object->getAuthorization())
    {
        print( HtmlSpecialChars($social_object->getClientError()) );
    }
    else
    {
        $social_object->getRedirect();
        return;
    }
?>