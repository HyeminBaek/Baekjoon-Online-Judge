import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

	private static void boy(int num, List<Integer> list) {
		for (int i = 1; i * num <= list.size(); i++) {
			if (list.get(i * num - 1) == 0)
				list.set(i * num - 1, 1);
			else
				list.set(i * num - 1, 0);
		}
	}

	private static void girl(int num, List<Integer> list) {
		if (num == 1 || num == list.size()) {
			if (list.get(num - 1) == 0)
				list.set(num - 1, 1);
			else
				list.set(num - 1, 0);

			return;
		}

		for (int i = 0; i < list.size() / 2; i++) {
			if (num - 1 - i >= 0 && num - 1 + i < list.size() && list.get(num - 1 - i) == list.get(num - 1 + i)) {
				int x = 0;
				if (list.get(num - 1 - i) == 0)
					x = 1;

				list.set(num - 1 - i, x);
				list.set(num - 1 + i, x);
			} else
				break;
		}
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer("");

		int N = Integer.parseInt(br.readLine());
		List<Integer> list = new ArrayList<>();

		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < N; i++) {
			int x = Integer.parseInt(st.nextToken());
			list.add(x);
		}

		int T = Integer.parseInt(br.readLine());
		for (int i = 0; i < T; i++) {
			st = new StringTokenizer(br.readLine());
			int student = Integer.parseInt(st.nextToken());
			int num = Integer.parseInt(st.nextToken());

			if (student == 1)
				boy(num, list);
			else
				girl(num, list);
		}
		int cnt=0;
		for (int j = 0; j < list.size(); j++) {
			cnt+=1;
			System.out.printf("%d ",list.get(j));
			if (cnt % 20 == 0)
				System.out.print("\n");
		}
	}

}
