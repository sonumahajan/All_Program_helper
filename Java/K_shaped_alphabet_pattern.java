public class K_shaped_alphabet_pattern  
{  
public static void main(String[] args)  
{  
for (int i = 8; i >= 0; i--)  
{  
int alphabet = 65;  
for (int j = 0; j <= i; j++)  
{  
System.out.print((char) (alphabet + j) + " ");  
}  
System.out.println();  
}  
for (int i = 0; i<= 8; i++)  
{  
int alphabet = 65;  
for (int j = 0; j <= i; j++)  
{  
System.out.print((char) (alphabet + j) + " ");  
}  
System.out.println();  
}  
}  
}  
