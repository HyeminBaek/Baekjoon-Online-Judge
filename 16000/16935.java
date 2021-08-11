import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	public static int arr[][];
	public static int N, M, str,ed;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		int R = Integer.parseInt(st.nextToken());
		
		arr = new int[N][M];
		for(int i=0;i<N;i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=0;j<M;j++)
				arr[i][j]=Integer.parseInt(st.nextToken());
		}
		
		st = new StringTokenizer(br.readLine());
		
		str= N; ed=M;
		for(int i=0;i<R;i++) {
			int x = Integer.parseInt(st.nextToken());
			switch(x) {
			case 1: one(); break;
			case 2: two(); break;
			case 3: three(); break;
			case 4: four(); break;
			case 5: five(); break;
			case 6: six();
			}
		}
		
		for(int i=0;i<str;i++) {
			for(int j=0;j<ed;j++)
				System.out.print(arr[i][j]+" ");
			System.out.println();
		}
	}
	private static void copy(int tmp[][]) {
		arr = new int[str][ed];
		for(int i=0;i<str;i++) {
			for(int j=0;j<ed;j++)
				arr[i][j]=tmp[i][j];
		}
	}//copy
	private static void one() {
		int tmp[][] = new int[str][ed];
		for(int i=str-1;i>=0;i--) {
			for(int j=0;j<ed;j++) {
				tmp[str-1-i][j]=arr[i][j];
			}
		}
		copy(tmp);
	}//one
	private static void two() {
		int tmp[][] = new int[str][ed];
		for(int i=0;i<str;i++) {
			for(int j=ed-1;j>=0;j--)
				tmp[i][ed-1-j]=arr[i][j];
		}
		copy(tmp);
	}//two
	private static void three() {
		int tmp[][] = new int[ed][str];
		for(int i=0;i<str;i++) {
			for(int j=0;j<ed;j++) {
				tmp[j][str-1-i]=arr[i][j];
			}
		}
		int temp = str;
		str= ed; ed=temp;
		copy(tmp);
	}//three
	private static void four() {
		int tmp[][] = new int[ed][str];
		for(int i=0;i<str;i++) {
			for(int j=0;j<ed;j++) {
				tmp[ed-1-j][i]=arr[i][j];
			}
		}
		
		int temp = str;
		str= ed; ed=temp;
		copy(tmp);
	}
	private static void five() {
		int tmp[][] = new int[str][ed];
		for(int i=0;i<str/2;i++) { //1번 자리
			for(int j=0;j<ed/2;j++) {
				tmp[i][j]=arr[str/2+i][j];//4
			}
		}
		for(int i=0;i<str/2;i++) {//2번 자리
			for(int j = ed/2;j<ed;j++) {
				tmp[i][j]=arr[i][j-ed/2];//1
			}
		}
		for(int i=str/2;i<str;i++){//3번 자리
			for(int j=ed/2;j<ed;j++) {
				tmp[i][j]=arr[i-str/2][j];//2
			}
		}
		for(int i =str/2;i<str;i++){//4번 자리
			for(int j=0;j<ed/2;j++) {
				tmp[i][j]=arr[i][j+ed/2];//3
			}
		}
		copy(tmp);
	}
	private static void six() {
		int tmp[][] = new int[str][ed];
		for(int i=0;i<str/2;i++) { //1번 자리
			for(int j=0;j<ed/2;j++) {
				tmp[i][j]=arr[i][j+ed/2];//2
			}
		}
		for(int i=0;i<str/2;i++) {//2번 자리
			for(int j = ed/2;j<ed;j++) {
				tmp[i][j]=arr[i+str/2][j];//3
			}
		}
		for(int i=str/2;i<str;i++){//3번 자리
			for(int j=ed/2;j<ed;j++) {
				tmp[i][j]=arr[i][j-ed/2];//4
			}
		}
		for(int i =str/2;i<str;i++){//4번 자리
			for(int j=0;j<ed/2;j++) {
				tmp[i][j]=arr[i-str/2][j];//1
			}
		}
		copy(tmp);
	}
}
