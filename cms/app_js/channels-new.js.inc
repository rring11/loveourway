$(document).ready(function()
{
});
function getChannelData()
{
    var jd = new Object();

    jd['name'] = getValue("name");
    jd['description'] = getValue("description");
    jd['platforms'] = [];

    $('[type="checkbox"].platform_active').each(function ()
    {
        var platform_id = (this.checked ? $(this).val() : "");
        if (platform_id != "")
        {
            var pd_obj = new Object();
            pd_obj['id'] = platform_id;
            pd_obj['hashtags'] = [];
            pd_obj['folders'] = [];

            // get hashtags
            for (var ht = 1; ht <= 4; ht++)
            {
                var ht_obj = new Object();
                var ht_value = $("#ht-" + platform_id + "-" + ht).val();
                if ( (ht_value != "") && (typeof ht_value != "undefined") )
                {
                    ht_obj['id'] = ht_value;
                    pd_obj['hashtags'].push(ht_obj);
                }
            }

            // get folders
            $('[type="checkbox"].fldr-' + platform_id).each(function ()
            {
                var fl_obj = new Object();
                var folder_id = (this.checked ? $(this).val() : "");
                var folder_name = "";
                if (folder_id != "")
                {
                    fl_obj['id'] = folder_id;
                    folder_name = $(this).attr("data-name");
                    fl_obj['name'] = folder_name;
                    pd_obj['folders'].push(fl_obj);
                }
            });

            jd['platforms'].push(pd_obj);
        }
    });
    console.log(jd);
    return jd;
}
function createChannel()
{
    var jd = getChannelData();
    var data = {request:JSON.stringify(jd)};
console.log(data);
    $.ajax(
    {
        type: "POST",
        url: "/api/channel-create",
        data: data,
        success : function(resp)
        {
            var rd = JSON.parse(resp);
            if (rd.code == "0") { showSuccessMessage("Saved!", "The channel has been created", createChannelCompleted); }
            else { showErrorMessage(rd.message); }
        },
        error : function(resp) { showErrorMessage(resp.statusText + '\n' + resp.status); }
    });
}
function createChannelCompleted()
{
    location.href="/channels/list";
}