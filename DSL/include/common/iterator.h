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

template<typename T, typename D = int>
class random_iterable : forward_iterable<T>{
  public:
    random_iterable();
    virtual ~random_iterable();

    virtual random_iterable<T>* elemAt(D element) = 0;

};


/**
* Sequential forward iterator
*/
template <class T>
class sequential_forward_iterator {

public:
  typedef T value_type;
  typedef T* pointer;
  typedef T& reference;

  inline sequential_forward_iterator() : m_i(nullptr) {}
  inline sequential_forward_iterator(pointer n) : m_i(n) {}
  inline sequential_forward_iterator(const sequential_forward_iterator &o) : m_i(o.m_i) {}

//operators
inline sequential_forward_iterator &operator=(const sequential_forward_iterator &o) { m_i = o.m_i; return *this; }
inline pointer operator->(){ return m_i->pointer();}
inline pointer operator&(){ return m_i->pointer();}
inline reference operator*(){ return m_i->value();}

inline bool operator==(const sequential_forward_iterator &o) const { return m_i == o.m_i; }
inline bool operator!=(const sequential_forward_iterator &o) const { return m_i != o.m_i; }

//pre-increment operator (return a reference)
inline sequential_forward_iterator &operator++() { m_i = m_i->next(); return *this; }
//post-increment operator (return a value)

inline sequential_forward_iterator operator++(int) { sequential_forward_iterator n = *this; m_i = m_i->next(); return n; }


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
     forward_iterator *i = this;
        while (j--)
          i++;
    return i;
  }

template<typename N = int>
  inline forward_iterator &operator+=(N j) {
    forward_iterator* fi = *this + j;
    this=fi;
    return *this;
  //  return *this = *this + j;
  }
template<typename N>
  inline forward_iterator &operator-=(N j){
      return operator+(-j);
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

  //pre-decrement operator (return a reference to the current object) ->returns a reference
  inline backward_iterator &operator--() { this->m_i = this->m_i->previous(); return *this; }
  //pre-decrement operator (return a copy of the current iterator and increments the original)->returns a value
  inline backward_iterator operator--(int) { backward_iterator n = *this; this->m_i = this->m_i->previous() ; return n; }

  template<class N = int>
  inline backward_iterator operator+(N j) const
  {
    if( j > 0){
      return this->forward_iterator<T>::operator+(j);

    }else{ // j<=0
     backward_iterator *i = this;
        while (j++)
          i--;

    return i;
    }
  }
};



template <typename T>
class random_access_iterator : public backward_iterator<T> {
    typedef T value_type;
    typedef T* pointer;
    typedef T* reference;


  inline random_access_iterator() {}
  inline random_access_iterator(pointer n) : backward_iterator<T>(n) {}
  inline random_access_iterator(const random_access_iterator &o) : backward_iterator<T>(o) {}

template <typename D = uint>
inline value_type operator[](D offset){
    random_access_iterator i = *this;
    i.m_i = i.m_i->elemAt(offset);
    return *i;
}

};

}

#endif /* ITERATOR_H_ */
