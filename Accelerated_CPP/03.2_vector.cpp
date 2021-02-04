#include <iostream>
#include <string>
#include <vector>

using std::cout;    using std::cin;
using std::endl;    using std::string;
using std::vector;

int main(int argc, char* argv[]){
    typedef vector<string>::size_type sz;
    vector<string> v_words;
    vector<int> v_cnt;
    string x;
    int wordPos;

    cout << "Please enter the words list (end with EOF): ";

    while (cin >> x) {
	sz i = 0;
	wordPos = -1;

        for (sz i = 0; i < v_words.size(); i++) {
            if (v_words[i] == x) {
                wordPos = i;
		break;
            }
	}

	if (wordPos == -1) {
            v_words.push_back(x);
	    v_cnt.push_back(1);
	} else {
	    v_cnt[wordPos]++;
	}
    }

    if (v_words.size() == 0){
	    cout << endl << "List is empty!" << endl;
    }

    for (sz i = 0; i < v_words.size(); i++) {
	    cout << "word " << v_words[i] << " meets " << v_cnt[i] << " times." << endl;
    }

    return 0;
}
