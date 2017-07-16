<?php
class obj_paging
{
    var $start = 0;
    var $count = 0;
    var $total = 0;

    //***********************************************
    //***********************************************
    function __construct($start, $count, $total)
    {
        $this->start = $start;
        $this->count = $count;
        $this->total = $total;
    }
    //*****************************************************
    //*****************************************************
    public function getPagingButtons()
    {
        $next_btn_type = " btn-default ";
        $next_btn_disabled = " disabled ";
        $last_btn_type = " btn-default ";
        $last_btn_disabled = " disabled " ;

        $next_start = ($this->count+1);
        $last_start = "0";

        // setup next
        if (($this->start + ($this->count+1)) <= $this->total)
        {
            $next_btn_type = " btn-success ";
            $next_btn_disabled = " ";

            // setup last
            $last_start = $this->total / $this->count;
            if (is_float($last_start)) { $last_start = floor($last_start); }
            else { $last_start -= 1; }
            $last_start = ($last_start * $this->count) + 1;

            if ($last_start >= $next_start)
            {
                $last_btn_type = " btn-success ";
                $last_btn_disabled = " " ;
            }
        }

        // setup buttons
        $first = "<button class='btn btn-xs btn-default btn-outline paging_btn' disabled data-type='first' data-start='1'> &lt;&lt; </button>&nbsp;";
        $previous = "<button class='btn btn-xs btn-default btn-outline paging_btn' disabled data-type='previous' data-start='1'> &lt; </button>&nbsp;";
        $next = "<button class='btn btn-xs " . $next_btn_type . " btn-outline paging_btn' " . $next_btn_disabled . " data-type='next' data-start='" . $next_start . "'> &gt; </button>&nbsp;";
        $last = "<button class='btn btn-xs " . $last_btn_type . " btn-outline paging_btn' " . $last_btn_disabled . " data-type='last' data-start='" . $last_start . "'> &gt;&gt; </button>&nbsp;";

        // return the paging nav buttons
        return $first . $previous . $next . $last;
    }
    //*****************************************************
    //*****************************************************
    public function getViewingRecords()
    {
        $end_num = $this->start + $this->count;
        if ($end_num > $this->total) { $end_num = $this->total; }
        $records = "record";
        if ($this->total > 1) { $records .= "s"; }
        return "Viewing <span id='record_viewing' class='stat_color'>" . ($this->start + 1) . "-" . $end_num . "</span> of <span class='stat_color'>" . $this->total . "</span> " . $records;
    }
    //*****************************************************
    //*****************************************************
    public function getPagingNavigation()
    {
        return '<div class="row">
            <div class="col-lg-6 col-md-6 col-sm-6 col-xs-6 text-left">
                <div class="list_viewing_total">' . $this->getViewingRecords() . '</div>
            </div>
            <div class="col-lg-6 col-md-6 col-sm-6 col-xs-6 text-right">
                ' . $this->getPagingButtons() . '
            </div>
        </div>';
    }
}
?>