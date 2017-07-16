$(document).ready(function()
{
    $(".albums_new_holder_content").click( function() { return addNewContent(); } );
});
function addNewContent()
{
    var jd = new Object();
    jd['album_id'] = album_id;
    var data = {request:JSON.stringify(jd)};
    $.ajax(
    {
        type: "POST",
        url: "/api/albums-new-content",
        data: data,
        success : function(resp)
        {
            var rd = JSON.parse(resp);
            if (rd.code == "0") { showNewContent(rd.data); }
            else { showErrorMessage(rd.message); }
        },
        error : function(resp) { showErrorMessage(resp.statusText + '\n' + resp.status); }
    });
}
function showNewContent(data)
{
    var filter_list = "<div><h3>Filter channels</h3></div>";
    var last_user = "";
    for (var a = 0; a < data[0].channels.length; a++)
    {
        var channel = data[0].channels[a];
        if (channel.user_name != last_user)
        {
            last_user = channel.user_name;
            filter_list += '<div style="font-weight:bold; margin-bottom:10px;">' + channel.user_name + '</div>';
        }
        filter_list += '<div style="margin-left:20px;"><input type="checkbox">&nbsp;&nbsp;' + channel.name + '</div>';
    }
    $("#new_album_filter_holder").html(filter_list);


    // extract content listing
    var content_list = "";
    for (var a = 0; a < data[0].content.length; a++)
    {
        var content = data[0].content[a];

        content_list += '<div class="col-lg-3 col-md-4 albums_holder">' +
            '<div class="albums_holder_content">' +
        '<div class="albums_profile_holder">' +
        '<div class="albums_profile"><img src="/imgs/content/' + content.image + '" style="max-width:100%; max-height:100%;"></div>' +
        '</div>' +
        '<div class="albums_options">' +
        '<div class="row">' +
        '<div class="col-lg-12 pull-left text-left">' + content.title + '</div>' +
        '</div>' +
        '</div>' +
        '</div>' +
        '</div>';
    }
    $("#new_album_content_holder").html(content_list);


    // show content
    $("#album_content_modal").modal("show");
}
