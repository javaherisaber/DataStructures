#include <iostream>
 
using namespace std;

struct stacknode
{
	stacknode *next;
	int data;
};

class  stacklink
{
public:
	stacklink();
	void add(int x);
	int remove();
	int top();
	bool isempty();
private:
	stacknode *head;
};
