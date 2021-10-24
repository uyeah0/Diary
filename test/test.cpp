#include<iostream>
#include<string>
using namespace std;


int main() {
	char ch[255];
	string body;
	string line;
	while (true) {
		getline(cin, line);
		if (line.compare("***") == 0)
			break;
		body += line;
	}

	//while (true) {
	//	fgets(ch, 255, stdin);
	//	if (ch[0] == '*' && ch[1] == '*' && ch[0] == '*')break;
	//	body += ch;

	//}
	cout << body;
	
}