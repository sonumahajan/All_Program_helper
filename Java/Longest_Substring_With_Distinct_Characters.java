import java.util.*;
 
public class Main {
 
    static final int NO_OF_CHARS = 256;
 
    static int longestUniqueSubsttr(String str)
    {
        int n = str.length();
 
        int res = 0;
 
        // last index of all characters is initialized as -1
        int [] lastIndex = new int[NO_OF_CHARS];
        Arrays.fill(lastIndex, -1);
 
        int i = 0;
 
        for (int j = 0; j < n; j++) {
            i = Math.max(i, lastIndex[str.charAt(j)] + 1);

            // Update result if we get a larger window
            res = Math.max(res, j - i + 1);

            // Update last index of j.
            lastIndex[str.charAt(j)] = j;
        }
        return res;
    }
 
    /* Driver program to test above function */
    public static void main(String[] args)
    {
        String str = "abaacdbab";
        // System.out.println("The input string is " + str);
        int len = longestUniqueSubsttr(str);
        System.out.println("The length of "
                           + "the longest non repeating character is " + len);
    }
}