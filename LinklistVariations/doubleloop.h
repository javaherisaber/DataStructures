#include <iostream>
#include <string>
using namespace std;

struct node{
	node *next, *pre;
	int data;
};
class doubleloop{
private :
	node *head, *end;
public :
	doubleloop();
	void add(int x);
	int remove();
	void trace();
	bool isempty();
};