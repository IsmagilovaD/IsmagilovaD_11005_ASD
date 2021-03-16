#include <iostream>
using namespace std;

struct Node
{
	int item = NULL;
	Node* next = 0;
	Node* prev = 0;
};

struct UnicSortedList
{
	Node* pHead = 0;
	Node* pEnd = 0;

	void add(int item)
	{
		Node* node = new Node;
		node->item = item;

		if (!pHead) { pHead = node; pEnd = pHead; }
		else
		{
			Node* temp = pHead;
			while (node->item > temp->item)
			{
				if (temp->next)
					temp = temp->next;
				else
				{
					temp->next = node;
					node->prev = temp;
					pEnd = node;
					return;
				}
			}
			if (node->item == temp->item) { return; }
			else {
				if (temp->prev)
				{
					(temp->prev)->next = node;
					node->prev = temp->prev;
					temp->prev = node;
					node->next = temp;
				}
				else
				{
					pHead->prev = node;
					node->next = pHead;
					pHead = node;
				}
			}
		}
	}

	int get(int id)
	{
		if (!pHead)
		{
			cout << "List is empty" << endl;
			return 0;
		}
		else
		{
			Node* temp = pHead;
			int i = 0;
			while (i != id)
			{
				if (temp->next)
				{
					temp = temp->next;
					i++;
				}
				else
				{
					cout << "id is not correct" << endl;
					return 0;
				}
			}
			return temp->item;
		}

	}

	void remove(int id)
	{
		if (!pHead) { cout << "List is empty"; throw 1; }
		else
		{
			if (id == 0) { if (pHead->next) { pHead = pHead->next; } delete pHead->prev; pHead->prev = NULL; }
			else
			{
				Node* temp = pHead;
				int i = 0;
				while (i != id)
				{
					if (temp->next)
					{
						temp = temp->next;
						i++;
					}
					else { cout << "id is not correct"; return; }
				}
				if (temp->next) {
					(temp->prev)->next = temp->next;
					(temp->next)->prev = temp->prev;
					delete temp;
				}
				else
				{
					temp = temp->prev;
					pEnd = temp;
					delete temp->next;
					pEnd->next = NULL;
				}

			}
		}
	}

	void PrintAll()
	{
		if (!pHead)
			throw 1;

		Node* temp = pHead;
		while (temp)
		{
			cout << temp->item << ' ';
			temp = temp->next;
		}
		cout << endl;
	}

	int size()
	{
		if (!pHead)
			return 0;
		else
		{
			int k = 0;
			Node* temp = pHead;
			while (temp->next)
			{
				temp = temp->next;
				k++;
			}

			return k + 1;
		}
	}
};


UnicSortedList* Union(UnicSortedList* a, UnicSortedList* b)
{
	UnicSortedList* list = new UnicSortedList;
	Node* temp = a->pHead;
	while (temp)
	{
		list->add(temp->item);
		temp = temp->next;
	}
	temp = b->pHead;
	while (temp)
	{
		list->add(temp->item);
		temp = temp->next;
	}
	return list;
}

UnicSortedList* Intersect(UnicSortedList* a, UnicSortedList* b)
{
	UnicSortedList* list = new UnicSortedList;

	Node* tempA = a->pHead;
	Node* tempB = b->pHead;

	while (tempA)
	{
		while (tempB)
		{
			if (tempA->item == tempB->item)
			{
				list->add(tempA->item);
			}
			tempB = tempB->next;
		}
		tempA = tempA->next;
		tempB = b->pHead;
	}
	return list;
}

UnicSortedList* Difference(UnicSortedList* a, UnicSortedList* b)
{
	UnicSortedList* list = new UnicSortedList;
	Node* tempA = a->pHead;
	

	b = Intersect(a, b);
	Node* tempB = b->pHead;

	int i = 0;

			while (tempA) {
					if (tempA->item == tempB->item)
					{
						if (tempA->next) {
							tempA = tempA->next;
						}
						else tempA = NULL;
						a->remove(i);
						b->remove(0);
						tempB = b->pHead;
					}
					else {
						if (tempB->next)
						{
							tempB = tempB->next;
						}
						else
						{
							tempA = tempA->next;
							tempB = b->pHead;
							i++;
						}
					}
			}
	list = a;
	return list;
}

int main()
{
	UnicSortedList* list = new UnicSortedList;

	list->add(1);
	list->add(20);
	list->add(0);
	list->add(0); 
	list->add(0);
	list->add(0);
	list->add(4);
	list->add(3);
	list->add(20);
	list->add(30);
	list->add(1);

	list->PrintAll();

	cout << endl << list->get(0) << ' ' << list->get(5) << endl;

	list->remove(0);
	list->remove(4);

	cout << endl;
	list->PrintAll();



	cout << "------------------------------------------------";
	//EX 3
	
	UnicSortedList* a = new UnicSortedList;
	a->add(5);
	a->add(3);
	a->add(1);
	a->add(4);
	a->add(6);
	cout << endl << "list a" << endl;
	a->PrintAll();

	UnicSortedList* b = new UnicSortedList;
	b->add(2);
	b->add(3);
	b->add(8);
	b->add(4);
	b->add(6);
	cout << endl << "list b" << endl;
	b->PrintAll();

	UnicSortedList* list1 = Union(a, b);
	cout << endl << "United list" << endl;
	list1->PrintAll();

	list1 = Intersect(a, b);
	cout << endl << "Intersected list" << endl;
	list1->PrintAll();

	list1 = Difference(a, b);
	cout << endl << "Differenced list" << endl;
	list1->PrintAll();
}