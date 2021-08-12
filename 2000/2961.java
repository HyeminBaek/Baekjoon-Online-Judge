import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	static class Pair{
		int s,b;

		public Pair(int s, int b) {
			this.s = s;
			this.b = b;
		}
	}
	static Pair[] arr;

	static int N,answer=-1;
	
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());
		
		arr = new Pair[N];
		for(int i=0;i<N;i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			int s= Integer.parseInt(st.nextToken());
			int b=Integer.parseInt(st.nextToken());
			
			arr[i]=new Pair(s,b);
		}//input
		makeSubset();
		System.out.print(answer);
	}//main
	private static void makeSubset() {
		for(int i=1;i<=N;i++) {
			Pair[] pick=new Pair[i];
			makeCombination(pick,i,0, 0);
		}
	}
	private static void makeCombination(Pair[] pick,int size,int n,int r) {
		if(r==size) {
			int sumS=1,sumB=0;
			for(int i=0;i<pick.length;i++) {
				sumS*=pick[i].s;
				sumB+=pick[i].b;
			}
			
			if(answer==-1) answer = Math.abs(sumB-sumS);
			else answer = Math.min(answer, Math.abs(sumB-sumS));
			return;
		}
		if(n==N) return;
		pick[r]=arr[n];
		
		makeCombination(pick,size,n+1,r+1);
		makeCombination(pick,size,n+1,r);
	}
}
