#include <iostream>
using namespace std;
struct Stack
{
	char data;
	Stack* next;
};

Stack* create()
{
	Stack* stack = new Stack();
	stack = nullptr;
	return stack;
}

void push(Stack*& stack, char n)
{
	stack = new Stack{ n, stack };
}

void pop(Stack*& stack)
{
	if (stack != nullptr)
	{
		Stack* temp = stack;
		stack = stack->next;
		delete temp;
	}

}

char top(Stack*& stack)
{
	return stack->data;
}

bool empty(Stack* stack)
{
	if (stack == nullptr)
	{
		return true;
	}
	return false;
}

bool OperatorCheck(char c)
{
	return (!isalpha(c) && !isdigit(c));
}

int Priority(char oper)
{
	if (oper == '-' || oper == '+')
		return 1;
	else if (oper == '*' || oper == '/')
		return 2;
	else if (oper == '^')
		return 3;
	return 0;
}

string InfixToPostfix(string infix)
{
	infix = '(' + infix + ')';
	int l = infix.size();
	string output;
	Stack* stack = create();
	for (int i = 0; i < l; i++)
	{
		if (isalpha(infix[i]) || isdigit(infix[i]))
			output += infix[i];
		else if (infix[i] == '(')
			push(stack, '(');
		else if (infix[i] == ')')
		{
			while (top(stack) != '(')
			{
				output += top(stack);
				pop(stack);
			}
			pop(stack);
		}
		else
		{
			if (OperatorCheck(top(stack)))
			{
				if (infix[i] == '^')
				{
					while (Priority(infix[i]) <= Priority(top(stack)))
					{
						output += top(stack);
						pop(stack);
					}
				}
				else
				{
					while (Priority(infix[i]) < Priority(top(stack)))
					{
						output += top(stack);
						pop(stack);
					}
				}
				push(stack, infix[i]);
			}
		}
	}
	while (!empty(stack))
	{
		output += top(stack);
		pop(stack);
	}
	return output;
}

string infixToPrefix(string infix)
{
	int l = infix.size();
	reverse(infix.begin(), infix.end());
	for (int i = 0; i < l; i++)
	{
		if (infix[i] == '(')
		{
			infix[i] = ')';
			i++;
		}
		else if (infix[i] == ')')
		{
			infix[i] = '(';
			i++;
		}
	}
	string prefix = InfixToPostfix(infix);
	reverse(prefix.begin(), prefix.end());
	return prefix;
}
int main()
{
	string s;
	cin>>s;
	cout << infixToPrefix(s) << std::endl;
	return 0;
}