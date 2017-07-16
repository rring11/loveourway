var channel_id = 0;
$(document).ready(function()
{
    $(".channel_option_item").click( function() { return channelOptionClicked($(this)); } );
    $(".channel_new_holder_content").click( function() { return addNewChannel(); } );

});
function addNewChannel()
{
    location.href="/channels/new";
}
function channelOptionClicked(item)
{
    var option = $(item).attr("data-option");
    if (option == "delete")
    {
        showConfirmMessage("Delete channel", "Are you sure you want to delete this channel?", "Yes, delete channel", deleteChannelConfirmed);
    }
    else
    {
        channel_id = $(item).attr("data-id");
        location.href="/channels/" + option + "/" + channel_id;
    }
}
function deleteChannelConfirmed()
{
    swal.close();
}
