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
template<typename T, typename C = int,
            template <typename ,
                    template<typename, typename...> class _Iterable, typename... Args> class _Iterator = forward_iterator
     >
class SingleLinkedList {

protected:

/**
   Node Class
 */
template<typename Y>
class node : public forward_iterable<T> {

friend SingleLinkedList;
public:
node<T>* next() {
        return m_next;
}

virtual  T& value(){
        return m_value;
}

explicit node( T& v) : m_value(v), m_next(nullptr) {
}
~node(){
};

inline bool operator==(const node &n) const {
        return n->m_value==this->m_value;
}
inline bool operator!=(const node &n) const {
        return !(*this==n);
}



node<T>* m_next;
T m_value;
};

typedef _Iterator<T, node> Iterator;

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

bool operator==(const SingleLinkedList &l) const;
inline bool operator!=(const SingleLinkedList &l) const
{
        return !(*this==l);
}


forward_iterator<T, node> begin(){
        forward_iterator<T, node> fi(m_head);
        return fi;
}


Iterator end(){
        Iterator fi(m_tail);
        return fi;
}


void clear_via_iterator(){
        Iterator i = begin();
        Iterator e = end();
        while(i != e) {
                Iterator n = i+1; //iterator advance
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
        return m_head->m_value;
}

T takeTheOnlyOneElement(){
        DSL_ASSERT( m_count == 1 );
        T val = m_head->m_value;
        delete m_head;
        m_head = m_tail = nullptr;
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
        node<T>* next_to_last = m_head;

        //size >= 2
        while( next_to_last->m_next != m_tail)
                next_to_last = next_to_last->m_next;

        delete m_tail;
        m_count--;
        m_tail = next_to_last;

        return elem;
}

int removeAll(const T &t);


bool removeOne(const T &t){
        /*
        for(auto it = begin(); it != end(); it++) {
                if(*it == t) {
                    Iterable* del_next = it->next();

                }
        }*/
}

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
