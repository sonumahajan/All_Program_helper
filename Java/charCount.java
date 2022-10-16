import java.io.*;
public class charCount
{
    public static void main (String[] args) throws Exception {    
        String string = "The best of both worlds";
        int count = 0;
        
        
        //counts each character except space 
        for(int i = 0; i <string.length();i++){
            if(string.charAt(i) != ' ')
            count++;
        }
        
        System.out.println("Total number of characters in a string: "+count);
        
    }
}
