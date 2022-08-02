#include <iostream>
#include <sstream>
#include <list>
using namespace std;

void ins(list<int>* tab, int key, int m) {
	
    int h = key % m;
	tab[h].push_front(key);
}
void del(list<int>* tab, int key, int m) {

	int h = key % m;
    int i = 0;
    bool success;
	list<int>::iterator step;

	for (step = tab[h].begin(); step != tab[h].end(); step++) {
		if (*step == key) {
			list<int>::iterator step2 = tab[h].begin();
			advance(step2, i);
			tab[h].erase(step2);
			cout << key << ":DELETED;" << endl;
            success = true;
			break;
		}
		i++;
	}
	if (success == false)
		cout << key << ":DELETE_FAILED;" << endl;
}
void search(list<int>* tab, int key, int m) {

	int h = key % m;
    int i = 0;
    bool success;
	list<int>::iterator step;

	for (step = tab[h].begin(); step != tab[h].end(); step++) {
		if (*step == key) {	
			cout << key << ":" << "FOUND_AT" << h << "," << i << ";" << endl;
			success = true;
			break;
		}
		i++;
	}
	if (success == false)
		cout << key << ":NOT_FOUND;" << endl;
}

void output(list<int>* tab, int m) {

	list<int>::iterator step;
    
	for (int i = 0; i < m; i++) {
		cout << i << ":";

		for (step = tab[i].begin(); step != tab[i].end(); step++)
			cout << *step << "->";
		
        cout << ";" << endl;
	}
}
int main(int argc, const char ** argv) {
	int m;
    char c[50];
	cin >> m;
	list<int>* tab = new list<int>[m];

	while (cin.getline(c, 50)) {
		string str(c);
        int key;
        
        if(str.size() == 0)
			continue;

		stringstream abc(str.substr(1, str.size() - 1));

		if (!(abc >> key))
			key = -1;

		if (str.substr(0, 1) == "i")
			ins(tab, key, m);

		if (str.substr(0, 1) == "d")
			del(tab, key, m);

		if (str.substr(0, 1) == "s")
			search(tab, key, m);

        if (str.substr(0, 1) == "o") {
			output(tab, m);
			continue;
		}

        if (str.substr(0, 1) == "e")
			return 0;

	}
	delete[] tab;

	return 0;
}