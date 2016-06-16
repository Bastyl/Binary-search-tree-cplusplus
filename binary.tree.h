#ifndef AVL_binary_tree_h //This is were you .h file is located
#define AVL_binary_tree_h//also you can just copy and paste the next code in your main file

#include <iostream>
using namespace std;

class Node {
private:
    int value;
    Node *left;
    Node *right;
public:
    Node (int value, Node* left=nullptr, Node* right=nullptr){
        this->value = value;
        this->left = left;
        this->right = right;
    }
    void getvalue(){
        cout<<value<<endl;
    }
    friend class Tree;
};

class Tree {
private:
    Node* root;
public:
    Tree () {
        root = nullptr;
    }
    
    Node* GetRoot(){
        return root;
    }
    
    void InsertValue(int value){
        if(!root){
            root = new Node(value);
        }
        else{
            Node *aux = root;
            while(aux->value != value){
                if(aux->value > value){
                    if(aux->left == nullptr){
                        aux->left = new Node(value);
                    }
                    aux = aux->left;
                }
                else{
                    if(aux->right == nullptr){
                        aux->right = new Node(value);
                    }
                    aux = aux->right;
                }
            }
        }
    }
    
    void PreOrder(Node* root){
        if(!root){
            return;
        }
        cout<<root->value<<endl;
        PreOrder(root->left);
        PreOrder(root->right);
    }
    
    void InOrder(Node* root){
        if(!root){
            return;
        }
        InOrder(root->left);
        cout<<root->value<<endl;
        InOrder(root->right);
    }
    
    void PostOrder(Node* root){
        if(!root){
            return;
        }
        PostOrder(root->left);
        PostOrder(root->right);
        cout<<root->value<<endl;
    }
    
    void DeleteElement(int value){
        if(!root){
            return;
        }
        else{
            Node* father = nullptr;
            Node* aux = root;
            while(aux){
                cout<<endl;
                if(aux->value == value){
                    if(!aux->left && !aux->right){
                        if(!father){
                            root = nullptr;
                        }
                        else if(father->left == aux){
                            father->left = nullptr;
                        }
                        else{
                            father->right = nullptr;
                        }
                        aux = nullptr; //cambiar por destructor
                    }
                    else{
                        Node* real = aux;
                        father = aux;
                        if(aux->left){
                            aux = aux->left;
                            while(aux->right){
                                father = aux;
                                aux = aux->right;
                            }
                        }
                        else{
                            aux = aux->right;
                            while(aux->left){
                                father = aux;
                                aux = aux->left;
                            }
                        }
                        swap(real->value,aux->value);
                    }
                }
                else{
                    father = aux;
                    if(aux->value > value){
                        aux = aux->left;
                    }
                    else{
                        aux = aux->right;
                    }
                }
            }
        }
    } //fix me
    
    bool IsLeaf(Node* leaf){
        return !leaf->left && !leaf->right;
    }
    
    Node* GetElement(Node* root,int value){
        Node* aux = root;
        while(aux){
            if(aux->value == value){
                break;
            }
            else if(aux->value > value){
                aux = aux->left;
            }
            else{
                aux = aux->right;
            }
        }
        return aux;
    }
    
    int GetNodeCounter(){
        int c = 0;
        if(root){
            AuxGetNodeCounter(root, &c);
        }
        return c;
    }
    
    void AuxGetNodeCounter(Node* root,int *c){
        (*c)++;
        if(root->left){
            AuxGetNodeCounter(root->left, c);
        }
        if(root->right){
            AuxGetNodeCounter(root->right, c);
        }
    }
    
    int GetLarge(){
        int large = 0;
        if(root){
            AuxGetLarge(root, 0, &large);
        }
        return large;
    }
    
    int GetLargeByValue(int value){
        int large = 0;
        if(root){
            AuxGetLarge(GetElement(root, value),0,&large);
        }
        return large;
    }
    
    void AuxGetLarge(Node* root, int a, int* large){
        if(root->left){
            AuxGetLarge(root->left,a+1, large);
        }
        if(root->right){
            AuxGetLarge(root->right, a+1, large);
        }
        if(IsLeaf(root) && a > *large){
            *large = a;
        }
    }
    
};

#endif
