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

   bool compare(string s1, string s2){      //zwraaca 1 jesli s1 jest mniejsze od s2
        for(int i=0; i<s1.size(); i++){
            if(mapa1[s1[i]] < mapa1[s2[i]]){
                return 1;
            }
            else if(mapa1[s1[i]] > mapa1[s2[i]]){
                return 0;
            }
        }
   }

   node* find(string word){
       node *temp = root;
       while(temp != NULL){
           if(temp->word == word){
               return temp;
           }
           if(compare(word, temp->word)){
               temp = temp->left;
           }
           else{
               temp = temp->right;
           }
       }
       return NULL;
   }
    
    void searchWord(string word){
        node *temp = root;
        while(temp != NULL){
            if(temp->word == word){
                cout << "Znaleziono slowo: " << temp->word << endl;
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
            cout << "Nie znaleziono slowa" << endl;
        }
    }

    void printInOrder(node *temp){
        if(temp != NULL){
            printInOrder(temp->right);
            cout << temp->word << endl;
            printInOrder(temp->left);
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
        advancedSearchInOrder(root, word1);
    }
    //funkcja usuwajaca istniejacego node'a i dodajaca w zamian innego

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
            cout << "Nie znaleziono slowa" << endl;
            return;
        }
        else{
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
    }

    void changeNode(string word, string newWord){
        deleteNode(word);
        addNode(newWord);
    }
    
};


int main(){

    tree drzewo;

    drzewo.addNode("ALA");
    drzewo.addNode("@(^A");
    drzewo.addNode("00000");
    drzewo.addNode("Z");
    drzewo.addNode("ALA");
   // drzewo.printTree(drzewo.root);

    drzewo.printInOrder(drzewo.root);

    //cout<<endl<<endl;

   drzewo.find("ALA");

    //regex word("^A");

    //drzewo.deleteNode("ALA");

    //drzewo.advancedSearchInOrder(drzewo.root, word);
    cout<<endl<<endl;
   // drzewo.changeNode("ALA", "ZIMA");
    drzewo.printInOrder(drzewo.root);
    

    return 0;

}