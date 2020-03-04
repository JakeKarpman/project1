#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct  Node{
    int data;
    Node* left;
    Node* right;
    Node* parent;
};
Node *newNode(int val){
    Node *temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp ->right = NULL;
    temp->parent=NULL;
    return temp;
}



Node* insertRec(Node* node, int val){
    if(node == NULL){
        return newNode(val);
    }
    if(val<node->data){
        Node *leftc = insertRec(node->left,val);
        node->left= leftc;
        leftc->parent= node;

    }
    else if(val>node->data){
        Node *rightc = insertRec(node->right,val);
        node->right = rightc;
        rightc->parent=node;

    }

    return node;
}
void print(Node*node){
    if(node!=NULL){
        print(node->left);
        cout<<node->data<<" ";
        print(node->right);
    }

}

void sort(vector<int> lst,int len){

    Node *bst = NULL;
    bst = insertRec(bst, lst[0]);
    for(int i=1;i<len;i++){
        insertRec(bst,lst[i]);
    }
   print(bst);

}
int main() {
    vector<int> lst;
    int size;
    int num;
    cout<<"Enter size of list:";
    cin>>size;
    for(int i=0;i<size;i++){
        cout<<"Enter number "<<i+1<<" :";
        cin>>num;
        lst.push_back(num);
    }



    sort(lst,size);





    return 0;
}
