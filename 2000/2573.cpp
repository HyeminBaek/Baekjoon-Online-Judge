import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	private static class Pair{
		int x,y;

		public Pair(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}
	private static int N,M;
	private static int arr[][];
	private static int dir[][] = {{-1,0},{1,0},{0,1},{0,-1}};
	
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		N = Integer.parseInt(st.nextToken()); M = Integer.parseInt(st.nextToken());
		arr = new int[N][M];
		
		for(int i=0;i<N;i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=0;j<M;j++)
				arr[i][j] =Integer.parseInt(st.nextToken());
		}//input 
		
		int ans = solution();
		
		System.out.println(ans);
	}

	private static int solution() {
		for(int y=0;;y++) {
			boolean flag = false;//녹을 빙산이 있는가?
			int cnt = 0;//나뉘어진 빙산의 갯수
			
			boolean visited[][]= new boolean[N][M];
			for(int i=0;i<N;i++) {
				for(int j=0;j<M;j++) {
					if(arr[i][j]>0&&!visited[i][j]) {
						cnt+=1; flag = true;
						
						if(cnt>1) return y;
						
						bfs(i,j,visited);
					}
				}
			}//n loop
//			for(int i=0;i<N;i++) {
//				for(int j=0;j<M;j++) {
//					System.out.print(arr[i][j]+" ");
//				}
//				System.out.println();
//			}//n loop
			if(!flag) return 0;
		}	
	}

	private static void bfs(int i, int j, boolean[][] visited) {
		Queue<Pair> q = new LinkedList<Pair>();
		q.offer(new Pair(i,j)); visited[i][j]=true;
		
		ArrayList<Pair> list = new ArrayList<Pair>();
		
		while(!q.isEmpty()) {
			int x =q.peek().x,y=q.peek().y; q.poll();
			list.add(new Pair(x,y));
			
			for(int k=0;k<4;k++) {
				int nx = x+dir[k][0],ny=y+dir[k][1];
				
				if(0<=nx&&nx<N&&0<=ny&&ny<M) {
					if(arr[nx][ny]>0&&!visited[nx][ny]) {
						visited[nx][ny]=true;
						q.offer(new Pair(nx,ny));
					}
				}
			}//dir
		}
		
		melt(list);
	}

	private static void melt(ArrayList<Pair> list) {
		int tmp[][] = new int[N][M];
		for(int i=0;i<N;i++) for(int j=0;j<M;j++) tmp[i][j]=arr[i][j];
		
		for(int i=0;i<list.size();i++) {
			int x = list.get(i).x,y=list.get(i).y;
			
			int cnt = 0;
			for(int k=0;k<4;k++) {
				int nx = x+dir[k][0],ny=y+dir[k][1];
				
				if(0<=nx&&nx<N&&0<=ny&&ny<M) {
					if(arr[nx][ny]==0) cnt+=1;
				}
			}//dir
			
			tmp[x][y]-=cnt; 
			if(tmp[x][y]<0) tmp[x][y]=0;
		}
		
		for(int i=0;i<N;i++) for(int j=0;j<M;j++) arr[i][j]=tmp[i][j];
	}

}
