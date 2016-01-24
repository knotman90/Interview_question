/*
 * iterator.h
 *
 *  Created on: 18 gen 2016
 *      Author: knotman
 */

#ifndef ITERATOR_H_
#define ITERATOR_H_

#include <common/utility.h>

namespace DSL{

template<typename T>
class forward_iterable {
public:
  forward_iterable();
  virtual ~forward_iterable();
  virtual forward_iterable<T>* next() = 0;
  inline T& value(){
    return *(pointer());
  }
  virtual T* pointer() = 0;
};

template<typename T>
class backward_iterable : forward_iterable<T>{
  public:
    backward_iterable();
    virtual ~backward_iterable();
    virtual backward_iterable<T>* previous() = 0;

};



/**
* Sequential forward iterator
*/
template <class T>
class sequential_forward_iterator {

public:
  typedef T value_type;
  typedef T* pointer;
  typedef T* reference;

  inline sequential_forward_iterator() : m_i(nullptr) {}
  inline sequential_forward_iterator(pointer n) : m_i(n) {}
  inline sequential_forward_iterator(const sequential_forward_iterator &o) : m_i(o.m_i) {}

//operators
inline sequential_forward_iterator &operator=(const sequential_forward_iterator &o) { m_i = o.m_i; return *this; }
inline reference operator&(){ return m_i->pointer();}
inline pointer operator*(){ return m_i->value();}

inline bool operator==(const sequential_forward_iterator &o) const { return m_i == o.m_i; }
inline bool operator!=(const sequential_forward_iterator &o) const { return m_i != o.m_i; }

//pre-increment operator (return a reference)
inline sequential_forward_iterator &operator++() { m_i = m_i->next(); return *this; }
//post-increment operator (return a value)
inline sequential_forward_iterator operator++(int) { pointer n = m_i; m_i = m_i->next(); return n; }


protected:

pointer * m_i;


};


template <class T>
class forward_iterator : public sequential_forward_iterator<T> {
  typedef T value_type;
  typedef T* pointer;
  typedef T* reference;

  inline forward_iterator() {}
  inline forward_iterator(pointer n) : sequential_forward_iterator<T>(n) {}
  inline forward_iterator(const forward_iterator &o) : sequential_forward_iterator<T>(o) {}

  template<class N>
  inline forward_iterator operator+(N j) const
  {
    DSL_ASSERT(j >= 0);
     pointer *n = this->m_i;
        while (j--)
          n = n->next();
    return n;
  }

  inline forward_iterator &operator+=(int j) {
    forward_iterator* fi = *this + j;
    this=fi;
    return *this;
  //  return *this = *this + j;
  }


};


template <class T>
class backward_iterator : public forward_iterator<T> {
  typedef T value_type;
  typedef T* pointer;
  typedef T* reference;

  inline backward_iterator() {}
  inline backward_iterator(pointer n) : forward_iterator<T>(n) {}
  inline backward_iterator(const backward_iterator &o) : forward_iterator<T>(o) {}

  template<class N>
  inline backward_iterator operator+(N j) const
  {
    if( j > 0){
       backward_iterator<T> b = forward_iterator<T>::operator+(j);
       return b;
    }else{ // j<=0
     pointer *n = this->m_i;
        while (j++)
          n = n->previous();
        }
    return n;
  }




};


/*
template <class T>
class random_access_iterator : public forward_iterator {

  inline random_access_iterator() : m_i(nullptr) {}
  inline random_access_iterator(pointer n) : m_i(n) {}
  inline random_access_iterator(const forward_iterator &o) : m_i(o.m_i) {}

  //pre-decrement operator (return a reference)
  inline forward_iterator &operator--() { m_i = i->p; return *this; }
  //pre-decrement operator (return a value)
  inline forward_iterator operator--(int) { Node *n = i; i = i->p; return n; }

  inline iterator operator+(int j) const
  { Node *n = i; if (j > 0) while (j--) n = n->n; else while (j++) n = n->p; return n; }
  inline iterator operator-(int j) const { return operator+(-j); }
  inline iterator &operator+=(int j) { return *this = *this + j; }
  inline iterator &operator-=(int j) { return *this = *this - j; }


};

*/
}

#endif /* ITERATOR_H_ */
