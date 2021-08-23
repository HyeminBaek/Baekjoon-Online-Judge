import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	private static StringBuilder sb;
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		sb= new StringBuilder();
		StringTokenizer st = new StringTokenizer(br.readLine());
		int N = Integer.parseInt(st.nextToken()),M= Integer.parseInt(st.nextToken()),V=Integer.parseInt(st.nextToken());
		
		boolean arr[][] = new boolean[1001][1001];
		for(int i=0;i<M;i++) {
			st = new StringTokenizer(br.readLine());
			
			int x = Integer.parseInt(st.nextToken()),y= Integer.parseInt(st.nextToken());
			arr[x][y]=arr[y][x]=true;
		}//input
		dfs(V,N,arr,new boolean[N+1]);
		sb.append("\n");
		bfs(V,N,arr,new boolean[N+1]);
		System.out.println(sb);
		
	}//main
	private static void dfs(int x, int N, boolean arr[][], boolean visited[]) {
		visited[x]=true;
		sb.append(x+" ");
		
		for(int k=1;k<=N;k++) {
			if(!visited[k]&&arr[x][k]) {
				dfs(k,N,arr,visited);
			}
		}
	}
	private static void bfs(int sx,int N,boolean arr[][],boolean visited[]) {
		Queue<Integer> q = new LinkedList<Integer>();
		q.offer(sx); visited[sx]=true;
		
		while(!q.isEmpty()) {
			int x = q.poll();
			
			sb.append(x+" ");
			
			for(int k=1;k<=N;k++) {
				if(!visited[k]&&arr[x][k]) {
					visited[k]=true;
					q.offer(k);
				}
			}
		}
	}
}
