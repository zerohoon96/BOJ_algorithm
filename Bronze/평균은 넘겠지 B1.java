import java.util.Scanner;
public class Main{
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int []arr;
        int tc,n,i,j,ct;
        double avg;
        tc=sc.nextInt();
        for(i=0;i<tc;i++){
            n=sc.nextInt();
            arr=new int[n];
            avg=ct=0;
            for(j=0;j<n;j++){
                arr[j]=sc.nextInt();
                avg+=arr[j];
            }
            avg/=n;
            for(j=0;j<n;j++){
                if(arr[j]>avg)
                    ct++;
            }
            System.out.printf("%.3f%%\n",(double)ct/n*100);
        }
        sc.close();
    }
}