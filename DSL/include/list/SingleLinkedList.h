/*
 * SingleLinkedList.h
 *
 *  Created on: 18 gen 2016
 *      Author: knotman
 */

#ifndef SINGLELINKEDLIST_H_
#define SINGLELINKEDLIST_H_

#include <list>
namespace DSL{

template<class T, class C = uint>
class SingleLinkedList {

protected:
 DSL::deallocator<T> d;

template<class Y>
struct node {
friend SingleLinkedList<T,C>;

	explicit node(T& v) : value(v), next(nullptr) {}
	~node(){ };
	void destroy(DSL::deallocator<T> d){
		d(value);
	}
	bool operator==(const node &n) const{
		return n->value==this->value;
	}
	bool operator!=(const node &n) const{
		return !(*this==n);
	}


	node<T>* next;
	T value;
};

node<T>* _head;
C _count;


public:
	explicit SingleLinkedList():  _count(0), _head(nullptr), d(DSL::noOpDeallocator) {}
	virtual ~SingleLinkedList(){
			this->clear();
	}

	bool isEmpty() const{
		return _count==0;
	}
	int size() const{
		return _count;
	}

	bool operator==(const SingleLinkedList<T> &l) const;
	inline bool operator!=(const SingleLinkedList<T> &l)const
		{
		return !(*this==l);
		}

	void clear(){
		node<T>* n = nullptr;
		while(_head != nullptr){
			n = _head->next;
			_head->destroy(d);
			_head=n;
			_count--;
		}
		_head=nullptr;
	}

	void append(const T&);
	void prepend(const T&);
	T takeFirst();
	T takeLast();
	int removeAll(const T &t);
	bool removeOne(const T &t);
	bool contains(const T &t) const;

	int count(const T &t) const;
};


}

#endif /* SINGLELINKEDLIST_H_ */
