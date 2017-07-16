$(document).ready(function()
{
    $(".albums_new_holder_content").click( function() { return addNewContent(); } );

});
function addNewContent()
{
    // get available content
    var list = "";
    for (a = 1; a <= 8; a++)
    {
        list += '<div class="col-lg-3 col-md-4 albums_holder">' +
            '<div class="albums_holder_content">' +
            '<div class="albums_profile_holder">' +
            '<div class="albums_profile"><img src="/imgs/sample-photo-1.png" style="max-width:100%; max-height:100%;"></div>' +
            '</div>' +
            '<div class="albums_options">' +
            '<div class="row">' +
            '<div class="col-lg-12 pull-left text-left">CAPTION</div>' +
            '</div>' +
            '</div>' +
            '</div>' +
            '</div>';
    }
    $("#new_album_content_holder").html(list);

    $("#album_content_modal").modal("show");
}
