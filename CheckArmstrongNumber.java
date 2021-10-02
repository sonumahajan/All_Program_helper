//PROGRAM TO CHECK WHETHER THE NUMBER IS ARMSTRONG OR NOT

import java.util.Scanner;

public class ArmstrongNumber 
{

    public static void main(String[] args) {

        int num, number, temp, total = 0;
        System.out.println("Enter the number:");
        Scanner inp = new Scanner(System.in);
        num = scanner.nextInt();
        inp.close();
        number = num;

        for( ;number!=0;number /= 10)
        {
            temp = number % 10;
            total = total + temp*temp*temp;
        }

        if(total == num)
            System.out.println(num + " is ARMSTRONG NUMBER");
        else
            System.out.println(num + " is an ARMSTRONG NUMBER");
    }
}
