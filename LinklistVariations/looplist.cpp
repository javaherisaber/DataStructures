#include "looplist.h"
using namespace std;

looplist::looplist()
{
	end = NULL;
	head = NULL;
}

void looplist::add(int x)
{
	loopnode *tmp = new loopnode();
	loopnode *headtmp = new loopnode();
	headtmp = head;
	tmp->data = x;
	if (!isempty())
	{
		cout << "Do you want to add in first(y/n)?";
		char d;
		cin >> d;
		if (d == 'y')
		{
			tmp->next = head;
			head = tmp;
			end->next = head;
			return;
		}
		else
		{
			while (headtmp != end->next)
			{
				cout << endl << headtmp->data << "y/n? \n";
				char s;
				cin >> s;
				if (s == 'y')
				{
					if (headtmp == end)
					{
						end->next = tmp;
						tmp->next = head;
						end = tmp;
						end->next = head;
						return;
					}
					else
					{
						tmp->next = headtmp->next;
						headtmp->next = tmp;
						return;
					}
				}
				headtmp = headtmp->next;
			}
		}

	}
	else
	{
		head = tmp;
		end = tmp;
		end->next = head;
	}
}


int looplist::remove(){
	loopnode *headtmp = new loopnode();
	loopnode *headPre = new loopnode();
	headtmp = head;
	if (!isempty())
	{
		cout << "Do you want to remove from first(y/n)?";
		char d;
		cin >> d;
		if (d == 'y')
		{
			int data = head->data;
			head = head->next;
			end->next = head;
			return data;
		}
		else
		{
			while (headtmp != end->next)
			{
				if (headtmp->next == end)
				{
					headPre = headtmp;
				}
				cout << endl << headtmp->data << "y/n? \n";
				char s;
				cin >> s;
				if (s == 'y')
				{
					if (headtmp == end)
					{
						int data = headtmp->data;
						headPre->next = head;
						end = headPre;
						end->next = head;
						return data;
					}
					else
					{
						int data = headtmp->data;
						headtmp = headtmp->next;
						return data;
					}
				}
				headtmp = headtmp->next;
			}
		}

	}
}

bool looplist::isempty()
{
	if (head == NULL)
		return true;
	return false;
}

void looplist::trace(loopnode *tmp)
{
	if (tmp == end)
	{
		cout << tmp->data;
		return;
	}
	cout << tmp->data;
	trace(tmp->next);	
}