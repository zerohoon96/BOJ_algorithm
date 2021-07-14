#include <stdio.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
int main(void){
    int m,n,l,x,y,i;
    int left,right,mid,ct=0;
    vector<int> seat;
    scanf("%d%d%d",&m,&n,&l);
    seat.resize(m,0);
    for(i=0;i<m;i++) //사대 좌표를 입력받고 정렬
        scanf("%d",&seat[i]);
    sort(seat.begin(),seat.end());
    for(i=0;i<n;i++){ //동물의 위치를 입력받으며 잡을 수 있는지 이진탐색으로 결정
        scanf("%d%d",&x,&y);
        if(y>l||x<seat[0]-l||x>seat[m-1]+l) //일직선 사정거리보다 멀리 있으면 잡을 수 없음
            continue;
        left=0;
        right=m-1;
        while(left<=right){ //이진탐색
            mid=(left+right)/2;
            if(abs(seat[mid]-x)+y<=l){ //잡을 수 있으면 횟수 추가 후 break
                ct++;
                break;
            }
            if(seat[mid]-x>0) //현재 사대의 왼쪽
                right=mid-1;
            else //현재 사대의 오른쪽
                left=mid+1;
        }
    }
    printf("%d\n",ct); //정답 출력
    return 0;
}