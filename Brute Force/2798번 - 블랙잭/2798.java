import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class B_2798 {
	public static void main(String[] args) throws IOException {
		
		BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
		
		StringTokenizer stringTokenizer = new StringTokenizer(bufferedReader.readLine());
		
		int N = Integer.parseInt(stringTokenizer.nextToken());
		
		int M = Integer.parseInt(stringTokenizer.nextToken());
		
		int result = 0;
		
		int sub = 0;
		
		int arr[] = new int[N];
		stringTokenizer = new StringTokenizer(bufferedReader.readLine());
		for (int i = 0; i < N; i++) {
			
			arr[i] = Integer.parseInt(stringTokenizer.nextToken());
		}
		
		for (int i = 0; i < arr.length-2; i++) 
		{
			for (int j = i+1; j <arr.length-1; j++)
			{
				for (int k=j+1; k <arr.length; k++)
				{
					sub =arr[i] + arr[j] + arr[k];
					
					if (M >= sub && result < sub)
						result = sub;
				}
			}
			
			
		}
		
		System.out.println(result);
		
	}
}
