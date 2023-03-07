//#include<iostream>
//#include<string>
//#include<vector>
//#include<fstream>
//using namespace std;
//struct Node {
//	char alph;
//	int freq;
//	Node* left, * right;
//	Node() {
//		left = NULL;
//		right = NULL;
//	}
//};
//class huffman {
//private:
//	Node* root;
//	vector<Node*> Vector_arr;
//public:
//	huffman() {
//		root = NULL;
//		Vector_arr.clear();
//	}
//	void extracting_file() {
//		int freq[94];
//		for (int i = 0; i < 94; i++)
//			freq[i] = 0;
//		ifstream input;
//		char alphabet;
//		int count = 0;
//		input.open("encode.txt");
//		if (input.is_open())
//			while (input.get(alphabet))
//				freq[alphabet - 32]++;
//		input.close();
//		for (int i = 0; i < 94; i++) {
//			if (freq[i] != 0) {
//				Node* newnode = new Node;
//				newnode->alph = i + 32;
//				newnode->freq = freq[i];
//				newnode->left = NULL;
//				newnode->right = NULL;
//				Vector_arr.push_back(newnode);
//			}
//		}
//	}
//	
//	void heapify(vector<Node*>& Vector_arr, int num, int count) {
//		int max = count;
//		int left = 2 * count + 1;
//		int right = 2 * count + 2;
//
//		if (left < num && Vector_arr[left]->freq > Vector_arr[max]->freq)
//			max = left;
//
//		if (right < num && Vector_arr[right]->freq > Vector_arr[max]->freq)
//			max = right;
//
//		if (max != count) 
//		{
//			swap(Vector_arr[count], Vector_arr[max]);
//			heapify(Vector_arr, num, max);
//		}
//	}
//
//	void minHeap() {
//		for (int i = Vector_arr.size() - 1 / 2; i >= 0; i--)
//			heapify(Vector_arr, Vector_arr.size() - 1, i);
//
//
//		for (int i = Vector_arr.size() - 1; i > 0; i--) {
//			swap(Vector_arr[0], Vector_arr[i]);
//			heapify(Vector_arr, i, 0);
//		}
//	}
//
//	Node* minimum() {
//		int i = 0, index;
//		Node* node = Vector_arr[0];
//		Vector_arr[0] = Vector_arr[Vector_arr.size() - 1];
//		Vector_arr.pop_back();
//		minHeap();
//			return node;
//	}
//
//	void tree() {
//		while (Vector_arr.size() != 1)
//			huffmantree();
//	}
//
//	/*void inorder(Node* root) {
//		if (root != NULL) {
//			cout << root->alph << endl;
//			in(root->left);
//			in(root->right);
//		}
//	}*/
//
//	void huffmantree() {
//		{
//			Node* left = minimum();
//			Node* right = minimum();
//			Node* newnode = new Node;
//			newnode->freq = left->freq + right->freq;
//			newnode->left = left;
//			newnode->right = right;
//			newnode->alph = '\0';
//			Vector_arr.push_back(newnode);
//			root = newnode;
//			minHeap();
//		}
//		
//	}
//	void encoding(char key, string encoded, Node* temp) {
//		if (temp == NULL)
//			return;
//		else {
//			encoding(key, encoded + "0", temp->left);
//			encoding(key, encoded + "1", temp->right);
//		}
//		if (temp->alph == key) {
//			cout << encoded;
//			return;
//		}
//	}
//	void encode() {
//		ifstream input;
//		char ch;
//		string code = "";
//		Node* t = root;
//		input.open("encode.txt");
//		if (input.is_open())
//			while (input.get(ch))
//				encoding(ch, code, t);
//		input.close();
//	}
//
//	void decode() {
//		ifstream input;
//		char letter;
//		Node* temp = Vector_arr[0];
//		input.open("decoded.txt");
//		if (input.is_open())
//			while (!input.eof()) {
//				if (temp->right == NULL || temp->left == NULL) {
//					cout << temp->alph;
//					temp = root;
//				}
//				input.get(letter);
//				if (letter == '0')
//					temp = temp->left;
//				if (letter == '1')
//					temp = temp->right;
//			}
//		input.close();
//	}
//	void Delete(Node* r) {
//		if (r->left == NULL && r->right == NULL)
//			delete r;
//		else {
//			if (r->left != NULL)
//				Delete(r->right);
//			else
//				Delete(r->left);
//		}
//	}
//	~huffman() {
//		Delete(root);
//	}
//};
//int main() {
//	huffman h1;
//	h1.extracting_file();
//	h1.minHeap();
//	h1.tree();
//	h1.encode();
//	cout << endl;
//	h1.decode();
//	return 0;
//}