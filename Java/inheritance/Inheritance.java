// Imports
import java.util.Scanner;

// Base class
class Shape {
    double area, parameter;
    String name;

    Shape(String n, double a, double p) {
        area = a;
        parameter = p;
        name = n;
    }

    void display() {
        System.out.println(name +"'s\nParameter: "+parameter+"\nArea: " + area);
    }
}

// Child class One
class Circle extends Shape {
    double radius;

    Circle(double r) {
        super("Circle", Math.PI * r * r, 2 * Math.PI * r);

        radius = r;
    }

    void display() {
        System.out.println(name +" of radius " + radius + "'s\nParameter: "+parameter+"\nArea: " + area);
    }
}

// Child class Two
class Square extends Shape {
    double side;

    Square(double r) {
        super("Square",  r * r, 4 * r);

        side = r;
    }
}

// Main class
class Inheritance {
    public static void main(String[] iudfhielrhfrekjf) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Input the circle's radius");
        double r = sc.nextDouble();
        
        System.out.println("Input the square's side");
        double s = sc.nextDouble();
        
        Circle c = new Circle(r);
        Square sq = new Square(s);

        c.display();
        sq.display();
    }
}