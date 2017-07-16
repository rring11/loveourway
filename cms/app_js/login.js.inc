$(document).ready(function()
{
    $("#btn_login").click( function() { loginClicked(); } );
    $("#btn_forgot").click( function() { forgotClicked(); } );
    $("#btn_reset").click( function() { resetClicked(); } );
});
//*********************************************************
//*********************************************************
function loginClicked()
{
    var username = getValue("username");
    var password = getValue("password");
    if (!isValidString(username,"username","Please enter your username")) { return false; }
    if (!isValidString(password,"password","Please enter your password")) { return false; }

    var data = {username:username, password:password};
    $.ajax(
    {
        type: "POST",
        url: "/api/login",
        data: data,
        success : function(resp)
        {
            var rd = JSON.parse(resp);
            if (rd.code == "0") { location.href="/"; }
            else { showErrorMessage(rd.message); }
        },
        error : function(resp) { showErrorMessage( resp.statusText + ' (' + resp.status + ')'); }
    });
    return false;
}
//*********************************************************
//*********************************************************
function forgotClicked()
{
    location.href="/forgot";
    return false;
}
//*********************************************************
//*********************************************************
function resetClicked()
{
    location.href="/reset";
    return false;
}
