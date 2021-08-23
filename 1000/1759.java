import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Set;
import java.util.StringTokenizer;

public class Main {
	private static StringBuilder sb;
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int L = Integer.parseInt(st.nextToken()), C = Integer.parseInt(st.nextToken());
		
		ArrayList<Character> list = new ArrayList<Character>();
		st=new StringTokenizer(br.readLine());
		for(int i=0;i<C;i++) {
			list.add(st.nextToken().charAt(0));
		}
		
		Collections.sort(list);
		sb= new StringBuilder();
		
		pick(0,0,L,new char[L],list);
		
		System.out.println(sb);
	}
	
	private static void pick(int idx,int cnt,int L,char crypto[],ArrayList<Character> list) {
		if(cnt==L) {
			StringBuilder tmp = new StringBuilder();
			
			int mo =0,ja=0;
			for(int i =0;i<crypto.length;i++) {
				if(crypto[i]=='a'||crypto[i]=='e'||crypto[i]=='i'||crypto[i]=='o'||crypto[i]=='u') mo+=1;
				else ja+=1;
				
				tmp.append(crypto[i]);
			}
			if(mo>=1&&ja>=2) sb.append(tmp+"\n");
			return;
		}
		if(idx==list.size()) return;
		crypto[cnt]=list.get(idx);
		pick(idx+1,cnt+1,L,crypto,list);
		pick(idx+1,cnt,L,crypto,list);
	}
}
