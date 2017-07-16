var platform = "";
$(document).ready(function()
{
    $(".channel_connect").click( function() { return connectToPlatform($(this)); } );
    $(".channel_disconnect").click( function() { return disconnectFromPlatform($(this)); } );
});
function connectToPlatform(item)
{
    platform = $(item).attr("data-platform");
    showConfirmMessage("Connect to " + platform, "Are you sure you want to coonect to " + platform + "?", "Yes, connect", connectToPlatformConfirmed);
}
function connectToPlatformConfirmed()
{
    swal.close();
    location.href = "/platform-connect/" + platform.toLowerCase();
}
function disconnectFromPlatform(item)
{
    platform = $(item).attr("data-platform");
    showConfirmMessage("Disconnect from " + platform, "Are you sure you want to discoonect from " + platform + "?", "Yes, disconnect", disconnectFromPlatformConfirmed);
}
function disconnectFromPlatformConfirmed()
{
    swal.close();
    var data = {platform:platform};
    $.ajax(
    {
        type: "POST",
        url: "/api/platform-disconnect",
        data: data,
        success : function(resp)
        {
            var rd = JSON.parse(resp);
            if (rd.code == "0") { location.reload(); }
            else { showErrorMessage(rd.message); }
        },
        error : function(resp) { showErrorMessage( resp.statusText + ' (' + resp.status + ')'); }
    });
    return false
}
