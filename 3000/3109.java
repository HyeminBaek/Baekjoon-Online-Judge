import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	private static boolean flag;
	private static int R,C,answer;
	private static int dir[][] = {{-1,1},{0,1},{1,1}};
	private static char arr[][];
	private static boolean visited[][];
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st= new StringTokenizer(br.readLine());
		R= Integer.parseInt(st.nextToken()); C = Integer.parseInt(st.nextToken());
		
		arr = new char[R][C]; visited = new boolean[R][C];
		for(int i=0;i<R;i++) {
			String s = br.readLine();
			for(int j=0;j<C;j++) 
				arr[i][j]=s.charAt(j);
		}//array input
		
		for(int i=0;i<R;i++) {
			flag = false;
			
			visited[i][0]=true; dfs(i,0);
		}
		
		System.out.println(answer);
	}//main
	
	private static void dfs(int x,int y) {
		if(y==C-1) {
			flag = true;	answer++;
			return;
		}
		
		for(int k=0;k<3;k++) {
			if(flag) break;
			int nx = x+dir[k][0],ny=y+dir[k][1];
			
			if(0<=nx&&nx<R&&0<=ny&&ny<C) {
				if(!visited[nx][ny]&&arr[nx][ny]=='.') {
					dfs(nx,ny); visited[nx][ny]=true;
				}
			}
		}//dir
		
	}
}
