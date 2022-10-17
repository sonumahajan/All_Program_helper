
import java.util.Scanner;

public class main {
	public static void main(String[] args) {
		Scanner scan= new Scanner(System.in);
		System.out.println("Enter msg:");	
        	String str=scan.next();
        	System.out.println("Enter key: ");
        
        	for(int i=0,x=str.length(), k = scan.nextInt();i<x;System.out.print((char)(str.charAt(i++) + k ))); 
    }

}
