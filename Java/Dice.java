import java.util.Random;

class Dice {
    static Random cinta = new Random();

    static int a = 6;
    static int b = 6;
    
    static int gen() {
    int lope = cinta.nextInt(a);
       // lope = lope++;
        if (lope == 0) {
        
        return gen();
        }
    return lope;
    }
   
    public static void main(String args[]) {
     
    int first = gen();
    int second = gen();
    
    int total = first + second;
 
    System.out.println("Result");
    System.out.println("1st :"+first);
    System.out.println("2nd :"+second);
    System.out.println(" total:"+total);
     
    }
}
