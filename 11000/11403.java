import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

/*
 * 문제에서 구해야 할 것 : 가중치 없는 방향 그래프 G가 주어졌을 때, 모든 정점 (i, j)에 대해서, i에서 j로 가는 경로가 있는지 없는지 구하기
 * 1. i번째 줄의 j번째 숫자가 1인 경우에는 i에서 j로 가는 간선이 존재한다
 * 2. 0인 경우는 없다는 뜻
 * 3. 문제의 정답을 인접행렬 형식으로 출력
*/

public class Main {
	private static int N;
	private static boolean arr[][];
	private static int ans[][];
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		N = Integer.parseInt(br.readLine());
		arr = new boolean[N][N]; ans = new int[N][N];
		
		for(int i=0;i<N;i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			for(int j=0;j<N;j++) {
				arr[i][j]=(Integer.parseInt(st.nextToken())==0)?false:true;
			}
		}
		
		solution();
	}
	
	private static void solution() {
		for(int i=0;i<N;i++) bfs(i);
		
		System.out.print(print());
	}
	private static StringBuilder print() {
		StringBuilder sb = new StringBuilder();
		
		for(int i=0;i<N;i++) {
			for(int j=0;j<N;j++) sb.append(ans[i][j]+" ");
			sb.append("\n");
		}
		
		return sb;
	}
	private static void bfs(int i) {
		Queue<Integer> q = new LinkedList<Integer>();
		q.offer(i);
		
		boolean visited[][]=new boolean[N][N];
		
		while(!q.isEmpty()) {
			int x = q.poll();
			
			for(int k=0;k<N;k++) {
				if(arr[x][k]&&!visited[x][k]) {
					visited[x][k]=true; ans[i][k]=1;
					q.offer(k);
				}
			}
		}
	}
}
