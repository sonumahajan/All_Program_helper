// dependencies -------------------------------
var express = require('express');
var app = express();
var path = require('path');
var bodyParser = require('body-parser');
const Student = require('./Student');

// app config --------------------------------
app.set('view engine','ejs');
app.use(express.static(path.join(__dirname, 'views')));

app.use(bodyParser.urlencoded({extended:false}));
app.use(bodyParser.json());


// CRUD Functionalities ----------------------
var student_data = [];

// to add student
function addStudent(student){
    if(!isStudentExist(student.rollno)){
        student_data.push(student);
    }    
}

// check if student is avlb or not
function isStudentExist(rollno){
    for(var i=0;i<student_data.length;i++){
        if(student_data[i].rollno === rollno){
            return true;
        }
    }
    return false;
}

// remove a student by rollno
function removeStudent(rollno){
    for(var i=0;i<student_data.length;i++){
        if(student_data[i].rollno == rollno){
            student_data.splice(i, 1);
            return;
        }
    }
}

// update a student
function updateStudent(student){
    removeStudent(student.rollno);
    addStudent(student);
}

// get student by roll no
function getStudent(rollno){
    for(var i=0;i<student_data.length;i++){
        if(student_data[i].rollno === rollno){
            return student_data[i];
        }
    }
}



// Request Handling starts here --------------------------------------------------

// GET : home page
app.get('/',(req,res) => {
    res.render('partials/home');
});


// GET : add student
app.get("/teacher/add",(req,res) =>{
    res.render('partials/admin-add-stud');
});

// POST : add student
app.post('/teacher/add', (req,res) => {
    var obj = req.body;
    addStudent(new Student(obj.rollno, obj.name, obj.dob, obj.score));
    res.redirect('/teacher');
});

// GET : delete a student
app.get('/teacher/delete/:rollno', (req,res) => {
    var rollno = req.params.rollno;
    console.log(rollno);
    removeStudent(rollno);
    console.log('User deleted');
    res.redirect('/teacher');
});

// GET : update a student
app.get('/teacher/edit/:rollno', (req,res) =>{
    var rollno = req.params.rollno;
    var student = getStudent(rollno);
    res.render('partials/admin-update-stud', {'student':student});
});

// POST : update a student
app.post('/teacher/update', (req,res) =>{
    var obj = req.body;
    updateStudent(new Student(obj.rollno, obj.name, obj.dob, obj.score));
    res.redirect('/teacher');
});


// GET : student table page
app.get('/teacher', (req,res) =>{
    res.render('partials/admin-stud-table',
    {'data':student_data, 'studentCount':student_data.length});
});



// GET : search result
app.get('/student', (req,res) =>{
    res.render('partials/find-result');
});

// POST : fill search result form
app.post('/student/result',(req,res) =>{
    var rollno = req.body.rollno;
    isExist = isStudentExist(rollno);
    if(isExist){
        student = getStudent(rollno);
        res.render('partials/show-result',{'student':student});
        return;
    }else{
        res.render('partials/404');
    }
});





app.listen(5001);
console.log('Server is running');