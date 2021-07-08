import java.util.Scanner;
public class Main{
    public static void main(String[] args){
        int n1,n2,tmp;
        Scanner sc=new Scanner(System.in);
        n1=sc.nextInt();
        n2=sc.nextInt();
        tmp=n2;
        while(tmp>0){
            System.out.println(n1*(tmp%10));
            tmp/=10;
        }
        System.out.println(n1*n2);
    }
}