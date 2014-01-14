#include <iostream>
#include <string>
using namespace std;

struct Queuenode
{
	Queuenode *next;
	int data;
};
class Queuelink
{
private:
	Queuenode *head, *end;
public:
	Queuelink();
	void add(int x);
	int remove();
	bool isempty();
	int front();
};