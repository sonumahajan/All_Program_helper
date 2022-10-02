const computerchoiceDisplay = document.getElementById('computer-choice') ;
const userchoiceDisplay = document.getElementById('your-choice') ;
const resultDisplay = document.getElementById('result') ;

const possibleChoices = document.querySelectorAll('button') ;
let userChoice ;
let computerChoice ;

possibleChoices.forEach(possibleChoice => possibleChoice.addEventListener('click',(e) => {

        userChoice =  e.target.id ; // rock
        userchoiceDisplay.innerHTML = userChoice ;
        // Now each time user click , i need to generate computer choice
        generateComputerChoice() ;
        getResult() ;
}))

function generateComputerChoice() {

    const randomNumber = Math.floor(Math.random()*3)+1 ;  // you can also use possibleChoices.length
    console.log(randomNumber) ;

    if(randomNumber == 1) {
        computerChoice = "rock" ;
    }
    if(randomNumber == 2) {
        computerChoice = "paper" ;
    }
    if(randomNumber == 3) {
        computerChoice = "scissor" ;
    }

    computerchoiceDisplay.innerHTML = computerChoice ;
}

function getResult() {
    if(computerChoice == userChoice) {
        result = "its a draw !" ;
    }
    else if(computerChoice === "rock") {
        result = "you lost" ;
    }
    else if(userChoice == "paper") {
        result = "You Lost !" ;
    } 
    else result = "You Win !" ;

    resultDisplay.innerHTML = result ;
}
