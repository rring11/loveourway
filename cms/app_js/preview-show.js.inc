var current_page = "start";

var showing_album = false;
var album_index = 1;
var album_content_index = 0;
var album_interval = null;
var album_delay = 10000;

var showing_channel = false;
var channel_index = 1;
var channel_content_index = 0;
var channel_interval = null;
var channel_delay = 10000;

$(document).ready(function()
{
    $(".btn_start").click( function() { return showHomePage(); } );
    $(".btn_landing").click( function() { return showPage("landing"); } );

    $(".btn_albums").click( function() { return showPage("albums"); } );
    $(".btn_albums_prev").click( function() { return showAlbumsItem("prev"); } );
    $(".btn_albums_next").click( function() { return showAlbumsItem("next"); } );
    $(".btn_back_albums").click( function() { return returnTo( $(this), "albums"); } );
    $(".album_cover").click( function() { return showAlbum( $(this) ); } );

    $(".btn_channels").click( function() { return showPage("channels"); } );
    $(".btn_channels_prev").click( function() { return showChannelsItem("prev"); } );
    $(".btn_channels_next").click( function() { return showChannelsItem("next"); } );
    $(".btn_channel_view").click( function() { return showChannel( $(this) ); } );
    $(".btn_back_channels").click( function() { return returnTo( $(this), "channels"); } );

    $(".btn_messages").click( function() { return showPage("messages"); } );

    channel_index = 1;
    channel_content_index = 0;

    album_index = 1;
    album_content_index = 0;
//    swal( { title: "Enable Casting", type:"warning", text: "Cast this browser tab in order<br>to preview the app on your T.V.", html:true });
});




//*******************************************************************
//*******************************************************************
function showHomePage()
{
    $("#app_preview").fadeIn(500);
    $("#page_start").fadeOut(500, showPage("landing"));
}



//*******************************************************************
//*******************************************************************
function showAlbumsItem(type)
{
    if (type == "prev")
    {
        if (album_index > 1) { showAlbumCover( album_index - 1); }
        else { showAlbumCover(total_albums); }
    }
    else
    {
        if (album_index < total_albums) { showAlbumCover( album_index + 1); }
        else { showAlbumCover(1); }
    }
}
//*******************************************************************
//*******************************************************************
function showAlbumCover(new_index)
{
    $("#album_" + album_index).fadeOut(500, function()
    {
        album_index = new_index;
        $("#album_" + album_index).fadeIn(500);
    });
}
//*******************************************************************
//*******************************************************************
function returnTo(item, section)
{
    console.log(section);
    if (section == "albums")
    {
        document.getElementById('album_bg_music').pause();

        clearInterval(album_interval);
        $("#page_album_contents").fadeOut(500, function()
        {
            showing_album = false;
            album_index = 1;
            $("#page_album_content_holder").fadeIn(500);
        });
    }
    else if (section == "channels")
    {
        document.getElementById('channel_bg_music').pause();

        clearInterval(channel_interval);
        $("#page_channel_contents").fadeOut(500, function()
        {
            showing_channel = false;
            // channel_index = 1;
            $("#page_channel_content_holder").fadeIn(500);
        });
    }
}
//*******************************************************************
//*******************************************************************
function showAlbum()
{
    $("#page_album_content_holder").fadeOut(500, function()
    {
        document.getElementById('album_bg_music').play();

        album_content_index = -1;
        changeAlbumContent();
        showing_album = true;
        $("#page_album_contents").fadeIn(500, function()
        {
            album_interval = setInterval(changeAlbumContent, album_delay);
        });
    });
}





//*******************************************************************
//*******************************************************************
function changeAlbumContent()
{
    album_content_index += 1;
    if (album_content_index == album_contents[ (album_index-1) ].length) { album_content_index = 0; }
    $("#album_content_image").css("background-image", "url('" + album_contents[ (album_index-1) ][ album_content_index ].image + "')");
    $("#album_content_title").html( album_contents[ (album_index-1) ][ album_content_index ].caption);
}
//*******************************************************************
//*******************************************************************
function showPage(page_id)
{
    console.log("show page: " + page_id);

    $("#page_" + current_page).fadeOut(500, function()
    {
        $("#page_" + page_id).fadeIn(100, function()
        {
            current_page = page_id;
        });
    });
}


//*******************************************************************
//*******************************************************************
function showChannelsItem(type)
{
    console.log(type);
    if (type == "prev")
    {
        if (channel_index > 1) { showChannelsCover( channel_index - 1); }
        else { showChannelsCover(total_channels); }
    }
    else
    {
        if (channel_index < total_channels) { showChannelsCover( channel_index + 1); }
        else { showChannelsCover(1); }
    }
}
//*******************************************************************
//*******************************************************************
function showChannelsCover(new_index)
{
    $("#channel_" + channel_index).fadeOut(500, function()
    {
        channel_index = new_index;
        $("#channel_" + channel_index).fadeIn(500);
    });
}
//*******************************************************************
//*******************************************************************
function showChannel(item)
{
    var channel = $(item).attr("data-id");
    $("#page_channel_content_holder").fadeOut(500, function()
    {
        document.getElementById('channel_bg_music').play();

        channel_content_index = -1;
        changeChannelContent();
        showing_channel = true;
        $("#page_channel_contents").fadeIn(500, function()
        {
            channel_interval = setInterval(changeChannelContent, channel_delay);
        });
    });
}
//*******************************************************************
//*******************************************************************
function changeChannelContent()
{
    channel_content_index += 1;
    if (channel_content_index == channel_contents[ (channel_index-1) ].length) { channel_content_index = 0; }
    $("#channel_content_image").css("background-image", "url('" + channel_contents[ (channel_index-1) ][ channel_content_index ].image + "')");
    $("#channel_content_title").html( channel_contents[ (channel_index-1) ][ channel_content_index ].caption);
}