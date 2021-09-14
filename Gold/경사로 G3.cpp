#include <stdio.h>
#include <math.h>
#include <vector>
using namespace std;
int main(void){
    int n,l,i,j,k,start,diff,res=0;
    vector<vector<int> > map;
    scanf("%d%d",&n,&l);
    map.resize(n,vector<int>(n));
    
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&map[i][j]);
        }
    }
    for(i=0;i<n;i++){ //가로 줄 검사
        start=0; //현재 크기의 블럭 시작점 초기화
        for(j=1;j<n;j++){
            diff=map[i][start]-map[i][j];
            if(abs(diff)>1) //두 칸의 높이 차이가 1보다 크면 불가능
                break;
            if(diff<0){ //새로운 지점이 더 높음 (↗)
                if(j-l<start) //올라가는 경사로를 놓을 수 없으므로 불가능
                    break;
                start=j; //새로운 현재높이 설정
            }
            else if(diff>0){ //새로운 지점이 더 낮음 (↘)
                if(j+l>n) //범위를 벗어났기 때문에 불가능
                    break;
                for(k=j+1;k<j+l;k++){
                    if(map[i][k]!=map[i][j]) //현재부터 L칸 가는 동안 경사가 달라지면 불가능
                        break;
                }
                if(k<j+l) //중간에 실패했으면 break
                    break;
                if(k<n){
                    if(map[i][k]>map[i][j]) //경사로 종료 다음 칸의 크기가 크면 불가능
                        break;
                    if(map[i][k]==map[i][j]) //경사로 종료 다음 칸의 크기가 같으면 k++
                        k++;
                }
                j=start=k-1; //시작위치, j 변경
            }
        }
        if(j>=n) //반복문이 제대로 종료된 경우 가능하므로 결과 추가
            res++;
    }

    for(i=0;i<n;i++){ //세로 줄 검사
        start=0; //현재 크기의 블럭 시작점 초기화
        for(j=1;j<n;j++){
            diff=map[start][i]-map[j][i];
            if(abs(diff)>1) //두 칸의 높이 차이가 1보다 크면 불가능
                break;
            if(diff<0){ //새로운 지점이 더 높음 (↗)
                if(j-l<start) //올라가는 경사로를 놓을 수 없으므로 불가능
                    break;
                start=j; //새로운 현재높이 설정
            }
            else if(diff>0){ //새로운 지점이 더 낮음 (↘)
                if(j+l>n) //범위를 벗어났기 때문에 불가능
                    break;
                for(k=j+1;k<j+l;k++){
                    if(map[k][i]!=map[j][i]) //현재부터 L칸 가는 동안 경사가 달라지면 불가능
                        break;
                }
                if(k<j+l) //중간에 실패했으면 break
                    break;
                if(k<n){
                    if(map[k][i]>map[j][i]) //경사로 종료 다음 칸의 크기가 크면 불가능
                        break;
                    if(map[k][i]==map[j][i]) //경사로 종료 다음 칸의 크기가 같으면 k++
                        k++;
                }
                j=start=k-1; //시작위치, j 변경
            }
        }
        if(j>=n) //반복문이 제대로 종료된 경우 가능하므로 결과 추가
            res++;
    }

    printf("%d\n",res);
    return 0;
}