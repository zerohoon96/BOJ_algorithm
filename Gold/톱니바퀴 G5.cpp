#include <stdio.h>
int arr[4][8];
void rotate(int wheel,int direction){ //회전 함수
    int i,tmp;
    if(direction==1){ //시계 방향 회전
        tmp=arr[wheel][7];
        for(i=7;i>0;i--)
            arr[wheel][i]=arr[wheel][i-1];
        arr[wheel][0]=tmp;
    }
    else{ //반시계 방향 회전
        tmp=arr[wheel][0];
        for(i=0;i<7;i++)
            arr[wheel][i]=arr[wheel][i+1];
        arr[wheel][7]=tmp;
    }
}
int main(void){
    int i,j,k,tmp,wheel,direction,cur_wheel,cur_direction,res=0;
    for(i=0;i<4;i++){
        scanf("%d",&tmp);
        for(j=7;j>=0;j--){
            arr[i][j]=tmp%10;
            tmp/=10;
        }
    }
    scanf("%d",&k);
    for(i=0;i<k;i++){ //k번 회전
        scanf("%d%d",&wheel,&direction);
        cur_wheel=wheel-1;
        cur_direction=direction;
        tmp=arr[cur_wheel][6];
        while(cur_wheel>=1){ //왼쪽 돌리기 (돌릴 수 있을 때까지 돌림)
            if(tmp==arr[cur_wheel-1][2])
                break;
            cur_wheel--;
            cur_direction*=-1;
            tmp=arr[cur_wheel][6];
            rotate(cur_wheel,cur_direction);
        }

        cur_wheel=wheel-1;
        cur_direction=direction;
        tmp=arr[cur_wheel][2];
         while(cur_wheel<=6){ //오른쪽 돌리기 (돌릴 수 있을 때까지 돌림)
            if(tmp==arr[cur_wheel+1][6])
                break;
            cur_wheel++;
            cur_direction*=-1;
            tmp=arr[cur_wheel][2];
            rotate(cur_wheel,cur_direction);
        }
        rotate(wheel-1,direction); //현재 톱니바퀴 돌리기
    }
    
    //점수계산
    if(arr[0][0]==1)
        res+=1;
    if(arr[1][0]==1)
        res+=2;
    if(arr[2][0]==1)
        res+=4;
    if(arr[3][0]==1)
        res+=8;
    printf("%d\n",res);
    return 0;
}