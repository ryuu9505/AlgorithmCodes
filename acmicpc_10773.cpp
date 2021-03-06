#include <iostream>
#include <string>
#define STACK_MAX_SIZE 100001
using namespace std;

class RuntimeException
{
private:
	string errorMsg;
public:
	RuntimeException(const string& err)
	{
		errorMsg = err;
	}
	string getMessage() const
	{
		return errorMsg;
	}
};

inline std::ostream& operator<<(std::ostream& out, const RuntimeException& e)
{
	return out << e.getMessage();
}

class StackEmptyException : public RuntimeException
{
public:
	StackEmptyException(const string& err) : RuntimeException(err) {}
};

class StackFullException : public RuntimeException
{
public:
	StackFullException(const string& err) : RuntimeException(err) {}
};

template <typename Object>
class Stack
{
private:
	int idx;
	Object arr[STACK_MAX_SIZE];
public:
	Stack()
	{
		idx = 0;		
	}
	int size() const;
	bool isEmpty() const;
	const Object& top();
	void push(const Object& obj);
	Object pop();
};


template <typename Object>
int Stack<Object>::size() const
{
	return idx;
}

template <typename Object>
bool Stack<Object>::isEmpty() const
{
	return !(idx);
}

template <typename Object>
const Object& Stack<Object>::top()
{
	if (idx == 0)
		throw StackEmptyException("-1");
	return arr[idx - 1];
}

template <typename Object>
Object Stack<Object>::pop()
{
	if (idx == 0)
		throw StackEmptyException("-1");
	return arr[--idx];
}
template <typename Object>
void Stack<Object>::push(const Object& obj)
{
	if (idx == STACK_MAX_SIZE - 1)
		throw StackFullException("FULL");
	arr[idx++] = obj;
}

int main()
{
	Stack<int> st;
	int n, num;
	unsigned int total = 0;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> num;
		try
		{
			if (num != 0)
			{
				st.push(num);
			}
			else
			{
				st.pop();
			}
		}
		catch (RuntimeException& expn)
		{
			cout << expn << endl;
		}
	}

	while (!st.isEmpty())
	{
		total += st.pop();
	}

	cout << total;
}
