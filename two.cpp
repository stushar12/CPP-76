#include<bits/stdc++.h>
using namespace std;

struct Node 
{
	int data; 
	Node* left;
	Node* right;
};

Node* GetNewNode(int data) 
{
	Node* newNode = new Node();
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}

Node* Insert(Node* root,int data) 
{
	if(root == NULL)                                      // empty tree
    {                                           
		root = GetNewNode(data);
	}
	
	else if(data <= root->data)                         // if data to be inserted start lesser, insert inorder left subtree. 
    {
		root->left = Insert(root->left,data);
	}
	
	else                                                // else, insert inorder right subtree. 
    {
		root->right = Insert(root->right,data);
	}
	return root;
}

Node* inorder_and_preorder(int inorder[],int preorder[],int start,int end,int &preorder_index)
{
    if(start>end)
    {
        return NULL;
    }
    Node* root = GetNewNode(preorder[preorder_index++]);
    int index;
    for(int i=start;i<=end;i++)
    {
        if(inorder[i]==root->data)
        {
         index=i;
        break;
        }
    }
    root->left=inorder_and_preorder(inorder,preorder,start,index-1,preorder_index);
    root->right=inorder_and_preorder(inorder,preorder,index+1,end,preorder_index);
return root;
}

Node* buildTree(int inorder[],int preorder[], int n)
{
    int preorder_index=0;
    int start=0;
	int end=n-1;
	Node *root1=inorder_and_preorder(inorder,preorder,start,end,preorder_index);
	return root1;
}
