$(document).ready(function(){

    $('.sidenav').sidenav();
    $(".dropdown-trigger").each(function(){
        console.log("fired")
        $(this).dropdown({ hover:false })   
    });

})