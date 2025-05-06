#include<iostream>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
using namespace std;
 
class node
{
	public:
		int data;
		int bal;
		node *left;	
		node *right;
 
};
 
class Tree
{
public:
	node *insert(node *,node *); 
	node *rotateRight(node *);
	node *rotateLeft(node *);
	void disp(node *,int);  
};
 
void Tree::disp(node* root,int k)
{
	int i;
	if(root)
	{
		disp(root->right, k+1);
		cout<<endl;
		for(i = 0; i< k; i++)
			cout<<' ';
		cout<<root->data;
		disp(root->left, k+1);
	}
}
 
node *Tree::insert(node *root,node *s)
{
	if(s->data > root->data)
	{
		if(root->right == NULL)
			root->right = s;
		else
			root->right = insert(root->right, s);
	}
 
	if(s->data <= root->data)
	{
		if(root->left == NULL)
			root->left = s;
		else
			root->left = insert(root->left,s);
	}
 
	if(root->left==NULL && root->right!=NULL)
		root->bal = -1;
	else if(root->left!=NULL && root->right==NULL)
		root->bal = 1;
	else
		root->bal = 0;
 
	if(root->bal == 1 && root->left->bal == 1)
	       root = rotateRight(root);
 
	if(root->bal == -1 && root->right->bal == -1)
		root = rotateLeft(root);
 
	if(root->bal == 1 && root->left->bal == -1)
	{
		root->left = rotateRight(root->left);
		root = rotateRight(root);
	}
 
	if(root->bal == -1 && root->right->bal == 1)
	{
		root->right = rotateLeft(root->right);
		root = rotateRight(root);
	}
	return root;
 
}
 
node *Tree :: rotateRight(node *root)
{
	node *temp;
	temp = root->left;
	root->left = temp->right;
	temp->right = root;
	return temp;
}
 
node *Tree :: rotateLeft(node *root)
{
	node *temp;
	temp = root->right;
	root->right = temp->left;
	temp->left = root;
	return temp;
}
 
int main()
{
	int ch,c;
	char temp;
	node *root,*s;
	Tree t;
 
	root = new node;	
	root = NULL;	

	do{
		s=new node;	
		s->bal = 0;
		s->left=NULL;	
		s->right=NULL;	
 
		cout<<"\n"<<"Enter node of tree::";
		cin>>s->data;
 
		if(root == NULL)
			root = s;
		else
			root = t.insert(root, s);
 
		cout<<"\n\n Tree is :\n\n";
		t.disp(root, 1);
		cout<<"\n";
		cout<<"\n"<<"WANT TO ENTER MORE ELEMENTS(y/n)::";
		cin>>temp;
 
	}while(temp=='y');
 
	cout<<endl;
}

