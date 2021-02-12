#include <iostream>
#include <string>
#define STACK_MAX_SIZE 100000
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
		throw StackEmptyException("EMPTY");
	return arr[idx - 1];
}

template <typename Object>
Object Stack<Object>::pop()
{
	if (idx == 0)
		throw StackEmptyException("NO");
	return arr[--idx];
}
template <typename Object>
void Stack<Object>::push(const Object& obj)
{
	if (idx == STACK_MAX_SIZE)
		throw StackFullException("FULL");
	arr[idx++] = obj;
}

int main()
{
	Stack<char> st;
	int n;
	string str;
	unsigned int total = 0;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		while (!st.isEmpty())
		{
			st.pop();
		}
		cin >> str;
		try
		{
			for (int j = 0; j < str.length(); j++)
			{
				if (str[j] == '(')
					st.push(str[j]);
				else
					st.pop();
			}
			if (st.isEmpty())
				cout << "YES" << endl;
			else
			{
				cout << "NO" << endl;
			}
		}
		catch (RuntimeException& expn)
		{
			cout << expn << endl;
		}
	}
}
