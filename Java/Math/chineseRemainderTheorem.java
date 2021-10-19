public class chineseRemainderTheorem {
    static int findMinX(int num[], int rem[], int k)
    {
        int x = 1; // Initialize result
      
        // As per the Chinese remainder theorem,
        // this loop will always break.
        while (true)
        {
            // Check if remainder of x % num[j] is
            // rem[j] or not (for all j from 0 to k-1)
            int j;
            for (j=0; j<k; j++ )
                if (x%num[j] != rem[j])
                   break;
      
            // If all remainders matched, we found x
            if (j == k)
                return x;
      
            // Else try next numner
            x++;
        }
      
    }
    public static void main(String[] args) {
        int num[] = {3, 4, 5};
        int rem[] = {2, 3, 1};
        int k = num.length;
        System.out.println("x is " + findMinX(num, rem, k));
    }
}
