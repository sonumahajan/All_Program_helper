import java.util.Random;

class Dice {
    public static void main(String[] args) {

    Random cinta = new Random();

    int a = 6;
    int b = 6;

    int lope = cinta.nextInt(a);
        lope = lope++;
    int lopyu = cinta.nextInt(b);
        lopyu = lopyu++;
    int too = lope+lopyu;

    System.out.println("Result");
    System.out.println("1st :"+lope);
    System.out.println("2nd :"+lopyu);
    System.out.println(" total:"+too);


    
    }
    
}
