<?php
class obj_page
{
    //***********************************************
    //***********************************************
    function __construct()
    {
    }
    //*****************************************************
    //*****************************************************
    public function setupPageHeader($title, $title_icon, $back, $search, $new, $analytics, $export)
    {
        $header = '
            <div class="row">
                <div class="col-lg-7 pull-left text-left">
                    <h2><i class="fa fa-' . $title_icon . '"></i> ' . $title . '</h2>
                </div>
                <div class="col-lg-5 pull-right text-right">';
/*
        if ($search)
        {
            $header .= '
                <div style="float:left; width:150px;">
                    <input type="text" class="form-control" placeholder="Search" style="height:22px;">
                </div>
                <div style="float:left;">
                    <button type="button" class="btn btn-xs btn-primary search_btn"><i class="fa fa-search"></i></button>
                </div>';
        }

        $header .= '<div style="float:left;">';

        if ($back)
        {
            $header .= '<button class="btn btn-xs btn-primary list_btn" data-target="' . $back . '"><i class="fa fa-reply"></i> Back</button>';
        }

        if ($new)
        {
            $header .= '<button class="btn btn-xs btn-primary list_btn" data-target="' . $new . '"><i class="fa fa-plus"></i> New</button>';
        }

        if ($analytics)
        {
            $header .= '<button class="btn btn-xs btn-primary list_btn" data-target="' . $analytics . '"><i class="fa fa-line-chart"></i> Analytics</button>';
        }

        if ($export)
        {
            $header .= '<button class="btn btn-xs btn-primary list_btn" data-target="' . $export . '"><i class="fa fa-download"></i> Export</button>';
        }
*/
        $header .= '</div>
            </div>';
        return $header;
    }
    //*****************************************************
    //*****************************************************
    public function setupFormHeader($title, $title_icon)
    {
        $header = '<h2><i class="fa fa-' . $title_icon . '"></i> ' . $title . '</h2>';
        return $header;
    }
    //*****************************************************
    //*****************************************************
    public function setupPageFooter($buttons)
    {
        $footer = "";
        if ($buttons)
        {
            for ($b = 0; $b < count($buttons); $b++)
            {
                $footer .= '<button class="btn_form btn btn-small btn-' . $buttons[$b]['color'] . '" data-target="' . $buttons[$b]['target'] . '"><i class="fa fa-' . $buttons[$b]['icon'] . '"></i> ' . $buttons[$b]['text'] . '</button>&nbsp;&nbsp;';
            }
        }
        return $footer;
    }
    //*****************************************************
    //*****************************************************
    function random_pronounceable_word( $length = 6 )
    {
        // consonant sounds
        $cons = array(
            // single consonants. Beware of Q, it's often awkward in words
            'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm',
            'n', 'p', 'r', 's', 't', 'v', 'w', 'x', 'z',
            // possible combinations excluding those which cannot start a word
            'pt', 'gl', 'gr', 'ch', 'ph', 'ps', 'sh', 'st', 'th', 'wh',
        );

        // consonant combinations that cannot start a word
        $cons_cant_start = array(
            'ck', 'cm',
            'dr', 'ds',
            'ft',
            'gh', 'gn',
            'kr', 'ks',
            'ls', 'lt', 'lr',
            'mp', 'mt', 'ms',
            'ng', 'ns',
            'rd', 'rg', 'rs', 'rt',
            'ss',
            'ts', 'tch',
        );

        // wovels
        $vows = array
        (
            // single vowels
            'a', 'e', 'i', 'o', 'u', 'y',
            // vowel combinations your language allows
            'ee', 'oa', 'oo',
        );

        // start by vowel or consonant ?
        $current = ( mt_rand( 0, 1 ) == '0' ? 'cons' : 'vows' );

        $word = '';

        while( strlen( $word ) < $length )
        {
            // After first letter, use all consonant combos
            if( strlen( $word ) == 2 )
            {
                $cons = array_merge( $cons, $cons_cant_start );
            }

            // random sign from either $cons or $vows
            $rnd = ${$current}[mt_rand( 0, count( ${$current} ) -1 )];

            // check if random sign fits in word length
            if( strlen( $word . $rnd ) <= $length )
            {
                $word .= $rnd;
                // alternate sounds
                $current = ( $current == 'cons' ? 'vows' : 'cons' );
            }
        }
        return $word;
    }
}
?>