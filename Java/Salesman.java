import java.util.*;
import java.io.DataInputStream;
class Salesman{
public static void main(String args[]){
    DataInputStream sc=new DataInputStream(System.in);
    int sales[][]=new int[2][4];
    int i,j,tot;
    try{
        for(i=0;i<5;i++){
            tot=0;
            System.out.println("Enter Sales of Sales Man "+(i+1));
            for(j=0;j<=12;j++){System.out.println("Month "+(j+1)+ " : ");
                sales[i][j]=Integer.parseInt(sc.readLine());
                tot+=sales[i][j];
            }
            System.out.println("Total sales  Salesman "+(i+1)+" = " + tot);
        }
    }
    catch(Exception e) {}
}
}