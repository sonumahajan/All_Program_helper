//This program helps you convert a string so that it gets easy to type it on a Nokia Keypad
// For example - for typing "hello", you need to type -
// h -> 4 4 (2 times number 4 key)
// e -> 3 3 
// l -> 5 5 5 
// l -> 5 5 5 
// o -> 6 6 6 

import java.util.Scanner;
public class nok_key {
public static void main(String[] args) {

		String a="";
		int i=0,j=0,n=0,m=0;
		String str[] = {" "," ","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
		Scanner scan = new Scanner(System.in);
		System.out.println("This program helps you convert a string so that it gets easy to type it on a Nokia Keypad.\nEnter a String (without special characters):");
		a = scan.nextLine().toLowerCase();
		String k = "";
		char[] chars = a.toCharArray();
		String sorted = new String(chars);
		System.out.println("Entered Word -> " + sorted);

		for(i=0;i<sorted.length();i++)
		{
			for(j=0;j<10;j++)
			{
				k = Character.toString(sorted.charAt(i));
				if((str[j].contains(k)) == false) {
				    if(j==9) {
				      System.out.print(k + " -> Invalid Character");  
				      break;
				    }
					continue;
				}
				else {
				    n = str[j].indexOf(k);
				    System.out.print(k + " -> ");
				    for(m=0 ; m<n+1 ; m++) {
				        System.out.print((j) + " ");
				    }
				    System.out.print("\n");
				    break;
				}
			}
		}
	}
}
