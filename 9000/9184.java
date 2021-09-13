import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	private static StringBuilder sb;
	
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		sb = new StringBuilder();
		
		int dp[][][] = new int[51][51][51];
		
		while(true) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			
			int a = Integer.parseInt(st.nextToken()),b=Integer.parseInt(st.nextToken());
			int c = Integer.parseInt(st.nextToken());
			
			if(a==-1&&b==-1&&c==-1) break;
			
			sb.append("w("+a+", "+b+", "+c+") = "+w(a,b,c,dp)+"\n");
		}
		
		System.out.println(sb);
	}
	private static int w(int a,int b,int c,int[][][] dp) {
		
		if(a <= 0 || b <= 0 || c <= 0) {
			return 1;
		}
		else if (a > 20 || b > 20 || c > 20) {
			return dp[a][b][c]=w(20, 20, 20,dp);
		}
		else if(dp[a][b][c]!=0) return dp[a][b][c]; //인덱스 때문
		else if(a < b && b < c) {
			return dp[a][b][c] =w(a, b, c-1,dp) + w(a, b-1, c-1,dp) - w(a, b-1, c,dp);
		}
		else
		    return dp[a][b][c] = w(a-1, b, c,dp) + w(a-1, b-1, c,dp) + w(a-1, b, c-1,dp) - w(a-1, b-1, c-1,dp);
	}
}
