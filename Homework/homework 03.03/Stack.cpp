#include <iostream>
using namespace std;

struct Node
{
	int item;
	Node* next;
};

struct Stack
{
	Node* pHead = 0;

	void Push(int item)
	{
		Node* node = new Node;
		node->item = item;
		node->next = pHead;
		pHead = node;
	}

	int Pop()
	{
		if (!pHead)
			throw 1;

		Node* temp = pHead;
		int x = temp->item;
		pHead = temp->next;
		delete temp;
		return x;
	}

	int Peek()
	{
		if (!pHead)
			throw 1;

		return pHead->item;
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
	Stack* stack = new Stack;

	stack->Push(10);
	stack->Push(20);
	stack->Push(30);

	stack->PrintAll();

	cout << stack->Pop() << endl;
	cout << stack->Peek() << endl;

	delete stack;

	return 0;
}