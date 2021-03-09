#include <iostream>
using namespace std;

struct Node
{
	int item = 0;
	Node* next = 0;
	Node* previous = 0;
};

struct Queue
{
	Node* pHead = 0;
	Node* pEnd = 0;

	void  enqueue(int item)
	{
		Node* node = new Node;
		node->item = item;
		node->next = pHead;
		if (pHead) { pHead->previous = node;}
		pHead = node;
		if (!pEnd) { pEnd = pHead; }
	}

	int dequeue()
	{
		if (!pEnd)
		{
			cout << "Queue is empty";
			return 0;
		}
		else
		{
			Node* temp = pEnd;
			int x = temp->item;
			pEnd = temp->previous;
			delete temp;
			return x;
		}
	}
};

int main()
{
	Queue* queue = new Queue;

	queue->enqueue(1);
	queue->enqueue(20);
	queue->enqueue(30);
	queue->enqueue(402);
	queue->enqueue(5);

	cout << queue->dequeue() << endl;
	cout << queue->dequeue() << endl;
	cout << queue->dequeue() << endl;
	cout << queue->dequeue() << endl;
	cout << queue->dequeue() << endl;
	cout << queue->dequeue();
	
	return 0;
}