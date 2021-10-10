import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

/*
 * 문제에서 구해야 할 것 : 100번 칸에 도착하기 위해 주사위를 최소 몇 번 굴려야 하는지
*/

public class Main {
	private static class Pair{
		int x,cnt;

		public Pair(int x, int cnt) {

			this.x = x;
			this.cnt = cnt;
		}
	}
	private static HashMap<Integer,Integer> map;
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int N = Integer.parseInt(st.nextToken()), M = Integer.parseInt(st.nextToken());
		map = new HashMap<Integer,Integer>();
		
		for(int i=0;i<N+M;i++) {
			st = new StringTokenizer(br.readLine());
			map.put(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
		}
		
		solution();
	}
	
	private static void solution() {
		System.out.print(bfs());
	}
	
	private static int bfs() {
		Queue<Pair> q = new LinkedList<Pair>();
		q.offer(new Pair(1,0));
		
		int ans = 987654321;
		
		boolean visited[] = new boolean[101];
		visited[1]=true;
		
		while(!q.isEmpty()) {
			int x = q.peek().x,cnt = q.peek().cnt; q.poll();
			
			if(x==100) {
				ans = Math.min(ans, cnt);
				continue;
			}
			for(int k=1;k<=6;k++) {
				int nx = x+k;
				if(nx>100) break;
				
				if(!visited[nx]) {
					if(map.get(nx)==null) {
						q.offer(new Pair(nx,cnt+1));
						visited[nx]=true;
					} else {
						nx = map.get(nx);
						
						if(!visited[nx]) {
							q.offer(new Pair(nx,cnt+1));
							visited[nx]=true;
						}
					}
				}
			}
		}//while loop
		
		return ans;
	}
}
