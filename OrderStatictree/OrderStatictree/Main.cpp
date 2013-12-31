#include "Dualsearchtree.h"
#include <iostream>
using namespace std;

void main()
{
	DualTree *tmp = new DualTree();
	Node *rs = new Node();
	bool flag = true,result=false;
	int choice,data;
	while (flag)
	{
		cout << "\t\t\t\tmenu\n\n\n";
		cout << "1-insert\n2-delete\n3-search\n4-Trace\n5-K_index\n6-X_Order\n\n\n";
		cout << "make your choice :";
		cin >> choice;
		switch (choice)
		{
		case 1 :
			cout << "insert your number :";
			cin >> data;
			result = tmp->Add(data);
			if (result == false)
			{
				cout << "\n\n\nOops!\nyour number is exist in tree";
			}
			else
				cout << "\n\n\nCongratulation !\nyour number has been added successfully";
			break;
		case 2 :
			cout << "insert your number :";
			cin >> data;
			result = tmp->Remove(data);
			if (result == true)
			{
				cout << "\n\n\nCongratulation !\nyour number has been removed successfully";
			}
			else
				cout << "\n\n\nOops!\nyour number isnt exist in tree";
			break;
		case 3 :
			cout << "insert your number :";
			cin >> data;
		    rs = tmp->Search(tmp->root, data);
			if (rs != NULL)
			{
				cout << "\n\n\nCongratulation !\nyour number has been FOUND successfully"<<"\n\n this is your number : "<<rs->data<<" <"<<rs->size<<">\n";
			}
			else
				cout << "\n\n\nOops!\nyour number isnt exist in tree";
			break;
		case 4 :
			cout << "\nyour tree is this :" ;
			tmp->Trace(tmp->root);
			break;
		case 5 :
			cout << "\ninsert your K :";
			cin >> data;
			choice = tmp->K_index(tmp->root,data);
			if (choice!=NULL)
				cout << "your "<<data<<"-th index is : " << choice<<endl;
			else
				cout << "\nyour number is larger than our size!\n";
			cout << endl;
			break;
		case 6 :
			cout << "\ninsert your number (xrate) :";
			cin >> data;
			int rst = tmp->X_rate(tmp->root, data);
			if (rst != 0)
				cout << "your number is bigger than " << rst << " Node!";
			else
				cout << "Oops !";
			break;
		}
		cout << "\npress Enter to continue";
		cin.get();
		cin.get();
		cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	}
	cin.get();
}