var album_id = 0;
$(document).ready(function()
{
    $(".albums_option_item").click( function() { return albumOptionClicked($(this)); } );
    $(".albums_new_holder_content").click( function() { return createNewAlbum(); } );

});
function createNewAlbum()
{
    location.href="/albums/new";
}
function albumOptionClicked(item)
{
    var option = $(item).attr("data-option");
    if (option == "delete")
    {
        showConfirmMessage("Delete album", "Are you sure you want to delete this album?", "Yes, delete album", deleteAlbumConfirmed);
    }
    else
    {
        album_id = $(item).attr("data-id");
        location.href="/albums/" + option + "/" + album_id;
    }
}
function deleteAlbumConfirmed()
{
    swal.close();
}
