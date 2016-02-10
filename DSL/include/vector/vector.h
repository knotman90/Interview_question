/*
 * vector.h
 *
 *  Created on: 7 Feb 2016
 *  Author: Davide Spataro
 */

#ifndef VECTOR_H_
#define VECTOR_H_

namespace DSL {

//pointer wrapper
template<typename T, typename D = uint>
class cell : public random_iterable<T, D>{
public:
cell<T,D>(): m_ptr(nullptr){};

cell<T,D>(T* ptr) : m_ptr(ptr){}
~cell<T,D>(){
        deallocate_ptr();
};
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

inline void deallocate_ptr(){
        delete m_ptr;
        m_ptr = nullptr;
}
inline void allocate_ptr(D size){
        m_ptr = new T[size];
        if(!m_ptr) {
                std::cerr<<"Unable to allocate memory\n";
                exit(-1);
        }
}
private:
T* m_ptr;
};



template<typename T, typename C = int, template <typename, typename> class _Iterable = cell,
         template <typename,
                   template<typename, typename ...> class _It, typename ... Args> class _Iterator = backward_iterator
         >
class vector {
const C DEFAULT_SIZE = 1;

public:
typedef _Iterator<T, _Iterable> Iterator;

typedef T* payload_pointer;
typedef T* payload_reference;

typedef cell<T,C> pointer_iterable;

constexpr vector() : vector(DEFAULT_SIZE){}

vector(const C size) {
        allocate(size);
}
vector(const C size, const T &val) {
        allocate(size);
}
vector(vector &v) {
        allocate(v.size);

}
~vector() {
        //cell destructor called automatically
}

Iterator begin(){
        return nullptr;
}


private:
 pointer_iterable m_ptr;
uint m_increment;
uint size;

void allocate(const C size){
        m_ptr.deallocate_ptr();
        m_ptr.allocate_ptr(size);
}
void initialize(const T& val){
        for(uint i=0; i<size; i++)
                m_ptr[i] = val;
}

}; //class vector


} //namespace DSL

#endif /* VECTOR */
