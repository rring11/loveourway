<?php
    // validate request
    if (!isset($_SESSION['user_id']))
    {
        if ($page_data[2] != "login")
        {
            print('{"code":"-1","message":"Invalid authorization","data":""}');
            exit;
        }
    }

    // set initial return codes
    $code = -1;
    $data = "";
    $message = "Invalid API call: ";
    if ( isset($page_data[2])) { $message .= $page_data[2];}
    if ( isset($page_data[3])) { $message .= "-" . $page_data[3];}

    // execute api
    $api_name = $page_data[2];
    $api_file_name = "app_api/" . $page_data[2] . ".inc";
    if (is_file($api_file_name)) { include_once $api_file_name; }

    // return the data
    if ($data == "") { $data = '""'; }
    print('{"code":"' . $code . '","message":"' . $message . '","data":' . $data . '}');
    exit;
?>