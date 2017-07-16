<?php
    // setup page header
    $page_header = $page_obj->setupPageHeader("Media - Upload", "image", "/media/list", null, null, null, null);
    $page_footer = $page_obj->setupPageFooter(
        array
        (
            array("color"=>"primary", "target"=>"uploadMedia", "text"=>"Upload Item", "icon"=>"save")
        )
    );
?>
<div class="ibox">
    <div class="ibox-title"><?php print($page_header); ?></div>
    <div class="ibox-content">
        <h2 style="text-align:center; margin:25px 0px 25px 0px;">On this page you can upload media.</h2>
        <div class="row">
            <div class="col-lg-12">
                <div class="ibox">
                    <div class="ibox-title">
                        <h2><i class="fa fa-plus"></i> New item</h2>
                    </div>
                    <div class="ibox-content">
                        <div class="row">
                            <div class="col-lg-6 col-md-6">
                                <div class="form-group">
                                    <label>Item to upload:</label>
                                    <div class="text-center" style="cursor:pointer;">
                                        <div id="mydropzone" class="dropzone" style="width:100%; height:100%; background-color:#f8fafb">
                                            <div class="dz-message" data-dz-message><span><i class="fa fa-upload fa-5x"></i><br>Drop a file here or click to browse</span></div>
                                        </div>
                                    </div>
                                </div>
                                <div class="form-group">
                                    <label>Caption for this item:</label>
                                    <input type="text" id="caption" class="form-control">
                                </div>
                            </div>
                        </div>
                    </div>
                </div>
            </div>
        </div>
    </div>
    <div class="ibox-footer"><?php print($page_footer); ?></div>
</div>
