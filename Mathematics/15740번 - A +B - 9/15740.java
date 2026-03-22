import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.math.BigInteger;

public class Main
{
    static BigInteger A;
    static BigInteger B;
    
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		A = new BigInteger(st.nextToken());
		B = new BigInteger(st.nextToken());
		
		solve();
		
		br.close();
	}
	
	private static void solve() {
	    System.out.println(A.add(B));
	}
}
