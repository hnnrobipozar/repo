#include <iostream>

using namespace std;


//stos to struktura danych, w ktorej mozna dodawac i usuwac elementy tylko z jednej strony
//stos jest typem danych abstrakcyjnym, czyli nie ma okreslonego sposobu jego implementacji
// w naszym przykładzie stos jest implementowany za pomoca listy jednokierunkowej
// stos jest typem danych LIFO (last in first out) - ostatni wchodzi, pierwszy wychodzi

class stack{
    struct node{
        int value;
        node *next;
    };
    node *head;
public:

    stack(){
        head = NULL;
    }

    void push(int value){
        node *newNode = new node;
        newNode->value = value;
        newNode->next = head;
        head = newNode;
    }

    node* pop(){
        node *temp = head;
        head = head->next;
        return temp;
    }

    void print(){
        node *temp = head;
        while(temp != NULL){
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main(){

    stack s1;
 for(int i = 0; i < 10; i++){
        s1.push(i);
    }
    s1.print();
    s1.pop();
    s1.print();


    return 0;

}