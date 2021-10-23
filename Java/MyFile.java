import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;
public class MyFile
{
    public static void FileWriteOperation()
    {
        try{
            FileWriter fileWriteObj = new FileWriter("file1.txt");
            fileWriteObj.write("Hello, I'm John Doe Studying in Shri K.J Polytechnic Bharuch.");
            System.out.println("Successfully Written.");
            fileWriteObj.close();
        }
        catch(IOException e){
            System.out.println("Any Error occured.");  
        }
    } 

    public static void FileReadOperation()
    {
        try{
            File fileObj = new File("file1.txt");
            Scanner fileReadobj = new Scanner(fileObj);           
            while(fileReadobj.hasNextLine()){
              String data = fileReadobj.nextLine();
              System.out.println(data);  
            }
            fileReadobj.close();
        }
        catch(IOException e){
            System.out.println("Any Error occured.");  
        }
    } 

    public static void FileDeleteOperation(){
        String strToFind = "Shri";
        String strToReplace = "Shree";

        try{
            File fileRead = new File("file1.txt");
            Scanner fread = new Scanner(fileRead);

            File fileWrite = new File("tempfile.txt");
            FileWriter fout = new FileWriter(fileWrite,true);

            while(fread.hasNextLine()){
                String str = fread.nextLine();
                
                str = str.replaceFirst(strToFind, strToReplace);

                fout.write(str);
            }

            String fileName = fileRead.getPath();
            fileRead.delete();

            if(fileWrite.renameTo(new File(fileName)))
                System.out.println("Delete Success");
            else 
                System.out.println("Delete Not Success");
              
            fread.close();
            fout.close();    

        }catch(IOException e){
            System.out.println("Any Error occured.");  
        }
    }
    public static void main(String args[])
    {
    //  FileReadOperation();
    //  FileWriteOperation(); 
        FileDeleteOperation();
    }
}
