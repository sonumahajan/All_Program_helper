public class catalanNumber {
    
    public static int catalan(int n)
    {
        int res = 0;
 
        // Base case
        if (n <= 1)
        {
            return 1;
        }
        for (int i = 0; i < n; i++)
        {
            res += catalan(i)
                * catalan(n - i - 1);
        }
        return res;
    }
    
    static long binomialCoeff(int n, int k)
    {
        long res = 1;
 
        // Since C(n, k) = C(n, n-k)
        if (k > n - k) {
            k = n - k;
        }
 
        // Calculate value of [n*(n-1)*---*(n-k+1)] /
        // [k*(k-1)*---*1]
        for (int i = 0; i < k; ++i) {
            res *= (n - i);
            res /= (i + 1);
        }
 
        return res;
    }
    static long catalan1(int n)
    {
        // Calculate value of 2nCn
        long c = binomialCoeff(2 * n, n);
 
        // return 2nCn/(n+1)
        return c / (n + 1);
    }
 
    public static void main(String[] args) {
        for (int i = 0; i < 10; i++)
        {
            System.out.print(catalan(i) + " ");
        } 
        System.out.print(catalan1(11) + " ");
    }
}
