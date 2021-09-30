import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.nio.channels.Channels;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class Main {
	
	private static String S;
	private static boolean[][] chk = new boolean[14][4]; //PKHT
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		S = br.readLine();
		
		boolean result = solution();
		if(!result) System.out.println("GRESKA");
		else {
			for(int j=0;j<4;j++) {
				int cnt =13;
				for(int i=1;i<=13;i++) {
					if(chk[i][j]) cnt-=1;
				}
				System.out.print(cnt+" ");
			}
		}
	}//main

	private static boolean solution() {
		
		for(int i=0;i<S.length();i+=3) {
			int idx = 0,num=0;
			if(S.charAt(i+1)=='1') num =10;
			num+=S.charAt(i+2)-'0';
			
			if(S.charAt(i)=='K') idx=1;
			else if(S.charAt(i)=='H') idx=2;
			else if(S.charAt(i)=='T') idx=3;
			
			if(chk[num][idx]) return false;
			chk[num][idx]=true;
		}
		
		return true;
	}
}
