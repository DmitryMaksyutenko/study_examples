$(document).ready(function(){

    let $div = $("#base");

    let fragment = document.createDocumentFragment();
    let ol = document.createElement("ol")

    fragment.appendChild(ol);

    for(let i = 0; i < 100; i++){
        let li = document.createElement("li");
        li.innerHTML = i;
        ol.appendChild(li);
    }

    $div[0].append(fragment);

    let str = "";
    for(let i = 100; i < 200; i++){
        str += "<li>" + i + "</li>";
    }
    $div.html(str);

});