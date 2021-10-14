/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package hacktoberfest;

import java.util.Random;
import java.util.Scanner;

/**
 *
 * @author vuvie
 */
public class BoomNumberGame {

    private final int MIN = 1;
    private final int MAX = 9999;
    private Scanner scanner = new Scanner(System.in);
    private int lowEnd = 0;
    private int highEnd = 0;
    private int boomNumber = 0;
    private int guessNumber = 0;
    private boolean isFirstUser = true;

    public BoomNumberGame() {

    }

    public void inputRange() {
        //let user input the range for guessing
        do {
            System.out.println("Please enter low end of the range for guessing");
            try {
                lowEnd = scanner.nextInt();
                //the range should in range [MIN,MAX]
                if (lowEnd < MIN) {
                    System.out.println("low end of the range should be bigger "
                            + "than or equal to " + MIN);
                    lowEnd = 0;
                } else if (lowEnd > MAX) {
                    System.out.println("high end of the range should be bigger "
                            + "than or equal to " + MAX);
                    lowEnd = 0;
                }
            } catch (Exception ex) {
                System.out.println("Please enter an integer number in range "
                        + "1 - 10000");
                scanner.nextLine();
            }
            
        } while (lowEnd == 0);

        do {
            System.out.println("Please enter high end of the range for guessing");
            try {
                highEnd = scanner.nextInt();
                if (highEnd > MAX) {
                    System.out.println("High end of the range should be less "
                            + "than or equal to " + MAX);
                    highEnd = 0;
                } else if (highEnd <= lowEnd + 10) {
                    System.out.println("High end of the range should be bigger "
                            + "or equal to the low end + 10");
                    highEnd = 0;
                }
            } catch (Exception ex) {
                System.out.println("Please enter an integer number in range "
                        + "1 - 10000");
                scanner.nextLine();
            }
        } while (highEnd == 0);
    }

    public void randomBoom() {
        Random random = new Random();
        boomNumber = random.nextInt(highEnd - lowEnd) + lowEnd;
    }

    public int guessNumber(int n) {
        if (n > boomNumber) {
            return 1;
        } else if (n < boomNumber) {
            return -1;
        } else {
            return 0;
        }
    }

    public void playGame() {
        while (guessNumber != boomNumber) {
            System.out.println("Let's choose a number in range [" + lowEnd + ","
                    + highEnd + "]");
            // guess a number
            while (guessNumber == 0) {
                try {
                    System.out.print(isFirstUser ? "User1: " : "User2: ");
                    guessNumber = scanner.nextInt();
                    if (guessNumber <= lowEnd || guessNumber >= highEnd) {
                        System.out.println("Please choose a number in range (" + lowEnd + ","
                                + highEnd + ")");
                        guessNumber = 0;
                    }

                } catch (Exception ex) {
                    System.out.println("Please enter a integer");
                    scanner.nextLine();
                }
            }
            //check guessNumber
            switch (guessNumber(guessNumber)) {
                case -1:
                    System.out.println("Your number u choose is less "
                            + "than the boom number");
                    lowEnd = guessNumber;
                    guessNumber = 0;
                    break;
                case 1:
                    System.out.println("Your number u choose is bigger "
                            + "than the boom number");
                    highEnd = guessNumber;
                    guessNumber = 0;
                    break;
                default:
                    System.out.println("U choose the boom number, R.I.P");
                    System.out.println("Congratulation! the winner is"
                            + (isFirstUser ? "User 2" : "User 1"));
                    break;
            }
            //change user
            isFirstUser = !isFirstUser;
        }

    }
    
    public static void main(String[] args) {
        BoomNumberGame boom = new BoomNumberGame();
        boom.inputRange();
        boom.randomBoom();
        boom.playGame();
    }
}
