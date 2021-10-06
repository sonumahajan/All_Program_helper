navHeaderTemplate();
contactTemplate();
loginTemplate();
footerTemplate();



function navHeaderTemplate() {
    let headertemplate = '<a href="./index.html">' +
        '<img src="./assests/images/logo.png" alt="logo"/>' +
        '</a>' +
        '<!-- Button trigger modal -->' +
        '<a class="login btn btn-light btn-sm text-uppercase" id="login" data-toggle="modal" data-target="#login-modal" href="./login.html">Login</a>' +
        '<a class="login btn btn-light btn-sm text-uppercase" id="logout">LOGOUT</a>';
    document.getElementById('navheader').innerHTML += headertemplate;
}


function footerTemplate() {
    let footertemplate = '<div class="contact-us">' +
        '<a class="btn btn-info btn-sm text-white" data-toggle="modal" data-target="#contactus-modal" target="_self" href="./contact.html">Contact Us</a>' +
        '</div>' +
        '<div class="copyright">' +
        '<span>&copy;2020 ROOM SEARCH PVT. LTD</span>' + '</div>' +
        '<div class="social-media-icons">' +
        '<a href="https://www.facebook.com/"  target="_blank">' +
        '<img src="./assests/images/facebook.png" alt="Fackbook"/>' +
        '</a>' +
        '<a href="https://www.instagram.com/"  target="_blank">' +
        '<img src="./assests/images/instagram.png" alt="Instagram"/>' +
        '</a>' +
        '<a href="https://www.twitter.com/"  target="_blank">' +
        '<img src="./assests/images/twitter.png" alt="Twitter"/>' +
        '</a>' +
        '</div>';

    document.getElementById('footer').innerHTML += footertemplate;
}

function loginTemplate() {
    let logintemplate =
        '<div class="modal-dialog" role="document">' +
        '<div class="modal-content">' +
        '<div class="modal-header">' +
        '<h5 class="modal-title" id="exampleModalLabel">Please Login</h5>' +
        '<button type="button" class="close" data-dismiss="modal" aria-label="Close">' +
        '<span aria-hidden="true">&times;</span>' +
        '</button>' +
        '</div>' +
        '<div class="modal-body pt-4 pb-2 pl-0 pr-0">' +
        '<!-- Modal body form Added -->' +
        '<form>' +
        '<div class="form-group row text-center mx-auto">' +
        '<label for="exampleInputName" class="col-sm-4 col-form-label line-height-1">Username:</label>' +
        '<div class="col-sm-6">' +
        '<input type="text" class="form-control form-control-sm p-1" id="username" autocomplete="off" placeholder="Enter Username">' +
        '</div>' +
        '</div>' +
        '<div class="form-group row text-center mx-auto">' +
        '<label for="exampleInputPassword" class="col-sm-4 col-form-label line-height-1">Password:</label>' +
        '<div class="col-sm-6">' +
        '<input type="password" class="form-control form-control-sm p-1" id="password" autocomplete="off" placeholder="Enter Password">' +
        '</div>' +
        '</div>' +
        '<div class="modal-footer justify-content-center pb-0">' +
        '<button type="button" class="btn btn-primary" data-dismiss="modal" onClick="loginFunction(event)">Login</button>' +
        '</div>' +
        '</form>' +
        '</div>' +
        '</div>' +
        '</div>';
    document.getElementById('login-modal').innerHTML += logintemplate;
}

function loginFunction(e) {

    e.preventDefault();
    alert("Login Successfully");
}

function contactTemplate() {
    let contacttemplate =
        '<div class="modal-dialog" role="document">' +
        '<div class="modal-content">' +
        '<div class="modal-header">' +
        '<h5 class="modal-title" id="exampleModalLabel">Get in touch</h5>' +
        '<button type="button" class="close" data-dismiss="modal" aria-label="Close">' +
        '<span aria-hidden="true">&times;</span>' +
        '</button>' +
        '</div>' +
        '<div class="modal-body pt-4 pb-2 pl-0 pr-0">' +
        '<p class="mb-0 mt-0 pl-3">Thank you for reaching out!!!</p>' +
        '<p class="mt-0 pl-3">Please enter your email and we will get back to you.</p>' +
        '<!-- Modal body form Added -->' +
        '<form>' +
        '<div class="form-group row mx-auto">' +
        '<label for="exampleInputEmail" class="col-sm-2 col-form-label line-height-1 pl-3 pr-0">Email:</label>' +
        '<div class="col-sm-6 pr-0">' +
        '<input type="email" class="form-control form-control-sm p0-1" id="exampleInputEmail" autocomplete="off" placeholder="Enter your email id">' +
        '</div>' +
        '</div>' +
        '<div class="modal-footer pb-0">' +
        '<button type="button" class="btn btn-primary" data-dismiss="modal">Submit</button>' +
        '</div>' +
        '</form>' +
        '</div>' +
        '</div>' +
        '</div>' +
        '</div>';
    document.getElementById('contactus-modal').innerHTML += contacttemplate;
}


$(document).ready(function() {
    preloaderFadeOutTime = 1000;

    function hidePreloader() {
        var preloader = $('.spin');
        preloader.fadeOut(preloaderFadeOutTime);
    }
    hidePreloader();
});