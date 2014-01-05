#include <iostream>
#include <string>
using namespace std;

struct doublelinknode{
	doublelinknode *next, *pre;
	int data;
};
class doublelinklist
{
public:
	doublelinklist();
	void add(int x);
	int remove();
	void trace();
	bool isempty();
private:
	doublelinknode *head;
};
