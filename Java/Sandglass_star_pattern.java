import java.util.Scanner;

public class Sandglass_star_pattern {
	private static Scanner sc;
	
	public static void main(String[] args) {
		sc = new Scanner(System.in);
		
		int i, j, k;
		
		System.out.print("Please Enter Sandglass Pattern Rows = ");
		int rows = sc.nextInt();
		
		System.out.println("Printing Sandglass Star Pattern");
		
		for (i = 0 ; i <= rows - 1; i++ ) 
		{
			for (j = 0 ; j < i; j++ ) 
			{
				System.out.print(" ");
			}
			for(k = i; k <= rows - 1; k++) 
			{
				System.out.print("* ");
			}
			System.out.println();
		}
		
		for (i = rows - 1; i >= 0; i-- ) 
		{
			for (j = 0 ; j < i; j++ ) 
			{
				System.out.print(" ");
			}
			for(k = i; k <= rows - 1; k++) 
			{
				System.out.print("* ");
			}
			System.out.println();
		}
	}
}
