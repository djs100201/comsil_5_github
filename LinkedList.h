#ifndef __LINKEDLIST__
#define __LINKEDLIST__

#include <iostream>
using namespace std;
template <typename T>
// template을 이용해서 다형성을 활용한다.
//LinkedList Node
class Node{
	public:
		//데이터를 저장할 변수
		T data;
		//노드구조체 이용; 다음노드의 주소를 저장할 포인터
		Node *link;
		//element를 parameter로 받고, data에 element를 저장, 그리고 link는 NULL(==0)으로 둔다.
		Node(T element){
		  data = element;
		  link = 0;
		}
	};

template <typename T>
//LinkedList Class
class LinkedList{
	protected:
		//첫번째 노드의 주소를 저장할 포인터
		Node<T> *first;
		int current_size;
	public:
		//생성자, 초기화 
		//생성하면서, current_size와 first변수를 0으로 초기화 해준다.
		LinkedList(){
			first = 0;
			current_size = 0;
		};

		//노드 개수를 리턴
		//current_size는 항상 노드 개수를 담고 있으므로 바로 return 해 준다.
		int GetSize(){
			return current_size;
		};

		//맨 앞에 원소를 삽입, LinkedList와 Stack 둘다 같다
		void Insert(T element);
		
		//맨 뒤의 원소를 삭제, 제일 나중에 들어온 원소 삭제  - LinkedList
		virtual bool Delete(T &element);

		//리스트 출력
		void Print();
};


//새 노드를 맨 앞에 붙이고 값을 넣음
template <typename T>
void LinkedList<T>::Insert(T element){
	//노드 생성
	Node<T> *newnode = new Node<T>(element);

	//새 노드가 첫번째 노드를 가리킴
	//newnode는 포인터이기 때문에 -> 를 사용해 함수, 변수를 불러옴 newnode.link와 뜻은 같다
	newnode -> link = first;
	first = newnode;
	current_size++;
}

//마지막 노드의 값을 리턴하면서 메모리에서 할당 해제
template <typename T>
bool LinkedList<T>::Delete(T &element){
	//만약 first가 0이라면 삭제할 것이 없는것!
	if (first == 0)
		return false;
	
	Node<T> *current = first;
	Node<T> *previous = 0;
	
	//마지막 노드까지 찾아가는 반복문
	while(1){
		if (current->link == 0){  //마지막 노드를 찾는것
			if (previous)
				//previous의 연결된 링크를 현재 링크로 바꿔주는 작업
				previous -> link = current -> link;
			else
				first = first -> link;
			break;
		}
		previous = current;
		current = current -> link;
	}
	element = current -> data;
	delete current;
	//size를 줄여준다.
	current_size--;

	return true;
}

//리스트를 출력하는 Print 함수
template <typename T>
void LinkedList<T>::Print(){
	Node<T> *i;
	//i는 노드 포인터, index는 1부터 시작
	int index = 1;

	if (current_size != 0){
		for( i = first; i != NULL; i=i->link){
			if (index == current_size){
				cout << "[" << index << "|";
				cout << i -> data <<"]->";
			}
			
			else {
				cout << "[" << index << "|";
				cout << i -> data << "]->";
				index++;
			}
		}
		//개행문자 출력
		cout << endl;
	}

}


#endif
