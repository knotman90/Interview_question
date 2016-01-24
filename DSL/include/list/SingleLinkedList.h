/*
 * SingleLinkedList.h
 *
 *  Created on: 18 gen 2016
 *      Author: knotman
 */

#ifndef SINGLELINKEDLIST_H_
#define SINGLELINKEDLIST_H_


#include <assert.h>
#include <common/iterator.h>
namespace DSL{



typedef unsigned int uint;


/*! \brief Singly Linked List implementation.
 *         The second template parameter is used as type of the  Lists's size.
 *
 */
template<typename T, typename C = uint>
class SingleLinkedList {

protected:

  /**
  Node Class
  */
template<typename Y>
  class node : public forward_iterable<T> {
   friend SingleLinkedList<T,C>;
    node<T>* next() { return this; }
    T* pointer() { return &value; }

  	explicit node(T& v) : value(v), m_next(nullptr) {}
  	~node(){ };

  	inline bool operator==(const node &n) const{
  		return n->value==this->value;
  	}
  	inline bool operator!=(const node &n) const{
  		return !(*this==n);
  	}

  	node<T>* m_next;
  	T value;
  };

node<T>* m_head;
node<T>* m_tail;
C m_count;

public:
	explicit SingleLinkedList():  m_count(0), m_head(nullptr) , m_tail(nullptr) {}
	virtual ~SingleLinkedList(){
			this->clear();
	}

	inline bool isEmpty() const{
		return m_count==0;
	}
	inline int size() const{
		return m_count;
	}

	bool operator==(const SingleLinkedList<T> &l) const;
	inline bool operator!=(const SingleLinkedList<T> &l)const
		{
		return !(*this==l);
		}

	void clear(){
		node<T>* n = nullptr;
		while(m_head != nullptr){
			n = m_head->m_next;
			delete m_head;
			m_head=n;
			m_count--;
		}
		m_head=nullptr;
	}

	void append(const T& v){
    node<T>* n = new node<T>(v);
    if(isEmpty){
      m_head = n;
      m_tail = n;
    }else{
      m_tail->m_next = n;
      m_tail = n;
    }
    count++;
  }
	void prepend(const T& v){
      node<T>* n = new node<T>(v);
      if(isEmpty){
        m_head = n;
        m_tail = n;
      }else{
        n->m_next = m_head;
        m_head = n;
      }
  }

  T first(){
    DSL_ASSERT(isEmpty());
    return *m_head;
  }

  T erase(){

  }

	T takeFirst(){
    T elem = first();
    erase(m_head);
  }

	T takeLast();
	int removeAll(const T &t);
	bool removeOne(const T &t);
	bool contains(const T &t) const;

	int count(const T &t) const;
};


}

#endif /* SINGLELINKEDLIST_H_ */
