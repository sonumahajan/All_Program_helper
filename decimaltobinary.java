//conversion of a decimal number to its binary form that is 0s & 1s 

import java.util.*;
public class DecimalToBinaryExample2{    
public static void toBinary(int decimal){    
     int binary[] = new int[40];    
     int index = 0;    
     while(decimal > 0){    
       binary[index++] = decimal%2;    
       decimal = decimal/2;    
     }    
     for(int i = index-1;i >= 0;i--){    
       System.out.print(binary[i]);    
     }    
System.out.println();//new line  
}    
public static void main(String args[]){  
Scanner sc=new Scanner(System.in);   //user input
int n=sc.nextInt(); 
toBinary(n);  
}}