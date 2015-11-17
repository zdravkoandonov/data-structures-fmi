#include <iostream>
#include <list>

class IPrioritizedNamed
{
public:
	virtual int getPriority() = 0;
	virtual const char* getName() = 0;
};

class Customer : public IPrioritizedNamed
{
protected:
	int priority;
public:
	Customer()
	{
		priority = 1;
	}
	int getPriority()
	{
		return priority;
	}
	const char* getName()
	{
		return "Customer";
	}
};

class Boss : public Customer
{
public:
	Boss()
	{
		priority = 100;
	}
	const char* getName()
	{
		return "Boss";
	}
};

class BossFriend : public Customer
{
public:
	BossFriend()
	{
		priority = 10;
	}
	const char* getName()
	{
		return "BossFriend";
	}
};

class PriorityQueue
{
	std::list<IPrioritizedNamed*> items;

public:
	PriorityQueue()
	{
	}

	void push(IPrioritizedNamed* item)
	{
		int currentPriority = (*item).getPriority();
		std::list<IPrioritizedNamed*>::iterator pos;
		pos = items.begin();
		while ((pos != items.end()) && (*pos)->getPriority() > currentPriority)
		{
			pos++;
		}
		items.insert(pos, item);
	}

	IPrioritizedNamed* pop()
	{
		IPrioritizedNamed* top = items.front();
		items.pop_front();
		return top;
	}

	void print()
	{
		std::list<IPrioritizedNamed*> itemsCopy(items);
		while (!itemsCopy.empty())
		{
			std::cout << (*(itemsCopy.front())).getName() << "\n";
			itemsCopy.pop_front();
		}
	}
};

int main()
{
	PriorityQueue customers;
	Boss boss;
	BossFriend bossFriend;
	Customer customer;
	customers.push(&boss1);
	customers.push(&customer1);
	customers.push(&customer2);
	customers.push(&boss2);
	customers.push(&boss3);
	customers.push(&bossFriend1);
	customers.print();

	return 0;
}