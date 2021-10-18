// variables and constants
let inputDir = { x:0 , y:0};
const foodSound = new Audio('food.mp3');
const moveSound = new Audio('move.mp3');
const musicSound = new Audio('music.mp3');
const gameoverSound = new Audio('gameover.mp3');
let lastPaintTime = 0;
let speed = 5;
let snakeArr = [
    { x:13,y:15,}
]
food = {x:5 , y:7}
let score = 0;


//Game Functions
function main(ctime){
    window.requestAnimationFrame(main);
    //console.log(ctime);

    if((ctime - lastPaintTime)/1000 < 1/speed){
        return;
    }
 lastPaintTime = ctime;
 gameEngine();
}
function isCollide(sarr){
// case 1: If bumped into myself
for(let i=1; i< snakeArr.length; i++){
    if(sarr[i].x === sarr[0].x && sarr[i].y === sarr[0].y){
        return true;
    }
}

// Case 2: Bumped into the wall

if(sarr[0].x >=18 || sarr[0].x <=0 || sarr[0].y >=18 || sarr[0].y <=0){
    return true;
}
   
}
function gameEngine(){
     // Part 1: Updating snake and food

     //Collision
if(isCollide(snakeArr)){
    gameoverSound.play();
    musicSound.pause();
    inputDir = { x:0,y:0};
    alert("Game over!! Press any key to continue")
     snakeArr = [ { x:13, y:15}];
     musicSound.play();
     score = 0;
}

//Feeding

if(snakeArr[0].x === food.x && snakeArr[0].y === food.y){
    score += 1;
    if(score > hiscoreval){
        hiscoreval = score;
        localStorage.setItem("hiScore", JSON.stringify(hiscoreval));
        hiscore.innerHTML = "High score: " + hiscoreval;
    }
    scoreBox.innerHTML = "score: " + score;
    foodSound.play();
    snakeArr.unshift({x: snakeArr[0].x + inputDir.x , y: snakeArr[0].y + inputDir.y});

    let a =2;
    let b =16;
    food = {x: Math.round(a + (b-a)* Math.random()) , y: Math.round(a + (b-a)* Math.random())};
}

//Moving

for(let i= snakeArr.length-2; i>=0; i--){
snakeArr[i+1] = {...snakeArr[i]};
}

snakeArr[0].x += inputDir.x;
snakeArr[0].y += inputDir.y;


     //Part 2: Display snake and food

     //display snake
     board.innerHTML = "";
     snakeArr.forEach((e,index) => {
         snakeElement = document.createElement('div');
         snakeElement.style.gridRowStart = e.y;
         snakeElement.style.gridColumnStart = e.x;

         
         if(index === 0){
             snakeElement.classList.add('head');
         }
         else{
            snakeElement.classList.add('snake');
         }

         board.appendChild(snakeElement);
     })

     // Display food

foodElement = document.createElement('div');
foodElement.style.gridRowStart = food.y;
foodElement.style.gridColumnStart = food.x;

foodElement.classList.add('food');
board.appendChild(foodElement);

}

// Game logic
window.requestAnimationFrame(main);

//Main logic

let hiScore = localStorage.getItem("hiScore");
if(hiScore === null){
    hiscoreval =0;
    localStorage.setItem("hiScore", JSON.stringify(hiscoreval));
}
else{
    hiscoreval = JSON.parse(hiScore);
    hiscore.innerHTML = "High score: " + hiScore;
}

window.addEventListener('keydown',e =>{
    inputDir = {x:0,y:1} //Start the game
    moveSound.play();
    musicSound.play();


    switch(e.key){
        case "ArrowDown" :
            console.log("ArrowDown");
            inputDir.x = 0;
            inputDir.y = 1;
        break;

        case "ArrowUp" :
            console.log("ArrowUp");
            inputDir.x = 0;
            inputDir.y = -1;
            break;

        case "ArrowLeft" :
            console.log("ArrowLeft");
            inputDir.x = -1;
            inputDir.y = 0;
            break;

            case "ArrowRight" :
                console.log("ArrowRight");
                inputDir.x = 1;
                inputDir.y = 0;
                break;

                default:
                       
                break;
    }

})