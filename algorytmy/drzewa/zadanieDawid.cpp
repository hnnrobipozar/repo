#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

struct node {
	string data;
	node* parent;
	node* left;
	node* right;
	string key;
};

class DrzewoBST {
public:
	node* root;
	DrzewoBST() {
		root = nullptr;
	}
	bool czy_s1_wiekszy_od_s2(string s1, string s2, string klucz) {	//funkcja pomocnicza, do porownywania wedlug ustalonego alfabetu
		int ile = s1.size();
		if (s2.size() < ile)
			ile = s2.size();
		int pom1 = 0, pom2 = 0;

		int j = 0;

		for (int i = 0; i < ile; i++) {		//szukanie pierwszej roznej litery
			if (s1[i] != s2[i])
				break;
			j++;
		}

		int n = 0;
		while (s1[j] != klucz[n]) {	//pozycja w alfabecie pierwszej litery
			pom1++;
			n++;
		}
		n = 0;
		while (s2[j] != klucz[n]) {	//pozycja w alfabecie drugiej litery
			pom2++;
			n++;
		}

		if (pom1 > pom2)	//sprawdzenie ktora jest blizej wedlug ustalonego alfabetu
			return 0;
		else
			return 1;
	}

	void add_node(string key, string data) {	//dodawanie wezlow
		if (search(data, key))
			return;

		node* n = new node;
		n->data = data;
		n->key = data;
		n->left = nullptr;
		n->right = nullptr;
		if (root == nullptr) {
			root = n;
		}
		else {
			node* temp = root;
			while (temp != nullptr) {
				if (czy_s1_wiekszy_od_s2(data, temp->data, key)) {
					if (temp->left == nullptr) {
						temp->left = n;
						n->parent = temp;
						break;
					}
					else
						temp = temp->left;

				}
				else if (!czy_s1_wiekszy_od_s2(data, temp->data, key)) {
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

	void print_inorder(node* temp) {	//wyswietlanie
		if (temp != nullptr) {
			print_inorder(temp->left);
			cout << temp->data << " ";
			print_inorder(temp->right);
		}
	}
	void print_inorder() {
		print_inorder(root);
	}

	node* delete_node(node* pom, string key) {


		if (pom == nullptr) //gdy puste
			return pom;

		if (key < pom->key)								//rekurencyjne szukanie wezla
			pom->left = delete_node(pom->left, key);
		else if (key > pom->key)
			pom->right = delete_node(pom->right, key);
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

			node* temp = pom_delete_node(pom->right);				//2 dzieci
			pom->right = delete_node(pom->right, temp->key);

			pom->data = temp->data;
			pom->key = temp->key;

		}
		return pom;
	}
	node* pom_delete_node(node* temp) {	//szuka najmniejszego elementu w prawym subdrzewie
		node* temp2 = temp;

		while (temp2 && temp2->left != nullptr)
			temp2 = temp2->left;

		return temp2;
	}


	node* search(string s1, string klucz) {	//szukanie
		node* temp = root;
		while (temp != nullptr) {
			if (s1 == temp->data) {
				return temp;
			}
			else if (czy_s1_wiekszy_od_s2(s1, temp->data, klucz)) {
				temp = temp->left;
			}
			else if (!czy_s1_wiekszy_od_s2(s1, temp->data, klucz)) {
				temp = temp->right;
			}
		}
		return nullptr;
	}

	node* search_zaawansowane(string s1, string klucz) {	//szukanie zaawansowane
		node* temp = root;
		int max_rozmiar = s1.size();
		bool czy_pocz_taki_sam = true;

		
		

		while (temp != nullptr) {
			czy_pocz_taki_sam = true;
			for (int i = 0; i < max_rozmiar; i++)
				if (temp->data[i] != s1[i])
					czy_pocz_taki_sam = false;

			if (czy_pocz_taki_sam) {
				return temp;
			}
			else if (czy_s1_wiekszy_od_s2(s1, temp->data, klucz)) {
				temp = temp->left;
			}
			else if (!czy_s1_wiekszy_od_s2(s1, temp->data, klucz)) {
				temp = temp->right;
			}
		}
		return nullptr;
	}

	void edit_node(string key, string new_data, string klucz) {
		if (search(key, klucz)) {
			delete_node(root, key);
			add_node(klucz, new_data);
		}
		else {
			cout << "nie ma takiego wezla" << endl;
		}
	}
};

int main() {

	string klucz = "0123456789ABCDEFGHIJKLMNOP!@#$%^&*()QRSTUVWXYZ";
	DrzewoBST slownik;

	//dodawanie slow
	slownik.add_node(klucz, "CDE");
	slownik.add_node(klucz, "ABCDF");

	slownik.add_node(klucz, "EFG");
	slownik.add_node(klucz, "BCD");

	slownik.add_node(klucz, "DEF");
	slownik.add_node(klucz, "212");
	slownik.add_node(klucz, "3UI");
	slownik.add_node(klucz, "ABC");
	slownik.add_node(klucz, "ABCD");
	slownik.add_node(klucz, "ABD");
	slownik.add_node(klucz, "AB0000");
	slownik.add_node(klucz, "Z000");
	slownik.add_node(klucz, "ZZZ");
	slownik.add_node(klucz, "Z#@");
	slownik.add_node(klucz, "Z");


	slownik.print_inorder();
	cout << endl << endl;;

	//wyszukiwanie
	cout << "wyszukiwanie slowa w slowniku: ";

	if (slownik.search("ABC", klucz))
		cout << slownik.search("ABC", klucz)->data;
	else
		cout << "nie znaleziono!";
	cout << endl << endl;

	//wyszukiwanie zaawansowane
	cout << "wyszukiwanie zaawansowane slowa w slowniku: ";
	if (slownik.search_zaawansowane("AB", klucz))
		cout << slownik.search_zaawansowane("AB", klucz)->data;
	else
		cout << "nie znaleziono!";
		cout << endl <<endl;

	//edycja wezlow
	slownik.edit_node("ABC", "NEWDATA", klucz);
	slownik.print_inorder();
	cout << endl;

	return 0;
}