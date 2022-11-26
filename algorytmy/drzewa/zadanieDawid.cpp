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
	bool czy_s1_wiekszy_od_s2(string s1, string s2, string klucz) {
		int ile = s1.size();
		if (s2.size() < ile)
			ile = s2.size();
		int pom1 = 0, pom2 = 0;
	
		int j = 0;
		
		for (int i = 0; i < ile; i++) {
			if (s1[i] != s2[i])
				break;
			j++;
		}
	
		int n = 0;
		while (s1[j] != klucz[n]){	//pozycja w alfabecie dwoch liter
			pom1++;
			n++;
		}
		n = 0;
		while (s2[j] != klucz[n]) {	//pozycja w alfabecie dwoch liter
			pom2++;
			n++;
		}

		if (pom1 > pom2)
			return 0;
		else 
			return 1;
	}

	bool czy_s1_rowne_s2(string s1, string s2, string klucz) {
		
		if (s2.size() != s2.size())
			return 0;

		int ile = s1.size();

		int j = 0;
		for (int i = 0; i < ile; i++) {
			if (s1[i] != s2[i])
				return 0;
			j++;
		}

			return 1;
	}

	

	void add_node(string key, string data) {
		node* n = new node;
		n->data = data;
		n->key = key;
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

	
	node* search(string s1, string klucz) {
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

	node* search_zaawansowane(string s1, string klucz) {
		node* temp = root;
		int max_rozmiar = s1.size();

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

	bool pom_search_zaawansowane(string s1, int max_rozmiar){}

	
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

	slownik.print_inorder();
	cout << endl;

	//wyszukiwanie slowa w slowniku
	if(slownik.search("ABC", klucz))
		cout<<slownik.search("ABC", klucz)->data;

	//
	

	return 0;
}