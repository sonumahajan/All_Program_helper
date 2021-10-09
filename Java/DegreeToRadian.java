import java.util.Scanner;
import java.lang.Math;

class DegreeToRadian {
    public static void main(String[] args) {
      Scanner input = new Scanner(System.in);
      System.out.println("Input Degree:");
      double deg = input.nextInt();
      System.out.println("Result:");
      System.out.println(Math.toRadians(deg));
    }
}
