import java.util.Scanner;

public class DudeneyNumber
{
    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        System.out.print("Enter the number: ");
        int n = in.nextInt();

        //Check if n is a perfect cube
        int cubeRoot = (int)Math.round(Math.cbrt(n));
        if (cubeRoot * cubeRoot * cubeRoot == n) {
            //If n is perfect cube then find
            //sum of its digits
            int s = 0;
            int t = n;
            while (t != 0) {
                int d = t % 10;
                s += d;
                t /= 10;
            }
            
            if (s == cubeRoot) {
                System.out.println(n + " is a Dudeney number");
            }
            else {
                System.out.println(n + " is not a Dudeney number");
            }
        }
        else {
            System.out.println(n + " is not a Dudeney number");
        }
    }
}