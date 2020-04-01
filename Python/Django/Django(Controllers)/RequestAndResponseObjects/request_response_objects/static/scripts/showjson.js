(function(){

  let getJsonLinc = document.getElementById("json");
  let bodyTag = document.getElementsByTagName("body")[0];

  function getAjax(){
    let xhttp = new XMLHttpRequest();

    xhttp.onreadystatechange = function(){
      if(this.readyState == 4){
          let nameKey = document.createElement("p");
          let nameValue = document.createElement("p");
          let placeKey = document.createElement("p");
          let placeValue = document.createElement("p");
          let responseObj = JSON.parse(this.responseText);

          nameKey.classList.add("pRed");
          placeKey.classList.add("pRed");

          nameKey.innerHTML = Object.keys(responseObj)[0] + " = ";
          nameValue.innerHTML = responseObj["name"];
          placeKey.innerHTML = Object.keys(responseObj)[1] + " = ";
          placeValue.innerHTML = responseObj["place"];

          bodyTag.appendChild(nameKey);
          bodyTag.appendChild(nameValue);
          bodyTag.appendChild(document.createElement("br"));
          bodyTag.appendChild(placeKey);
          bodyTag.appendChild(placeValue);
          bodyTag.appendChild(document.createElement("br"));
      }
    }

    xhttp.open("GET", "http://localhost:8000/json", true);
    xhttp.send();
  }

  getJsonLinc.onclick = function(event) {
    event.preventDefault();
    getAjax();
  }

})();
