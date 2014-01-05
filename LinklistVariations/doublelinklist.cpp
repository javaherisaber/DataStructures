#include "doublellinklist.h"
using namespace std;

doublelinklist::doublelinklist()//”«“‰œÂ Ì ò·«”
{
	head = NULL;
}
bool doublelinklist::isempty()
{
	if (head == NULL)
		return true;
	return false;
}
void doublelinklist::add(int x)
{
	doublelinknode *headtmp = new doublelinknode();//«Ì‰ «‘«—Â ê— »—«Ì ÅÌ„«Ì‘ ò· ·Ì”  „Ì»«‘œ
	headtmp = head;
	doublelinknode *tmp = new doublelinknode();
	tmp->data = x; 
	if (!isempty()){
		cout << "Do you want to add in first(y/n)?";
		char s;
		cin >> s;
		if (s == 'y')//œ— «Ì‰ Õ«·  ê—Â ÃœÌœ »Â «Ê· ·Ì”  «÷«›Â „Ì‘Êœ
		{
			tmp->next = head;
			head->pre = tmp;
			head = tmp;
			return;
		}
		else
		{
			while (headtmp != NULL)
			{
				cout << headtmp->data << "y/n?";
				cin >> s;
				if (s == 'y'&&headtmp->next!=NULL)//œ— Õ«· Ì òÂ ê—Â ÃœÌœ »Ì‰ œÊ ê—Â Ê’· „Ì‘Êœ
				{
					tmp->next = headtmp->next;
					tmp->pre = headtmp;
					headtmp->next->pre = tmp;
					headtmp->next = tmp;
					return;
				}
				if (s == 'y'&&headtmp->next == NULL)//œ— Õ«· Ì òÂ ê—Â ÃœÌœ »⁄œ «“ ¬Œ—Ì‰ ê—Â œ—Ã „Ì‘Êœ
				{
					headtmp->next = tmp;
					tmp->pre = headtmp;
					return;
				}			 
				headtmp = headtmp->next;
			}
		}
	}
	else//œ— Õ«· Ì òÂ ·Ì”  Œ«·Ì «” 
	{
		head = tmp;
	}
}
int doublelinklist::remove()
{
	doublelinknode *headtmp = new doublelinknode();
	headtmp = head;
	if (!isempty()){
		cout << "Do you want to remove from first(y/n)?";
		char s;
		cin >> s;
		if (s == 'y')
		{
			int data = head->data;
			head = head->next;
			head->pre = NULL;
			return data;
		}
		else
		{
			while (headtmp != NULL)
			{
				cout << endl << headtmp->data << "y/n?";
				cin >> s;
				if (s == 'y'&&headtmp->next != NULL)
				{
					int data = headtmp->data;
					headtmp->pre->next = headtmp->next;
					headtmp->next->pre = headtmp->pre;
					return data;
				}
				if (s == 'y'&&headtmp->next == NULL)
				{
					int data = headtmp->data;
					headtmp->pre->next = NULL;
					return data;
				}			 
				headtmp = headtmp->next;
			}
			return 0;
		}
	}
	else
		return false;
}
void doublelinklist::trace()
{
	doublelinknode *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << endl;
		temp = temp->next;
	}
}