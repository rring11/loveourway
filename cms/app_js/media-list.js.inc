var media_id = 0;
$(document).ready(function()
{
    $(".media_option_item").click( function() { return mediaOptionClicked($(this)); } );
    $(".media_new_holder_content").click( function() { return addNewMedia(); } );

});
function addNewMedia()
{
    location.href="/media/new";
}
function mediaOptionClicked(item)
{
    var option = $(item).attr("data-option");
    if (option == "delete")
    {
        showConfirmMessage("Delete item", "Are you sure you want to delete this item?", "Yes, delete item", deleteMediaConfirmed);
    }
    else
    {
        media_id = $(item).attr("data-id");
        location.href="/media/" + option + "/" + media_id;
    }
}
function deleteMediaConfirmed()
{
    swal.close();
}
