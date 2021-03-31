#include "LinkedList.h"


//1. 템플릿 클래스로 확장해야함
//2. Stack형식으로 Delete 함수 재정의해야함
//주의: first, current_size는 class의 멤버 변수이기 때문에 this 포인터를 사용하여 가져와야함

//LinkedList class를 상속받음
template <typename T> 
class Stack:public LinkedList<T> {
public:
	bool Delete(T& element) {
		//first가 0이면 false반환
		if (this->first==0)return false;

		// LinkedList와 달리 Stack은 current가 가리키는 곳을 삭제
		//stack 의 특성상 current를 삭제한다.
		Node<T>* t = this->first;
		this->first = this->first->link;
		delete t;
		//delete연산을 실행하고 사이즈를 줄여준다.
		this->current_size--;
		return true;
	}
};
