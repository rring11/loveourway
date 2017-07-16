$(document).ready(function()
{
    myDropzone = new Dropzone("div#mydropzone", { maxFiles: 1, autoProcessQueue:false, url: "/" });
    myDropzone.on("maxfilesexceeded", function(file) { this.removeAllFiles(); this.addFile(file); });
});
