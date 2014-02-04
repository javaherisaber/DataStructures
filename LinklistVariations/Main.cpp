#include <iostream>
#include "QueueLink.h"
#include "Stacklink.h"
using namespace std;

void main()
{
	stacklink *tmp = new stacklink();
	bool flag = true;
	while (flag)
	{
		cout << "1-add\n2-remove\n3-top\n4-isempty\nchoose: \n";
		int c;
		cin >> c;
		int num;
		switch (c)
		{
		case 1:
			cout << "\nGive me number : ";
			cin >> num;
			tmp->add(num);
			break;
		case 2 :	
			num = tmp->remove();
			cout << endl << num << endl;
			break;
		case 3 :
			num = tmp->top();
			cout << endl << num<<endl;
			break;
		case 4:
			cout <<endl<< tmp->isempty()<<endl;
			break;
		}
	}

	cin.get();
}