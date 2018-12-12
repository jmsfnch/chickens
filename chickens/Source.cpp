#include <string>
#include <iostream>


using namespace std;

enum gender {
	male=0,
	female=1
};

class chicken {
	int id;
	string name;
	chicken *ptrChickenMother;
	chicken *ptrChickenFather;
	gender gender;
};

int main(int argc, char * argv[]) {
	cout << "Hello world!";
	return 0;
}