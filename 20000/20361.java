import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class Main {
	private static int N,X,K,idx;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		N = Integer.parseInt(st.nextToken()); X = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(st.nextToken());
		
		boolean arr[] = new boolean[N+1];
		arr[X]=true; idx = X;
		
		for(int i=0;i<K;i++) {
			st = new StringTokenizer(br.readLine());
			int A = Integer.parseInt(st.nextToken()),B=Integer.parseInt(st.nextToken());
			
			swap(A,B,arr);
		}
		
		System.out.println(idx);
	}//main
	private static void swap(int a,int b,boolean[] arr) {
		boolean tmp = arr[a];
		arr[a] = arr[b];
		arr[b] = tmp;
		
		if(arr[a]) idx = a;
		else if(arr[b]) idx =b;
	}
}
