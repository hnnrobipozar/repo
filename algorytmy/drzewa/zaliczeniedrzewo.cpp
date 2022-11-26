#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;


class tree{
    
    struct node {
        int data;
        node *parent;
        node *left;
        node *right;
        int key;            //jezeli wartosc szukana jest mniejsza niz dana w wezle to idziemy w lewo, jesli wieksza to w prawo
        };                  //np szukamy 13 a mamy 10 to idziemy w lewo, jesli szukamy 13 a mamy 15 to idziemy w prawo
                            //PFS - przeszukiwanie w glab:
                            //pre order - idziemy w lewo do momentu gdy nie ma juz lewego syna, potem idziemy w prawo,
                            // a potem w lewo

                            //in order - daje posortowany ciag liczb

                            //post order - odwiedzamy na koncu root, czyli najpierw idziemy w lewo, potem w prawo, a na koncu root
                            //po galeziach chodzimy od dolu do gory;
    public:

        node *root;
        tree(){
            root = NULL;
        }
        void addNode(int key, int data){
            node *n = new node;
            n->data = data;
            n->key = key;
            n->left = NULL;
            n->right = NULL;
            if(root == NULL){
                root = n;
            }
            else{
                node *temp = root;
                while(temp != NULL){
                    if(key < temp->key){
                        if(temp->left == NULL){
                            temp->left = n;
                            n->parent = temp;
                            break;
                        }
                        else{
                            temp = temp->left;
                        }
                    }
                    else if(key > temp->key){
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
        
        void printPreOrder(node *temp){
            if(temp != NULL){
                cout << temp->data << " ";
                printPreOrder(temp->left);
                printPreOrder(temp->right);
            }
        }
        void printInOrder(node *temp){
            if(temp != NULL){
                printInOrder(temp->left);
                cout << temp->data << " ";
                printInOrder(temp->right);
            }
        }
        void printPostOrder(node *temp){
            if(temp != NULL){
                printPostOrder(temp->left);
                printPostOrder(temp->right);
                cout << temp->data << " ";
            }
        }

        void printPreOrder(){
            printPreOrder(root);
        }
        void printInOrder(){
            printInOrder(root);
        }
        void printPostOrder(){
            printPostOrder(root);
        }
        void printTree(){
            printPreOrder(root);
            cout << endl;
            printInOrder(root);
            cout << endl;
            printPostOrder(root);
            cout << endl;
        }

        node *search(int key){
            node *temp = root;
            while(temp != NULL){
                if(key == temp->key){
                    return temp;
                }
                else if(key < temp->key){
                    temp = temp->left;
                }
                else if(key > temp->key){
                    temp = temp->right;
                }
            }
            return NULL;
        }

    void printGraphicTree(node *temp, int level){
        if(temp != NULL){
            printGraphicTree(temp->right, level + 1);
            for(int i = 0; i < level; i++){
                cout << "   ";
            }
            cout << temp->data << endl;
            printGraphicTree(temp->left, level + 1);
        }
    }

    //funkcja do usuwania wezla zachowujaca strukture drzewa dst

    void deleteNode(int key){
        node *temp = search(key);                                    //znajdujemy wezel do usuniecia
        if(temp != NULL){                                            //jesli istnieje        
            if(temp->left == NULL && temp->right == NULL){           //jesli nie ma synow
                if(temp->parent->left == temp){                      //jesli jest lewym synem
                    temp->parent->left = NULL;                       //to usuwamy go
                }
                else{
                    temp->parent->right = NULL;                      //jesli jest prawym synem
                }
                delete temp;                                         //usuwamy wezel
            }
            else if(temp->left == NULL && temp->right != NULL){     //jesli ma tylko prawego syna
                if(temp->parent->left == temp){                     //jesli jest lewym synem
                    temp->parent->left = temp->right;               //to jego prawy syn staje sie jego lewym synem
                }
                else{
                    temp->parent->right = temp->right;              //jesli jest prawym synem to jego prawy syn staje sie jego prawym synem
                }
                delete temp;                                        //usuwamy wezel
            }
            else if(temp->left != NULL && temp->right == NULL){     //jesli ma tylko lewego syna
                if(temp->parent->left == temp){                     //jesli jest lewym synem
                    temp->parent->left = temp->left;                //to jego lewy syn staje sie jego lewym synem
                }
                else{
                    temp->parent->right = temp->left;               //jesli jest prawym synem to jego lewy syn staje sie jego prawym synem
                }
                delete temp;                                        //usuwamy wezel
            }
            else if(temp->left != NULL && temp->right != NULL){     //jesli ma dwoch synow
                node *temp2 = temp->right;                          //szukamy najmniejszego elementu w prawym poddrzewie
                while(temp2->left != NULL){                         //czyli idziemy w lewo az dojdziemy do najmniejszego elementu                
                    temp2 = temp2->left;                            //czyli do tego ktory nie ma lewego syna               
                }
                temp->data = temp2->data;                           //zamieniamy wartosci wezlow - data
                temp->key = temp2->key;                             //zamieniamy wartosci wezlow - key
                if(temp2->parent->left == temp2){                   //jesli jest lewym synem
                    temp2->parent->left = temp2->right;             //to jego prawy syn staje sie jego lewym synem
                }
                else{
                    temp2->parent->right = temp2->right;            //jesli jest prawym synem to jego prawy syn staje sie jego prawym synem
                }
                delete temp2;                                       //usuwamy wezel ktory zamienilismy wartosciami
            }
        }
    }
};

void line(){
    cout << "--------------------------------------------" << endl;
}

void menu(){
    line();
    cout<<"\tMENU OBSLUGI PASA STARTOWEGO \t \n";
    line();
    cout<<"1. ZAREZERWUJ PAS"<<endl;
    cout<<"2. WYSWIETL PLANOWANE LADOWANIA"<<endl;


}


int main(){

    time_t t =0;
    ctime(&t);

    cout<<"czas zerowy: "<<ctime(&t)<<endl;

    time(&t);
    cout<<"aktualny czas: "<<ctime(&t)<<endl;

    tree pas;
    menu();

    // for(;;){


    // }

    return 0;

}