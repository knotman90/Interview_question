//============================================================================
// Name        : printTree.cpp
// Author      : Davide Spataro
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdlib>
#include <queue>
using namespace std;

template<typename T>
struct Node{

	Node(T val){
		value=val;
		left=NULL;
		right=NULL;
	}

	void insertRight(Node<T>* n){
		right = n;
	}

	void insertLeft(Node<T>* n){
		left = n;
	}

	Node<T>* left;
	Node<T>* right;
	T value;


};


template <typename T>
Node<T>* createSeqTree(int level, int maxlevel, int val){
	if(level == maxlevel)
		return NULL;
	else{
		Node<T>* root = new Node<T>(val++);
		root->left=createSeqTree<T>(level+1,maxlevel,val);
		root->right=createSeqTree<T>(level+1,maxlevel,val);
		return root;
	}
}

template <typename T>
Node<T>* createRandomTree(int level, int maxlevel){
	if(level == maxlevel)
		return NULL;
	else{
		T val = rand() % 100;
		Node<T>* root = new Node<T>(val);
		root->left=createRandomTree<T>(level+1,maxlevel);
		root->right=createRandomTree<T>(level+1,maxlevel);
		return root;
	}
}

template <typename T>
Node<T>* deleteTree(Node<T>* node){
	if(node->left)
		deleteTree<T>(node->left);
	if(node->right)
		deleteTree<T>(node->right);

	delete node;
}

template <typename T>
std::queue<T> createQueue(Node<T>* node,std::queue<T>* queue){
	if(node){
		queue->push(node);
		if(node->left){
			queue->push(node->left);
		}
		if(node->left){
			queue->push(node->right);
		}
	}else{
		return queue;
	}
}


template <typename T>
std::queue<T> printQueue(std::queue<T> queue){
	for (T v : queue) {
		cout<<v<<" ";
	}
	cout<<endl;
}


template <typename T>
void print(Node<T>* node){
	std::queue<T>* queue = new std::queue<T>();
	createQueue(node,queue);



}




int main() {
	Node<int>* tree = createSeqTree<int>(0,2,0);
	print(tree),

			deleteTree<int>(tree);
	return 0;
}
