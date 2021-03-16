#include <iostream>
using namespace std;

struct Node
{
	int item;
	Node* next = 0;
	Node* prev = 0;
};

struct SortedList
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
			if (id == 0) { pHead = pHead->next; delete pHead->prev; pHead->prev = NULL; }
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
};

int main()
{
	SortedList* list = new SortedList;

	list->add(1);
	list->add(20);
	list->add(0);
	list->add(4);
	list->add(3);
	list->add(30);
	list->add(1);


	list->PrintAll();

	cout << endl << list->get(0) << ' ' << list->get(5) << endl;

	list->remove(0);
	list->remove(4);

	cout << endl;
	list->PrintAll();

	return 0;
}