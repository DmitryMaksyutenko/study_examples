$(document).ready(function(){

    let $table = $("table");
    let $tableParent = $table.parent();

    $table.detach();

    $table.append("<tr><th>numbers:</th></tr>");

    for(let i = 0; i < 10; i++){
        $table.append("<tr><td>" + i + "</tf></tr>");
    }

    $tableParent.append($table);

});