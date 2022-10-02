import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Binary_Search {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    
    public static int[] takeInput() throws IOException {
        int size = Integer.parseInt(br.readLine().trim());
        int[] input = new int[size];

        if (size == 0) {
            return input;
        }
        
        String[] strNums; 
        strNums = br.readLine().split("\\s");
        

        for (int i = 0; i < size; ++i) {
            input[i] = Integer.parseInt(strNums[i]);
        }

        return input;
    }
    

    public static void printArray(int[] arr) {
        for (int element : arr) {
            System.out.print(element + " ");
        }

        System.out.println();
    }
  public static int binarySearch(int[] arr, int x) {
        
    	//Your code goes here
        	int start=0;
		int end=(arr.length)-1;	
		int i=0;
		while(start<=end) {
			int mid = (start+end)/2;
				if (x==arr[mid]) {
					return mid;
					
				}
				else if (x>arr[mid]) {
					start=mid+1;
				}
				else  {
					end=mid-1;
				}
				i++;
		}
		return -1;
    }


    public static void main(String[] args) throws NumberFormatException, IOException {
        int[] input = takeInput();
        int t = Integer.parseInt(br.readLine().trim());

        while(t > 0) {

            int x = Integer.parseInt(br.readLine().trim());
            System.out.println(binarySearch(input, x));

            t -= 1;
        }
    }
}

