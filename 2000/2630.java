import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
	private static int one =0,zero=0;
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		
		int[][] arr = new int[N][N];
		for(int i=0;i<N;i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			for(int j=0;j<N;j++) arr[i][j]=Integer.parseInt(st.nextToken());
		}
		
		solution(0,0,N,arr);
		System.out.println(zero+"\n"+one);
	}
	private static boolean chk(int sx,int sy,int len,int [][]arr) {
		for(int i=0;i<len;i++) {
			for(int j=0;j<len;j++) {
				if(arr[sx][sy]!=arr[sx+i][sy+j]) return false;
			}
		}
		return true;
	}
	private static void solution(int x,int y,int len,int arr[][]) {
		if(chk(x,y,len,arr)) {
			if(arr[x][y]==0) zero+=1;
			else one+=1;
			
			return;
		}
		
		solution(x,y,len/2,arr);
		solution(x,y+len/2,len/2,arr);
		solution(x+len/2,y,len/2,arr);
		solution(x+len/2,y+len/2,len/2,arr);
	}
}
