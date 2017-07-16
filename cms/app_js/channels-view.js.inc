var content_idx = -1;
var total_content = content.length;
var playing = true;

$(document).ready(function()
{
    console.log(total_content);
    changeContent();

    $("#pause_content").click( function() { playing = false; } );
    $("#play_content").click( function() { playing = true; } );
    setInterval(changeContent, 5000);
});
function changeContent()
{
    if (!playing) { return false;}
    if ( (content_idx+1) < total_content) { content_idx += 1;}
    else { content_idx = 0; }

    console.log("showing " + content_idx);
    $("#content_image").attr("src","/imgs/content/" + content[content_idx].image);
    $("#content_title").html(content[content_idx].title);
}