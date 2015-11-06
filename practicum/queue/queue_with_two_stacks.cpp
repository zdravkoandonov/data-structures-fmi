#include <iostream>
#include <stack>

using namespace std;

class myqueue
{
public:
	stack<int> a, b;
	void push(int n)
	{
		a.push(n);
	}
	int top()
	{
		if (b.empty())
			transfer();
		return b.top();
	}
	void pop()
	{
		if (b.empty())
			transfer();
		b.pop();
	}
	bool empty()
	{
		return a.empty() && b.empty();
	}

private:
	void transfer()
	{
		while (!a.empty())
		{
			b.push(a.top());
			a.pop();
		}
	}
};

int main()
{
	myqueue q;
	q.push(5);
	q.push(6);
	q.push(6);
	q.pop();
	q.push(7);
	q.push(8);
	q.pop();
	q.pop();
	q.pop();
	
	cout << q.top() << endl;
	return 0;
}