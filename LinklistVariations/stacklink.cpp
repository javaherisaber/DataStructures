#include "Stacklink.h"

using namespace std;

stacklink::stacklink()
{
	head = NULL;
}
void  stacklink::add(int x)
{
	stacknode *tmp = new stacknode();
	tmp->data = x;
	if (!isempty())
	{
		tmp->next = head;
		head = tmp;
	}
	else
	{
		head = tmp;
	}

}
bool stacklink::isempty()
{
	if (head == NULL)
		return true;
	return false;
}
int stacklink::remove()
{
	if (!isempty())
	{
		int data = head->data;
		head = head->next;
		return data;
	}
	return false;
}
int stacklink::top()
{
	if (!isempty())
	{
		return head->data;
	}
	return false;
}