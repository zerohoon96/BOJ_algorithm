import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
public class Main{
	public static void main(String[] args) {
		int n,i,j,cur;
		int[] stack;
		boolean fail;
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		String str=null;
		try {
			str=br.readLine();
		}
		catch(IOException e) {
			e.printStackTrace();
		}
		n=Integer.parseInt(str);
		for(i=0;i<n;i++) {
			try {
				str=br.readLine();
			}
			catch(IOException e) {
				e.printStackTrace();
			}
			fail=false;
			cur=0;
			stack=new int[str.length()];
			for(j=0;j<str.length();j++) {
				if(str.charAt(j)=='(') //push
					stack[cur++]=1;
				else { //pop
					if(cur<1) { //pop 불가능
						fail=true;
						break;
					}
					cur--;
				}
			}
			if(cur>0||fail) //남은 괄호가 있거나 pop이 불가능하면 실패
				System.out.println("NO");
			else
				System.out.println("YES");
		}
	}
}