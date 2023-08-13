#include "BSTnode.h"

template <class T, class U>
class BST {
public:
	BST() {
		root = NULL;
		ifstream infile;
		U line;
		U ch;
		U morse;
		U english_line;
		U search_morse;
		int position = 0;
		infile.open("Morsetable.txt", ios::in);
		if (infile.is_open()) {
			while (!infile.eof()) {
				getline(infile, line);
				position = line.find_first_of(' ');
				ch = line.substr(0, position);
				position = line.find_last_of(' ');
				morse = line.substr(position + 1, line.length() - (position + 1));
				BSTnode<T,U>* new_node = new BSTnode<T,U>;
				if (new_node != nullptr) {
					new_node->set_character(ch[0]);
					new_node->set_string(morse);
					new_node->set_left(nullptr);
					new_node->set_right(nullptr);
					insert_new(new_node);
				}
			}
			infile.close();
			//printing the tree
			cout << endl << "printing the tree" << endl;
			Print_tree(root);
			cout << endl;

			// reading from converison file
			infile.open("convert.txt", ios::in);
			if (infile.is_open()) {
				cout << endl << "conversion to morse code: " << endl;
				while (!infile.eof()) {
					getline(infile, english_line);
					for (int i = 0; i < english_line.length(); i++) {
						char chc = toupper(english_line[i]);
						if (chc != ' ') {
							search_morse = search_node(root, chc);
							cout << search_morse;
							cout << " ";
						}
						else {
							cout << " ";
							cout << " ";
							cout << " ";
						}
					}
				}
				infile.close();
			}
		}
	}
	~BST() {
		delete_tree(root);
		root = nullptr;
	}

private:
	/**********
function: insert new
Date created: 3/29/2022
Date last modified:3/28/2022, 3/29/2022
Description: inserts a new children in tree
Input parameters: BST new node
Returns: none
preconditions:data must be inputted, the order of file must be read 
postconditions: if executed right, this will insert a node into a binary tree based on ascii value
**/
	BSTnode<T,U>* root;
	void insert_new(BSTnode<T, U>* n) {
		if (root == NULL) {
			root = n;
			return;
		}
		BSTnode<T, U>* temp = root;
		while (temp != NULL) {
			if ((n->get_character() < temp->get_character()) && (temp->get_left() == NULL)) {
				temp->set_left(n);
			}
			else if (n->get_character() < temp->get_character()) {
				temp = temp->get_left();
			}
			else if ((n->get_character() > temp->get_character()) && (temp->get_right() == NULL)) {
				temp->set_right(n);
			}
			else {
				temp = temp->get_right();
			}
		}
	}
	/**********
function: print tree
Date created: 3/29/2022
Date last modified:3/28/2022, 3/29/2022
Description: print the entire tree using post order travsersal recursively
Input parameters: BST root
Returns: none
preconditions:data must be inputted, the order of file must be read
postconditions: if executed right, this will print the entire tree using post order travsersal recursively
**/
	template <class T, class U>
	void Print_tree(BSTnode<T, U>* r) {
		if (r == nullptr) {
			return;
		}
		Print_tree(r->get_left());
		cout << r->get_character();
		cout << r->get_string();
		Print_tree(r->get_right());
		return;
	}

	template <class T, class U>
	void delete_tree(BSTnode<T, U>* root) {
		if (root != nullptr) {
			delete_tree(root->get_left());
			delete_tree(root->get_right());
			delete root;
		}
		return;
	}
/**********
function: search tree
Date created: 3/29/2022
Date last modified:3/28/2022, 3/29/2022
Description: searches a node using left and right pointers
Input parameters: BST root and the character to find
Returns: morse code string
preconditions:data must be inputted, the order of file must be read
postconditions: if executed right, this will return the string that matches the character
**/
	template <class T, class U>
	U search_node(BSTnode<T, U>* r, T c) {
		if (root == NULL) {
			cout << "list is empty" << endl;
			return "";
		}
		BSTnode<T, U>* temp = root;
		while (temp != NULL) {
			if (temp->get_character() == c) {
				return temp->get_string();
			}
			if (c < temp->get_character()) {
				temp = temp->get_left();
			}
			else {
				temp = temp->get_right();
			}
		}
		cout << "value not found" << endl;
		return "";
	}
};
