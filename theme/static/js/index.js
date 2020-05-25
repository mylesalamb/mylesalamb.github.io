$(document).ready(function(){

    $('.sidenav').sidenav();
    $(".dropdown-trigger").each(function(){
        $(this).dropdown({ 
            hover:false,
            belowOrigin: true,
            inDuration: 300,
            outDuration: 225, })   
    });

})