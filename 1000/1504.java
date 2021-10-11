import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.StringTokenizer;

/*
 * 문제에서 구해야 할 것 : 1번 정점에서 N번 정점으로 이동할 때, 주어진 두 정점을 반드시 거치는 최단 경로의 길이
 * 1. 한번 이동했던 정점은 물론, 한번 이동했던 간선도 다시 이동할 수 있다.
 * 
 * 1 -> v1 -> v2 -> N
*/

public class Main {
	private static class Pair implements Comparable<Pair>{
		int prev,cur,val;

		public Pair(int cur, int val) {
			this.cur = cur;
			this.val = val;
		}

		public Pair(int prev, int cur, int val) {
			this.prev = prev;
			this.cur = cur;
			this.val = val;
		}

		@Override
		public int compareTo(Pair o) {
			return this.val-o.val;
		}
	}
	private static int N,v1,v2;
	private static ArrayList<Pair> list[];
	
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		N = Integer.parseInt(st.nextToken());int E = Integer.parseInt(st.nextToken());
		
		list = new ArrayList[N+1];
		for(int i=1;i<=N;i++) list[i] = new ArrayList<Pair>();
			
		for(int i=0;i<E;i++) {
			st = new StringTokenizer(br.readLine());
			//틀린 이유: a번 정점에서 b번 정점까지 양방향 길이 존재하며~
			int x = Integer.parseInt(st.nextToken()),y = Integer.parseInt(st.nextToken()),v= Integer.parseInt(st.nextToken());
			list[x].add(new Pair(y,v)); list[y].add(new Pair(x,v));
		}//input
		
		st = new StringTokenizer(br.readLine());
		v1 = Integer.parseInt(st.nextToken()); v2=Integer.parseInt(st.nextToken());
		
		solution();
	}
	
	private static void solution() {
		int result = -1;
		int stv1 = bfs(1,v1), v1tv2= bfs(v1,v2), v2te=bfs(v2,N);
		if(stv1!=987654321&&v1tv2!=987654321&&v2te!=987654321) result = stv1+v1tv2+v2te;
		
		int stv2=bfs(1,v2),v2tv1=bfs(v2,v1),v1te=bfs(v1,N);
		if(stv2!=987654321&&v2tv1!=987654321&&v1te!=987654321) {
			if(result == -1) result = stv2+v2tv1+v1te;
			else result=Math.min(result, stv2+v2tv1+v1te);
		}
	
		
		System.out.print(result);
	}

	private static int bfs(int st,int ed) {
		//여기서 시간 좀 걸림 
		int[][] ans = new int[N+1][N+1];
		for(int i=1;i<=N;i++) for(int j=1;j<=N;j++) ans[i][j] = 987654321;
		ans[st][st]=0;
		
		PriorityQueue<Pair> pq = new PriorityQueue<Pair>();
		pq.add(new Pair(st,st,0));
		
		while(!pq.isEmpty()) {
			//System.out.println(pq.peek().val);
			int x = pq.peek().cur, prev = pq.peek().prev; pq.poll();
			
			for(int k=0;k<list[x].size();k++) {
				int nx = list[x].get(k).cur,nval=list[x].get(k).val;
				if(ans[st][x]+nval<ans[st][nx]) {
					//System.out.println(x+" "+nx);
					ans[st][nx] = ans[st][x]+nval;
					//System.out.println(x+" "+nx+" "+ans[x][nx]);
					pq.offer(new Pair(x,nx,nval));
				}
			}
		}//while loop
		
		return ans[st][ed];
	}
	
	
}
