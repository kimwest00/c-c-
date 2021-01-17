#include <stdio.h>
#include <stdlib.h>

typedef struct Point {// 다각형의 점들을 저장해주기 위한 구조체 선어
   float x;
   float y;
}Point;//typedef 형으로 Point만 써주면 된다.

float ccw(Point P1,Point P2,Point P3){//벡터의 외적식을 이용하여 점의 진행방향을 나타내는 숫자를 출력해주는 함수
	
	float S;//진행방향을 나타내줄 숫자 선언

	S = (P2.x-P1.x)*(P3.y-P1.y) - (P2.y-P1.y)*(P3.x-P1.x);//벡터의 외적식
   
	if(S>0)//시계방향이면 –1을, 일직선이면 0을, 반시계방향이면 1을 반환한다.
		return 1;
   
	else if(S==0)
		return 0;
   
	else
		return -1;

}


int main() {
	int input[100];//세점의 진행방향을 나타내는 함수의 숫자를 저장해주기 위한 배열
	int n;//n각형의 n
	int count = 0;//오목점 개수를 세어주는 변수 선언
	scanf("%d", &n);//입력받음
  Point* polygon= malloc(sizeof(Point)*n);//구조체를 malloc을 이용하여 동적할당받음
	
	for (int i = 0; i < n; i++){//다각형의 점 좌표 입력받음
		scanf("%f %f", &polygon[i].x, &polygon[i].y);
		
	}
	for(int i=0; i<=n-2 ; i++){//세점의 진행방향을 나타내는 함수의 숫자를 input에 저장해줌
		input[i] = ccw(polygon[i],polygon[i+1],polygon[i+2]);
   
   }
	for(int i=0; i<=n-2 ; i++){
		if(input[0] != input[i]){//처음의 점 진행방향과 다르면 방향이 바뀐것이므로
			
			count += 1;//오목점으로 간주하고 count 변수에 1을 더해준다
      }
   }
	printf("%d",count);//오목점 개수 출력
	
	
	return 0;
}
4. 느낀 점
