#include <iostream>
#include <string>
#include <stack>
using namespace std;

struct Node
{
	int data,size;
	Node *left, *right;
};

class DualTree
{
public:
	Node *root;
	DualTree();
	bool Add(int data);// true for completed and false for not completed
	bool Remove(int data);// true for completed and false for not completed
	Node* Search(Node *r,int data);//NULL for not found
	void Trace(Node *root);
	int K_index(Node *r,int k);//NULL for which is not in size of tree
	int X_rate(Node *r,int x);
private:
	void sizechanger(int select);// 1 for add parents sizes and 2 for reduce parents sizes
	Node* rsearch(Node*r, int data);
	void Noderemover(Node *r);
};