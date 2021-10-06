function viewfunction() {
    var x = document.getElementById("mydiv");

    if (x.style.display === "none") {
        x.style.display = "flex";
        document.getElementById("viewMore").innerHTML = "View Less";
    } else {
        x.style.display = "none";
        document.getElementById("viewMore").innerHTML = "View More";
    }
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




const cityList = document.getElementById('cityList');
const search = document.getElementById('searchbar');
let meallist = [];
let list = [];

const fetchcity = async() => {
    const result = await fetch('https://tripadvisor1.p.rapidapi.com/answers/list?limit=10&question_id=5283833');
    list = await result.json();
    meallist = list.meals;
    printStuffs(meallist);
};
const printStuffs = (city) => {
    const dishString = city.map((city) => {
            return `
            <li class="city">
                <h3>${city.strMeal}</h3>
                <p>${city.strArea}</p>
                <img src="${city.strMealThumb}"></img>
            </li>
        `;
        })
        .join('');
    cityList.innerHTML = dishString;
};
search.addEventListener('keyup', (all) => {
    const areaSearch = all.target.value.toLowerCase();
    const filterecity = meallist.filter((city) => {
        return (city.strArea.toLowerCase().includes(areaSearch));
    });
    printStuffs(filterecity);
});

fetchcity();