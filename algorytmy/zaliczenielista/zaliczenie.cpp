#include <iostream>
#include<fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Lista {
  
    struct node{
        string year;
        string country1;
        string song;
        string artist;
        string country2;
        int counter = 0;
        node *next;
    };
public:
    node *head;

    Lista(){
        head = NULL;
    }

    Lista(istream& inFile){
        head = NULL;
        string line;
        string buff;
        string year;
        string country1;
        string song;
        string artist;
        string country2;
        while(getline(inFile, line)){
            int i = 0;
            istringstream iss(line);
            while(getline(iss, buff, ',')){
                if(i == 0){
                    year = buff;
                }
                else if(i == 1){
                    country1 = buff;
                }
                else if(i == 2){
                    song = buff;
                }
                else if(i == 3){
                    artist = buff;
                }
              else if (i==4){
                country2=buff;
                addNode(year, country1, song, artist, country2);
              }
                i++;
            }
        }
    }
    void addNode(string year,string country1, string song, string artist, string country2){
        node *temp = new node;
        temp->year = year;
        temp->country1=country1;
        temp->song = song;
        temp->artist = artist;
        temp->country2 = country2;
        temp->next = NULL;
        if(head == NULL){
            head = temp;
        }
        else{
            node *temp1 = head;
            while(temp1->next != NULL){
                temp1 = temp1->next;
            }
            temp1->next = temp;
        }
    }
    //write fucion to remove node where year is less than 2000
    void removeNode(string year){
        node *temp = head;
        node *prev = NULL;
        if(temp != NULL && temp->year == year){
            head = temp->next;
            delete temp;
            return;
        }
        while(temp != NULL && temp->year != year){
            prev = temp;
            temp = temp->next;
        }
        if(temp == NULL){
            return;
        }
        prev->next = temp->next;
        delete temp;
    }
    void removeLessThan2000(){
        node *temp = head;
        while(temp != NULL){
            if(stoi(temp->year) < 2000){
                removeNode(temp->year);
            }
            temp = temp->next;
        }
    }

    void printList(){
        node *temp = head;
        while(temp != NULL){
            cout << temp->year << "" << temp->country1 << "" << temp->song << "" << temp->artist << "" << temp->country2 << endl;
            temp = temp->next;
        }
    }
    

    bool isInList(string country2){
        node *temp = head;
        while(temp!= NULL){
            if(temp->country2 == country2){
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    bool isInList1(string country1){
        node *temp = head;
        while(temp!= NULL){
            if(temp->country1 == country1){
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    void addToCounter(string country){
        node *temp = head;
        while(temp!=NULL){
            if(temp->country2 == country){
                temp->counter++;
            }
            temp = temp->next;
        }
    }

    void addToCounter1(string country){
        node *temp = head;
        while(temp!=NULL){
            if(temp->country1 == country){
                temp->counter++;
            }
            temp = temp->next;
        }
    }

    Lista howManyCountry2(Lista nowalista){
        node* temp=head;
        nowalista.addNode("", "", "", "", temp->country2);
        nowalista.addToCounter(temp->country2);
        temp = temp ->next;
        while (temp != NULL){
            if(nowalista.isInList(temp->country2)){
                nowalista.addToCounter(temp->country2);
            }
            else{
                nowalista.addNode("", "", "", "", temp->country2);
                nowalista.addToCounter(temp->country2);
            }
            temp = temp->next;
        }
        
        return nowalista;
    }

    Lista moreThan2Country(Lista nowaLista){
        node* temp = head;
        while(temp != NULL){
            if(temp->counter > 2){
            
                nowaLista.addNode("", temp->country1, "", "", "");
            }
            temp = temp->next;
        }
        return nowaLista;
    }

    Lista howManyCountry1(Lista nowalista){
        node* temp=head;
        nowalista.addNode("", temp->country1, "", "", "");
        nowalista.addToCounter(temp->country1);
        temp = temp ->next;
        while (temp != NULL){
            if(nowalista.isInList1(temp->country1)){
                nowalista.addToCounter1(temp->country1);
            }
            else{
                nowalista.addNode("", temp->country1, "", "", "");
                nowalista.addToCounter1(temp->country1);
            }
            temp = temp->next;
        }
        Lista nowaLista2;
        return nowalista.moreThan2Country(nowaLista2);
    }

    void printFor2Wins(){
        node *temp = head;
        cout<<"Countries that won more than 2 times:"<<endl;
        while(temp != NULL){
            cout<<temp->country1<<endl;
            temp = temp->next;
        }
    }

    void printForCountry2(){
        node *temp = head;
        cout<<"Number of wins in different languages:"<<endl;
        while(temp != NULL){
            cout<<temp->country2<<" - "<<temp->counter<<endl;
            temp = temp->next;
        }
    }
    
};

    

int main(){
    //WCZYTYWANIE LISTY
    ifstream inFile;
    inFile.open("lista.txt");
    Lista list(inFile);
    //list.printList();
    Lista nowaLista;
    //PODPUNKT 1
    nowaLista = list.howManyCountry2(nowaLista);
    nowaLista.printForCountry2();
    cout<<endl<<"------------------------------------------------------------"<<endl<<endl;
    //PODPUNKT 2
    Lista moreThan2Wins;
    moreThan2Wins = list.howManyCountry1(moreThan2Wins);
    moreThan2Wins.printFor2Wins();
    cout<<endl<<"------------------------------------------------------------"<<endl;
    //PODPUNKT 3
    list.removeLessThan2000();
    cout<<endl<<"List after removing nodes with year less than 2000:"<<endl;
    list.printList();
    inFile.close();
  
    return 0;
}