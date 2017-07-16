<?php
    if ($api_name == "logout")
    {
        // reset session
        unset($_SESSION['user_id'] );
        unset($_SESSION['client_id'] );
        unset($_SESSION['is_admin'] );

        // setup return data
        $code = "0";
        $message = "Success";
    }
?>