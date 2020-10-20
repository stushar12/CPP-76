Node* abc(int in[],int pre[],int is,int ie,int &preIndex)
{
    if(is>ie)
    {
        return NULL;
    }
    Node *root=new Node(pre[preIndex++]);
    int index;
    for(int i=is;i<=ie;i++)
    {
        if(in[i]==root->data)
        {
         index=i;
        break;
        }
    }
    root->left=abc(in,pre,is,index-1,preIndex);
    root->right=abc(in,pre,index+1,ie,preIndex);
return root;
}
Node* buildTree(int in[],int pre[], int n)
{
    int preIndex=0;
    int is=0;int ie=n-1;
Node *root1=abc(in,pre,is,ie,preIndex);
return root1;
}