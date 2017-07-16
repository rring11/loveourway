$(document).ready(function()
{
});
function addUser()
{
    var first_name = $("#first_name").val();
    var last_name = $("#last_name").val();
    var nickname = $("#nickname").val();
    var email = $("#email").val();
    var address_1 = $("#address_1").val();
    var address_2 = $("#address_2").val();

    var city = $("#city").val();
    var state = $("#state").val();
    var zip = $("#zip").val();

    var phone = $("#phone").val();
    var gender = $("#gender:checked").val();
    var dob_month = $("#dob_month").val();
    var dob_day = $("#dob_day").val();
    var dob_year = $("#dob_year").val();

    var user_message = $("#user_message").val();

    if (!isValidString(first_name,"first_name","Please enter the first name")) { return false; }

    var data = new Object();
    data['first_name'] = first_name;
    data['last_name'] = last_name;
    data['nickname'] = nickname;
    data['email'] = email;
    data['address_1'] = address_1;
    data['address_2'] = address_2;
    data['city'] = city;
    data['state'] = state;
    data['zip'] = zip;
    data['phone'] = phone;
    data['gender'] = gender;
    data['dob'] = dob_year + "-" + dob_month + "-" + dob_day;
    data['user_message'] = user_message;

    $.ajax(
    {
        type: "POST",
        url: "/api/user/new",
        data: data,
        success : function(response)
        {
            var rd = JSON.parse(response);
            if (rd.code == "0") { addUserCompleted(); }
            else { showErrorMessage( rd.message); }
        },
        error : function(response) { showErrorMessage("Unable to add new user"); }
    });
}
function addUserCompleted()
{
    swal.close();
}