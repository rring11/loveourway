<?php
// load libraries
require_once 'libs/httpclient-2016-05-02/http.php';
require_once 'libs/oauth-api-2016-05-11/oauth_client.php';
require_once 'libs/oauth-api-2016-05-11/database_oauth_client.php';
require_once 'libs/oauth-api-2016-05-11/mysqli_oauth_client.php';
require_once "app_objects/platforms.inc";


class obj_socialmedia
{
    var $client = null;
    var $platforms = null;

    //***********************************************
    //***********************************************
    function __construct()
    {
        $this->client = new mysqli_oauth_client_class;
        $this->client->debug = false;
        $this->client->debug_http = false;
        $this->client->reauthenticate = false;

        $platforms_obj = new obj_platforms();
        $this->platforms = $platforms_obj->getListing();
    }
    //*****************************************************
    //*****************************************************
    public function setupPlatform($name)
    {
        for ($p = 0; $p < count($this->platforms); $p++)
        {
            if ($this->platforms[$p]->name == $name)
            {
                $this->client->server = $name;
                $this->client->client_id = $this->platforms[$p]->app_id;
                $this->client->client_secret = $this->platforms[$p]->app_secret;
                $this->client->redirect_uri = 'https://' . $_SERVER['HTTP_HOST'] . '/platform-connect/' . strtolower($name);
                $this->client->scope = $this->platforms[$p]->app_scope;
                return true;
                break;
            }
        }
        return false;
    }

