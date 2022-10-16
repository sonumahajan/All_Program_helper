import java.io.*;
import java.net.*;

public class Rserver {
    public static void main(String[] args) {
        try {
            ServerSocket sock1 = new ServerSocket(6666);
            Socket s = sock1.accept();
            System.out.println("Server: Established connection");// establishes connection
            DataInputStream receiveddata = new DataInputStream(s.getInputStream());
            System.out.println("Server: Recevied data ");
            String str = (String) receiveddata.readUTF();
            System.out.println("Hola !" + str + "Welcome to the server");
            sock1.close();
        } catch (Exception e) {
            System.out.println(e);
        }
    }
}