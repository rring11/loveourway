$(document).ready(function()
{
    $("#link_logout").click( function() { return logoutClicked(); } );
    $(".list_btn").click( function() { return listButtonClicked( $(this) ); } );
    $(".action_icon").click( function() { return actionClicked( $(this) ); } );
    $(".btn_form").click( function() { return buttonClicked( $(this) ); } );

    Dropzone.autoDiscover = false;

    animateCounters();
    setupSwitches();
    setupFullscreenModals();
});

//*********************************************************
//*********************************************************
function setupFullscreenModals()
{
    $(".modal-fullscreen").on('show.bs.modal', function ()
    {
        setTimeout(function () { $(".modal-backdrop").addClass("modal-backdrop-fullscreen"); }, 0);
    });
    $(".modal-fullscreen").on('hidden.bs.modal', function ()
    {
        $(".modal-backdrop").addClass("modal-backdrop-fullscreen");
    });
}

//*********************************************************
//*********************************************************
function setupSwitches()
{
    var elems = Array.prototype.slice.call(document.querySelectorAll('.js-switch'));
    elems.forEach(function(html)
    {
        var switchery = new Switchery(html, {color: '#faab43'});
    });
}
//*********************************************************
//*********************************************************
function buttonClicked(item)
{
    var call = $(item).attr("data-target");
    window[call]();
}
//*********************************************************
//*********************************************************
function animateCounters()
{
    $('.animated_counter').each(function ()
    {
        $(this).prop('Counter',0).animate(
        {
            Counter: $(this).text()
        },
        {
            duration: 1000,
            easing: 'swing',
            step: function (now) { $(this).text(Math.ceil(now)); }
        });
    });
}
//*********************************************************
//*********************************************************
function listButtonClicked(item)
{
    var target = $(item).attr("data-target");
    location.href = target;
}
//*********************************************************
//*********************************************************
function actionClicked(item)
{
    var target = $(item).attr("data-target");
    location.href = target;
}

//*********************************************************
//*********************************************************
function logoutClicked()
{
    showConfirmMessage("Logout", "Are you sure you want to logout?", "Yes, logout", logoutUser);
}
//*********************************************************
//*********************************************************
function logoutUser()
{
    // make ajax call
    $.ajax(
    {
        type: "POST",
        url: "/api/logout",
        data: "",
        success : function(resp) { location.href="/"; },
        error : function(resp) { showErrorMessage( resp.statusText + ' (' + resp.status + ')'); }
    });
    return false;
}
//*********************************************************
//*********************************************************
function showWarningMessage(message)
{
    swal( { title: "Something's wrong!", type:"warning", text: message, html:true });
    return false;
}
//*********************************************************
//*********************************************************
function showErrorMessage(message)
{
    swal( { title: "Oops!", type:"error", text: message, html:true });
    return false;
}
//*********************************************************
//*********************************************************
function showConfirmMessage(title, message, button, confirmCallback)
{
    swal( { title: title, type:"warning", text: message, html:true, showCancelButton: true, confirmButtonColor: "#DD6B55", confirmButtonText: button, closeOnConfirm: false}, function() { confirmCallback() } );
    return false;
}
//*********************************************************
//*********************************************************
function showSuccessMessage(title, message, successCallback)
{
    swal( { title: title, type:"success", text: message, html:true, closeOnConfirm: false }, function(isConfirm) { swal.close(); successCallback(); } );
}
//*********************************************************
//*********************************************************
function getValue(field)
{
    return $("#" + field).val();
}
//*********************************************************
//*********************************************************
function isNotNull(val, message)
{
    if (val == null)
    {
        showWarningMessage(message);
        return false;
    }
    return true;
}
//*********************************************************
//*********************************************************
function hasItemSelected(cnt, message)
{
    if (cnt < 1)
    {
        showWarningMessage(message);
        return false;
    }
    return true;
}
//*********************************************************
//*********************************************************
function isValidString(str, field, message)
{
    $("#" + field).removeClass("error");
    if (str == "")
    {
        $("#" + field).addClass("error");
        showWarningMessage(message);
        return false;
    }
    return true;
}
//*********************************************************
//*********************************************************
function isValidNumber(str, field, message)
{
    $("#" + field).removeClass("error");
    if ( (str == "") || (isNaN(str) ) )
    {
        $("#" + field).addClass("error");
        showWarningMessage(message);
        return false;
    }
    return true;
}
//*********************************************************
//*********************************************************
function isValidNumberRange(str, min, max, message)
{
    if (str == "")
    {
        showWarningMessage(message);
        return false;
    }
    if (isNaN(str))
    {
        showWarningMessage(message);
        return false;
    }
    if ( (str < min) || (str > max) )
    {
        showWarningMessage(message);
        return false;
    }
    return true;
}
//*********************************************************
//*********************************************************
function isValidNumberMinimum(str, min, message)
{
    if (str < min)
    {
        showWarningMessage(message);
        return false;
    }
    return true;
}
//*********************************************************
//*********************************************************
function isValidBoolean(chk, value, message)
{
    if (chk != value)
    {
        showWarningMessage(message);
        return false;
    }
    return true;
}
//*********************************************************
//*********************************************************
function isValidCheck(chk, message)
{
    if (!$(chk).is(":checked"))
    {
        showWarningMessage(message);
        return false;
    }
    return true;
}
//*********************************************************
//*********************************************************
function isValidDate(str, message)
{
}
//*********************************************************
//*********************************************************
function areValidDates(dt1, dt2, message)
{
    if (dt1 > dt2)
    {
        showWarningMessage(message);
        return false;
    }
    return true;
}
