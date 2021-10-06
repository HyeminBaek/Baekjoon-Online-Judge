import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;

public class Main {
	
	private static int N,ans;
	private static int num[];
	private static ArrayList<Integer>[] list;
	
	public static void main(String[] args) throws Exception{
		BufferedReader br=  new BufferedReader(new InputStreamReader(System.in));
		N=Integer.parseInt(br.readLine());
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		num=new int[N+1];
		for(int i=1;i<=N;i++) num[i]=Integer.parseInt(st.nextToken());
		
		list = new ArrayList[N+1];
		for(int i=1;i<=N;i++) list[i]= new ArrayList<Integer>();
		
		for(int i=1;i<=N;i++) {
			st = new StringTokenizer(br.readLine());
			
			int adj = Integer.parseInt(st.nextToken());
			for(int j=0;j<adj;j++) list[i].add(Integer.parseInt(st.nextToken()));
		}//input
		
		ans=987654321; solution();
		
		if(ans==987654321) ans =-1;
		System.out.println(ans);
	}
	private static void solution() {
		for(int i=1;i<=N/2;i++) {
			int chk[] = new int[i];
			combination(1,0,i,chk);
		}
	}
	private static void combination(int idx,int cnt,int tgt,int chk[]) {
		if(cnt==tgt) {
			boolean visited[]=new boolean[N+1];
			
			ArrayList<Integer> distB = new ArrayList<Integer>();
			for(int i=1;i<=N;i++) {
				distB.add(i);
				for(int j=0;j<chk.length;j++) {
					if(chk[j]==distB.get(distB.size()-1)) {
						distB.remove(distB.size()-1); break;
					}
				}
			}
			
			dfs(chk[0],true,chk,distB,visited);
			boolean flag = true;
			for(int i=0;i<chk.length;i++) {
				if(!visited[chk[i]]) {
					flag=false; break;
				}
			}
			
			if(flag) {
				visited=new boolean[N+1];
				dfs(distB.get(0),false,chk,distB,visited);
				
				for(int i=0;i<distB.size();i++) {
					if(!visited[distB.get(i)]) {
						flag=false; break;
					}
				}
				
				if(flag) {
//					for(int i=0;i<chk.length;i++) System.out.print(chk[i]+" ");
//					System.out.println();
					ans = Math.min(ans, count(chk,distB));
				}
			}
			return;
		}
		if(idx==N+1) return;
		
		combination(idx+1,cnt,tgt,chk);
		
		chk[cnt]=idx;
		combination(idx+1,cnt+1,tgt,chk);
	}
	private static int count(int[] chk, ArrayList<Integer> distB) {
		int A=0,B=0;
		
		for(int i=0;i<chk.length;i++) A+=num[chk[i]];
		for(int i=0;i<distB.size();i++) B+=num[distB.get(i)];
		
		return Math.abs(A-B);
	}
	private static void dfs(int x,boolean flag,int[] chk,ArrayList<Integer> distB,boolean visited[]) {
		visited[x]=true;
		for(int k=0;k<list[x].size();k++) {
			int nx = list[x].get(k);
			if(flag) {
				for(int i=0;i<chk.length;i++) {
					if(nx==chk[i]) {
						if(!visited[nx]) dfs(nx,flag,chk,distB,visited);
						break;
					}
				}
			} else {
				for(int i=0;i<distB.size();i++) {
					if(nx==distB.get(i)) {
						if(!visited[nx]) dfs(nx,flag,chk,distB,visited);
						break;
					}
				}
			}
			
		}
	}
}
