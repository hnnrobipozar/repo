#include <iostream>

#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>

#define zakres1 []
using namespace std;


class tree{
    struct node{
        string word;
        node *left;
        node *right;
        node *parent;
        int key;
        
    };
   
    public:
    node *root;
    tree(){
        root = NULL;
    }

    void addNode(string word){
        node *n = new node;
        n->word = word;
        n->left = NULL;
        n->right = NULL;
        if(root == NULL){
            root = n;
        }
        else{
            node *temp = root;
            while(temp != NULL){
                    if(){

                    }
                // if(word < temp->word){
                //     if(temp->left == NULL){
                //         temp->left = n;
                //         n->parent = temp;
                //         break;
                //     }
                //     else{
                //         temp = temp->left;
                //     }
                // }
                // else if(word > temp->word){
                //     if(temp->right == NULL){
                //         temp->right = n;
                //         n->parent = temp;
                //         break;
                //     }
                //     else{
                //         temp = temp->right;
                //     }
                // }
            }
        }
    }
    

};

int main(){

    return 0;

}