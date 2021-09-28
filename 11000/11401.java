import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		//nCr = n! * (k!(n-k)!)^1000000005 %1000000007
		int N = Integer.parseInt(st.nextToken()),K = Integer.parseInt(st.nextToken());
		K = (K>N/2)?N-K:K;
		
		long A = pactorial(N);
		long B =(pactorial(K)*pactorial(N-K))%1000000007;
		B = pow(B,1000000005)%1000000007;
		
		System.out.println(A*B%1000000007);
	}//main
	private static long pactorial(int x) {
		long result = 1;
		for(int i=1;i<=x;i++) {
			result*=i; result%=1000000007;
		}
		
		return result;
	}
	private static long pow(long x,long y) {
		long result = 1;
		while(y>0) {
			if(y%2==1) {
				result*=x;
				result%=1000000007;
			}
			x*=x;
			x%=1000000007;
			y/=2;
		}
		return result;
	}
}
