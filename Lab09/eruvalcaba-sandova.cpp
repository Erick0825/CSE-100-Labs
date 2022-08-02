#include <iostream>
#include <bits/stdc++.h>
using namespace std;

string a = "";
string b = "";
string c = "";
string d = "";
string e = "";
string f = "";

struct MinHeap{
char data;
size_t q;
MinHeap *left; 
MinHeap *right; 
    MinHeap(char data, unsigned q){
		left = NULL; 
        right = NULL;
		this-> data = data;
		this-> q = q;
	}
};
struct compare{
	bool operator()(MinHeap* l, MinHeap* r){
		return (r->q < l->q);
	}
};
void PrintTree(struct MinHeap* root, string str){
	if(root->data == 'A'){
		a += "A:" + str;
	}
	else if(root->data == 'B'){
		b += "B:" + str;
	}
	else if(root->data =='C'){
		c += "C:" + str;
	}
	else if(root->data =='D'){
		d += "D:" + str;
	}
	else if(root->data =='E'){
		e += "E:" + str;
	}
	else if(root->data =='F'){
		f += "F:" + str;
	}
    else if (root == NULL) {
        return;
    }
	else if (root -> data = '$'){       
        if (root -> left) {
	        PrintTree(root->left, str + "0");
        }
        if (root -> right) {
	        PrintTree(root->right, str + "1");
        }
	} 
    else {
        exit;
    }
}
void Huffman(char data[], int freq[]){
	struct MinHeap *left, *right, *top;
	priority_queue<MinHeap*, vector<MinHeap*>, compare> h_tree;

    int i = 0;
    while (i < 6) {
        h_tree.push(new MinHeap(data[i], freq[i]));
        i++;
    }
    while(h_tree.size() > 1){
		left = h_tree.top();
		h_tree.pop();
		right = h_tree.top();
		h_tree.pop();
		top = new MinHeap('$', right->q + left ->q);
		top->left = left;
		top->right = right;
		h_tree.push(top);
	}   
    PrintTree(h_tree.top(), "");
}
void PrintPrintTree() {
    cout << a << endl;
	cout << b << endl;
	cout << c << endl;
	cout << d << endl;
	cout << e << endl;
	cout << f << endl;
}
int main(){
	int queue[6]; 
	int input;
    char arr[] = {'A','B','C','D','E','F'};
    for (int i = 0; i < 6; i++){
		cin >> queue[i];
	}
	Huffman(arr , queue);	
    PrintPrintTree();
}