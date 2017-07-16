<?php
class obj_database
{
    var $db_conn = null;
    var $db_host = "";
    var $db_user = "";
    var $db_pass = "";
    var $db_name = "low_main";
    var $db_connected = false;

    //***********************************************
    //***********************************************
    function __construct()
    {
        $this->db_conn = new mysqli($this->db_host,$this->db_user, $this->db_pass);
        if ($this->db_conn->connect_error) { return false; }
        mysqli_select_db($this->db_conn, $this->db_name);
        $this->db_connected = true;
    }
    //***********************************************
    //***********************************************
    public function isConnected()
    {
        return $this->db_connected;
    }
    //***********************************************
    //***********************************************
    public function filterInput($value)
    {
        return filter_input(INPUT_POST, $value, FILTER_SANITIZE_STRING);
    }
    //***********************************************
    //***********************************************
    public function filterString($value)
    {
        return mysqli_real_escape_string($this->db_conn,$value);
    }
    //***********************************************
    //***********************************************
    public function executeSQL($sql)
    {
        $result = mysqli_query($this->db_conn, $sql);
        return $result;
    }
    //***********************************************
    //***********************************************
    public function getSQLResults($sql)
    {
        $list = [];
        $result = mysqli_query($this->db_conn, $sql);
        if ($result)
        {
            while ($obj = mysqli_fetch_object($result))
            {
                $list[] = $obj;
            }
        }
        return $list;
    }
    //***********************************************
    //***********************************************
    public function getLastId()
    {
        return $this->db_conn->insert_id;
    }
    //***********************************************
    //***********************************************
    public function closeConnection()
    {
        if ($this->db_conn)
        {
            $this->db_connected = false;
            mysqli_close($this->db_conn);
        }
    }
}
?>