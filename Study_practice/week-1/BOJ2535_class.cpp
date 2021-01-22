#include <iostream>
using namespace std;
/*
입력)학생수N -> (소속국가,학생번호,성적)
출력)금->은->동 수상자 출력(소속국가, 학생번호) 엔터로 구분
제한) 나라별 매달수는 최대 2개
1. 입력된 데이터 3가지가 묶어져야함(배열,혹은 클래스로 연결해야할듯)
2. 
*/
class Olympiad{
private:
    int country;
    int student;
    int grade;
public:
    Olympiad(){
    cin >>country>>student>>grade;

    }
};
int main(){
    int N;//학생수
    for(int i=0;i<N;i++){
        Olympiad();//클래스 여러개 호출
    }
    for(int i=0;i<N;i++){
        Olympiad();//큰순으로 금,은,동 해당되는 클래스차례로선정
    }
    //만약 금,은 나라가 동일하다면
    //금,은 나라가 아닌 국가를 대상으로
    //동메달을 선정한다
    




    return 0;
}