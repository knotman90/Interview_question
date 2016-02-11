/*
 * vector.h
 *
 *  Created on: 7 Feb 2016
 *  Author: Davide Spataro
 */

#ifndef VECTOR_H_
#define VECTOR_H_

#include<assert.h>
namespace DSL {

//pointer wrapper
template<typename T, typename D = uint>
class cell : public random_iterable<T, D> {
public:
cell<T,D>(): m_ptr(nullptr){};

cell<T,D>(T* ptr) : m_ptr(ptr){}
~cell<T,D>(){};
virtual  forward_iterable<T> *next(){
        ++m_ptr;
        return static_cast<forward_iterable<T>*>(this);
};
virtual  T& value() {return *m_ptr;};

inline backward_iterable<T>* previous(){
        --m_ptr;
        return this;
};
inline cell<T,D> *elemAt(D offset){
        m_ptr +=offset;
        return this;
}

virtual inline T* pointer() { return m_ptr; }

private:
T* m_ptr;
};



template<typename T, typename C = int, template <typename, typename> class _Iterable = cell,
         template <typename,
                   template<typename, typename ...> class _It, typename ... Args> class _Iterator = random_access_iterator
         >
class vector {
static const C DEFAULT_SIZE = 1;
static const short DEFAULT_RESIZE_FACTOR  = 2;
public:
typedef _Iterator<T, _Iterable> Iterator;

typedef T* payload_pointer;
typedef T* payload_reference;

typedef cell<T,C> pointer_iterable;

constexpr vector() : vector(DEFAULT_SIZE){}

vector(const C _capacity) :m_ptr(nullptr),m_size(0), m_capacity(_capacity){
        allocate(m_capacity);

}
vector(const C _capacity, const T &val) : vector(_capacity) {
        initialize(val);
}
vector(vector &v) {
        //allocate(v.size());


}
~vector() {
        deallocate();
}

Iterator begin(){
        return nullptr;
}


inline C size() const{
    return m_size;
}

inline C capacity() const{
    return m_capacity;
}

inline  T& front()const {
    return elemAt[0];
}

inline  T& back() const {
    return elemAt[m_size];
}

inline T& elemAt(const uint& pos) const{
    DSL_ASSERT(pos >=0);
    return m_ptr[pos];
}

void push_back(const T &val){
    if(m_size+1 > m_capacity){
        resize(m_capacity * DEFAULT_RESIZE_FACTOR);
        m_capacity = m_capacity * DEFAULT_RESIZE_FACTOR;
    }
    m_ptr[m_size] = val;
    ++m_size;
}

void pop_back(){
    if(m_size <=0)
        return;

    m_ptr[m_size].~T();
    --m_size;
    if(m_size < m_capacity/2){
        uint newsize = 1 + m_capacity / DEFAULT_RESIZE_FACTOR;
        resize(newsize);
        m_capacity = newsize;
    }

}


private:
 pointer_iterable m_iterable;

payload_pointer m_ptr;
C m_increment;
C m_capacity;
C m_size;

void deallocate(){
    delete[] m_ptr;
}
void allocate(const C size){
    if(m_ptr != nullptr)
        deallocate();

        m_ptr = new T[size];
}
void initialize(const T& val){
        #pragma unroll
        for(uint i=0; i<size; i++)
                m_ptr[i] = val;
}

void resize(const uint& newsize){
    DSL_ASSERT(newsize > 0);
    payload_pointer tmp_p = new T[newsize];
    for(uint i=0;i<m_size;i++){
        tmp_p[i] = m_ptr[i];
    }
    delete[] m_ptr;
    m_ptr = tmp_p;
}

}; //class vector


} //namespace DSL

#endif /* VECTOR */
