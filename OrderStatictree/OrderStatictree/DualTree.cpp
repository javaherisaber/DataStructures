#include "Dualsearchtree.h"
#include <stack>
using namespace std;
DualTree::DualTree()
{
	root = NULL;
}

static stack<Node*> me;//this stack keep nodes parent to change their size after add and remove

void DualTree::sizechanger(int select)
{
	if (select == 1)
	{
		while (!me.empty())
		{
			
			me.top()->size++;
			me.pop();
		}
	}
	else
	{
		while (!me.empty())
		{
			me.top()->size--;
			me.pop();
		}
	}

}

bool DualTree::Add(int data)
{
	Node *temp = new Node();
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	temp->size = 1;
	if (root == NULL)
	{
		root = temp;
		return true;
	}
	else
	{
		bool flag = true;
		Node *tmp = root;
		while (flag)
		{
			if (tmp->data == data)
				return false;
			if (data < tmp->data)
			{
				me.push(tmp);
				if (tmp->left == NULL)
				{
					tmp->left = temp;
					sizechanger(1);
					return true;
				}
				else
				{
					tmp = tmp->left;
					continue;
				}
			}
			if (tmp->data < data)
			{
				me.push(tmp);
				if (tmp->right == NULL)
				{
					tmp->right = temp;
					sizechanger(1);
					return true;
				}
				else
				{
					tmp = tmp->right;
					continue;
				}
			}
		}
	}
}

Node* DualTree::Search(Node *r,int data)
{
	if (r == NULL)
		return NULL;
    if (r->data == data)
		return r;
	else if (data < r->data)
		Search(r->left, data);
	else if (data > r->data)
		Search(r->right, data);
}

Node* DualTree::rsearch(Node *r, int data)
{
	if (r == NULL)
	{
		for (int i = 0; me.empty() != true; i++)
		{
			me.pop();
		}
		return NULL;
	}
	if (r->data == data)
		return r;
	else if (data < r->data)
	{
		me.push(r);
		rsearch(r->left, data);
	}
	else if(data > r->data)
	{
		me.push(r);
		rsearch(r->right, data);
	}
}

bool DualTree::Remove(int data)
{
	Node *temp = rsearch(root, data);
	if (temp == NULL)
		return false;
	else 
	{
		if (temp->left != NULL&&temp->right != NULL)//this node has 2 children
		{
			me.push(temp);
			Node *temp2 = temp->right;
			while (temp2->left != NULL)
			{
				me.push(temp2);
				temp2 = temp2->left;
			}
			temp->data = temp2->data;
			Noderemover(temp2);
			return true;
		}
		else
		{
			Noderemover(temp);
			return true;
		}
	}
}

void DualTree::Noderemover(Node *r)
{
	if (r->left == NULL&&r->right == NULL)//this node is Leaf
	{
		if (r == root)
		{
			root = NULL;
		}
		else
		{
			if (me.top()->left != NULL)
			{
				if (me.top()->left->data == r->data)
					me.top()->left = NULL;
			}
			if (me.top()->right != NULL)
			{
				if (me.top()->right->data == r->data)
					me.top()->right = NULL;
			}
			sizechanger(2);
		}
	}
	if ((r->left == NULL&&r->right != NULL) || (r->left != NULL&&r->right == NULL))//this node has 1 child
	{
		if (root == r)
		{
			if (r->left == NULL)
			{
				root = r->right;
			}
			else
			{
				root = r->left;
			}
		}
		else
		{
			if (r->left == NULL)
			{
				if (me.top()->left != NULL)
				{
					if (me.top()->left->data == r->data)
						me.top()->left = r->right;
				}
				if (me.top()->right != NULL)
				{
					if (me.top()->right->data == r->data)
						me.top()->right = r->right;
				}
			}
			else
			{
				if (me.top()->left != NULL)
				{
					if (me.top()->left->data == r->data)
						me.top()->left = r->left;
				}
				if (me.top()->right != NULL)
				{
					if (me.top()->right->data == r->data)
						me.top()->right = r->left;
				}				
			}
			sizechanger(2);
		}	
	}
}

void DualTree::Trace(Node *r)
{
	if (r == NULL)
		return;
	Trace(r->left);
	cout << r->data<<"<"<<r->size<<"> _";
	Trace(r->right);
}

int DualTree::K_index(Node *r,int k)
{
	static Node *p;
	if (k > root->size)
		return NULL;
	if (k == 0)
		return p->data;
	if (r != NULL)
	{
		if (r->size >= k)
		{
			p = r;
			if (r->left != NULL)
				return K_index(r->left, k);
			else
				return K_index(r->right, k - 1);
		}
		else
		{
			if (p == NULL)
				return NULL;
			k -= r->size;
			return K_index(p->right, k - 1);
		}
	}
	return NULL;
}

int DualTree::X_rate(Node *r,int x)
{
	while (r!=NULL)
	{
		if (r->data <= x)
		{
			if (r->data == x)
			{
				if (r->left != NULL)
					return r->left->size + 1;
				else
					return 1;
			}
			else
			{
				if (r->left != NULL)
					return r->left->size + 1 + X_rate(r->right, x);
				else
					return X_rate(r->right, x) + 1;
			}

		}
		else
			r = r->left;
	}
	return 0;
}
