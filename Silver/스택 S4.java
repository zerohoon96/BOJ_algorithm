import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main{
    static int[] stack;
    static int cur=-1;
    private static void push(int num){
        stack[++cur]=num;
    }
    private static int pop(){
        return cur<0?-1:stack[cur--];
    }
    private static int size(){
        return cur+1;
    }
    private static int empty(){
        return cur<0?1:0;
    }
    private static int top(){
        return cur<0?-1:stack[cur];
    }
    public static void main(String[] args){
        String input,tmp;
        String[] type={"push","pop","size","empty","top"};
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = null;
        int n,i,j;
        try{
            st = new StringTokenizer(br.readLine());    
        }
        catch(IOException e){
            e.printStackTrace();
        }
        n=Integer.parseInt(st.nextToken());
        stack=new int[n];
         for(i=0;i<n;i++){
        	 try{
        		 st = new StringTokenizer(br.readLine());
        	 }
        	 catch(IOException e) {
        		 e.printStackTrace();
        	 }
             input=st.nextToken();
             for(j=0;j<type.length;j++){
                 if(input.equals(type[j])){
                     switch(j){
                         case 0:
                             push(Integer.parseInt(st.nextToken()));
                             break;
                         case 1:
                             System.out.println(pop());
                             break;
                         case 2:
                             System.out.println(size());
                             break;
                         case 3:
                             System.out.println(empty());
                             break;
                         case 4:
                             System.out.println(top());
                             break;
                     }
                     break;
                 }
             }
         }
    }
}