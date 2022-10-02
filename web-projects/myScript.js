function isValidForm() {

  var gender = document.forms["EnrollmentForm"]["Gender"].value;
  var name = document.forms["EnrollmentForm"]["Name"].value;

  if(isValidName(name)){
  if(isValidGender(gender)) {
    if(isValidSkills())
      if(confirm('Do you want to submit the form?')) {
        addRow();
        return true;
      }
  }
}
}
function isValidName(name)
{
	var letters = /^[A-Za-z]+$/;
	if(!name.match(letters))
        {
        alert("Please enter only alphabets");
		return false;
        }
		return true;
}
function isValidGender(gender) {
  if (gender == "") {
    alert("Gender must be filled out");
    return false;
  }
  return true;
}

function isValidSkills() {
  var java = document.getElementById("Java");  
  var html = document.getElementById("HTML");  
  var css = document.getElementById("CSS");
  if (java.checked == false && html.checked == false && css.checked == false) {
    alert("Mention at least 1 skill");
    return false;
  }
  return true; 
}

function addRow()
{
    // get input values
  var name = document.getElementById('UserName').value;
  var email = document.getElementById('Email').value;
  var web = document.getElementById('Website').value;
  var image = document.getElementById('ImageLink').value;
  var gender = document.forms["EnrollmentForm"]["Gender"].value;

  // For Skills
  var java = document.getElementById("Java");  
  var html = document.getElementById("HTML");  
  var css = document.getElementById("CSS");
  var skills = "";

  if(java.checked == true) {
    skills = skills + java.value;
  }

  if(html.checked == true) {
    if(skills.toString() != "") {
      skills = skills + ', ';
    }
    skills =  skills + html.value;
  }

  if(css.checked == true) {
    if(skills.toString() != "") {
      skills = skills + ', ';
    }
    skills =  skills + css.value;
  }


  // get the html table
  // 0 = the first table
  var table = document.getElementsByTagName('table')[0];

  var img = document.createElement('img');
  img.src = image;
  // add new empty row to the table
  // 0 = in the top 
  // table.rows.length = the end
  var newRow = table.insertRow(table.rows.length);

  // add cells to the row
  var cel1 = newRow.insertCell(0);
  var cel2 = newRow.insertCell(1);

  // add values to the cells
  cel1.innerHTML = "<ul><li> <b>" + name + "</b></li><li>" + gender + "</li><li>" + email + "</li><li> <a href=" + web + " target= _blank>"  + web + "</a></li><li>"+ skills + " </li></ul>";
  cel2.innerHTML = "<img src= " + image + " alt=User Image class = responsive>";

  addToDataBase(name, gender, email, web, skills, image);
}

$(document).ready(function(){
  $(".btn-primary").click(function() {
    $("table").fadeOut();
    $("table").fadeIn("slow");
  });
});


/// Data Base 

var db;
var request = window.indexedDB.open("Student", 1);
var count = 5;

request.onerror = function(event) {
  console.log("error: ");
};

request.onsuccess = function(event) {
  db = request.result;
  console.log("success: "+ db);
  var prev = 0;
  var objectStore = db.transaction("entry").objectStore("entry");
            
  objectStore.openCursor().onsuccess = function(event) {
   var cursor = event.target.result;
   
   if (cursor) {
    var table = document.getElementsByTagName('table')[0];

    var img = document.createElement('img');
    img.src = cursor.value.imageLink;
    // add new empty row to the table
    // 0 = in the top 
    // table.rows.length = the end
    var newRow = table.insertRow(table.rows.length);

    // add cells to the row
    var cel1 = newRow.insertCell(0);
    var cel2 = newRow.insertCell(1);

    // add values to the cells
    cel1.innerHTML = "<ul><li> <b>" + cursor.value.name + "</b></li><li>" + cursor.value.gender + "</li><li>" + cursor.value.email + "</li><li> <a href=" + cursor.value.website + " target= _blank>"  + cursor.value.website + "</a></li><li>"+ cursor.value.skills + " </li></ul>";
    cel2.innerHTML = "<img src= " + cursor.value.imageLink + " alt=User Image class = responsive>";
    prev++;
    // alert("Name for id " + cursor.key + " is " + cursor.value.name);
    cursor.continue();
   }
   else {
      count = prev;
   }
  };

};

request.onupgradeneeded = function(event) {

  var db = event.target.result;
  var objectStore = db.createObjectStore("entry", {keyPath: "id"});
  console.log("no need of upgarde");
}

function addToDataBase(fullname, g, e, web, s, image) {
  var request = db.transaction(["entry"], "readwrite").objectStore("entry")
  .add({id: count, name: fullname, gender: g, email: e, website: web, skills: s, imageLink: image});
  
  request.onsuccess = function(event) {
    count++;
  };
  
  request.onerror = function(event) {
     alert("Unable to add data");
  };
}

window.addEventListener("load", function(){
  console.log("page reload");
  
});