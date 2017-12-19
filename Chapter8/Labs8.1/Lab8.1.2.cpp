#include <string>
#include <iostream>

using namespace std;


class Stack {
private:
	int *stack;
	int size;
	int current;
public:
	Stack(int size) {
		if (size <= 0)
			throw string("size must be >= 0");
		try {
			stack = new int[size];
		}
		catch (bad_alloc ba) {
			throw string("stack_bad_alloc");
		}
		size = size;
		current = 0;
	}
	~Stack(void) {
		delete stack;
	}
	void push(int value) {
		if (current == size)
			throw string("stack size exceeded");
		stack[current++] = value;
	}
	int pop(void) {
		if (current == 0)
			throw string("stack is empty");
		return stack[--current];
	}
	int top(void) {
		if (current == 0)
			throw string("stack is empty");
		return stack[current];
	}
	Stack& operator<< (int v) throw(string) {
		push(v);
		return *this;
	}
	Stack& operator>>(int &v) throw(string) {
		v = pop();
		return *this;
	}
};

int main(void) {
	int n;

	cout << "Enter how many items should be pushed onto the stack: ";
	cin >> n;
	try {
		Stack stk(n);


		int j;
		try
		{
			for (int i = 0; i < n; i++)
			{
				cin >> j;
				stk << j;
			}
		}
		catch (string e)
		{
			cout << "Exeption: " << e;
		}

		cout << "Enter how many items should be printed: ";
		cin >> n;
		try
		{
			for (int i = 0; i < n; i++)
			{
				stk >> j;
				cout << j << endl;
			}
		}
		catch (string e)
		{
			cout << "Exeption: " << e;
		}
	}
	catch (string e)
	{
		cout << "Exeption: " << e;
	}


	return 0;
}

