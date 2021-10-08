package encrypt;
import java.util.Scanner;


public class main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int key=26;

		int k;

		Scanner scan=new Scanner(System.in);

		System.out.println("Enter msg");	

String str=scan.next();

System.out.println("enter key");

k=scan.nextInt();

int x=str.length();

if(k==key)

{for(int i=0;i<x;i++)

{int d=str.charAt(i);

int e=(d*2)+2;

int f=(e/2)-1;

System.out.print((char)f);







}

	}}



	}
