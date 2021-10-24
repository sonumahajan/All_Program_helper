#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
/*
    Hey there This is Om Duragkar wanted to share a game which can engage people to learn c.
    The game is to guess no. v/s with computer in less attempt
    Best Luck!,
    Regards,
    Om Duragkar
*/
void display1();
void display2();
void display3();
void display4();
int main(){
    int attempt=1;
    printf("Hello gamers\n");
    display1();
    display2();
    display3();
    display4();
    printf("Please rate our game!!!\nThanks for downloading it\n");
    getch();
}
 void display1(){
    printf("let's begin\n");
    printf("Press Enter: ");

}
void display2(){
    getch();
    printf("\n\nHey, how are you?Lets go through the rules: \nRule 1: dont try to cheat\nThats it..Thanks for downloading!!\n Press Enter to start the game: ");
    getch();
    printf("Lets start the game\n");
}
void display3(){
    int number, guess, attempt=1;
    srand(time(0));
    number =rand()%100+ 1;
    printf("Computer has guessed a random no. now it's your turn to guess it\n");
    do
    {
        
        printf("Guess the no. between 1 to 100\n");
        scanf("%d", &guess);
        if (number>guess)
        {
            printf("You have entered a slighlty lower number, Enter a higher no.\n");
        }
        else if (number<guess)
        {
            printf("You have entered a slighlty higher number,Enter a lower no.\n");
        }
        else{
            printf("You guessed it in %d attempts\n", attempt);
        }
        attempt++;
        
    } while (guess!=number);    
    
} 
void display4(){
    int bomb;
    printf("You have won the game \nThanks for downloading game\n");
    printf("Press  enter to End the Game\n");
    getch();
}