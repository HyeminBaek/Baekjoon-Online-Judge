import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	private static class Pair {
		int first, second, third, day;

		public Pair(int first, int second) {
			this.first = first;
			this.second = second;
		}

		public Pair(int first, int second, int third) {
			this.first = first;
			this.second = second;
			this.third = third;
		}

		public Pair(int first, int second, int third, int day) {
			this.first = first;
			this.second = second;
			this.third = third;
			this.day = day;
		}
	}

	private static Pair dir[] = { new Pair(-1, 0, 0), new Pair(1, 0, 0), new Pair(0, -1, 0), new Pair(0, 1, 0),
			new Pair(0, 0, 1), new Pair(0, 0, -1) };
	private static int N, M, H, total;
	private static int map[][][];

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		H = Integer.parseInt(st.nextToken());

		map = new int[M][N][H];
		for (int k = 0; k < H; k++) {
			for (int i = 0; i < M; i++) {
				st = new StringTokenizer(br.readLine());

				for (int j = 0; j < N; j++) {

					map[i][j][k] = Integer.parseInt(st.nextToken());
					if (map[i][j][k] == 0)
						total += 1;
				}
			}
		} // input

		int day = bfs() - 1;
		if (day != 0 && total != 0)
			day = -1;

		System.out.println(day);
	}// main

	private static int bfs() {
		int cnt = -1;

		Queue<Pair> q = new LinkedList<Pair>();
		for (int k = 0; k < H; k++) {
			for (int i = 0; i < M; i++) {
				for (int j = 0; j < N; j++) {
					if (map[i][j][k] == 1)
						q.offer(new Pair(i, j, k, 1));
				}
			}
		} // input

		if (q.isEmpty())
			return 0;

		while (!q.isEmpty()) {
			int x = q.peek().first, y = q.peek().second, z = q.peek().third;
			int day = q.peek().day;
			cnt = day;
			q.poll();

			for (int k = 0; k < 6; k++) {
				int nx = x + dir[k].first, ny = y + dir[k].second, nz = z + dir[k].third;

				if (0 <= nx && nx < M && 0 <= ny && ny < N && 0 <= nz && nz < H) {
					if (map[nx][ny][nz] == 0) {
						total -= 1;
						map[nx][ny][nz] = 1;
						q.offer(new Pair(nx, ny, nz, day + 1));
					}
				}
			}
		}

		return cnt;
	}// bfs
}
