#include <iostream>
using namespace std;

struct Node
{
	int item;
	Node* next = 0;
};

struct LinkedList
{
	Node* root = 0;

	void Add(int item) 
	{
		Node* node = new Node;
		node->item = item;
		
		if (!root)
			root = node;
		else
		{
			Node* temp = root;
			while (temp->next)
			{
				temp = temp->next;
			}
			temp->next = node;
		}
	}

	int size()
	{
		if (!root)
			return 0;
		else
		{
			int k = 0;
			Node* temp = root;
			while (temp->next)
			{
				temp = temp->next;
				k++;
			}

			return k+1;
		}
	}

	int get(int id)
	{
		if (!root)
			return 0;
		else
		{
			Node* temp = root;
			int i = 1;
			while (i != id)
			{
				if (temp->next)
				{
					temp = temp->next;
					i++;
				}
				else
				{
					cout << "id is not correct";
						return 0;
				}
			}
			return temp->item;
		}
	}

	void PrintAll()
	{
		if (!root)
			throw 1;

		Node* temp = root;
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
	LinkedList* list = new LinkedList;

	list->Add(100);
	list->Add(20);
	list->Add(3000);
	list->Add(4);

	cout << list->get(3) << endl << list->size() << endl;

	list->PrintAll();

	delete list;

	return 0;
}