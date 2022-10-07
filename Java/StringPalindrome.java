
import java.util.*;
class HelloWorld {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
         System.out.print("Enter a String : ");
         String s1 = sc.nextLine();
         String rev="";

         for(int i=0;i<s1.length();i++){
             rev=s1.charAt(i)+rev;
         }
         System.out.println(rev);
         if(s1.equals(rev)){
             System.out.println("Palindrome");
         }
         else{
             System.out.println("Not Palindrome");
         }
    }
}
