#include <iostream>
#include <string>

using namespace std;


	int main()
	{
		cout << "what to find?";
		string from;
		getline(cin, from);
		string to;
		cout << "what to replace?";
		getline(cin, to);
		string sentence;
		cout << "sentence to find";
		getline(cin, sentence);
		while (sentence.find(from) != string::npos) {
			sentence.replace(sentence.find(from), from.size(), to);
			if (to.find(from) != string::npos)
				break;
		}
		// change all occurrences of 'from' into 'to' in the sentence
		cout << sentence << "\n";
	
    return 0;
}