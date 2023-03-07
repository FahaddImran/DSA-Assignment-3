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
//		input.open("encoded.txt");
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
//			encodedVector_array[i]=freq[i] ;
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
//	void heapify(int Vector_arr[], int size, int num)
//	{
//
//		int max = num;
//		int left = 2 * num + 1;
//		int right = 2 * num + 2;
//
//		if (left < size && Vector_arr[left] > Vector_arr[max])
//			max = left;
//
//		if (right < size && Vector_arr[right] > Vector_arr[max])
//			max = right;
//
//		if (max != num) 
//		{
//			swap(Vector_arr[num], Vector_arr[max]);
//
//			heapify(Vector_arr, size, max);
//		}
//	}
//
//	void minHeap()
//	{
//		int num = size;
//		sorted_Vector_array = new int[size];
//		for (int j = 0, i = 0; i < 94; i++)
//		{
//			if (freq[i] != 0)
//			{
//				sorted_Vector_array[j] = freq[i];
//				j++;
//			}
//		}
//
//		for (int i = num / 2 - 1; i >= 0; i--)
//			heapify(sorted_Vector_array, num-1, i);
//
//		for (int i = num - 1; i > 0; i--) {
//
//			swap(sorted_Vector_array[0], sorted_Vector_array[i]);
//			heapify(sorted_Vector_array, i, 0);
//		}
//		
//
//	}
//	void print()
//	{
//		for (int i = 0; i < size; i++)
//		{
//			cout<<sorted_Vector_array[i] << " ";
//		}
//	}
//	int minimumimum()
//	{
//		
//		int minimum = 0, count = 0;
//		for (int i = 0; i < size; i++)
//		{
//			if (sorted_Vector_array[i] != 0)
//			{
//				count = i;
//				minimum = sorted_Vector_array[i];
//				break;
//			}
//		}
//		sorted_Vector_array[count] = 0;
//		return minimum;
//	}
//	
//	void tree()
//	{
//		static int num = 0;
//	    bool flag = false;
//
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
//					    freq[i] = 0;
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
//			tree();
//
//	}
//
//	void Encoding()
//	{
//		static int count = 0, freq = 0;
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
//			Encoding(root, letter,encoded);
//			count++;
//		}
//	}
//	void Encoding(Node* temp,int letter,string encoded)
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
//		}
//	}
//	void decoding()
//	{
//		static int count = 0;
//		while(encoded[count]!='\0')
//		decoding(root,count);
//	}
//	void decoding(Node* temp,int& count)
//	{
//		if (temp->right == NULL||temp->left==NULL)
//			cout << temp->alph;
//
//		if (encoded[count] == '1')
//		{
//			count++;
//			decoding(temp->right,count);
//		}
//		else if (encoded[count] == '0')
//		{
//			count++;
//			decoding(temp->left,count);
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
//		cout << temp->alph<<" : "<<temp->alph<<" ";
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
//	obj.print();
//	obj.tree();
//	obj.inorder();
//	cout << endl;
//	obj.Encoding();
//	cout << endl;
//	obj.decoding();
//	return 0;
//}