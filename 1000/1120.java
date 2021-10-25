import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	/*
	 * B 안에 A와 겹치는 최대 문자열의 길이 -> 최소 차이
	 */
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		String A = st.nextToken(), B = st.nextToken();

		int ans = solution(A,B);

		System.out.println(ans);
	}

	private static int solution(String A,String B) {
		int ans = 987654321;
		
		for(int i=0;i<=B.length()-A.length();i++) {
			int cnt = 0;
			//System.out.println(B.charAt(i));
			for(int j=0;j<A.length();j++) {
				if(A.charAt(j)!=B.charAt(i+j)) cnt+=1;
			}
			
			ans = Math.min(ans, cnt);
		}
		
		return ans;
	}
}
