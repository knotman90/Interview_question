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
#include <algorithm/algorithm.h>
#include <common/utility.h>
#include <common/assert.h>

namespace DSL {



    /**
       Node Class
     */
    template<typename T>
    class node : public forward_iterable<T> {


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


typedef unsigned int uint;


/*! \brief Singly Linked List implementation.
 *         The second template parameter is used as type of the  Lists's size.
 *
 */
template<typename T, typename C = int, template <typename> class NODE = node,
            template <typename ,
                    template<typename, typename...> class _Iterable, typename... Args> class _Iterator = forward_iterator

     >
class SingleLinkedList {



typedef _Iterator<T, NODE> Iterator;

NODE<T>* m_head;
NODE<T>* m_tail;
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


Iterator begin() const {
        Iterator fi(m_head);
        return fi;
}


Iterator end() const  {
        //Iterator fi(m_tail);
        NODE<T>* e =  static_cast<NODE<T>*> (m_tail == nullptr ? nullptr : m_tail->next());
        Iterator fi (e);
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
        NODE<T>* n = nullptr;
        int i=0;
        while(m_head != nullptr) {
                n =  static_cast<NODE<T>*> (m_head->m_next);
                delete m_head;
                m_head=n;
                m_count--;
        }
        m_head=nullptr;
        m_tail = nullptr;
}

void append( T& v){
        NODE<T>* n = new NODE<T>(v);
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
        NODE<T>* n = new NODE<T>(v);
        if(isEmpty()) {
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
        m_count--;
        return val;
}

T last(){
        DSL_ASSERT( !isEmpty() );
        return m_tail->m_value;

}



T takeFirst(){
        DSL_ASSERT( !isEmpty() );
        if(m_count == 1) {
                return takeTheOnlyOneElement();
        }
        T elem = first();

        NODE<T>* head_next = static_cast<NODE<T>*> (m_head->m_next);

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
        NODE<T>* next_to_last = m_head;

        //size >= 2
        while( next_to_last->m_next != m_tail)
                next_to_last =  static_cast<NODE<T>*> (next_to_last->m_next);

        delete m_tail;
        m_count--;
        m_tail = next_to_last;

        return elem;
}


//use fold when backwards iterator are present
int removeAll(const T &t){
    uint n_rem = 0;
    NODE<T> *curr = m_head;
    NODE<T> *next = m_head->m_next;
    while(curr != next){
      if(next->m_value == t){
        NODE<T> *next_next =  static_cast<NODE<T>*> (next->m_next);
        delete next;
        curr->m_next = next_next;
        m_count--;
        ++n_rem;
      }
    }
    return n_rem;
}



bool removeOne(const T &t){

        if(isEmpty())
            return false;
        if(first()==t){
            takeFirst();
            return true;

        }else if(size() >= 2){
            NODE<T> *curr = m_head;
            NODE<T> *next = m_head->m_next;
            while(next){

              if(next->m_value == t){
                    NODE<T> *next_next = next->m_next;
                    delete next;
                    curr->m_next = next_next;
                    if(next_next == nullptr)//we removed the last element
                        m_tail = nullptr;
                    m_count--;
                    return true;
              }

              curr = next;
              next = next ->m_next;
            }
    }
        return false;
}

bool contains(const T &t) const {

  return DSL::contains(begin() , end() , t);

}


};


}

#endif /* SINGLELINKEDLIST_H_ */
