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
	private static class EndPoint implements Comparable<EndPoint>{
		Time st,ed;

		public EndPoint(Time st, Time ed) {
			this.st = st;
			this.ed = ed;
		}

		@Override
		public int compareTo(EndPoint o) {
			if(this.ed.HH>o.ed.HH) return 1;
			else if(this.ed.HH==o.ed.HH) {
				if(this.ed.MM>o.ed.MM) return 1;
				else if(this.ed.MM==o.ed.MM) {
					if(this.ed.SS>o.ed.SS) return 1;
					else if(this.ed.SS==o.ed.SS) {
						if(this.ed.sss>o.ed.sss) return 1;
						else if(this.ed.sss==o.ed.sss) return 0;
						else return -1;
					}
					return -1;
				}
				return -1;
			}
			return -1;
		}

		@Override
		public String toString() {
			return "Pair [st=" + st.toString() + ", ed=" + ed.toString() + "]";
		}
	}
	private static class Pair implements Comparable<Pair>{
		Time st,ed;

		public Pair(Main.Time st, Main.Time ed) {
			this.st = st;
			this.ed = ed;
		}

		@Override
		public int compareTo(Pair o) {
			if(this.st.HH>o.st.HH) return 1;
			else if(this.st.HH==o.st.HH) {
				if(this.st.MM>o.st.MM) return 1;
				else if(this.st.MM==o.st.MM) {
					if(this.st.SS>o.st.SS) return 1;
					else if(this.st.SS==o.st.SS) {
						if(this.st.sss>o.st.sss) return 1;
						else if(this.st.sss==o.st.sss) return 0;
						else return -1;
					}
					return -1;
				}
				return -1;
			}
			return -1;
		}

		@Override
		public String toString() {
			return "Pair [st=" + st.toString() + ", ed=" + ed.toString() + "]";
		}
	}
	private static class Time{
		int HH,MM,SS,sss;
		
		public Time(int hH, int mM, int sS, int sss) {
			HH = hH;
			MM = mM;
			SS = sS;
			this.sss = sss;
		}

		@Override
		public String toString() {
			return "Time [HH=" + HH + ", MM=" + MM + ", SS=" + SS + ", sss=" + sss + "]";
		}
		
	}
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		
		ArrayList<Pair> list = new ArrayList<Pair>();
		for(int i=0;i<N;i++) {
			StringTokenizer st = new StringTokenizer(br.readLine()," :.");
			Time str = new Time(Integer.parseInt(st.nextToken()),Integer.parseInt(st.nextToken()),
					Integer.parseInt(st.nextToken()),Integer.parseInt(st.nextToken()));
			Time ed = new Time(Integer.parseInt(st.nextToken()),Integer.parseInt(st.nextToken()),
					Integer.parseInt(st.nextToken()),Integer.parseInt(st.nextToken()));
			
			list.add(new Pair(str,ed));
		}
		Collections.sort(list);
		
		solution(list);
	}//main
	private static void solution(ArrayList<Pair> list) {
		int answer =0;
		PriorityQueue<EndPoint> bus = new PriorityQueue<EndPoint>();
		
		for(int i=0;i<list.size();i++) {
			if(!bus.isEmpty()) {
				Time ed = bus.peek().ed,st = list.get(i).st;
				while(true) {
					boolean flag = compare(st,ed);
					
					if(flag) bus.poll(); 
					if(!flag || bus.isEmpty()) break;
					
					ed = bus.peek().ed;
				}//while loop		
			}
			bus.add(new EndPoint(list.get(i).st,list.get(i).ed));
			answer =Math.max(answer, bus.size());
		}//for
		
		System.out.println(answer);
	}
	private static boolean compare(Time st,Time ed) {
		boolean flag = false;
		
		if(ed.HH<st.HH) flag = true;
		else if(ed.HH==st.HH) {
			if(ed.MM<st.MM) flag = true;
			else if(ed.MM==st.MM) {
				if(ed.SS<st.SS) flag = true;
				else if(ed.SS==st.SS) {
					if(ed.sss<=st.sss) flag = true;
				}
			}
		}//end of if
		
		return flag;
	}
}
