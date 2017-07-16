var video_id = 0;
$(document).ready(function()
{
    $(".video_option_item").click( function() { return videoOptionClicked($(this)); } );
    $(".video_new_holder_content").click( function() { return addNewCall(); } );
});
function addNewCall()
{
    location.href="/video/call";
}
function videoOptionClicked(item)
{
    var option = $(item).attr("data-option");
    video_id = $(item).attr("data-id");
    if (option == "DELETE")
    {
        showConfirmMessage("Delete video call", "Are you sure you want to delete this video call?", "Yes, delete video", deleteVideoConfirmed);
    }
    else
    {
        location.href="/video/" + option + "/" + video_id;
    }
}
function deleteVideoConfirmed()
{
    console.log("delete user_id: " + video_id);
    swal.close();
}
