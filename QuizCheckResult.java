import java.util.*;
class QuizCheckResult
{
    public static final int PASSWORD_LENGTH = 8;

    public static boolean is_Valid_Password(String password) {

        if (password.length() < PASSWORD_LENGTH) return false;

        int charCount = 0;
        int numCount = 0;
        for (int i = 0; i < password.length(); i++) {

            char ch = password.charAt(i);

            if (is_Numeric(ch)) numCount++;
            else if (is_Letter(ch)) charCount++;
            else return false;
        }


        return (charCount >= 2 && numCount >= 2);
    }

    public static boolean is_Letter(char ch) {
        ch = Character.toUpperCase(ch);
        return (ch >= 'A' && ch <= 'Z');
    }


    public static boolean is_Numeric(char ch) {

        return (ch >= '0' && ch <= '9');
    }

	// creating array object.
    char A[][],K[];
    int S[],n;
    
    void input()
    {
    	// create object of scanner class.
        Scanner sc = new Scanner(System.in);
        
        // enter number of participants.
        System.out.print("Enter number of participants : ");
        n = sc.nextInt();
        
        // condition of least and heighest input
        if(n<4 || n>10)
        {
        	// input the range here.
            System.out.print("Input size out of range : ");
            System.exit(0);
        }
        
        A = new char[n][5]; 
        K = new char[5]; 
        S = new int[n]; 
        
        // enter the correct answer to check the answers of students.
        System.out.println("\n* Enter answer of each participant row-wise in a single line *\n");
        for(int i = 0; i<n; i++)
        {
            System.out.print("Participant "+(i+1)+" : ");
            for(int j=0; j<5; j++)
            {
                A[i][j] = sc.next().charAt(0);
            }
        }
        System.out.print("\nEnter Answer Key : ");
        for(int i = 0; i<5; i++)
        {
            K[i] = sc.next().charAt(0);
        }
    }
 
    // Function to calculate score of participant
    void Score() 
    {
 
        for(int i = 0; i<n; i++)
        {
            S[i] = 0;
            for(int j=0; j<5; j++)
            {
            	// Checking if Answer of the participants match with the key or not
                if(A[i][j] == K[j]) 
                {
                    S[i]++;
                }
            }
        }
    }
 
    // function to print score.
    void printScore()
    {
        int max = 0;
        System.out.println("\nSCORES : ");
        for(int i = 0; i<n; i++)
        {
            System.out.println("\tParticipant "+(i+1)+" = "+S[i]);
            if(S[i]>max)
            {
            	// Storing the Highest Score
                max = S[i]; 
            }
        }
        System.out.println();
         
        System.out.println("\tHighest Score : "+max);
         
        // Printing all those participant number who got highest score
        System.out.println("\tHighest Scorers : ");
        for(int i = 0; i<n; i++) 
        {
            if(S[i] == max)
            {
                System.out.println("\t\t\tParticipant "+(i+1));
            }
        }
    }
 
    public static void main(String args[])
    {

        Scanner input = new Scanner(System.in);
        System.out.print(
                "1. A password must have at least eight characters.\n" +
                "2. A password consists of only letters and digits.\n" +
                "3. A password must contain at least two digits \n" +
                "Input a password (You are agreeing to the above Terms and Conditions.): ");
        String s = input.nextLine();

        if (is_Valid_Password(s)) {
            System.out.println("Password is valid: " + s);
        } else {
            System.out.println("Not a valid password: " + s);
        }
    	QuizCheckResult ob = new QuizCheckResult();
        ob.input();
        ob.Score();
        ob.printScore();
    }
}

