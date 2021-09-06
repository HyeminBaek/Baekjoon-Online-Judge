import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String s = br.readLine();
		StringTokenizer st = new StringTokenizer(s,"+-");
		StringTokenizer op = new StringTokenizer(s,"0123456789");
		
		ArrayList<Integer> num = new ArrayList<Integer>();
		while(st.hasMoreTokens()) {
			num.add(Integer.parseInt(st.nextToken()));
		}
		ArrayList<String> oper = new ArrayList<String>();
		while(op.hasMoreTokens()) {
			oper.add(op.nextToken());
		}
		
		System.out.print(sol(num,oper));
	}
	private static int sol(ArrayList<Integer> num,ArrayList<String> oper) {
		int answer= num.get(0); num.remove(0);
		
		boolean fst = false;
		while(!oper.isEmpty()) {
			String op = oper.get(0); oper.remove(0);
			if(op.equals("-")) {
				if(!oper.isEmpty()&&oper.get(0).equals("+")) {
					int sum =0;
					while(!num.isEmpty()&&!oper.isEmpty()&&oper.get(0)!="-") {
						sum+=num.get(0); num.remove(0); oper.remove(0);
						if(oper.isEmpty()) {
							sum+=num.get(0); num.remove(0);
						}
					}
					
					answer-=sum;
				} else {
					answer -= num.get(0); num.remove(0);
				}
			} else {
				answer+=num.get(0); num.remove(0);
			}
		}
		return answer;
	}
}
