public class fibonachiUsingMatrix {
    //oLog(n) time 
    public static int fib(int n){
        int a = 0, b = 1, c;
        if (n == 0)
            return a;
        for (int i = 2; i <= n; i++)
        {
            c = a + b;
            a = b;
            b = c;
        }
        return b;
    }

    public static int fibmatrix(int n){
        int F[][] = new int[][]{{1,1},{1,0}};
        if (n == 0)
            return 0;
        power(F, n-1);
        
        return F[0][0];
    }
    static void multiply(int F[][], int M[][])
    {
        int x =  F[0][0]*M[0][0] + F[0][1]*M[1][0];
        int y =  F[0][0]*M[0][1] + F[0][1]*M[1][1];
        int z =  F[1][0]*M[0][0] + F[1][1]*M[1][0];
        int w =  F[1][0]*M[0][1] + F[1][1]*M[1][1];
        
        F[0][0] = x;
        F[0][1] = y;
        F[1][0] = z;
        F[1][1] = w;
    }
    static void power(int F[][], int n)
    {
        if( n == 0 || n == 1)
            return;
        int M[][] = new int[][]{{1,1},{1,0}};
        
        power(F, n/2);
        multiply(F, F);
        
        if (n%2 != 0)
            multiply(F, M);
    }
    public static void main(String[] args) {
        int n=11;
        System.out.println(fib(n));
        System.out.println(fibmatrix(n));
    }
}
