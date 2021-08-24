import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		StringBuilder sb = new StringBuilder();

		StringTokenizer st = new StringTokenizer(br.readLine());

		int N = Integer.parseInt(st.nextToken()), M = Integer.parseInt(st.nextToken());

		int arr[] = new int[N + 1]; // parent arr
		for (int i = 1; i <= N; i++)
			arr[i] = i;

		for (int i = 0; i < M; i++) {
			st = new StringTokenizer(br.readLine());
			int oper = Integer.parseInt(st.nextToken()), x = Integer.parseInt(st.nextToken());
			int y = Integer.parseInt(st.nextToken());

			if (oper == 0) {
				Unionfind(x, y, arr);
			} else if (oper == 1) {
				if (unionFind(x, arr) == unionFind(y, arr))
					sb.append("YES\n");
				else
					sb.append("NO\n");
			}
		} // input
		System.out.println(sb);
	}// main

	private static int unionFind(int x, int[] arr) {
		if (arr[x] == x)
			return x;
		arr[x] = unionFind(arr[x], arr);
		return arr[x];
	}

	private static void Unionfind(int x, int y, int[] arr) {
		x = unionFind(x, arr);
		y = unionFind(y, arr);
		if (x == y)
			return;

		if (x > y)
			arr[x] = y;
		else
			arr[y] = x;
	}
}
