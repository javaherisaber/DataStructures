#include "doubleloop.h"
using namespace std;

doubleloop::doubleloop()
{
	head = NULL;
	end = NULL;
}

void doubleloop::add(int x)
{
	node *headtmp = new node();//��� ����� �� ���� ������ �� ���� ������
	headtmp = head;
	node *tmp = new node();
	tmp->data = x;
	if (!isempty()){
		cout << "Do you want to add in first(y/n)?";
		char s;
		cin >> s;
		if (s == 'y')//�� ��� ���� ��� ���� �� ��� ���� ����� �����
		{
			tmp->next = head;
			head->pre = tmp;
			head = tmp;
			end->next = head;
			head->pre = end;
			return;
		}
		else
		{
			do
			{
				cout << headtmp->data << "y/n?";
				cin >> s;
				if (s == 'y'&&headtmp->next != head)//�� ����� �� ��� ���� ��� �� ��� ��� �����
				{
					tmp->next = headtmp->next;
					tmp->pre = headtmp;
					headtmp->next->pre = tmp;
					headtmp->next = tmp;
					return;
				}
				if (s == 'y'&&headtmp->next == head)//�� ����� �� ��� ���� ��� �� ����� ��� ��� �����
				{
					tmp->pre = end;
					end->next = tmp;
					tmp->next = head;
					head->pre = tmp;
					end = tmp;
					return;
				}				 
				headtmp = headtmp->next;
			} while (headtmp != head);
		}
	}
	else//�� ����� �� ���� ���� ���
	{
		head = tmp;
		end = tmp;
	}
}

int doubleloop::remove()
{
	node *headtmp = new node();
	headtmp = head;
	if (!isempty()){
		cout << "Do you want to remove from first(y/n)?";
		char s;
		cin >> s;
		if (s == 'y')
		{
			int data = head->data;
			head = head->next;
			head->pre = end;
			end->next = head;
			return data;
		}
		else
		{
			do
			{
				cout << endl << headtmp->data << "y/n?";
				cin >> s;
				if (s == 'y'&&headtmp->next != head)
				{
					int data = headtmp->data;
					headtmp->pre->next = headtmp->next;
					headtmp->next->pre = headtmp->pre;
					return data;
				}
				if (s == 'y'&&headtmp->next == head)
				{
					int data = headtmp->data;
					headtmp->pre->next = head;
					head->pre = headtmp->pre;
					end = head->pre;
					return data;
				}
				headtmp = headtmp->next;
			} while (headtmp != head);
		}
	}
	else
		return false;
}

void doubleloop::trace()
{
	node *temp = head;
	do
	{
		cout << temp->data << endl;
		temp = temp->next;
	} while (temp != head);
}

bool doubleloop::isempty()
{
	if (head != NULL)
		return false;
	return true;
}
