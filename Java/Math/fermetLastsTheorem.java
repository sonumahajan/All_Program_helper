public class fermetLastsTheorem {
    static void testSomeNumbers(int limit, int n)
    {
        if (n < 3)
            return;
         
        for (int a = 1; a <= limit; a++)
            for (int b = a; b <= limit; b++)
            {
                int pow_sum = (int)(Math.pow(a, n)
                               + Math.pow(b, n));
                double c = Math.pow(pow_sum, 1.0 / n);
                int c_pow = (int)Math.pow((int)c, n);
                if (c_pow == pow_sum)
                {
                    System.out.println("Count example found");
                    return;
                }
            }
         
            System.out.println("No counter example within given"+
                               " range and data");
    }
     
    // Driver code
    public static void main (String[] args)
    {
        testSomeNumbers(12, 5); 
    }
}
