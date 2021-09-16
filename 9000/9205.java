import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class hwalgo20_서울_10반_백혜민 {
	private static class Pair {
		int x, y;

		public Pair(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());

		StringBuilder sb = new StringBuilder();
		for (int test_case = 1; test_case <= T; test_case++) {
			int N = Integer.parseInt(br.readLine());

			ArrayList<Pair> list = new ArrayList<Pair>();

			for (int i = 0; i < N + 2; i++) {
				StringTokenizer st = new StringTokenizer(br.readLine());
				list.add(new Pair(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken())));
			} // input

			boolean res= solution(N, list);
			
			if(res) sb.append("happy\n");
			else sb.append("sad\n");
		} // tc
		System.out.println(sb);
	}

	private static boolean solution(int N, ArrayList<Pair> list) {
		int dist[][] = new int[list.size()][list.size()];
		for (int i = 0; i < list.size(); i++) {
			for (int j = 0; j < list.size(); j++) {
				if (i == j)
					dist[i][j] = 0;
				else {	
					int distance = Math.abs(list.get(i).x - list.get(j).x) + Math.abs(list.get(i).y - list.get(j).y);
					dist[i][j] = (distance<=1000)?distance:987654321;	
				}
			}

		} // init

		for (int k = 0; k < list.size(); k++) {
			for (int i = 0; i < list.size(); i++) {
				for (int j = 0; j < list.size(); j++)
					dist[i][j] = Math.min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
		
		if (dist[0][list.size() - 1] != 987654321) return true;
		return false;
	}
}
