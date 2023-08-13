#include <iostream>
#include <string>
#include <fstream>
using std::cin;
using std::cout;
using std::endl;
using namespace std;
/**********
BST node with four pirvate members of left, right , a character and string, all with a setter and getter
and a constructor that intializes the left and right to nullptr, and a destrcutor that again nullifies
the pointers
**/
template <class T, class U>
class BSTnode {
public:
	BSTnode() {
		right = nullptr;
		left = nullptr;
	}
	T get_character() {
		return this->character;
	}
	void set_character(T c) {
		this->character = c;
	}
	void set_string(U s) {
		this->morse_code = s;
	}
	U get_string() {
		return this->morse_code;
	}
	BSTnode<T,U>* get_left() {
		return this->left;
	}
	void set_left(BSTnode<T,U>* l) {
		this->left = l;
	}
	BSTnode<T,U>* get_right() {
		return this->right;
	}
	void set_right(BSTnode<T,U>* r) {
		this->right = r;
	}
	~BSTnode() {
		right = nullptr;
		left = nullptr;
	}
private:
	T character;
	U morse_code;
	BSTnode<T,U>* right;
	BSTnode<T,U>* left;
};


