<?php
    if ($logged_in)
    {
        if ($page_name == "users") { $active_user = "active"; }
        else if ($page_name == "channels") { $active_channels = "active"; }
        else if ($page_name == "albums") { $active_albums = "active"; }
        else if ($page_name == "messages") { $active_messages = "active"; }
        else if ($page_name == "video") { $active_video = "active"; }
        else if ($page_name == "media") { $active_media = "active"; }
        else if ($page_name == "sharing") { $active_sharing = "active"; }
        else if ($page_name == "settings") { $active_settings = "active"; }
        else if ($page_name == "account") { $active_account = "active"; }
        else { $active_home = "active"; }

        $menu = '<li class="' . $active_home . '"><a href="/"><i class="fa fa-home menu-item-icon"></i> <span class="nav-label">Home</span></a></li>';
        if ($_SESSION['is_admin'])
        {
            $menu .= '<li class="' . $active_user . '"><a href="/users/list"><i class="fa fa-users menu-item-icon"></i> <span class="nav-label">Users</span></a></li>';
        }

        $menu .= '
            <li class="' . $active_settings . '"><a href="/settings/list"><i class="fa fa-gears menu-item-icon"></i> <span class="nav-label">Connections</span></a></li>
            <li class="' . $active_channels . '"><a href="/channels/list"><i class="fa fa-share-alt menu-item-icon"></i> <span class="nav-label">Channels</span></a></li>
            <li class="' . $active_albums . '"><a href="/albums/list"><i class="fa fa-trophy menu-item-icon"></i> <span class="nav-label">Albums</span></a></li>
            <li class="' . $active_messages . '"><a href="/messages/list"><i class="fa fa-play menu-item-icon"></i> <span class="nav-label">Messages</span></a></li>
            <li class="' . $active_video . '"><a href="/video/list"><i class="fa fa-video-camera menu-item-icon"></i> <span class="nav-label">Video Calls</span></a></li>
            <li class="' . $active_media . '"><a href="/media/list"><i class="fa fa-image menu-item-icon"></i> <span class="nav-label">Media Gallery</span></a></li>
            <li class="' . $active_sharing . '"><a href="/sharing/list"><i class="fa fa-star menu-item-icon"></i> <span class="nav-label">Sharing is Ageless</span></a></li>
            <li class="' . $active_account . '"><a href="/account/info"><i class="fa fa-gear menu-item-icon"></i> <span class="nav-label">Account</span></a></li>
            <li class=""><a href="/preview/show" target="_blank"><i class="fa fa-eye menu-item-icon"></i> <span class="nav-label">Preview App</span></a></li>
            <li><a href="#" id="link_logout"><i class="fa fa-sign-out menu-item-icon"></i> <span class="nav-label">Logout</span></a></li>';
    }
?>
