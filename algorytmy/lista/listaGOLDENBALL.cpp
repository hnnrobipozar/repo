#include<iostream>
#include<fstream>
#include <sstream>
#include <string>

using namespace std;

class Lists{

    struct node{
        string name;
        string year;
        string club;
        string country;
        node *next;
    };
    node *head;
    public:     
    Lists(istream& inFile){
        head = NULL;
        string line;
        string buff;
        string name;
        string year;
        string club;
        string country;
        while(getline(inFile, line)){
            int i = 0;
            istringstream iss(line);
            while(getline(iss, buff, ',')){
                if(i == 0){
                    name = buff;
                }
                else if(i == 1){
                    year = buff;
                }
                else if(i == 2){
                    club = buff;
                }
                else if(i == 3){
                    country = buff;
                    addNode(name, year, club, country);
                }
                i++;
            }
        }
        
    }
    void addNode(string name, string year, string club, string country){
        node *temp = new node;
        temp->name = name;
        temp->year = year;
        temp->club = club;
        temp->country = country;
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
    
    void display(){
        node *temp = head;
        while(temp != NULL){
            cout << temp->name << " " << temp->year << " " << temp->club << " " << temp->country << endl;
            temp = temp->next;
        }
    }
    void danyKraj(ofstream& out,string kraj){
        if(head == NULL){
            cout << " Pusta lista " << endl;
            return;
        }
        node *temp = head;    
        while(temp->next != NULL){
            if (temp->country == kraj){
                
                out<<temp->name<<" "<<temp->year<<" "<<temp->club<<" "<<temp->country<<endl;
            }
            temp = temp->next;
        }
        
    }

    //void listaKlubow()){

    //}
};




int main(){
    ifstream inFile;
    inFile.open("goldenBall.txt");
    ofstream out("2.txt");
    out.is_open();
    Lists lists(inFile);
    lists.display();
    lists.danyKraj(out, " Spain");
    lists.danyKraj(out, " France");
    out.close();
    return 0;
}