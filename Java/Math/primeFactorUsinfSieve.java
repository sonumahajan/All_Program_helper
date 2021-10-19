import java.util.Scanner;
import java.util.Vector;

public class primeFactorUsinfSieve {

    static final int MAXN = 100001;
       
    // stores smallest prime factor for every number
    static int spf[] = new int[MAXN];

    public static void sieve()
    {
        spf[1] = 1;
        for (int i=2; i<MAXN; i++)
            spf[i] = i;
       
        for (int i=4; i<MAXN; i+=2)
            spf[i] = 2;
       
        for (int i=3; i*i<MAXN; i++)
        {    
            if (spf[i] == i)
            {
                for (int j=i*i; j<MAXN; j+=i)
                    if (spf[j]==j)
                        spf[j] = i;
            }
        }
    }

    public static Vector<Integer> getFactorization(int x){
        Vector<Integer> ret = new Vector<>();
        while (x != 1)
        {
            ret.add(spf[x]);
            x = x / spf[x];
        }
        return ret;
    }
    public static void main(String[] args) {
        sieve();
        Scanner scn=new Scanner(System.in);
        int x=scn.nextInt();
        System.out.print("prime factorization for " + x + " : ");
        Vector <Integer> p = getFactorization(x);
       
        for (int i=0; i<p.size(); i++)
            System.out.print(p.get(i) + " ");
        System.out.println();
        scn.close();
    }
}
