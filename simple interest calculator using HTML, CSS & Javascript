<!DOCTYPE html>
<head>
<title>Simple Interest Calculator</title>
<!-- Google Fonts -->
<link rel="preconnect" href="https://fonts.googleapis.com">
<link rel="preconnect" href="https://fonts.gstatic.com" crossorigin>
<link href="https://fonts.googleapis.com/css2?family=PT+Sans&display=swap" rel="stylesheet">
<!-- custom style css -->
<style>
body 
{
background-color: #9C9EFE;
color: #ffffff;
font-family: 'PT Sans', sans-serif;
}
.container
{
background-color: #ffffff;
color: #000000;
width: 625px;
padding: 40px;
border-radius: 15px;
margin-top:2%;
margin-left: auto;
margin-right: auto;
box-shadow: rgba(0, 0, 0, 0.12) 0px 1px 3px, rgba(0, 0, 0, 0.24) 0px 1px 2px;
}
/* #result
{
display: none;
} */
.contents
{
margin-left: 80px;
}
table td
{
padding-bottom: 10px;
}
#compute
{
margin-top:20px;
margin-bottom: 20px;
background-color: #3CCF4E;
border-radius:8px;
border: 20px;
color: white;
font-size:20px;
height: 40px;
width: 300px;
box-shadow: rgba(60, 64, 67, 0.3) 0px 1px 2px 0px, rgba(60, 64, 67, 0.15) 0px 2px 6px 2px;
}
#principal{
height: 25px;
width: 190px;
}
#years{
height: 35px;
width: 200px;
}
.highlight
{
background-color: #ffff00;
}
span{
font-size:18px;
}
</style>
</head>
<body>
<div class="container">
<h1>Simple Interest Calculator</h1>
<div class="contents">
<table id="table">
<tbody>
<tr>
<td class="labels"><b>Amount</b></td>
<td>
<input type="number" id="principal">
</td>
</tr>
<tr>
<td class="labels"><b>Interest Rate</b></td>
<td>
<input type="range" min="1" max="20" step="0.25" value="10.25" id="rate" name="rate" onchange="SliderValue()"> 
<span id="rate_display">10.25%</span>
</td>
</tr>
<tr>
<td class="labels"><b>No. of Years</b></td>
<td>
<select name="years" id="years">
<option value="1">1</option>
<option value="2">2</option>
<option value="3">3</option>
<option value="4">4</option>
<option value="5">5</option>
<option value="6">6</option>
<option value="7">7</option>
<option value="8">8</option>
<option value="9">9</option>
<option value="10">10</option>
<option value="11">11</option>
<option value="12">12</option>
<option value="13">13</option>
<option value="14">14</option>
<option value="15">15</option>
</select>
</td>
</tr>
</tbody>
</table>
<button id="compute" onclick="compute()">Calculate Interest</button> <br>
<span id="result"> </span>
<span id="result2"> </span>
</div>
</div>
<script>
function compute()
{
var principal = document.getElementById("principal").value;

if(principal !== "")
{
if (principal <= 0){
alert("Enter a positive number");
document.getElementById("principal").focus();
return;
}
}
else{
alert("Enter number Amount..");
return;
}
var rate = document.getElementById("rate").value;
var years = document.getElementById("years").value;
var interest = principal * years * rate / 100;

var dateNow = new Date();
var yearNow = parseInt(dateNow.getFullYear()) + parseInt(years);

var resultDisplay = document.getElementById("result");
resultDisplay.innerHTML = "<br/> ➔ If you deposit " + "<span class='highlight'>" + principal + "</span> Rupees.<br/>" + "<br>➔ At an interest Rate of "+ "<span class='highlight'>" + rate + "</span>%." + "<br/><br/>➔ You will receive an amount of " + "<span class='highlight'>" + interest + "</span> Rupees" + " in the year " + "<span class='highlight'>" + yearNow + "</span>";

var full_Display = document.getElementById("result2");

var t = parseFloat(principal) + parseFloat(interest);
full_Display.innerHTML = "<br/><br/> ➔ Your Total amount is: <span class='highlight'>" +t+ "</span> Rupees.";

}

function SliderValue()
{
var slider = document.getElementById("rate");
var output = document.getElementById("rate_display");
output.innerHTML = slider.value; // Display the default slider value

// Update the current slider value (each time you drag the slider handle)
slider.oninput = function() 
{
output.innerHTML = this.value;
} 
}
</script>
</body>
</html>
