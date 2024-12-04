#include <bits/stdc++.h>

using namespace std;

class Node {
    private:
        int data;
        Node* left = nullptr;
        Node* right = nullptr;
    
    public:
        void setData(int value){
            data = value;
        }
        int getData(){
            return data;
        }

        void setLeft(int value){
            left = new Node;
            left->data = value;
        }
        Node* getLeft(){
            return left;
        }

        void setRight(int value){
            right = new Node;
            right->data = value;
        }
        Node* getRight(){
            return right;
        }
};

class BST {
    private:
        Node* root = nullptr;

        enum side {LEFT, RIGHT};

        void insert_aux(Node* T, int value){
            if(value < T->getData())
                if(!(T->getLeft())) T->setLeft(value);
                else insert_aux(T->getLeft(), value);
            else
                if(!(T->getRight())) T->setRight(value);
                else insert_aux(T->getRight(), value);
        }

        bool find_aux(Node* T, int value){
            if(!T) return false;
            if(value < T->getData()) return find_aux(T->getLeft(), value);
            else return find_aux(T->getRight(), value);
        }

        void show_aux(Node* T){
            if(!T) cout << "nil ";
            else{
                cout << "[ " << T->getData() << " ";
                show_aux(T->getLeft());
                show_aux(T->getRight());
                cout << "]";
            }
        }

        bool check_onesided_aux(Node* T, bool L, bool R){
            if(!T) return true;
            if(T->getLeft() == NULL && T->getRight() == NULL) return true;
            if((((T->getLeft()) == NULL) == L) && (((T->getRight()) == NULL) == R))
                if(L) return check_onesided_aux(T->getRight(),L,R);
                else return check_onesided_aux(T->getLeft(),L,R);
            else return false;
        }

        bool check_separation_aux(Node* T, side S){
            switch(S){
                case LEFT:
                    if(!(T->getLeft())) return true;
                    else
                        if(T->getData()-3 <= T->getLeft()->getData() && T->getLeft()->getData() <= T->getData()-1)
                            return check_separation_aux(T->getLeft(), S);
                        else return false;
                    break;
                case RIGHT:
                    if(!(T->getRight())) return true;
                    else
                        if(T->getData()+1 <= T->getRight()->getData() && T->getRight()->getData() <= T->getData()+3)
                            return check_separation_aux(T->getRight(), S);
                        else return false;
                    break;
            }
            return false;
        }

    public:
        Node* getRoot(){
            return root;
        }

        void insert(int value){
            if(!root){
                root = new Node;
                root->setData(value);
            }else insert_aux(root, value);
        }

        bool find(int value){
            return find_aux(root, value);
        }

        void show(){
            show_aux(root);
            cout << "\n";
        }

        bool check_onesided(){
            if(!root) return false;
            if(!(root->getLeft()))
                if(!(root->getRight())) return true;
                else return check_onesided_aux(root->getRight(),true,false);
            else
                if(!(root->getRight())) return check_onesided_aux(root->getLeft(),false,true);
                else return false;
        }

        bool check_separation(){
            if(!root) return false;
            if(!(root->getLeft())) return check_separation_aux(root->getRight(),RIGHT);
            else return check_separation_aux(root->getLeft(),LEFT);
        }
};

int processCase(string S){
    int v;
    BST tree;

    string data;
    stringstream ss(S);
    
    while(getline(ss,data,' ')){
        v = stoi(data);
        if(tree.find(v)) return 0;
        tree.insert(v);
    }
    
    if(tree.check_onesided())
        if(tree.check_separation()) return 1;
        else return 0;
    else return 0;
}

int main(void){
    string line;
    ifstream inputFile("input.txt");
    //ifstream inputFile("coso.txt");

    int cont = 0;
    while (getline(inputFile, line)){
        cont += processCase(line);
    }
    inputFile.close();

    cout << cont << "\n";

    return 0;
}
