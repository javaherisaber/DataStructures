#include <iostream>
#include <string>
using namespace std;

struct loopnode
{
	loopnode *next;
	int data;
};
class looplist
{
public:
	looplist();
	void add(int x);
	int remove();
	void trace(loopnode *tmp);
	bool isempty();
private:
	loopnode *head, *end;
};
