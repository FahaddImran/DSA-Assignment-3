//#include<iostream>
//#include<vector>
//#include<string>
//#include<fstream>
//using namespace std;
//struct Node
//{
//	int alph;
//	Node* right;
//	Node* left;
//	char alph;
//	Node()
//	{
//		left = NULL;
//		right = NULL;
//		alph = 0;
//		alph = '-';
//	}
//};
//
//class huffman {
//private:
//	string text;
//	int* freq;
//	Node* root;
//	int size;
//	vector<Node*> vec_Vector_arr;
//	int* encodedVector_array;
//	string encoded;
//public:
//	huffman()
//	{
//		root = NULL;
//		text = "";
//		size = 0;
//		freq = new int[94];
//		encodedVector_array = new int[94];
//
//		for (int i = 0; i < 94; i++)
//		{
//			freq[i] = 0;
//		}
//	}
//	void extracting_alph()
//	{
//		char letter;
//		ifstream input;
//		input.open("encode.txt");
//		while (input.get(letter))
//		{
//			if (letter != '\n') {
//				text += letter;
//			}
//		}
//		input.close();
//
//		cout << text;
//		freq();
//	}
//	void freq()
//	{
//		char num = 32;
//		int count = 0;
//		bool flag = false;
//		while (text[count] != '\0')
//		{
//			if (text[count] == num)
//			{
//				freq[num - 32]++;
//				flag = true;
//			}
//			else if (text[count] < num)
//			{
//				flag = false;
//				num--;
//			}
//			else
//			{
//				flag = false;
//				num++;
//			}
//			if (flag == true)
//				count++;
//		}
//		total_alphabets();
//
//		cout << endl;
//		for (int i = 0; i < 94; i++)
//		{
//			cout << freq[i] << " ";
//		}
//		cout << endl;
//
//		for (int i = 0; i < 94; i++) {
//			if (freq[i] != 0) {
//				Node* newNode = new Node;
//				newNode->alph = i + 32;
//				newNode->alph = freq[i];
//				newNode->left = NULL;
//				newNode->right = NULL;
//				vec_Vector_arr.push_back(newNode);
//			}
//		}
//
//		for (int i = 0; i < 94; i++)
//		{
//			encodedVector_array[i] = freq[i];
//		}
//		cout << endl;
//
//	}
//	void total_alphabets()
//	{
//		for (int i = 0; i < 94; i++)
//		{
//			if (freq[i] != 0)
//				size++;
//		}
//	}
//
//	void heapify(vector<Node*>& Vector_arr, int size, int num)
//	{
//		int max = num;
//		int l = 2 * num + 1;
//		int r = 2 * num + 2;
//		if (l < size && Vector_arr[l]->alph > Vector_arr[max]->alph)
//			max = l;
//		if (r < size && Vector_arr[r]->alph > Vector_arr[max]->alph)
//			max = r;
//		if (max != num) {
//			swap(Vector_arr[num], Vector_arr[max]);
//			heapify(Vector_arr, size, max);
//		}
//	}
//
//	void minHeap()
//	{
//		for (int i = vec_Vector_arr.size() - 1 / 2; i >= 0; i--)
//			heapify(vec_Vector_arr, vec_Vector_arr.size() - 1, i);
//		for (int i = vec_Vector_arr.size() - 1; i > 0; i--) {
//			swap(vec_Vector_arr[0],vec_Vector_arr[i]);
//			heapify(vec_Vector_arr, i, 0);
//		}
//	}
//	
//	Node* minimumimum()
//	{
//		int i = 0, index;
//		Node* m = vec_Vector_arr[0];
//		vec_Vector_arr[0] = vec_Vector_arr[vec_Vector_arr.size() - 1];
//		vec_Vector_arr.pop_back();
//		minHeap();
//
//		/*int minimum = 0, count = 0;
//		for (int i = 0; i < size; i++)
//		{
//			if (sorted_Vector_array[i] != 0)
//			{
//				count = i;
//				minimum = sorted_Vector_array[i];
//				break;
//			}
//		}
//		sorted_Vector_array[count] = 0;*/
//		return m;
//	}
//	void tree()
//	{
//
//		Node* left = minimumimum();
//		Node* right = minimumimum();
//		Node* newnode = new Node;
//		newnode->alph = left->alph + right->alph;
//		newnode->left = left;
//		newnode->right = right;
//		newnode->alph = '\0';
//		vec_Vector_arr.push_back(newnode);
//		root = newnode;
//		minHeap();
//
//
//
//		/*static int num = 0;
//		bool flag = false;
//
//		if (root == NULL)
//		{
//			int left_minimum = minimumimum(), right_minimum = minimumimum();
//
//			Node* newNode = new Node;
//			newNode->alph = right_minimum + left_minimum;
//			newNode->alph = '-';
//			root = newNode;
//
//			Node* RnewNode = new Node;
//			RnewNode->alph = right_minimum;
//			for (int i = 0; i < 94; i++)
//			{
//				if (freq[i] == right_minimum)
//				{
//					freq[i] = 0;
//					RnewNode->alph = i + 32;
//					break;
//				}
//			}
//			RnewNode->left = NULL;
//			RnewNode->right = NULL;
//
//			root->right = RnewNode;
//
//			Node* LnewNode = new Node;
//			LnewNode->alph = left_minimum;
//			for (int i = 0; i < 94; i++)
//			{
//				if (freq[i] == left_minimum)
//				{
//					freq[i] = 0;
//					LnewNode->alph = i + 32;
//					break;
//				}
//			}
//			LnewNode->left = NULL;
//			LnewNode->right = NULL;
//
//			root->left = LnewNode;
//		}
//		else
//		{
//			num = minimumimum();
//			if (num < root->alph)
//			{
//				Node* newNode = new Node;
//				newNode->alph = num + root->alph;
//				newNode->right = root;
//				root = newNode;
//
//				Node* LnewNode = new Node;
//				LnewNode->alph = num;
//				for (int i = 0; i < 94; i++)
//				{
//					if (freq[i] == num)
//					{
//						freq[i] = 0;
//						LnewNode->alph = i + 32;
//						break;
//					}
//				}
//				LnewNode->left = NULL;
//				LnewNode->right = NULL;
//
//				root->left = LnewNode;
//			}
//			else
//			{
//				Node* newNode = new Node;
//				newNode->alph = num + root->alph;
//				newNode->left = root;
//				root = newNode;
//
//				Node* RnewNode = new Node;
//				RnewNode->alph = num;
//				for (int i = 0; i < 94; i++)
//				{
//					if (freq[i] == num)
//					{
//						freq[i] = 0;
//						RnewNode->alph = i + 32;
//						break;
//					}
//				}
//				RnewNode->left = NULL;
//				RnewNode->right = NULL;
//
//				root->right = RnewNode;
//			}
//		}
//
//		for (int i = 0; i < size; i++)
//		{
//			if (sorted_Vector_array[i] != 0)
//			{
//				flag = true;
//				break;
//			}
//		}
//		if (flag == true)
//			tree();*/
//
//	}
//
//	void Encoding()
//	{
//		static int count = 0;
//		char letter;
//		while (text[count] != '\0')
//		{
//			string encoded;
//
//			letter = text[count];
//			for (int i = 0; i < 94; i++)
//			{
//				if ((i + 32) == letter)
//				{
//					break;
//				}
//			}
//			Encoding(root, letter, encoded);
//			count++;
//		}
//	}
//	void Encoding(Node* temp, int letter, string encoded)
//	{
//		if (temp == NULL)
//			return;
//
//		else
//		{
//			Encoding(temp->left, letter, encoded + "0");
//			Encoding(temp->right, letter, encoded + "1");
//		}
//		if (temp->alph == letter)
//		{
//			encoded += encoded;
//			cout << encoded << endl;
//			return;
//		}
//	}
//	void decoding()
//	{
//		static int count = 0;
//		while (encoded[count] != '\0')
//			decoding(root, count);
//	}
//	void decoding(Node* temp, int& count)
//	{
//		if (temp->right == NULL || temp->left == NULL)
//			cout << temp->alph;
//
//		if (encoded[count] == '1')
//		{
//			count++;
//			decoding(temp->right, count);
//		}
//		else if (encoded[count] == '0')
//		{
//			count++;
//			decoding(temp->left, count);
//		}
//	}
//	void inorder()
//	{
//		inorder(root);
//	}
//	void inorder(Node* temp)
//	{
//		if (temp == NULL)
//			return;
//		inorder(temp->left);
//		cout << temp->alph << " : " << temp->alph << " ";
//		inorder(temp->right);
//	}
//};
//
//
//int main()
//{
//	huffman obj;
//	obj.extracting_alph();
//	obj.minHeap();
//	//obj.print();
//	obj.tree();
//	obj.inorder();
//	cout << endl;
//	obj.Encoding();
//	cout << endl;
//	obj.decoding();
//	return 0;
//}