import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		
		StringTokenizer st = new StringTokenizer(br.readLine());
	
		long dist[]= new long[N-1];
		for(int i=0;i<N-1;i++) {
			dist[i]=Long.parseLong(st.nextToken());
		}
		
		long fee[] = new long[N];
		st=new StringTokenizer(br.readLine());
		for(int i=0;i<N;i++) {
			fee[i]=Long.parseLong(st.nextToken());
		}
		solution(N,dist,fee);
	}
	private static void solution(int N,long[] dist,long[] fee) {
		long cur = fee[0], answer = 0;
		for(int i=1;i<N;i++) {
			answer += cur*dist[i-1];
			if(cur>fee[i]) {
				cur=fee[i];
			}
		}
		System.out.println(answer);
	}
}
