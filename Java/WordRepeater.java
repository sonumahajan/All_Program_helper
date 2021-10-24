import java.util.Scanner;

public class WordRepeater {
    private String bunga;
    private int jumlah;
    private boolean barisbaru;
    private String tmp;
    
    public static void main(String[] args) {
      welcome();
      Scanner gemas = new Scanner(System.in);
      WordRepeater huda = new WordRepeater();
      out("Enter Text:");
      huda.setText(gemas.nextLine());
      out("Repeat Count:");
      huda.repeatCount(gemas.nextInt());
      out("Repeat Mode:");
      out("[0] One Line");
      out("[1] New Line");
      out("Answer:");
      huda.newLine(convertBoolean(gemas.nextInt()));
      huda.verify(huda.newLine());
      huda.clear();

      out(huda.result());
      
    }
    private void verify(boolean nya) {
        if (nya) {
            bunga = bunga+System.getProperty("line.separator");
        }
    }
    private boolean newLine() {
        return this.barisbaru;
    }
    private void setText(String bunga) {
        this.bunga = bunga;
    }
    
    private void repeatCount(int jumlah) {
        this.jumlah = jumlah;
    }
    
    private void newLine(boolean barisbaru) {
        this.barisbaru = barisbaru;
    }
    
    private String result() {
        tmp = new String(new char[jumlah]).replace("\0", bunga);

        return this.tmp;
    }
    public static boolean convertBoolean(int cantik) {
        boolean sayang = (cantik == 0 ) ? false : true;
        
        return sayang;
    }
    public static void out(String flower) {
        System.out.println(flower);
    }
    public static void welcome() {
        out("Simple TextRepater using Java");
        System.out.println(System.getProperty("line.separator"));
    }
    private void clear() {
        
      try {
          
      
        //Todo
 
      } catch (Exception e) {
          //np
      }
    }
}
