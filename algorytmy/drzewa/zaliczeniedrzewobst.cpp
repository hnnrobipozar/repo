#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <map>
#include <regex>

using namespace std;


class tree{
    struct node{
        string word;
        node *left;
        node *right;
        node *parent;
        int key;
        
    };

    map<char, int> mapa1;

    public:
    node *root;
    tree(){
        root = NULL;

        string s1 = "0123456789ABCDEFGHIJKLMNOP!@#$%^&*()QRSTUVWXYZ";
        string s ="ZYXWVUTSRQ)(*&^%$#@!PONMLKJIHGFEDCBA9876543210";

        for(int i = 0; i < s1.size(); i++){
            mapa1[s1[i]] = s1.size()-1-i;
        }
        
    }

    void addNode(string word){
        node *n = new node;
        n->word = word;
        n->left = NULL;
        n->right = NULL;
        if(root == NULL){
            root = n;
        }
        else if(IsAlreadyInTree(word)){
            cout <<word<< " is already in the tree" << endl;
            return;
        }
        else{
            node* temp = root;
            while(temp != NULL){
                if(compare(n->word, temp->word)){
                    if(temp->left == NULL){
                        temp->left = n;
                        n->parent = temp;
                        break;
                    }
                    else{
                        temp = temp->left;
                    }
                }
                else{
                    if(temp->right == NULL){
                        temp->right = n;
                        n->parent = temp;
                        break;
                    }
                    else{
                        temp = temp->right;
                    }
                }
            }
        }
    }

    bool IsAlreadyInTree(string word){
        node *temp = root;
        while(temp != NULL){
            if(temp->word == word){
                return true;
            }
            if(compare(word, temp->word)){
                temp = temp->left;
            }
            else{
                temp = temp->right;
            }
        }
        return false;
    }

   bool compare(string s1, string s2){      
        for(int i=0; i<s1.size(); i++){
            if(mapa1[s1[i]] < mapa1[s2[i]]){
                return 1;
            }
            else if(mapa1[s1[i]] > mapa1[s2[i]]){
                return 0;
            }
        }
   }

  
    void searchWord(string word){
        node *temp = root;
        while(temp != NULL){
            if(temp->word == word){
                cout << "Word found: " << temp->word << endl;
                break;
            }
            else if(compare(word, temp->word)){
                temp = temp->left;
            }
            else{
                temp = temp->right;
            }
        }
        if(temp == NULL){
            cout << "Word not found" << endl;
        }
    }

    void printInAlphOrder(node *temp){
        if(temp != NULL){
            printInAlphOrder(temp->right);
            cout << temp->word << endl;
            printInAlphOrder(temp->left);
        }
    }


    void advancedSearchInOrder(node *temp, regex word){
        
        if(temp != NULL){
            advancedSearchInOrder(temp->left, word);
            if(regex_search(temp->word, word)){
                cout << temp->word << endl;
            }
            advancedSearchInOrder(temp->right, word);
        }
    }

    void advancedSearch(string word){
        regex word1(word);
        cout<<"Found: "<<endl;
        advancedSearchInOrder(root, word1);
    }
 

    void changeNode(string word1, string word2){
        if(IsAlreadyInTree(word1)){
            deleteNode(word1);
            addNode(word2);
        }
        else{
            cout << "Word not found" << endl;
        }
    }

    void deleteNode(string word){
        node *temp = root;
        while(temp != NULL){
            if(temp->word == word){
                break;
            }
            else if(compare(word, temp->word)){
                temp = temp->left;
            }
            else{
                temp = temp->right;
            }
        }
        if(temp == NULL){
            cout << "Word not found" << endl;
            return;
        }
        if(temp->left == NULL && temp->right == NULL){
            if(temp->parent->left == temp){
                temp->parent->left = NULL;
            }
            else{
                temp->parent->right = NULL;
            }
            delete temp;
        }
        else if(temp->left == NULL && temp->right != NULL){
            if(temp->parent->left == temp){
                temp->parent->left = temp->right;
            }
            else{
                temp->parent->right = temp->right;
            }
            delete temp;
        }
        else if(temp->left != NULL && temp->right == NULL){
            if(temp->parent->left == temp){
                temp->parent->left = temp->left;
            }
            else{
                temp->parent->right = temp->left;
            }
            delete temp;
        }
        else{
            node *temp2 = temp->right;
            while(temp2->left != NULL){
                temp2 = temp2->left;
            }
            temp->word = temp2->word;
            if(temp2->right != NULL){
                temp2->parent->left = temp2->right;
            }
            else{
                temp2->parent->left = NULL;
            }
            delete temp2;
        }
    }
};


int main(){

    tree drzewo;

    drzewo.addNode("ALA");
    drzewo.addNode("ALA");

    drzewo.addNode("@(^A");
    drzewo.addNode("00000");
    drzewo.addNode("Z");
    drzewo.addNode("Q4#E");
    drzewo.addNode("Q4#E00000");
    drzewo.addNode("AAQ4#E00000");
    drzewo.addNode("ZB");
    drzewo.addNode("A");
    cout<<endl;

    drzewo.printInAlphOrder(drzewo.root);
    cout<<endl;

    drzewo.changeNode("AAQ4#E00000", "ZBQ4#E00000");
    drzewo.printInAlphOrder(drzewo.root);
    cout<<endl;
  
    //do zaawansowanego wyszukiwania uzywamy regexow umozliwiajacych wyszukiwanie wzorcow

    //do wyszukiwania dokladnych slow uzyj ^ i $ np. ^Q4#E$
    //wtedy advancedSearch wyszuka tylko Q4#E pomimo tego ze w drzewie jest jeszcze Q4#E00000 i AAQ4#E00000

    drzewo.advancedSearch("Q4#E");
    cout<<endl;
    drzewo.advancedSearch("^Q4#E$");
    cout<<endl;
    
    drzewo.searchWord("Q4");
    cout<<endl;
    drzewo.searchWord("Q4#E");
    cout<<endl;
    

    return 0;

}