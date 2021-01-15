#include <iostream>
using namespace std;

class family {//가계도에 있는 가족의 아이디(idArray),자손-조상관계를 저장할 클래스를 선언
private:
	int n;//가계도에있는 사람의 숫자
	int* idArray;//가계도에 있는 가족의 아이디를 저장하는 배열
	int* parent;//가족관계를 저장하는 배열
public:
	family(int n) {//생성자를 통해 priviate에 있는 변수들을 설정해준다.
		this->n = n;//생성자의 매개변수로 n을 받고 이를 n에 재선언 해준다.
		this->idArray = new int[n] {0};//idArray의 배열을 new를 이용하여 입력받은 n크기만큼 동적할당해준다.
		this->parent = new int[n] {0};//oarent의 배열을 new를 이용하여 입력받은 n크기만큼 동적할당해준다.
		for (int i = 0; i < n; i++)//부모관계를 입력받을때에, 관계를 입력받지못한 사람은 -1을 값으로 갖고있어야하므로
			parent[i] = -1;//parent 배열의 모든 원소를 -1로 초기화 해준다
	}
	~family() {
		delete this->idArray;
		delete this->parent;
	}
	void setId(int i, int id) {//setID함수:입력받은 순서-아이디를 배열에 저장해준다.
		this->idArray[i] = id;
	}
	void setParent(int i, int parent_num) {//setParent함수:입력받은 부모관계를 배열에 저장해준다.
		this->parent[i] = parent_num;
	}

	int relation(int p1, int p2) {//relation 함수: p1가 p2의 손자(1)인지, 조상(2)인지, 아무런 관계가 없는지(0) 판별하는 함수
		for (int i = 0; i < n; i++) {//parent 배열을 이용하기위해, 아이디를 번호로 바꾸어준다
			if (idArray[i] == p1)
				p1 = i;
			if (idArray[i] == p2)
				p2 = i;
		}
		/*relation함수에 대한 부가설명
		
		p1값을 인덱스로 가지는 parent배열의 값을 compareArray이라는 배열에 저장하고,
		parent 배열의 값이 -1이라면, 더이상 해당 인덱스를 번호로 가진 아이디의 사람은 부모가 없다는것을 의미하므로,
		해당인덱스 까지만 compareArray배열에 저장하여준다.
		저장된 배열에 만
	
		
		*/
		int compareArray1[100], compareArray2[100];//compareArray<-p1,p2와 직접적으로 연결되어있는 라인을 저장해주기위한 배열/크기는 큰숫자 100을 임의로 설정
		int count1 = 0;//compareArray 배열의 크기를 알기위해 count1,2 변수를 선언해줌
		int count2 = 0;
		int search = p1;//p1값을 저장해두기위한 변수
		if (p1 == p2)//둘이 같은 값이라면, 
			return 0;//0을 반환한다.
		while (p1 != -1) {//p1값이 -1이 아닐동안( 해당 인덱스를 번호로 가진 아이디의 사람은 부모가 없을때까지)
			p1 = parent[p1];//부모배열에 직계부모들을 저장해주기위해 p1을 재선언해준다.
			compareArray1[count1] = p1;//compareArray 배열에 저장
			count1++;//compareArray 배열의 크기를 알기위해 하나씩 더해줌
		}
		for (int i = 0; i < count1; i++){//만약 compareArray배열에 p2가 포함되어있으면 
			if (p2 == compareArray1[i])// p2가 p1보다 그림상으로 위에 있는것이므로
				return 1;//1을 반환
		}

		while (p2 != -1) {//p2값이 -1이 아닐동안( 해당 인덱스를 번호로 가진 아이디의 사람은 부모가 없을때까지)
			p2 = parent[p2];//부모배열에 직계부모들을 저장해주기위해 p2을 재선언해준다.
			compareArray2[count2] = p2;//compareArray 배열에 저장
			count2++;//compareArray 배열의 크기를 알기위해 하나씩 더해줌

		}

		for (int i = 0; i < count2; i++) {//만약 compareArray배열에 p1가 포함되어있으면 

			if (compareArray2[i] == search)// p1가 p2보다 그림상으로 위에 있는것이므로
				return 2;//2를 반환
		}
		return -1;//아직까지 아무것도 반환되지않았다면, 직접적인 손자,조상 관계가 아니므로 관계없음(-1 반환)


	}
};



int main() {

	int person_num, relation_num;//사람의 개수, 부모관계 정보의 개수 변수 선언
	cin >> person_num >> relation_num;
	family f(person_num);
	int son, parent, id, I;
	int p1, p2;

	for (int i = 0; i < person_num; i++) {
		cin >> I >> id;
		f.setId(I, id);//아이디-번호 저장
	}
	for (int i = 0; i < relation_num; i++) {
		cin >> son >> parent;
		f.setParent(son, parent);//부모관계 정보 저장
	}
	cin >> p1 >> p2;//비교할 사람의 아이디 입력
	//f.change(p1, p2);


	cout << f.relation(p1, p2) << endl;//관계 출력 

	return 0;
}
