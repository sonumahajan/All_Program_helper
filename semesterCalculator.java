class Sem1{
    Double AVG_SEM1,M11,M12,M13,M14;
//Creating Constructor
    Sem1(){
        M11 = 85.2;
        M12 = 87.2;
        M13 = 82.3;
        M14 = 78.8;
        AVG_SEM1 = (M11+M12+M13+M14)/4;
    }
}
class Sem2 extends Sem1{
    Double AVG_SEM2,M21,M22,M23,M24;
//Creating Constructor
    Sem2(){
        M21 = 75.2;
        M22 = 89.3;
        M23 = 92.5;
        M24 = 63.2;
        AVG_SEM2 = (M21+M22+M23+M24)/4;
    }
}
class Sem3 extends Sem2{
    Double AVG_SEM3,M31,M32,M33,M34;
//Creating Constructor
    Sem3(){
        M31 = 88.6;
        M32 = 85.7;
        M33 = 96.5;
        M34 = 75.3;
        AVG_SEM3 = (M31+M32+M33+M34)/4;
    }
}

class Sem4 extends Sem3{
    Double SEM_AVG,AVG_SEM4,M41,M42,M43,M44;
//Creating Constructor
    Sem4(){
        M41 = 79.1;
        M42 = 95.3;
        M43 = 99.5;
        M44 = 90.3;
        AVG_SEM4 = (M41+M42+M43+M44)/4;
        //Total Semester Average
        SEM_AVG = (AVG_SEM1+AVG_SEM1+AVG_SEM3+AVG_SEM4)/4;
    }
}

public class semesterCalculator{
    public static void main(String[] args) {
        Sem4 semester = new Sem4();   
        System.out.println("------------------------------------------");
        System.out.println("Semester 1 Average : " + semester.AVG_SEM1);
        System.out.println("------------------------------------------");
        System.out.println("Semester 2 Average : " + semester.AVG_SEM2);
        System.out.println("------------------------------------------");
        System.out.println("Semester 3 Average : " + semester.AVG_SEM3);
        System.out.println("------------------------------------------");
        System.out.println("Semester 4 Average : " + semester.AVG_SEM4);
        System.out.println("------------------------------------------");
        System.out.println("Total Semester Average : " + semester.SEM_AVG);
        System.out.println("------------------------------------------");
    }
}