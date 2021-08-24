import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.StringTokenizer;

public class BOJ_1753_최단경로 {
	private static class Pair implements Comparable<Pair>{
		int first,second;

		public Pair(int first, int second) {
			super();
			this.first = first;
			this.second = second;
		}

		@Override
		public int compareTo(Pair o) {
			if(this.second==o.second) return this.first-o.first;
			return this.second-o.second;
		}
		
		
	}
	private static ArrayList<Pair>[] list;
	private static int[] visited;
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();

		StringTokenizer st = new StringTokenizer(br.readLine());

		int V = Integer.parseInt(st.nextToken()), E = Integer.parseInt(st.nextToken());
		int K = Integer.parseInt(br.readLine());
		
		list = new ArrayList[V+1];
		for(int i=1;i<=V;i++) list[i]=new ArrayList<>();
		
		visited = new int[V+1];
		for(int i=1;i<=V;i++)  visited[i]=987654321;
		
		for(int i=0;i<E;i++) {
			st= new StringTokenizer(br.readLine());
			int u = Integer.parseInt(st.nextToken()),v=Integer.parseInt(st.nextToken());
			int w=Integer.parseInt(st.nextToken());
			
			list[u].add(new Pair(v,w)); 
		}//input
		bfs(K,V);
		sb = solution(K,V);
		
		System.out.println(sb);
	}// main
	private static StringBuilder solution(int K,int V) {
		StringBuilder answer = new StringBuilder();
		
		for(int i=1;i<=V;i++) {
			if(visited[i]==987654321) answer.append("INF");
			else answer.append(visited[i]);
			answer.append("\n");
		}
		
		return answer;
	}
	private static void bfs(int sx,int V) {
		PriorityQueue<Pair> q = new PriorityQueue<Pair>();
		q.offer(new Pair(sx,0)); visited[sx]=0;
		
		while(!q.isEmpty()) {
			int x = q.peek().first, val = q.peek().second;
			q.poll();
			
			for(int k=0;k<list[x].size();k++) {
				int nx = list[x].get(k).first;
				
				if(visited[nx]>visited[x]+list[x].get(k).second) {
					visited[nx]=visited[x]+list[x].get(k).second;
					q.offer(new Pair(nx,visited[nx]));
				}
			}
		}
	}
	
}
