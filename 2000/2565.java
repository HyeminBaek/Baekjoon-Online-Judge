import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Main {
	private static class Pair implements Comparable<Pair>{
		int A,B;	
		
		public Pair(int a, int b) {
			A = a;
			B = b;
		}

		@Override
		public String toString() {
			return "Pair [A=" + A + ", B=" + B + "]";
		}

		@Override
		public int compareTo(Pair o) {
			return this.A-o.A;
		}
		
	}
	public static void main(String[] args) throws Exception {
		/*
		 * 도저히 생각이 안나 풀이법을 참조
		 * "A를 기준으로 오름차순으로 정렬했을 때, B 수열에서 가장 긴 증가하는 부분 수열의 개수가 남겨야 할 전깃줄의 개수"
		 */
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		
		Pair arr[] = new Pair[N];
		for(int i=0;i<N;i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			arr[i]=new Pair(Integer.parseInt(st.nextToken()),Integer.parseInt(st.nextToken()));
		}//input
		
		Arrays.sort(arr);
		//for(Pair p : arr) System.out.println(p.toString());
		solution(N,arr);
	}//main
	private static void solution(int N,Pair[] arr) {
		int dp[] = new int[N];
		
		int val =0;
		for(int i=0;i<N;i++) dp[i]=1;
		
		for(int i=1;i<N;i++) {
			for(int j=0;j<i;j++) {
				if(arr[i].B>arr[j].B) {
					dp[i] = Math.max(dp[j]+1, dp[i]);
				}
			}
			val = Math.max(val, dp[i]);
		}//for loop

		System.out.println(N-val);//실수했다
	}
}
