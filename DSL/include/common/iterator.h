/*
 * iterator.h
 *
 *  Created on: 18 gen 2016
 *      Author: knotman
 */

#ifndef ITERATOR_H_
#define ITERATOR_H_

namespace DSL{

template<typename Payload>
class forward_iterable {


public:
  forward_iterable() {};
  virtual ~forward_iterable(){};
  virtual forward_iterable *next() = 0;


  virtual  Payload& value() = 0;

  virtual inline Payload* pointer() { return nullptr; }
};

template< typename Payload>
class backward_iterable : forward_iterable< Payload > {

  public:
    backward_iterable();
    virtual ~backward_iterable();
    virtual backward_iterable* previous() = 0;

};

template< typename Payload, typename Numeric >
class random_iterable : backward_iterable< Payload >{

  public:
    random_iterable();
    virtual ~random_iterable();

    virtual random_iterable* elemAt(Numeric element) = 0;

};


/**
* Sequential forward iterator
*/
template <typename Payload,
        template <typename, typename... >class _Iterable ,
         typename... Args>
class sequential_forward_iterator {

 typedef _Iterable<Payload,Args...> Iterable;

public:
  typedef Iterable iterable_value_type;
  typedef Iterable* iterable_pointer;
  typedef Iterable& iterable_reference;

  typedef Payload payload_value_type;
  typedef Payload* payload_pointer;
  typedef Payload& payload_reference;

  inline sequential_forward_iterator() : m_i(nullptr) {}
  inline sequential_forward_iterator(iterable_pointer n) : m_i(n) {}
  inline sequential_forward_iterator(const sequential_forward_iterator &o) : m_i(o.m_i) {}

//operators
inline sequential_forward_iterator &operator=(const sequential_forward_iterator &o) { m_i = o.m_i; return *this; }
inline iterable_pointer operator->(){ return m_i;}
inline payload_pointer operator&(){ return m_i->pointer();}
inline payload_reference operator*(){ return m_i->value();}

inline bool operator==(const sequential_forward_iterator &o) const { return m_i == o.m_i; }
inline bool operator!=(const sequential_forward_iterator &o) const { return m_i != o.m_i; }

//pre-increment operator (return a reference)
inline sequential_forward_iterator &operator++() { m_i = m_i->next(); return *this; }
//post-increment operator (return a value)

inline sequential_forward_iterator operator++(int) { sequential_forward_iterator n = *this; m_i = m_i->next(); return n; }


protected:

iterable_pointer m_i;


};


template <typename Payload,
        template<typename, typename...> class _Iterable,
         typename... Args>
class forward_iterator : public sequential_forward_iterator<Payload, _Iterable, Args...> {

    typedef _Iterable<Payload,Args...> Iterable;

   public:
     typedef Iterable iterable_value_type;
     typedef Iterable* iterable_pointer;
     typedef Iterable& iterable_reference;

     typedef Payload payload_value_type;
     typedef Payload* payload_pointer;
     typedef Payload& payload_reference;


public:
  inline forward_iterator() {}
  inline forward_iterator(iterable_pointer n) : sequential_forward_iterator<Payload,_Iterable,Args...>(n) {}
  inline forward_iterator(const forward_iterator &o) : sequential_forward_iterator<Payload,_Iterable,Args...>(o) {}

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


template <typename Payload, template<typename, typename...> class _Iterable, typename... Args>
class backward_iterator : public forward_iterator<Payload, _Iterable, Args...> {

typedef _Iterable<Payload,Args...> Iterable;

    typedef Iterable iterable_value_type;
    typedef Iterable* iterable_pointer;
    typedef Iterable& iterable_reference;

    typedef Payload payload_value_type;
    typedef Payload* payload_pointer;
    typedef Payload& payload_reference;

  inline backward_iterator() {}
  inline backward_iterator(iterable_pointer n) : forward_iterator<Payload, _Iterable, Args...>(n) {}
  inline backward_iterator(const backward_iterator &o) : forward_iterator<Payload, _Iterable, Args...>(o) {}

  //pre-decrement operator (return a reference to the current object) ->returns a reference
  inline backward_iterator &operator--() { this->m_i = this->m_i->previous(); return *this; }
  //pre-decrement operator (return a copy of the current iterator and increments the original)->returns a value
  inline backward_iterator operator--(int) { backward_iterator n = *this; this->m_i = this->m_i->previous() ; return n; }

  template<class N = int>
  inline backward_iterator operator+(N j) const
  {
    if( j > 0){
      return this->forward_iterator<Payload, _Iterable, Args...>::operator+(j);

    }else{ // j<=0
     backward_iterator *i = this;
        while (j++)
          i--;

    return i;
    }
  }
};



template <typename Payload, template<typename, typename...> class _Iterable, typename... Args>
class random_access_iterator : public backward_iterator<Payload, _Iterable, Args...> {

    typedef _Iterable<Payload,Args...> Iterable;

    typedef Iterable iterable_value_type;
    typedef Iterable* iterable_pointer;
    typedef Iterable& iterable_reference;

    typedef Payload payload_value_type;
    typedef Payload* payload_pointer;
    typedef Payload& payload_reference;


  inline random_access_iterator() {}
  inline random_access_iterator(iterable_pointer n) : backward_iterator<Payload, _Iterable, Args...>(n) {}
  inline random_access_iterator(const random_access_iterator &o) : backward_iterator<Payload, _Iterable, Args...>(o) {}

template <typename D = uint>
inline payload_value_type operator[](D offset){
    random_access_iterator i = *this;
    i.m_i = i.m_i->elemAt(offset);
    return *i;
}

};

}

#endif /* ITERATOR_H_ */
