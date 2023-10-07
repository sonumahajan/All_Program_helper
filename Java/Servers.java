import java.io.*;
import java.net.*;
public class Servers {
  public static void main(String[] args) {
    try {
      ServerSocket ss = new ServerSocket(6666);
      Socket s = ss.accept(); // establishes connection
      //   DataInputStream dis = new DataInputStream(s.getInputStream());
      DataInputStream dis = new DataInputStream(new BufferedInputStream(socket.getInputStream()));

      String str = (String) dis.readUTF();

      System.out.println("message= " + str.toUpperCase());
      ss.close();
    } catch (Exception e) {
      System.out.println(e);
    }
  }
}