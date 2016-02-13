/*
 * SingleLinkedList.h
 *
 *  Created on: 04 gen 2016
 *      Author: knotman
 */

#ifndef DOUBLELINKEDLIST_H_
#define DOUBLELINKEDLIST_H_
#include <list/SingleLinkedList.h>
namespace DSL{
/**
   Node Class
 */
template<typename T>
class backward_node : public node<T> {


public:



explicit backward_node(const T& v) : DSL::node<T>(v), m_previous(nullptr) {
}

~backward_node(){
};

virtual backward_node<T>* previous() {return nullptr;}



 backward_node<T>* m_previous;

};


/*! \brief Singly Linked List implementation.
 *         The second template parameter is used as type of the  Lists's size.
 *
 */
template<typename T, typename C = int, template <typename... ArgsNode> class NODE = backward_node,
            template <typename ,
                    template<typename, typename...> class _Iterable, typename... Args> class _Iterator = backward_iterator
     >
class DoubleLinkedList : public SingleLinkedList<T,C,backward_node,backward_iterator>{



};

} //namespace DSL

#endif /* DOUBLELINKEDLIST_H_ */
