#include <iostream>
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

void print(Node*node){
    if(node!=NULL){
        print(node->left);
        cout<<node->data<<" ";
        print(node->right);
    }

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

Node* deleteRec(Node* node, int val){
    if(node == NULL)
        return node;
    if(node->data>val){
        node->left = deleteRec(node->left,val);
    }
    else if(node->data<val){
        node->right=deleteRec(node->right,val);
    }
    else{
        if(node->left == NULL){
            Node *temp = node->right;
            node=NULL;
            return temp;
        }
        else if(node->right==NULL){
            Node *temp = node->left;
            node=NULL;
            return temp;
        }
        Node* curr = node->right;
        while(curr && curr->left!=NULL){
            curr = curr->left;
        }
        node ->data = curr->data;

        node->right=deleteRec(node->right,curr->data);
    }
    return node;
}

void findNextRec(Node* node,int val) {

    if (node->data > val) {
        findNextRec(node->left, val);

        }
    else if (node->data < val) {
        findNextRec(node->right, val);
    }

    if (node->data == val) {
       //cout<<"here1"<<endl;
        if (node->right != NULL) {
            node = node->right;
            //cout << "here 2" << endl;
            if (node->left != NULL) {
                while (node->left != NULL) {

                    node = node->left;
                    //cout << "made it to one" << endl;
                }
            }
            cout << "The next value is: " << node->data << endl;
        }
        else {
            while(node->parent != NULL ) {
                if(node->parent->data < val)
                    node=node->parent;
                else{
                    node=node->parent;
                    //cout<<"thsfhdlkfadjfkasd"<<endl;
                    break;
                }
                //cout<<"new node: "<<node->data<<endl;
            }
            if(node->data < val){
                cout<<val<<" is the highest value"<<endl;
            }
            else {
                cout << "The next value is: " << node->data << endl;
            }
        }
    }
}

void findPrevRec(Node * node, int val ){
    //if (node == NULL)
        //return 0;
    if (node->data > val) {
        findPrevRec(node->left, val);

    }
    else if (node->data < val) {
        findPrevRec(node->right, val);
    }
    if(node->data==val) {
        //cout << "here1" << endl;
        if (node->left != NULL) {
            node = node->left;
            //cout << "here 2" << endl;
            if (node->right != NULL) {
                while (node->right != NULL) {

                    node = node->right;
                    //cout << "made it to one" << endl;
                }

            }
            cout << "The prev is: " << node->data << endl;
        }
        else if (node->right != NULL) {

        }
        else {
            while(node->parent != NULL ) {
                if(node->parent->data > val)
                    node=node->parent;
                else{
                   node=node->parent;
                   break;
                }
                //cout<<"new node: "<<node->data<<endl;
            }
            if(val>node->data)
                cout << "The prev is: " << node->data << endl;
            else
                cout<<val<<" has no prev "<<endl;


        }

    }
}

void findMinRec(Node * node){
    if(node->left !=NULL)
        findMinRec(node->left);
    else
        cout<<" The smallest value is: "<<node->data<<endl;
}
void findMaxRec(Node * node){
    if(node->right != NULL)
        findMaxRec(node->right);
    else
        cout<<"The largest value is: "<<node->data<<endl;

}



Node* insertIter(Node * node, int val){
    Node* newn = newNode(val);
    Node* t = NULL;
    while(node!=NULL){
        t=node;
        if(val>node->data)

            node=node->right;
        else
            node=node->left;

    }

    if(t==NULL)
        t=newn;
    else if(val>t->data)
        t->right=newn;

    else
        t->left=newn;
    t->parent=newn->parent;

    return t;


}
Node* deleteIter(Node * node, int val){
    while(node!=NULL) {
        if (val < node->data) {
            cout << "here1" << endl;
            node = node->left;
        }
        else if(val>node->data){
            cout <<"here2"<<endl;
             node = node->right;
        }
        else{
            if(node->left == NULL) {
                if (node->right != NULL)
                    node = node->right;
            }
            else{
                Node* temp = node;
                node=node->left;
                while(node->right!=NULL)
                    node=node->right;
                temp=node;
                node=NULL;
            }
        }
    }
    cout<<node->data<<" here"<<endl;
    return node;
}
void findNextIter(Node* node, int val) {
    while (node != NULL) {
        if (val < node->data)
            node = node->left;
        else if (val > node->data)
            node = node->right;
        if (node->data == val) {
            if (node->right != NULL) {
                node = node->right;
                if (node->left != NULL) {
                    while (node->left != NULL)
                        node = node->left;
                }
                cout << "The next value is: " << node->data << endl;
                break;
            }
            else {
                while (node->parent != NULL) {
                    if (node->parent->data < val)
                        node = node->parent;
                    else {
                        node = node->parent;
                        break;
                    }
                }
                if (node->data < val) {
                    cout << val << " is the highest value" << endl;
                    break;
                }
                else {
                    cout << "The next value is: " << node->data << endl;
                    break;
                }
            }


        }

    }
}

void findPrevIter(Node* node, int val){
    while(node !=NULL){
        if(val< node->data)
          node=node->left;
        else if(val>node->data)
            node=node->right;
        if(node->data==val) {
            if (node->left != NULL) {
                node = node->left;
                if (node->right != NULL) {
                    while (node->right != NULL) {
                        node = node->right;
                    }
                }
                cout << "The prev is: " << node->data << endl;
                break;
            }
            else if (node->right != NULL) {

            }
            else {
                while(node->parent != NULL ) {
                    if(node->parent->data > val)
                        node=node->parent;
                    else{
                        node=node->parent;
                        break;
                    }
                }
                if(val>node->data)
                    cout << "The prev is: " << node->data << endl;
                else
                    cout<<val<<" has no prev "<<endl;
                break;

            }

        }

    }
}

void findMinIter(Node* node){
    while(node->left !=NULL){
        node=node->left;
    }
    cout<<"The smallest value is "<<node->data<<endl;
}
void findMaxIter(Node* node){
    while(node->right !=NULL){
        node=node->right;
    }
    cout<<"The largest value is "<<node->data<<endl;
}


int main() {


    int value=0;
    int count =0;
    Node *bst = NULL;
    bst = insertRec(bst, 50);
    insertRec(bst,70);
    insertRec(bst,30);
    insertRec(bst,60);
    insertRec(bst,80);
    insertRec(bst,40);
    insertRec(bst,45);
    insertRec(bst,39);
    insertRec(bst,20);
    insertRec(bst,22);
    insertRec(bst,1);






   /* cout<<"Enter values to make BST (enter 999 stop):";
    cin>>value;
    while(value != 999 ) {

        if (count == 0) {

            bst = insertRec(bst, value);
            count++;
        }
        else{
        cout << "Enter values to make BST (enter 999 stop):";
        cin >> value;

        if(value!=999)
        insertRec(bst, value);
        }
    }
    */
    print(bst);
    cout<<endl;

    cout<<"Enter values to delete from BST (enter 999 stop):";
    cin>>value;
    while(value != 999 ) {
        deleteRec(bst, value);
        cout<<"Enter values to delete from BST (enter 999 stop):";
        cin>>value;
    }

    print(bst);
    cout<<endl;
    cout<<"Enter values to find next from BST (enter 999 stop):";
    cin>>value;
    while(value != 999 ) {
        findNextRec(bst, value);
        cout<<"Enter values to find next from BST (enter 999 stop):";
        cin>>value;
        print(bst);
        cout<<endl;

    }


    cout<<"Enter value to find previous  from BST (enter 999 stop):";
    cin>>value;
    while(value != 999 ) {
        findPrevRec(bst, value);
        cout<<"Enter value to find previous from BST (enter 999 stop):";
        cin>>value;
    }

    print(bst);
    cout<<endl;
    findMinRec(bst);
    findMaxRec(bst);
/*
    cout<<"Enter values to make BST (enter 999 stop):";
    cin>>value;
    while(value != 999 ) {

        if (count == 0) {

            bst = insertIter(bst, value);
            count++;
        }
        else{
            cout << "Enter values to make BST (enter 999 stop):";
            cin >> value;
            // cout<<"Enter values to make BST (enter 999 stop):";
            //cin>>value;
            if(value!=999)
                insertIter(bst, value);
        }
    }


    print(bst);
    cout<<endl;
    cout<<"Enter values to delete from BST (enter 999 stop):";
    cin>>value;
    while(value != 999 ) {
        deleteIter(bst, value);
        print(bst);
        cout<<endl;
        cout<<"Enter values to delete from BST (enter 999 stop):";
        cin>>value;
    }
    */
    print(bst);
    cout<<endl;
    cout<<"Enter values to find next from BST Iter(enter 999 stop):";
    cin>>value;
    while(value != 999 ) {
        findNextIter(bst, value);
        cout<<"Enter values to find next from BST Iter(enter 999 stop):";
        cin>>value;
        print(bst);
        cout<<endl;

    }

    print(bst);
    cout<<endl;
    cout<<"Enter value to find previous from BST Iter (enter 999 stop):";
    cin>>value;
    while(value != 999 ) {
        findPrevIter(bst, value);
        cout<<"Enter value to find previous from BST Iter(enter 999 stop):";
        cin>>value;
    }

    print(bst);
    cout<<endl;
    findMinIter(bst);
    findMaxIter(bst);
    return 0;
}
