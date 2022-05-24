const char MAIN_page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
<head>
  <meta charset="UTF-8">
  <title>Lập trình esp8266 hiển thị nhiệt độ, độ ẩm </title>
  <style>
    .container{
      margin-top: 100px;
      font-size: 50px;
      text-align : center;
    }
    #data{
      color:Blue;
    }
    .btn{
      background-color: #4CAF50; /* Green */
      border: none;
      color: white;
      padding: 15px 32px;
      text-align: center;
      text-decoration: none;
      display: inline-block;
      font-size: 16px;
    }
  </style>
</head>
<body>

<div class = "container">
  Nhiệt độ, Độ Ẩm : <span id="data">0</span><br>
</div>
<div class = "container">
  <button class="btn" onClick = "ledon()">Bật đèn</button>
  <button class="btn" onClick = "ledoff()">Tắt đèn</button>
</div>
<script>
setInterval(function() {
  // Call a function repetatively with 2 Second interval
  getdata();
}, 500); //2000mSeconds update rate

function getdata() {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("data").innerHTML = this.responseText;
    }
  };
  xhttp.open("GET", "getData", true);
  xhttp.send();
}
function ledon(){
  var xhttp = new XMLHttpRequest();
  xhttp.open("GET", "ON", true);
  xhttp.send();
}
function ledoff(){
  var xhttp = new XMLHttpRequest();
  xhttp.open("GET", "OFF", true);
  xhttp.send();
}


</script>
</body>
</html>
)=====";
