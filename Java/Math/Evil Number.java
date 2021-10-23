import java.util.*;   //even no. of 1s in a binary form
class evil
{
    public static void main(String args[])
    {
        Scanner I=new Scanner(System.in);
        int n,c=0;
        String s="";
        System.out.println("ENTER A NO.");
        n=I.nextInt();
        while(n>0)
         {
                s=Integer.toString(n%2)+s;
                n/=2;
         }
        for(int i=0;i<s.length();i++)   
          if(s.charAt(i)=='1')
            c++;
        if(n>=0)
         if(c%2==0)
          System.out.println("EVIL NUMBER");
          else
          System.out.println("Not An EVIL NUMBER");
          else
          System.out.println("INVALID ENTRY");
        }
    }
