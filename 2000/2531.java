import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.StringTokenizer;

public class Main {
	private static int N, D, K, C;
	private static int[] arr;

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		N = Integer.parseInt(st.nextToken());
		D = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(st.nextToken());
		C = Integer.parseInt(st.nextToken());

		arr = new int[N];
		for (int i = 0; i < N; i++)
			arr[i] = Integer.parseInt(br.readLine());

		System.out.println(solution());
	}// main

	private static int solution() {
		int ans = 0, cnt = 0;
		
		int chk[] = new int[D+1];
		
		for(int i=0;i<K;i++) {
			if(chk[arr[i]]==0) cnt+=1;
			chk[arr[i]]+=1;
		}
		ans=cnt;
		if(chk[C]==0) ans +=1;
		
		for(int i=K;i<arr.length+K;i++) {
			int cur = (i<arr.length)?i:i-arr.length;
			int prev=(i<arr.length)?cur-K:i-K;
			
			chk[arr[prev]]-=1;
			if(chk[arr[prev]]<1) cnt-=1;
			
			if(chk[arr[cur]]==0) cnt+=1;
			chk[arr[cur]]+=1;
			
			if(chk[C]==0) ans = (ans<cnt+1)?cnt+1:ans;
			ans = (ans<cnt)?cnt:ans;
		}
		
		return ans;
	}
}
