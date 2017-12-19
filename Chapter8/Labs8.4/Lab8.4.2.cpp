#include "iostream"
#include "string"

using namespace std;

struct Node
{
	int data;
	Node* left;
	Node* right;
};
class BinaryTree
{
protected:


	Node* root;
	Node* Add(int value, Node* node)
	{
		if (node == NULL)
		{
			node = new Node;
			node->data = value;
			node->left = node->right = NULL;
		}
		else if (value < node->data)
			node->left = Add(value, node->left);
		else if (value > node->data)
			node->right = Add(value, node->right);
		return node;
	}
	virtual void Print(Node* t) { }
	virtual void FindByIndex(Node* t, int &index, int &value) { }
public:
	BinaryTree()
	{
		root = NULL;
	}

	
	void Insert(int x)
	{
		root = Add(x, root);
	}
	void PrintTree()
	{
		Print(root);
	}
	int operator[] (int index)
	{
		if (index < 1)
			throw string("index out of range");
		int value;
		FindByIndex(root, index, value);
		return value;
	}
};

class InorderTree : public BinaryTree
{
	void Print(Node* t)
	{
		if (t == NULL)
			return;
		Print(t->left);
		cout << t->data << " ";
		Print(t->right);
	}

	void FindByIndex(Node* t, int& index, int& value)
	{
		if (t == NULL)
			return;
		FindByIndex(t->left, index, value);
		if (index == 1)
			value = t->data;
		index--;
		FindByIndex(t->right, index, value);
	}
};

class PostorderTree : public BinaryTree
{
	void Print(Node* t)
	{
		if (t == NULL)
			return;
		Print(t->left);
		Print(t->right);
		cout << t->data << " ";
	}
	void FindByIndex(Node* t, int& index, int& value)
	{
		if (t == NULL)
			return;
		FindByIndex(t->left, index, value);

		FindByIndex(t->right, index, value);
		if (index == 1)
			value = t->data;
		index--;
	}
};

class PreorderTree : public BinaryTree
{
	void Print(Node* t)
	{
		if (t == NULL)
			return;
		cout << t->data << " ";
		Print(t->left);
		Print(t->right);
	}
	void FindByIndex(Node* t, int& index, int& value)
	{
		if (t == NULL)
			return;
		if (index == 1)
			value = t->data;
		index--;
		FindByIndex(t->left, index, value);

		FindByIndex(t->right, index, value);
	}
};

ostream& operator<< (ostream &strm, InorderTree t) {
	t.PrintTree();
	return strm;
}

ostream& operator<< (ostream &strm, PostorderTree t) {
	t.PrintTree();
	return strm;
}

ostream& operator<< (ostream &strm, PreorderTree t) {
	t.PrintTree();
	return strm;
}

int main()
{
	int n;
	cout << "Enter how many items should be pushed onto the tree: ";
	cin >> n;
	InorderTree it;
	PostorderTree pot;
	PreorderTree prt;
	int j;
	for (int i = 0; i < n; i++)
	{
		cin >> j;
		it.Insert(j);
		pot.Insert(j);
		prt.Insert(j);
	}
	cout << "Inorder: " << it<<endl;
	cout << "Postorder: " << pot<< endl;
	cout << "Preorder: " << prt<< endl;
	cout << "Enter number of item: ";
	cin >> j;
	try {
		cout << "Inorder: " << it[j] << endl;
		cout << "Postorder: " << pot[j] << endl;
		cout << "Preorder: " << prt[j] << endl;
	}
	catch (string s)
	{
		cout << "exeption: " << s << endl;
	}
	return 0;
}
