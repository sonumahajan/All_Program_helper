// This is a codechef question solution written in java.

package CodechefProblems;

import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.InputStream;

public class TheLeadGame {
	public static void main(String[] args) {
		// System.in and System.out are input and output streams, respectively.
		InputStream inputStream = System.in;

		InputReader in = new InputReader(inputStream);

		int n = in.nextInt();
		int lead1[] = new int[n];
		int lead2[] = new int[n];
		int k=0,l=0;
		for(int i=0; i<n; i++) {
			int s= k + in.nextInt();
			int t= l + in.nextInt();
			lead1[i]=s-t;
			lead2[i]=t-s;
			k=s;
			l=t;
		}
		Arrays.sort(lead1);
		Arrays.sort(lead2);
		if(lead1[n-1]>lead2[n-1]) {
			System.out.println(1 + " " + Math.abs(lead1[n-1]));
		}
		else {
			System.out.println(2 + " " + Math.abs(lead2[n-1]));
		}
		
	}

	static class InputReader {
		public BufferedReader reader;
		public StringTokenizer tokenizer;

		public InputReader(InputStream stream) {
			reader = new BufferedReader(new InputStreamReader(stream), 32768);
			tokenizer = null;
		}

		public String next() {
			while (tokenizer == null || !tokenizer.hasMoreTokens()) {
				try {
					tokenizer = new StringTokenizer(reader.readLine());
				} catch (IOException e) {
					throw new RuntimeException(e);
				}
			}
			return tokenizer.nextToken();
		}

		public int nextInt() {
			return Integer.parseInt(next());
		}
	}
}
