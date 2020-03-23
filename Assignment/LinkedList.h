#ifndef _LINKEDLIST
#define _LINKEDLIST

#include "Node.h"
#include <iostream>
#include <Bits.h>

using namespace std;
template <typename T>
class LinkedList
{
private:
	Node<T> * Head;
public:


	LinkedList()
	{
		Head = nullptr;
	}

	~LinkedList()
	{
		DeleteAll();
	}

	void PrintList()	const
	{
		Node<T> *p = Head;
		while (p)
		{
			cout << p->getItem() << " ";
			p = p->getNext();
		}

	}

	void Insertend(const T &data)
	{
		Node<T> *R = new Node<T>(data);
		Node<T> *temp = Head;
		if (!Head)
		{
			Head = R;
			return;
		}
		while (temp->getNext())
			temp = temp->getNext();
		temp->setNext(R);
	}
	
	void DeleteAll()
	{
		Node<T> *P = Head;
		while (Head)
		{
			P = Head->getNext();
			delete Head;
			Head = P;
		}
	}

	void CompressEquals()
	{
		Node<T> *prev = Head;
		Node<T>*temp = new Node<T>;
		Node<T> *curr = Head ? Head->getNext() : Head;
		while (curr)
		{
			temp->setItem(prev->getItem()) ;
			while (curr && temp->getItem() == curr->getItem() && prev != curr)
			{
				prev->setItem(prev->getItem() + curr->getItem());
				prev->setNext(curr->getNext());
				curr = curr->getNext();
			}
			prev = curr;
			curr = curr?curr->getNext():curr;
		}
	}
	void RemoveEquals()
	{
		bool l = false;
		Node<T> *prev = Head;
		Node<T> *temp = Head;
		Node<T> *curr = Head ? Head->getNext() : Head;
		if (curr != Head)
		{
			while (curr && prev->getItem() == curr->getItem())
			{
				if (prev->getItem() == curr->getItem())
				{
					l = true;
					prev->setNext(curr->getNext());
					delete curr;
					curr = NULL;
					if(prev->getNext())
						curr = prev->getNext();
				}
			}
			if (l)
			{
				Head = curr;
				delete prev;
				prev = curr;
				curr = curr ? curr->getNext() : curr;
			}
			while (curr)
			{
				if (prev->getItem() == curr->getItem())
				{
					while (prev->getItem() == curr->getItem())
					{
						prev->setNext(curr->getNext());
						delete curr;
						curr = prev->getNext();
					}
					delete prev;
					prev = curr;
					curr = curr->getNext();
					temp->setNext(prev);
					continue;
				}
				temp = prev;
				prev = curr;
				curr = curr->getNext();
			}
		}
		
	}
	void CompletesTen()
	{
		Node<T> *prev = Head;
		Node<T> *curr = Head ? Head->getNext() : Head;
		while (curr)
		{
			if (prev->getItem() < 10)
			{
				Node<T>* newNode = new Node<T>;
				newNode->setItem(10 - prev->getItem());
				prev->setNext(newNode);
				newNode->setNext(curr);
			}
			prev = curr;
			curr = curr->getNext();
		}

		if (prev->getItem() < 10)
		{
			Node<T>* newNode = new Node<T>;
			newNode->setItem(10 - prev->getItem());
			prev->setNext(newNode);
			newNode->setNext(curr);
		}

	}
	void RemoveEvensAfterOdds()
	{
		Node<T> *prev = Head;
		Node<T> *curr = Head ? Head->getNext() : Head;

		while (curr)
		{

			while (((prev->getItem()) & 1) == 1 && ((curr->getItem()) & 1) == 0)
			{
				prev->setNext(curr->getNext());
				delete curr;
				curr = prev->getNext();
				if (!curr)
					return;
			}
			prev = curr;
			curr = curr->getNext();

		}
	}
	

};

#endif	
