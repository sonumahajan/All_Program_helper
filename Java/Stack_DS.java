import java.util.Scanner;
import java.io.IOException;

class Stack {
    private static final int MAX = 5;   //Maximum Stack Size
    private int top;
    private int arr[] = new int[MAX];

    public Stack() {
        top = -1;
    }

    public void push(int val) {
        if(top >= MAX-1){
           System.out.println("\nStack is Overflow.");
           return;
        } 
           arr[++top] = val;
           System.out.println("\nValue Pushed.");
    }

    public int pop() {
        if (top < 0) {
            System.out.println("\nStack is Underflow.");
            return -1;
        }
        return arr[top--];
    }

    public int peek() {
        if (top < 0) {
            System.out.println("\nStack is Underflow");
            return -1;
        }
        return arr[top];
    }

    public boolean isEmpty() {
        return (top < 0);
    }
    public boolean isFull(){
        return top == MAX-1;
    }

    public void printStack() {
        if (top < 0) {
            System.out.println("\nStack is Underflow");
            return;
        }
        System.out.println("\nStack:");
        for (int i = 0; i <= top; i++) {
            System.out.print(arr[i] + "  ");
        }
    }
}

public class Stack_DS {
    static Scanner input = new Scanner(System.in);

    static byte menu() {
        clearConsole();
        System.out.println("1] PUSH Element");
        System.out.println("2] POP Element");
        System.out.println("3] Is Stack Underflow ?");
        System.out.println("4] Is Stack Overflow ?");
        System.out.println("5] Print Stack");
        System.out.println("6] Exit");
        byte choice = 0;
        try {
            System.out.print("\nEnter Your Choice: ");
            choice = input.nextByte();
        } catch (Exception ex) {
            System.out.println("\n\nInvalid Choice");
            input.nextLine();
        }
        return choice;
    }

    // To clear the Console
    static void clearConsole() {
        System.out.println("\033[H\033[2J");
        System.out.flush();
        // System.out.println('\f'); Or // System.out.println('\u000C');
    }

    // To Get Key Press
    static void getKeyPress() {
        try {
            char ch = (char) System.in.read();
        } catch (IOException e) {}
    }

    public static void main(String[] args) {
        Stack s1 = new Stack();

        while (true) {
            switch (menu()) {
                case 1:
                    System.out.print("\nEnter Value to Insert: ");
                    int val = input.nextInt();
                    s1.push(val);
                    break;
                case 2:
                    int popValue = s1.pop(); 
                    if(popValue >=0)
                       System.out.println("\nPoped Value: " + popValue);    
                    break;
                case 3:
                    System.out.println("\nStack is " + (s1.isEmpty() ? "Underflow." : "Not Underflow."));
                    break;
                case 4:
                    System.out.println("\nStack is " + (s1.isFull() ? "Overflow." : "Not Overflow."));
                    break;    
                case 5:
                    s1.printStack();
                    break;
                case 6:
                    System.exit(1);
                    break;
                default:
                    System.out.println("\nInvalid Choice");
                    break;
            }
            getKeyPress();
        }
    }
}
