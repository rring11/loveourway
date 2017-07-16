var user_id = 0;
$(document).ready(function()
{
    $(".user_option_item").click( function() { return userOptionClicked($(this)); } );
    $(".user_new_holder_content").click( function() { return addNewUser(); } );

});
function addNewUser()
{
    location.href="/users/new";
}
function userOptionClicked(item)
{
    var option = $(item).attr("data-option");
    user_id = $(item).attr("data-id");
    if (option == "delete")
    {
        showConfirmMessage("Delete user", "Are you sure you want to delete this user?", "Yes, delete user", deleteUserConfirmed);
    }
    else
    {
        location.href="/users/" + option + "/" + user_id;
    }
}
function deleteUserConfirmed()
{
    console.log("delete user_id: " + user_id);
    swal.close();
}
