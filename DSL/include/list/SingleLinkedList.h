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
#include <common/utility.h>
#include <common/assert.h>

namespace DSL {



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
node<T>* next() {
        return m_next;
}
T* pointer() {
        return &value;
}

explicit node( T& v) : value(v), m_next(nullptr) {
}
~node(){
};

inline bool operator==(const node &n) const {
        return n->value==this->value;
}
inline bool operator!=(const node &n) const {
        return !(*this==n);
}

node<T>* m_next;
T value;
};

node<T>* m_head;
node<T>* m_tail;
C m_count;

public:
explicit SingleLinkedList() :  m_count(0), m_head(nullptr), m_tail(nullptr) {
}
virtual ~SingleLinkedList(){
        this->clear();
}

inline bool isEmpty() const {
        return m_count==0;
}
inline int size() const {
        return m_count;
}

bool operator==(const SingleLinkedList<T> &l) const;
inline bool operator!=(const SingleLinkedList<T> &l) const
{
        return !(*this==l);
}

forward_iterator<T> begin(){
        forward_iterator<T> fi(m_head);
        return fi;
}

forward_iterator<T> end(){
        forward_iterator<T> fi(m_tail);
        return fi;
}
void clear_via_iterator(){
        forward_iterator<T> i = begin();
        forward_iterator<T> e = end();
        while(i != e) {
                forward_iterator<T> n = i+1; //iterator advance
                delete &i; //pointer to the iterator payload
                i = n;
        }
        if(m_count == 1)
                delete &i;

        m_count = 0;
        m_head = nullptr;
        m_tail = nullptr;

}
void clear(){
        node<T>* n = nullptr;
        while(m_head != nullptr) {
                n = m_head->m_next;
                delete m_head;
                m_head=n;
                m_count--;
        }
        m_head=nullptr;
        m_tail = nullptr;
}

void append( T& v){
        node<T>* n = new node<T>(v);
        if(isEmpty()) {
                m_head = n;
                m_tail = n;
        }else{
                m_tail->m_next = n;
                m_tail = n;
        }
        m_count++;
}
void prepend(const T& v){
        node<T>* n = new node<T>(v);
        if(isEmpty) {
                m_head = n;
                m_tail = n;
        }else{
                n->m_next = m_head;
                m_head = n;
        }
}

T first(){
        DSL_ASSERT( !isEmpty() );
        return m_head->value;
}

T takeTheOnlyOneElement(){
        DSL_ASSERT( !m_count == 1 );
        T val = m_head->value;
        delete m_head;
        m_head == m_tail == nullptr;
        return val;
}

T last(){
        DSL_ASSERT( !isEmpty() );

}



T takeFirst(){
        DSL_ASSERT( !isEmpty() );
        if(m_count == 1) {
                return takeTheOnlyOneElement();
        }
        T elem = first();

        node<T>* head_next = m_head->m_next;

        delete m_head;
        m_count--;

        m_head = head_next;

        return elem;
}

T takeLast(){
        if(m_count == 1) {
                return takeTheOnlyOneElement();
        }

        T elem = last();
        node<T> next_to_last = m_head;

        //size >= 2
        while( next_to_last->m_next != m_tail)
                next_to_last = next_to_last->next;

        delete m_tail;
        count--;
        m_tail = next_to_last;

        return elem;
}

int removeAll(const T &t);
bool removeOne(const T &t);

bool contains(const T &t) const {

}

template <typename D>
int count(const T &t) const {
        auto count_if = [&](const D acc, const T val) { if (val == t) return acc+1; return acc; };
        D count = fold(begin(),end(),0, count_if );
        return count;

}
};


}

#endif /* SINGLELINKEDLIST_H_ */
