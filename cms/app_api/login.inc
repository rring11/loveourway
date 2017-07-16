<?php
    if ($api_name == "login")
    {
        $username = $GLOBALS['db']->filterInput("username");
        $password = $GLOBALS['db']->filterInput("password");

        // get password hash
        $password_hash = md5($password);
//print("SELECT client_id FROM clients WHERE username ='" . $username . "' AND password = '" . $password_hash . "'");
//        $sql_result = $GLOBALS['db']->getSQLResults("SELECT client_id FROM clients WHERE username ='" . $username . "' AND password = '" . $password_hash . "'");
        $sql = "SELECT user_id, is_admin FROM users WHERE email ='" . $username . "'";
        $sql_result = $GLOBALS['db']->getSQLResults($sql);
        if ( count($sql_result) > 0)
        {
            if ($sql_result[0]->user_id)
            {
                $_SESSION['user_id'] = $sql_result[0]->user_id;
                $_SESSION['client_id'] = 1;
                $_SESSION['is_admin'] = $sql_result[0]->is_admin;
                $code = "0";
                $message = "Success";
                return;
            }
        }

        $code = "-2";
        $data = "";
        $message = "Invalid login credentials";
        return;
    }
?>