import java.io.*;
import java.net.*;

public class Rclient {
    public static void main(String[] args) {
        try {
            Socket s = new Socket("localhost", 6666);
            System.out.println("client: Now sending data ");
            DataOutputStream tosend= new DataOutputStream(s.getOutputStream());
            tosend.writeUTF(" Shravan ");
            tosend.flush();
            tosend.close();
            s.close();
        } catch (Exception e) {
            System.out.println(e);
        }
    }
}