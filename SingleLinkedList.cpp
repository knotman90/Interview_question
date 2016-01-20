//============================================================================
// Name        : ProgrammingInterview.cpp
// Author      : Davide Spataro
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <memory>
using namespace std;

namespace SingleLinkedList{


template <typename T>
class Node{

	Node(const T value){
		next=NULL;
		this->value=value;
	}

	Node(const Node& _node){
		next=_node.next;
		this->value=_node.value;
	}

	Node* next;
	T value;

	//insert a node on left of the List
	Node& HeadInsert(const T& _node){
		_node.next=this;
		return _node;
	}


	bool Insert(T data){
		Node* n = new Node(data);
		NextInsert(n);
		return true;
	}

	//insert a node on right of the List
	void NextInsert(const T& _node){
		const Node*  headNext=this->next;
		this->next=_node;
		_node.next=headNext;
	}

	void TailInsert(const Node& _node){
		Node n = this;
		while(n.next!=NULL){
			n=n.next;
		}
		n.next=_node;

	}
	void TailInsert(const T data){
		Node n = new Node(data);
		TailInsert(n);
	}

	//insert a node on right of the List
	bool deleteNext(const T& _node){
		if(!next)
			return false;

		Node*  nn= next->next;
		this->next =nn;
		return true;
	}


};



}





int main() {
	cout << "" << endl; // prints 
	return 0;
}
