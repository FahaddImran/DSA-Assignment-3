//#include<iostream>
//#include<fstream>
//#include<vector>
//using namespace std;
//struct Node
//{
//	int freq;
//	string word;
//	Node* next;
//	Node() {
//		freq = 0;
//		word = "";
//		next = NULL;
//	}
//	Node(string w)
//	{
//		word = w;
//		next = NULL;
//		freq = 1;
//	}
//};
//class Search_Engine
//{
//	int capacity, index, size;
//	int numberOfElements;
//	int* Vector_arr;
//	vector<Node*> v1;
//public:
//
//	Search_Engine()
//	{
//		Vector_arr = new int[16]{ 11, 19 ,41, 79, 163, 317, 641, 1279, 2557, 5119, 10243,
//				 20479, 40961, 81919, 163841, 327673 };
//		for (int i = 0; i < Vector_arr[0]; i++)
//		{
//			v1.push_back(new Node());
//		}
//		index = 0;
//		numberOfElements = 0;
//		capacity = Vector_arr[index];
//
//	}
//	float load_factor() {
//		return capacity / numberOfElements;
//	}
//	void extract_alph()
//	{
//		ifstream input;
//		char letter;
//		string words = "";
//		int place;
//		input.open("encode.txt");
//		if (input.is_open())
//		{
//			while (input.get(letter))
//			{
//				if ((letter >= 48 && letter <= 63) || (letter >= 65 && letter <= 90) || (letter >= 97 && letter <= 122))
//				{
//					if (letter >= 65 && letter <= 90)
//						letter += 32;
//					words += letter;
//				}
//				else
//				{
//					words = words + '\0';
//					int sum_char = 0;
//					for (int i = 0; i < words.size(); i++)
//					{
//						if (words[i] != '-')
//							sum_char = sum_char + words[i];
//					}
//					sum_char = find_index(sum_char);
//					put(sum_char, words);
//					if (load_factor() >= 0.75) {
//						if (capacity < 200000)
//							Rehashing();
//					}
//					words.clear();
//				}
//			}
//
//		}
//	}
//	int find_index(int num)
//	{
//		num = num * 3 % capacity;
//		return num;
//	}
//	void put(int index, string words)
//	{
//		bool flag = false;
//		Node* temp = v1[index];
//		if (contain(index) == true)
//		{
//			if (words != "")
//			{
//				while (temp != NULL)
//				{
//					if (temp->word == words)
//					{
//						temp->freq++;
//						flag = true;
//						break;
//					}
//					temp = temp->next;
//				}
//
//
//				if (flag == false)
//				{
//					Node* temp = v1[index];
//					while (temp->next != NULL)
//					{
//						temp = temp->next;
//					}
//					Node* temp1 = new Node;
//					temp1->word = words;
//					temp1->freq = 1;
//					temp1->next = NULL;
//					temp->next = temp1;
//
//				}
//				numberOfElements++;
//			}
//		}
//	}
//	void Rehashing()
//	{
//		vector<Node*> V;
//		index++;
//		for (int i = 0; i < Vector_arr[index]; i++)
//		{
//			V.push_back(new Node());
//		}
//		int cap;
//		cap = capacity;
//		this->capacity = Vector_arr[index];
//		for (int i = 0; i < cap; i++) {
//			Node* temp = v1[i];
//			if (temp != NULL) {
//				if (temp->word != "")
//				{
//					while (temp != nullptr)
//					{
//						int sum_char = 0;
//						for (int i = 0; i < temp->word.size(); i++)
//						{
//							if (temp->word[i] != '-')
//								sum_char = sum_char + temp->word[i];
//						}
//						sum_char = find_index(sum_char);
//						if (V[sum_char]->next == nullptr)
//						{
//							V[index]->next = new Node(temp->word);
//						}
//						else
//						{
//							Node* temp2 = V[sum_char]->next;
//							while (temp2->next != nullptr) {
//								temp2 = temp2->next;
//							}
//							temp2->next = new Node(temp->word);
//						}
//						temp = temp->next;
//					}
//				}
//
//			}
//		}
//		this->v1 = V;
//	}
//
//	bool contain(int index)
//	{
//		if (index >= 0 && index < capacity)
//			return true;
//		else
//			return false;
//	}
//	void Delete(int index,string Word)
//	{
//		Node* temp = v1[index];
//		temp = temp->next;
//
//		while (temp != nullptr) {
//			Node* temp2 = temp;
//			temp = temp->next;
//			temp2->next = nullptr;
//			delete temp2;
//			numberOfElements--;
//		}
//		v1[index]->next = nullptr;
//		cout << endl << Word << " deleted\n";
//
//	}
//	int get(int index, string Word)
//	{
//		Node* temp = v1[index];
//		if (contain(index) == true)
//		{
//			while (temp != NULL)
//			{
//				if (temp->word == Word)
//					return temp->freq;
//
//				temp = temp->next;
//
//			}
//			cout << Word << " deleted\n";
//			return 0;
//		}
//		else
//		{
//			cout << "Entered word do not exist\n";
//			return 0;
//		}
//	}
//	void print() {
//		for (int i = 0; i < v1.size(); i++) {
//			Node* temp = v1[i];
//			if (temp->next != NULL) {
//				while (temp != NULL) {
//
//					cout << " -> " << temp->word << " : " << temp->freq;
//					temp = temp->next;
//				}
//				cout << endl;
//			}
//
//		}
//	}
//
//};
//int main()
//{
//	Search_Engine obj;
//	obj.extract_alph();
//	obj.print();
//	string input="";
//
//	while(true)
//	{
//		cout << "Write a word to get the freq" << endl << "Write '-' before your word to delete it" << endl << "Click Enter to exit" << endl << endl;
//		cin >> input;
//		
//		if (input[0]=='+')
//		{
//			break;
//		}
//		input += '\0';
//
//		int index = 0;
//		for (int i = 0; input[i] != '\0'; i++)
//		{
//			if (input[i] != '-')
//				index = index + input[i];
//		}
//		index = obj.find_index(index);
//		
//		if (input[0] == '-')
//		{
//			obj.Delete(index, input);
//		}
//		else
//		{
//			int freq = 0;
//			freq = obj.get(index, input);
//			cout << input << " appears " << freq << " times\n";
//		}
//
//	}
//	return 0;
//}