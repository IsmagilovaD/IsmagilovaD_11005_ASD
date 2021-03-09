#include <iostream>
using namespace std;

struct Node
{
	int item;
	Node* next = 0;
	Node* previous = 0;
};

struct DoublyLinkedList
{
	Node* pHead = 0;
	Node* pEnd = 0;

	void Add(int item)
	{
		Node* node = new Node;
		node->item = item;

		if (!pHead)
		{
			pHead = node;
			pEnd = pHead;
		}
		else
		{
			pEnd->next = node;
			node->previous = pEnd;
			pEnd = node;
		}
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

	int get(int id)
	{
		if (!pHead)
			return 0;
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

	void insertAt(int item, int id) {

		Node* node = new Node;
		node->item = item;

		if (!pHead) {
			if (id != 0) {
				cout << "id is not correct";
				throw 1;
			}
			else { pHead = node; pEnd = pHead; }
		}
		else
		{
			int i = 0;
			Node* temp = pHead;
			if (id == 0) { pHead->previous = node; pHead = node; pHead->next = temp; }
			else {
				while (i != id)
				{
					if (temp->next)
					{
						temp = temp->next;
						i++;
					}
					else
					{
						if (temp == pEnd)
						{
							pEnd->next = node;
							node->previous = pEnd;
							pEnd = node;
							return;
						} 
						else
						{
							cout << "id is not correct";
							return;
						}
					}
				}
				temp->previous->next = node;
				node->next = temp;
				node->previous = temp->previous;
				temp->previous = node;
			}
		}
	}

	void removeAt(int id)
	{
		if (!pHead) { cout << "List is empty"; throw 1; }
		else
		{
			if (id == 0) { pHead = pHead->next; delete pHead->previous; pHead->previous = NULL; }
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
					(temp->previous)->next = temp->next;
					(temp->next)->previous = temp->previous;
					delete temp;
				}
				else
				{
					temp = temp->previous;
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
	DoublyLinkedList* list = new DoublyLinkedList;

	list->Add(100);
	list->Add(20);
	list->Add(3000);
	list->Add(5);
	list->insertAt(4000,3);

	cout << "------------- size is " << list->size() << endl;
	list->PrintAll();
	cout << endl;
	
	list->insertAt(0, 0);
	cout << "-------------" <<  endl;
	list->PrintAll();
	cout << endl;

	list->insertAt(6, 6);
	cout << "-------------" << endl;
	list->PrintAll();
	cout << endl;
	
	list->removeAt(0);
	cout << "------------- " << endl;
	list->PrintAll();
	cout << endl;

	list->removeAt(4);
	cout << "------------- " << endl;
	list->PrintAll();
	cout << endl;

	list->removeAt(4);
	cout << "------------- " << endl;
	list->PrintAll();
	cout << endl;

	list->removeAt(11);
	cout << "-------------" << endl;
	list->PrintAll();
	
	delete list;
	return 0;
}