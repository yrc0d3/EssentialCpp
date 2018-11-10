#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <string>

using namespace std;

void init_exclusion_set(set<string> &s)
{
	static string _excluded_words[26] = {
		"the","and","but","that","then","are","been",
		"can","a","could","did","for", "of",
		"had","have","him","his","her","its","is", 
		"were","which","when","with","would"
	};
	s.insert(_excluded_words, _excluded_words + 26);
}

void process_file(ifstream &ifile, map<string, int> &m, set<string> &s)
{
	string word;
	while (ifile >> word) {
		if (s.count(word))
			continue;
		m[word]++;
	}
}

void user_query(map<string, int> &m)
{
	string word;
	cout << "Please enter a word to search:";
	cin >> word;
	map<string, int>::const_iterator it = m.begin();
	map<string, int>::const_iterator end_it = m.end();
	for (; it != end_it; it++) {
		if (it->first == word) {
			cout << word << " is found!\n";
			return;
		}
	}
	cout << word << " is not found.\n";
}

void display_word_count(map<string, int> &m, ofstream &os)
{
	map<string, int>::const_iterator it = m.begin();
	map<string, int>::const_iterator end_it = m.end();
	for (; it != end_it; it++) {
        os << it->first << " => " << it->second << endl;
	}
}

int main()
{
    ifstream ifile("3.1.txt");
    ofstream ofile("3.1.map");
    
    if (!ifile || !ofile) {
        cout << "Unable to open file!\n";
        return -1;
    }

    set<string> exclusion_set;
	init_exclusion_set(exclusion_set);

    map<string, int> word_count;
	process_file(ifile, word_count, exclusion_set);

	user_query(word_count);
    display_word_count(word_count, ofile);

    return 0;
}
