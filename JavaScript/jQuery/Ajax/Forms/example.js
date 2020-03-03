$(document).ready(function(){

    // Name attribure of the form fields must be specified.
    let $form = $("#form");

    $form.submit(function(event){
        event.preventDefault();

        $("#str").text($(this).serialize());

        let $result = $(this).serializeArray();

        let str = "";
        for(i in $result)
            for(j in $result[i])
            {
                if(j == "name" )
                    str += $result[i][j] + ": ";
                else
                    str += $result[i][j] + " ";
            }

        $("#array").text(str);
    });


});