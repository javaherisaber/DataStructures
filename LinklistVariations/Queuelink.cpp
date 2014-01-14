#include "QueueLink.h"
using namespace std;

Queuelink::Queuelink()
{
	head = NULL;
	end = NULL;
}
void Queuelink::add(int x)
{
	Queuenode *tmp = new Queuenode();
	tmp->data = x;
	if (head != NULL)
	{
		end->next = tmp;
		end = tmp;
	}
	else
	{
		head = tmp;
		end = tmp;
	}
}
bool Queuelink::isempty()
{
	if (head == NULL)
	{
		return true;
	}
	return false;
}

int  Queuelink::remove()
{
	if (!isempty())
	{
		int data;
		data = head->data;
		head = head->next;
		return data;
	}
	return false;
}

int Queuelink::front()
{
	if (!isempty())
		return head->data;
	return false;
}