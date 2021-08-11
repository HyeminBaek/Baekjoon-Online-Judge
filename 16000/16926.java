import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	public static int arr[][];
	public static int N,M;
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		N=Integer.parseInt(st.nextToken());
		M=Integer.parseInt(st.nextToken());
		int R = Integer.parseInt(st.nextToken());
		
		arr = new int[N][M];
		for(int i=0;i<N;i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=0;j<M;j++)
				arr[i][j]=Integer.parseInt(st.nextToken());
		}
		
		int s = Math.min(N, M)/2;
		for(int i=0;i<R;i++) {
			spin(0,0,s);
		}
		for(int i=0;i<N;i++) {
			for(int j=0;j<M;j++)
				System.out.print(arr[i][j]+" ");
			System.out.println();
		}
	}
	public static void spin(int r,int c,int S) {
		int tmp[][]= new int[N][M];
		
		for(int s=0;s<S;s++) {
			
			//왼쪽 세로
			for(int i=s;i<N-s-1;i++) {
				tmp[i+1][s]=arr[i][s];
			}
			//밑 가로
			tmp[N-s-1][s+1]=arr[N-s-1][s];
			for(int i=s+1;i<M-s-1;i++) {
				tmp[N-s-1][i+1]=arr[N-s-1][i];
			}
			//오른쪽 세로 tmp[2][2]= arr[3][2]
			tmp[N-s-2][M-s-1]=arr[N-s-1][M-s-1];
			for(int i=N-s-3;i>=s;i--) {
				tmp[i][M-s-1]=arr[i+1][M-s-1];
			}
			//위 가로
			tmp[s][M-s-2]=arr[s][M-s-1];
			for(int i = M-s-3;i>=s;i--) {
				tmp[s][i]=arr[s][i+1];
			}
		}//for
		for(int i=0;i<N;i++) {
			for(int j=0;j<M;j++)
				arr[i][j]=tmp[i][j];
		}
	}
}