    //*****************************************************
    //*****************************************************
    public function getFacebookData()
    {
        $user = null;
        $this->client->CallAPI( 'https://graph.facebook.com/v2.3/me?fields=id,first_name,gender,last_name,link,locale,name,timezone,updated_time,verified,email', 'GET', array(), array('FailOnAccessError' => true), $user);
        return $user;
    }
    //*****************************************************
    //*****************************************************
    public function getPinterestBoards($platform_id)
    {
        if ($this->getAuthorization())
        {
            $board_list = [];
            $this->client->CallAPI( 'https://api.pinterest.com/v1/me/boards/', 'GET', array(), array('FailOnAccessError'=>true), $boards);
            for ($b = 0; $b < count($boards->data); $b++)
            {
                $board = new stdClass();
                $board->id = $boards->data[$b]->id;
                $board->name = $boards->data[$b]->name;
                $board_list[] = $board;

//                $board_list .= '<input type="checkbox" class="fldr-' .$platform_id .'" value="' . $boards->data[$b]->id . '" data-name="' . $boards->data[$b]->name . '"> ' . $boards->data[$b]->name . '<br>';
            }
            return $board_list;
        }
        else
        {
            return "No authorization found";
        }
    }
    //*****************************************************
    //*****************************************************
    public function getPinterestData()
    {
        $user = null;
        $this->client->CallAPI( 'https://api.pinterest.com/v1/me/', 'GET', array(), array('FailOnAccessError'=>true), $user);
        return $user;
    }
    //*****************************************************
    //*****************************************************
    public function getTwitterData()
    {
        $user = null;
        $this->client->CallAPI('https://api.twitter.com/1.1/account/verify_credentials.json', 'GET', array(), array('FailOnAccessError'=>true), $user);
        return $user;
    }
    //*****************************************************
    //*****************************************************
    public function getInstagramData()
    {
        $user = null;
        $this->client->CallAPI('https://api.instagram.com/v1/users/self/','GET', array(), array('FailOnAccessError'=>true), $user);
        return $user;
    }
    //*****************************************************
    //*****************************************************
    public function getDropboxFolders()
    {
        $folders = null;
        if ($this->getAuthorization())
        {

            $ch = curl_init();
            curl_setopt($ch, CURLOPT_URL,"https://api.dropboxapi.com/2/files/list_folder");
            curl_setopt($ch, CURLOPT_POSTFIELDS, "{\"path\":\"\",\"recursive\":false,\"include_media_info\":false}");
            curl_setopt($ch, CURLOPT_POST, 1);
            curl_setopt($ch, CURLOPT_HTTPHEADER, [ "Authorization: Bearer " . $this->client->access_token, "Content-Type: application/json" ]);
            curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);
            $server_output = curl_exec ($ch);
            curl_close ($ch);

            $server_output = str_replace('".tag"','"tag"',$server_output);
            $json_data = json_decode($server_output);

            for ($f = 0; $f <= count($json_data->entries); $f++)
            {
                if ($json_data->entries[$f]->tag == "folder")
                {
                    $folder = new stdClass();
                    $folder->id = $json_data->entries[$f]->id;
                    $folder->name = $json_data->entries[$f]->path_display;
                    $folders[] = $folder;
                }
            }
        }
        return $folders;
    }
    //*****************************************************
    //*****************************************************
    public function getDropboxFolderFiles($folder)
    {
        $files = null;
        if ($this->getAuthorization())
        {
            $ch = curl_init();
            curl_setopt($ch, CURLOPT_URL,"https://api.dropboxapi.com/2/files/list_folder");
            curl_setopt($ch, CURLOPT_POSTFIELDS, "{\"path\":\"" . $folder . "\",\"recursive\":false,\"include_media_info\":false}");
            curl_setopt($ch, CURLOPT_POST, 1);
            curl_setopt($ch, CURLOPT_HTTPHEADER, [ "Authorization: Bearer " . $this->client->access_token, "Content-Type: application/json" ]);
            curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);
            $server_output = curl_exec ($ch);
            curl_close ($ch);

            $server_output = str_replace('".tag"','"tag"',$server_output);
            $json_data = json_decode($server_output);
            for ($f = 0; $f < count($json_data->entries); $f++)
            {
                if ($json_data->entries[$f]->tag == "file")
                {
                    $file = new stdClass();
                    $file->id = $json_data->entries[$f]->id;
                    $file->name = $json_data->entries[$f]->name;
                    $files[] = $file;
                }
            }
        }
        return $files;
    }
    //*****************************************************
    //*****************************************************
    public function getDropboxFile($file, $filename)
    {
        $ch = curl_init();
        curl_setopt($ch, CURLOPT_URL,"https://content.dropboxapi.com/2/files/download");
        curl_setopt($ch, CURLOPT_POST, 1);
        curl_setopt($ch, CURLOPT_HTTPHEADER, [ "Authorization: Bearer " . $this->client->access_token, "Content-Type: ", "Dropbox-API-Arg: {\"path\":\"" . $file . "\"}" ]);
        curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);
        $server_output = curl_exec ($ch);
        curl_close ($ch);

        // save to local file
        $downloaded_image = "/var/www/files/" .  $filename;
        $file = fopen($downloaded_image,"w");
        fwrite($file,$server_output);
        fclose($file);

        // move file to final location
        if (file_exists($downloaded_image))
        {
            rename($downloaded_image, '/var/www/vhosts/dev-cms.loveourway.com/imgs/content/' . $filename);
        }
    }
    //*****************************************************
    //*****************************************************
    public function getDropboxData()
    {
        $user = null;
        $this->client->CallAPI('https://api.dropboxapi.com/2/users/get_current_account','POST', array(), array('FailOnAccessError'=>true), $user);
        return $user;
    }



    //*****************************************************
    //*****************************************************
    public function getAuthorization()
    {
        // initialize connection
        if (($success = $this->client->Initialize()))
        {
            // process the connection
            if (($success = $this->client->Process()))
            {
                // get the token
                if (strlen($this->client->access_token))
                {
                    $this->client->SetUser($_SESSION['user_id']);
                    $success = $this->client->Finalize($success);
                    return $success;
                }
                else
                {
                    print("No auth token: " . $this->client->server . "<br>");
                }
            }
            else
            {
                print("Failed Process(): " . $this->client->server . "<br>");
            }
        }
        else
        {
            print("Failed Initialize(): " . $this->client->server . "<br>");
        }
        $success = $this->client->Finalize($success);
        return $success;
    }


    //*****************************************************
    //*****************************************************
    public function getClient()
    {
        return $this->client;
    }
    //*****************************************************
    //*****************************************************
    public function getClientError()
    {
        return $this->client->error;
    }
    //*****************************************************
    //*****************************************************
    public function redirectUser()
    {
//        header("Location: http://us.inpowerdev.com/pls/ngs/ngsfma_dojo_module.show_myaccount_module?fv_page_type=content_share&fn_content_id=" . $_SESSION['content_id']);
    }
    //*****************************************************
    //*****************************************************
    public function getRedirect()
    {
        print('<html><head><meta http-equiv="refresh" content="0;url=http://' . $_SERVER['HTTP_HOST'] . '/settings/list"/></head></html>');
    }


    //*****************************************************
    //*****************************************************
    public function disconnectFromChannel($platform)
    {
        $sql = "DELETE FROM social_media_sessions WHERE session ='" . $_SESSION['user_id'] . "' AND server = '" . $platform . "'";
        $GLOBALS['db']->executeSQL($sql);
    }
}
?>
