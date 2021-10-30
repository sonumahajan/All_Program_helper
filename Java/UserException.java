import java.lang.Exception;
import java.util.Scanner;
class MyException extends Exception
{
    
    MyException(String msg)
    {
         super(msg);
    }
}
public class UserException
{
    public static void main(String args[])
    {
        PutData obj = new PutData();
        obj.get();
        obj.put();
        System.out.println("Main method is executed");
    }
}
class GetData
{
    Scanner sc = new Scanner(System.in);
    int i,j;
    int acc_num [] = new int[6];
    String cus_name [] = new String[6];
    int balance [] = new int[6];
    int flag [] = new int[6];
    void get()
    {   
        System.out.println("Enter the corresponding account number of the user:- ");
        for(i=0; i<acc_num.length; i++)
            acc_num[i] = sc.nextInt();
        System.out.println("Enter the corresponding name of the customer:- ");
        for(i=0; i<cus_name.length; i++)
            cus_name[i] = sc.nextLine();
        System.out.println("Enter the corresponding balance amount of the user:- ");
        for(i=0; i<balance.length; i++)
            balance[i] = sc.nextInt();
        System.out.println("Enter the minimum balance amount :- ");  
        for(i=0; i<flag.length; i++)
            flag[i] = sc.nextInt();
    } 
}

class PutData extends GetData
{
    int k;
    void put()
    {
        System.out.println("The customer details are as follows:-");
        System.out.println("Account Number :- ");
        for(j=0; j<acc_num.length; j++)
            System.out.print(acc_num[j]);
        System.out.println("Customer Name :- ");
        for(j=0; j<cus_name.length; j++)
            System.out.print(cus_name[j]); 
        System.out.println("Balance Amount :- ");
        for(j=0; j<balance.length; j++)
            System.out.print(balance[j]);
        System.out.println("Minimum Balance Amount :- ");
        for(k=0; k<flag.length; k++)
            System.out.print(flag[k]);   
        try
        { 
             for(k=0; k<balance.length; k++)
             {
                 if(balance[k] < flag[k])
                 {
                      throw new MyException("Balance Amount is less");
                 }
             }
        }
        catch (MyException ex)
        {
            System.out.println("Exception Caught");
            System.out.println(ex.getMessage());
        }
    }
}