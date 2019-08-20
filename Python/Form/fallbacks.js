var current_date = new Date();
var day = String(current_date.getDate()).padStart(2, '0');
var month = String(current_date.getMonth() + 1).padStart(2, '0');
var year = current_date.getFullYear();
current_date = year + '-' + month + '-' + day;

var date = document.getElementById("start_date");
date.value = current_date;