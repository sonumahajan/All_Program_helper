//Problem Statement is from codechef.

package CodeChef;
import java.util.*;
public class PointOfImpact {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int t = s.nextInt();
		while(t-- !=0) {
			int n = s.nextInt();
			int k = s.nextInt();
			int x = s.nextInt();
			int y = s.nextInt();
			if(x==y) {
				System.out.println(n + " " + n);
			}
			else {
			if(x>y) {
				List<Integer> list1 = new ArrayList<Integer>(4); 
		        list1.add(0,x-y);
		        list1.add(1,n);
		        list1.add(2,n+y-x);
		        list1.add(3,0); 
		        List<Integer> list2 = new ArrayList<Integer>(4); 
		        list2.add(0,0);
		        list2.add(1,n+y-x);
		        list2.add(2,n);
		        list2.add(3,x-y); 
		        int num=k%4;
		        System.out.print(list1.get(num));
		        System.out.print(" ");
		        System.out.print(list2.get(num));
		        System.out.println();
			}
			else {
				List<Integer> numbers1 = new ArrayList<Integer>(4);
				numbers1.add(0,0);
				numbers1.add(1,n+x-y); 
		        numbers1.add(2,n);
		        numbers1.add(3,y-x); 
		        List<Integer> numbers2 = new ArrayList<Integer>(4);
		        numbers2.add(0,y-x);
		        numbers2.add(1,n); 
		        numbers2.add(2,n+x-y);
		        numbers2.add(3,0); 
		        int num=k%4;
		        System.out.print(numbers1.get(num));
		        System.out.print(" ");
		        System.out.print(numbers2.get(num));
		        System.out.println();
			}
			}
			
}
		s.close();
}
}
