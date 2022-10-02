public class CustomMethods {
    public static void main(String args[]) {
     booleanTest(true);
     intTest(50);
    }

    public static void booleanTest(boolean isPass){

        if (isPass == true){
            System.out.println("He got great marks and he is Pass");
        }else{
            System.out.println("He tried well but didn't came through");
        }

    }

    public static void intTest(int marks){
        if (marks < 33){
            System.out.println("He is fail");
        }else if (marks > 33 && marks < 50) {
            System.out.println("He is Pass");
        }else if (marks >= 50 && marks < 80){
            System.out.println("He got marks above average");
        }else{
            System.out.println("He got great marks. Cheers!");
        }
    }
}
