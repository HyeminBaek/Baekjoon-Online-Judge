import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		boolean arr[][] = new boolean[101][101];
		
		int N = Integer.parseInt(br.readLine());
		for(int i=0;i<N;i++)
		{
			StringTokenizer st = new StringTokenizer(br.readLine());
			int x = Integer.parseInt(st.nextToken());
			int y = Integer.parseInt(st.nextToken());
			
			for(int m=0;m<10;m++) {
				for(int n=0;n<10;n++) {
					arr[x+m][y+n]=true;
				}
			}
		}
		
		int answer= 0;
		for(int i=0;i<100;i++) {
			for(int j=0;j<100;j++) {
				if(arr[i][j]) answer+=1;
			}
		}
		
		System.out.print(answer);
	}

}
