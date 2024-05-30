import java.io.*;
import java.util.stream.Stream;

public class Main {
	static int n;
	static int[] arr;
	
	private static boolean nextNums() {
		int digit1 = n - 1;
		while(digit1 > 0 && arr[digit1] < arr[digit1 - 1]) digit1--;
		if (digit1 <= 0) return false;
		
		int digit2 = n - 1;
		while(arr[digit2] < arr[digit1 - 1]) digit2--;
		
		swap(digit1 - 1, digit2);
		digit2 = n - 1;
		while(digit1 < digit2) {
			swap(digit1, digit2);
			digit1++; digit2--;
		}
		
		return true;
	}
	
	private static void swap(int num1, int num2) {
		int temp = arr[num1];
		arr[num1] = arr[num2];
		arr[num2] = temp;
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		n = Integer.parseInt(br.readLine());
		String[] tempArr = br.readLine().split(" ");
		arr = Stream.of(tempArr).mapToInt(Integer::parseInt).toArray();
		
		if(nextNums()) {
			for(int i = 0; i < n; i++) {
				System.out.print(arr[i] + " ");
			}
		}
		else {
			System.out.println(-1);
		}
	}

}
