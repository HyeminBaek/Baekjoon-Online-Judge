import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		
		StringBuilder sb = new StringBuilder();
		for(int test_case=1;test_case<=T;test_case++) {
			String s = br.readLine();
			
			sb.append("URL #"+test_case+"\n");
			solution(sb,s);
		}
		System.out.println(sb);
	}//main

	private static void solution(StringBuilder sb,String s) {
		int idx=0;
		
		String sub="";
		for(int i=0;i<s.length();i++) {
			if(idx==0&&s.charAt(i)==':') {
				sb.append("Protocol = "+sub+"\n");
				sub = ""; idx+=1; i+=2;
			} else if(idx==1&&s.charAt(i)==':') {
				sb.append("Host     = "+sub+"\n");
				sub = ""; idx+=1;
			} else if(idx==1&&s.charAt(i)=='/'){
				sb.append("Host     = "+sub+"\n");
				sub = ""; idx=4;
			} else if(idx==2&&s.charAt(i)=='/'){
				sb.append("Port     = "+sub+"\n");
				sub = ""; idx+=1;
			} else sub+=s.charAt(i);
		}//for

		if(idx==1) {
			sb.append("Host     = "+sub+"\n"); idx+=1;
		} else if(idx==2){
			sb.append("Port     = "+sub+"\n"); idx+=1;
		} else if(idx==3) {
			sb.append("Path     = "+sub+"\n\n"); idx=5;
		}
		
		if(idx!=5) {
			if(idx==2||idx==4) sb.append("Port     = <default>\n");
			if(idx!=4) sb.append("Path     = <default>\n\n");
			else sb.append("Path     = "+sub+"\n\n");
		}
	}
}
