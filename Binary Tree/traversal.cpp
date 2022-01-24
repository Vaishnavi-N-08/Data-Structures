//preorder = Root ->left -> right
//postorder = left - >right->root
//inorder = left -> root ->right
#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
   }

};

void preOrder(Node* node){

        if(node==NULL){
            return;
        }
         cout<<node->data<<" ";
         preOrder(node->left);
         preOrder(node->right);
}

void postOrder(Node* node){

        if(node==NULL){
            return;
        }
         
         postOrder(node->left);
         postOrder(node->right);
         cout<<node->data<<" ";
         
}

void inorder(Node* node)
{
     if(node==NULL){
            return;
        }
         
         inorder(node->left);
         cout<<node->data<<" ";
         inorder(node->right);
        
}

int main(){
   
       //create tree
       Node* root = new Node(1);
       root->left = new Node(2);
       root->right = new Node(3);
       root->left->left = new Node(4);
       root->left->right = new Node(5);
       root->right->left = new Node(6);
       root->right->right = new Node(7);

       cout<<"Preoredr Traversal : ";
       preOrder(root); 
       cout<<endl;
       cout<<"Postoredr Traversal : ";
       postOrder(root);
       cout<<endl;
       cout<<"inorder Traversal : ";
       inorder(root);

}

