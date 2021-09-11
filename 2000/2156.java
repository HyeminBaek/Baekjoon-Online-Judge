import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;


public class Main {
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		
		int arr[] = new int[N];
		for(int i=0;i<N;i++) {
			arr[i] = Integer.parseInt(br.readLine());
		}
		
		solution(N,arr);
	}

	private static void solution(int N, int[] arr) {
		int dp[][] = new int[N][3];
		
		int answer= arr[0]; //answer를 별도로 두어야 하는 이유: max값이 꼭 마지막 잔을 마셨을 때 나오는 것이 아니다
		dp[0][0]=0; dp[0][1]=arr[0]; dp[0][2] =arr[0];
		
		if(N>=2) { //이거 처리 안해줘서 틀림 ㅂㄷㅂㄷ n==1 이 원인이 아니였다 왜 92퍼에서 틀릴까? 2nd try //가 문제가 아니였다!
			/*
			 	2
				10 9 에서 19가 나와야하는데 10만 나옴-> 이곳이 문제
			 */
			dp[1][0] = Math.max(dp[0][0], Math.max(dp[0][1], dp[0][2]));
			dp[1][1] = dp[0][0]+arr[1]; dp[1][2]=dp[0][1]+arr[1];
			answer = Math.max(answer, Math.max(dp[1][1], dp[1][0]));
			answer = Math.max(answer, dp[1][2]);//를 안해줌
		}
		for(int i=2;i<N;i++) {
			/*
				dp[1][1]=dp[0][0]+arr[1];
				dp[1][0]=arr[1];
				
				dp[2][1]=dp[1][0]+arr[2];
				dp[2][0]=dp[0][0] || dp[0][1] + arr[2];
				
				간과한 점 
				6
				30 30 5 5 30 30 처럼 저 멀리 떨어진 애인 경우 체크 불가
				
				포도주를 마시지 않는 경우를 고려하지 않고 다 마신다마신다마신다 체크
				
				마시지 않고 이전 최댓값만 저장하는 상태 추가 0 안마신다 1 마신다 하지만 노 연속 2 마시지만 연속
				dp[i][0] = i번째일때 마시지 않은 경우 > dp[i-1] 맥스 로 값 갱신
				dp[i][1] = i번째일 때 마신 경우 > dp[i-1][0]+arr[i]
				dp[i][2] = dp[i-1][1]+arr[i]

			*/
			dp[i][2] = dp[i-1][1]+arr[i];
			dp[i][1] = dp[i-1][0]+arr[i];
			dp[i][0] = Math.max(dp[i-1][0], Math.max(dp[i-1][2],dp[i-1][1] ));
			
			answer = Math.max(answer, Math.max(dp[i][1], dp[i][0]));
			answer = Math.max(answer, dp[i][2]);
		}//for loop
		
		System.out.println(answer);
	}
}
