    var map;

    function initMap() {
        map = new google.maps.Map(document.getElementById("map"), {
            center: { lat: -34.397, lng: 150.644 },
            zoom: 8
        });
    }


    var settings = {
        "async": true,
        "crossDomain": true,
        "url": "https://tripadvisor1.p.rapidapi.com/answers/list?limit=10&question_id=5283833",
        "method": "GET",
        "headers": {
            "x-rapidapi-host": "tripadvisor1.p.rapidapi.com",
            "x-rapidapi-key": "4cd554b5d0msh64fbc9215092a71p1053f8jsn747a753f682f"
        }
    }

    $.ajax(settings).done(function(response) {
        console.log(response);
    });