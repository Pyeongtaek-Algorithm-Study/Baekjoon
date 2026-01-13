import java.util.*;
import java.io.*;

public class Main
{
	private static Set<Integer> setA;
	private static Set<Integer> setB;
	private static int n, m;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;

		st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());

		setA = new HashSet<>();
		setB = new HashSet<>();

		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < n; i++) {
			setA.add(Integer.parseInt(st.nextToken()));
		}

		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < m; i++) {
			setB.add(Integer.parseInt(st.nextToken()));
		}

		solve();
	}

	public static void solve() {
		int comEl = 0;

		for (int aEl : setA) {
		    if (setB.contains(aEl)) {
		        comEl++;
		    }
		}

		System.out.println(setA.size() + setB.size() - (2 * comEl));
	}
}
