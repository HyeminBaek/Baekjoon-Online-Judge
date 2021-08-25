import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Map;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {
	private static int dir[][] = { { -1, 0 }, { 1, 0 }, { 0, 1 }, { 0, -1 } };

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int N = Integer.parseInt(br.readLine());
		int arr[][] = new int[N][N];

		int minV = 987654321, maxV = -1;
		for (int i = 0; i < N; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			for (int j = 0; j < N; j++) {
				arr[i][j] = Integer.parseInt(st.nextToken());
				
				minV=Math.min(minV, arr[i][j]);
				maxV=Math.max(maxV, arr[i][j]);
			}
		}//input
		
		int answer= 0;
		
		for(int m=0;m<=maxV;m++) { //아무 지역도 물에 잠기지 않을 수도 있다. 라는 조건 간과
			int tmp[][] = new int[N][N];
			for(int i=0;i<N;i++) {
				for(int j=0;j<N;j++) {
					tmp[i][j]=(arr[i][j]<=m)?-1:arr[i][j];
				}
			}//copy
			
			int cnt= 0;
			boolean visited[][] = new boolean[N][N];
			for(int i=0;i<N;i++) {
				for(int j=0;j<N;j++) {
					if(!visited[i][j]&&tmp[i][j]!=-1) {
						visited[i][j]=true; cnt+=1;
						bfs(i,j,N,tmp,visited);
					}
				}
			}//search
			
			answer = Math.max(answer, cnt);
		}
		
		System.out.println(answer);
	}// main

	private static void bfs(int i, int j, int N, int map[][], boolean visited[][]) {
		Queue<int[]> q = new LinkedList<>();
		q.offer(new int[] { i, j });

		while (!q.isEmpty()) {
			int x = q.peek()[0], y = q.peek()[1];
			q.poll();

			for (int k = 0; k < 4; k++) {
				int nx = x + dir[k][0], ny = y + dir[k][1];
				if (0 <= nx && nx < N && 0 <= ny && ny < N) {
					if (!visited[nx][ny] && map[nx][ny]!=-1) {
						visited[nx][ny] = true;
						q.offer(new int[] { nx, ny });
					}
				}
			}
		}
	}
}
