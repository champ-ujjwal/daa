// NAME: UJJWAL KUMAR
// ROLL: B200062CS
// PROGRAM 1: UGLY NUMBER

//  Ugly numbers are positive numbers whose prime factors only include 2, 3, 5.
// Note that 1 is typically treated as an ugly number. As example, 10th ugly number
// is 12, because first 10 ugly numbers are 1, 2, 3, 4, 5, 6, 8, 9, 10, 12. Write a
// program to find the n-th ugly number. In this program, input is the n as positive
// integer.

#include<bits/stdc++.h>
using namespace std ;

class Node {
    public:
    long long val;
    Node *left, *right;
};
Node *uglynumber=NULL ;
Node *root=NULL;
Node* createNewNode(long long v)
{
    Node *nod= new Node();
    nod->val= v;
    nod->left= NULL ;
    nod->right= NULL ;
    return nod;
}

void insert(long long v)
{
    // Node *root= (*rot);
    Node *nod= createNewNode(v);
    if(root==NULL)
    {
        root= nod;
    }
    else
    {
        Node *tem= root;
        while (tem->right&&tem->right->val<v)
        {
            tem=tem->right;
        }
        if (tem->right==NULL||tem->right->val!=v)
        {
            Node *t= tem->right ;
            nod->left=tem;
            tem->right=nod;
            nod->right=t; 
        }
    }

}
void InsertAtBegin(int v)
{
    // Node *root= (*rot);
    if (!uglynumber)
    {
        uglynumber= createNewNode(v);
    }
    else
    {
        Node *t= createNewNode(v);
        uglynumber->left= t;
        t->right= uglynumber;
        uglynumber= t;
    }
    // cout<<"inserted at begin \n";
}
Node* pop()
{
    if (!root)
    {
        //  cout<<"popped NULL\n";
        return NULL;
    }
    
    if(!root->right)
    {
        //  cout<<"popped rt null\n";
        Node *tem= root;
        root= NULL;
        return tem;
    }
    else
    {
        //  cout<<"popped\n";
        Node *nod= root;
        root->right->left=NULL;
        root=root->right;
        return nod;
    }
}
// void printList()
// {
//     Node *tm= root;
//     cout<<"List  : ";
//     while (tm)
//     {
//         cout<<tm->val<<"  ";
//         tm= tm->right;
//     }
// }
long long NthUglyNumber(long long n)
{
    long long t= 1,x=1;
    insert(1);
    while (t<=n)
    {
        x= pop()->val;
        InsertAtBegin(x);
        insert(x*2);
        insert(x*3);
        insert(x*5);
        t++;
    }
    return uglynumber->val;
}
int main()
{
    long long n;
    cout<<"which ugly number you want: ";
    cin>>n;
    cout<<n<<"th ugly Number= "<<NthUglyNumber(n)<<"\n";
}