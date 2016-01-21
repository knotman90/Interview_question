/*
 * SingleLinkedList.h
 *
 *  Created on: 18 gen 2016
 *      Author: knotman
 */

#ifndef SINGLELINKEDLIST_H_
#define SINGLELINKEDLIST_H_

#include <list>
namespace DSL{

template<class T>
class SingleLinkedList {


public:
	SingleLinkedList();
	virtual ~SingleLinkedList();

	bool isEmpty() const;
	int size() const;

	bool operator==(const SingleLinkedList<T> &l) const;
	inline bool operator!=(const SingleLinkedList<T> &l)const
		{
		return !(*this==l);
		}

	void clear();

	void append(const T&);
	void prepend(const T&);
	T takeFirst();
	T takeLast();
	int removeAll(const T &t);
	bool removeOne(const T &t);
	bool contains(const T &t) const;

	int count(const T &t) const;
};


}

#endif /* SINGLELINKEDLIST_H_ */
