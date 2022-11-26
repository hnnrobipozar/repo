#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include <cstring>
#include <cstdlib>
#include <chrono>
#include <fstream>


using namespace std;

struct node {
	int data;
	node* parent;
	node* left;
	node* right;
	int key;
};

class DrzewoBST {
public:
	node* root;
	DrzewoBST() {
		root = nullptr;
	}
	void dodaj_przylot(DrzewoBST odloty, int czas) {
		int czas_pocz = czas -= 3;
		int czas_kon = czas += 3;
		bool flag = false;
		for (int i = czas_pocz; i < czas_kon; i++) {
			if (odloty.search(i))
				flag = true;
		}
		if (flag) {
			add_node(czas);
			cout << "proba rezerwacji " << czas << " odmowa" << endl;
		}
		else
			cout << "proba rezerwacji " << czas << " sukces" << endl;

	}
	void add_node(int czas) {
		node* n = new node;
		n->data = czas;
		n->key = czas;
		n->left = nullptr;
		n->right = nullptr;
		if (root == nullptr) {
			root = n;
		}
		else {
			node* temp = root;
			while (temp != nullptr) {
				if (czas < temp->key) {
					if (temp->left == nullptr) {
						temp->left = n;
						n->parent = temp;
						break;
					}
					else
						temp = temp->left;

				}
				else if (czas > temp->key) {
					if (temp->right == nullptr) {
						temp->right = n;
						n->parent = temp;
						break;
					}
					else
						temp = temp->right;

				}
			}
		}
	}	
	void print_inorder(node* temp) {	
		if (temp != nullptr) {
			print_inorder(temp->left);
			cout << temp->data << " ";
			print_inorder(temp->right);
			
		}
	}
	void print_inorder() {
		print_inorder(root);
	}
	
	bool search(int key) {
		node* temp = root;
		while (temp != nullptr) {
			if (key == temp->key) {
				return true;
			}
			else if (key < temp->key) {
				temp = temp->left;
			}
			else if (key > temp->key) {
				temp = temp->right;
			}
		}
		return false;
	}
	

	node* usun_przylot(node* pom, int key){
		
		
		if (pom == nullptr) //gdy puste
			return pom;

		if (key < pom->key)								//rekurencyjne szukanie wezla
			pom->left = usun_przylot(pom->left, key);
		else if (key > pom->key)
			pom->right = usun_przylot(pom->right, key);
		else {	//gdy znajdzie wezel
			if (pom->left == nullptr && pom->right == nullptr)		//gdy nie ma dzieci
				return nullptr;

			else if (pom->left == nullptr) {		//gdy ma jedno albo nie ma
				node* temp = pom->right;
				free(pom);
				return temp;
			}
			else if (pom->right == nullptr) {
				
				node* temp = pom->left;
				free(pom);
				return temp;
			}

			node* temp = pom_usun_przylot(pom->right);				//2 dzieci
			pom->right = usun_przylot(pom->right, temp->key);

			pom->data = temp->data;
			pom->key = temp->key;
			
		}
		return pom;
	}
	node* pom_usun_przylot(node* temp){	//szuka najmniejszego elementu w prawym subdrzewie
		node* temp2 = temp;

		while (temp2 && temp2->left != nullptr)
			temp2 = temp2->left;

		return temp2;
	}
};

int main() {
	fstream plik;


	const std::time_t now = std::time(nullptr); // get the current time point
	const std::tm calendar_time = *std::localtime(std::addressof(now));
	cout << "aktualny czas: " << calendar_time.tm_min << endl;
	

	DrzewoBST oczekiwane_przyloty;
	oczekiwane_przyloty.add_node(41);
	oczekiwane_przyloty.add_node(47);
	oczekiwane_przyloty.add_node(50);
	oczekiwane_przyloty.add_node(58);
	
	cout << "Planowane zdarzenia: (";
	oczekiwane_przyloty.print_inorder();
	cout << ")" << endl;

	oczekiwane_przyloty.dodaj_przylot(oczekiwane_przyloty, 48);
	oczekiwane_przyloty.dodaj_przylot(oczekiwane_przyloty, 20);
	oczekiwane_przyloty.dodaj_przylot(oczekiwane_przyloty, 54);
	

	return 0;
}
