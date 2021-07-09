import java.util.Scanner;
public class Main{
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int n,cur,ct=0;
        n=sc.nextInt();
        cur=n;
        sc.close();
        while(true){
            cur=((cur%10)*10)+(((cur/10)+(cur%10))%10);
            ct++;
            if(cur==n)
                break;
        }
        System.out.print(ct);
    }
}