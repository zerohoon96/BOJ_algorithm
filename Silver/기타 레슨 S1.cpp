#include <stdio.h>
#include <vector>
using namespace std;
int main(void){
    int n,m,i;
    int left=0,right=0,mid,ct,tmp,res=0;
    vector<int> lesson;
    scanf("%d%d",&n,&m);
    lesson.resize(n,0);
    for(i=0;i<n;i++){ //입력받으면서 left,right 설정 (left : 전체를 한 조각씩 나누는 최솟값, right : 전체를 한 조각으로 나누는 최솟값)
        scanf("%d",&lesson[i]);
        right+=lesson[i];
        if(lesson[i]>left)
            left=lesson[i];
    }
    while(left<=right){ //이분탐색으로 최적의 mid값 찾기
        mid=(left+right)/2;
        tmp=ct=0;
        for(i=0;i<n;i++){ //현재 mid로 나눠지는 블루레이 수 구하기
            if(tmp+lesson[i]>mid){ //한 구간의 크기가 mid보다 커지면 count
                ct++;
                if(ct>m)
                    break;
                tmp=0;
                i--;
            }
            else
                tmp+=lesson[i];
        }
        ct++; //마지막 구간 처리
        if(ct>m) //블루레이 개수가 많으면 크기를 늘려서 개수를 줄임
            left=mid+1;
        else{ //정답이 가능하면 최솟값을 위해 크기를 줄임
            res=mid;
            right=mid-1;
        }
    }
    printf("%d\n",res);
    return 0;
}