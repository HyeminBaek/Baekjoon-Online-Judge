import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;


public class Main {
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		
		int arr[][] = new int[N][3];
		for(int i=0;i<N;i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			for(int j=0;j<3;j++)
				arr[i][j] = Integer.parseInt(st.nextToken());
		}
		
		solution(N,arr);
	}

	private static void solution(int N, int[][] arr) {
		/*
		dp[i][j] = i번째 집의 컬러가 j일 때 드는 최소 비용 -> 0 R 1 G 2 B 
		*/
		int dp[][] = new int[N][3];
		for(int i=0;i<3;i++) dp[0][i]=arr[0][i];
			
		for(int i=1;i<N;i++) {
			/*
			dp[1][0] = Math.min(dp[0][1],dp[0][2]) + arr[1][0];
			dp[1][1] = Math.min(dp[0][0],dp[0][2])+ arr[1][1];
			dp[1][2] = Math.min(dp[0][0],dp[0][1])+ arr[1][2];
			*/
			dp[i][0] = Math.min(dp[i-1][1],dp[i-1][2]) + arr[i][0];
			dp[i][1] = Math.min(dp[i-1][0],dp[i-1][2])+ arr[i][1];
			dp[i][2] = Math.min(dp[i-1][0],dp[i-1][1])+ arr[i][2];
		}
		
		int answer = Math.min(dp[N-1][0], Math.min(dp[N-1][1],dp[N-1][2] ));
		System.out.println(answer);
	}
}
