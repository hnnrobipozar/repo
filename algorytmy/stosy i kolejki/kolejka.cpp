#include <iostream>

using namespace std;

//kolejka priorytetowa to struktura danych, w ktorej mozna dodawac elementy na lewo i prawo od glowy
//kolejka priorytetowa jest typem danych abstrakcyjnym, czyli nie ma okreslonego sposobu jej implementacji
// w naszym przykładzie kolejka priorytetowa jest implementowana za pomoca listy jednokierunkowej
 
class priorityQueue{
    struct node{
        int priority;
        int data;
        node *next;
    };
    node *head;
public:

    priorityQueue(){
        head = NULL;
    }

    void push(int data, int prio){
        node *newNode = new node;
        newNode->data = data;
        newNode->priority = prio;
        newNode->next = NULL;
        if(head == NULL){
            head = newNode;
        }
        else if(head->priority < prio){
            newNode->next = head;
            head = newNode;
        }
        else{
            node *temp = head;
            while(temp->next != NULL && temp->next->priority >= prio){
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    

    void pop(int prio){
        node *temp = head;
        if(head->priority == prio){
            head = head->next;
            delete temp;
        }
        else{
            while(temp->next != NULL && temp->next->priority != prio){
                temp = temp->next;
            }
            if(temp->next != NULL){
                node *temp2 = temp->next;
                temp->next = temp->next->next;
                delete temp2;
            }
        }
    }

    void print(){
        node *temp = head;
        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }


};

int main(){

    priorityQueue q1;
    q1.push(1, 5);
    q1.push(2, 3);
    q1.push(3, 1);
    q1.push(4, 6);
    q1.push(5, 2);
    q1.push(6, 9);
    q1.push(7, 4);
    q1.push(8, 7);
    q1.push(9, 8);

    q1.print();

    q1.pop(1);
    q1.print();
    q1.pop(5);
    q1.print();
    q1.pop(9);
    q1.print();


    
    return 0;

}