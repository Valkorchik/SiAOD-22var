#include <iostream>
struct Node
{
	int data;
	Node* next;
};
Node* insert(short data, Node*& l);
void fill(Node*& l);
void print(Node*& l);
void list_change(Node*& l);
int main()
{
	Node* l = nullptr;
	std::cout << "Enter a list node (0 - end):\n";
	fill(l);
	std::cout << "Source list:\n";
	print(l);
	list_change(l);
}
Node* insert(short data, Node*& l)
{
	return new Node{ data,l };
}
void fill(Node*& l)
{
	short fill;
	while (true)
	{
		std::cin >> fill;
		if (fill == 0)
			return;
		l = insert(fill, l);
	}
}
void print(Node*& l)
{
	Node* temp = l;
	while (l)
	{
		std::cout << l->data << "\t";
		l = l->next;
	}
	std::cout << std::endl;
	l = temp;
}
void list_change(Node*& l)
{
	Node* temp = l;
	if (l)
	{
		if (l->data < 0)
		{
			std::cout << l->data << " ";
			list_change(l->next);
		}
		else
		{
			list_change(l->next);
			std::cout << l->data << " ";
		}
	}
	l = temp;
}