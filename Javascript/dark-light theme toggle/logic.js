var ele = document.getElementById("text");
var c = 0;
var mode;
var btn = document.getElementById("switch");
btn.addEventListener('click', function() {
    c++;
    if(c%2==0)
    mode="dark";
    else
    mode="light";
    ele.className = mode;
    ele.innerHTML = `Text colour in ${mode} mode`;
})