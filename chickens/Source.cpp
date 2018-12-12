#include <string>
#include <iostream>

const int MAX_CHICKENS = 100;
const int MAX_LIVECHICKENS = 100;
const int MAX_DEADCHICKENS = 100;

int nextChickenId=-1;

int nextLiveChickenId = -1;
int LiveChickensCount = -1;
int CurrentLiveChicken = NULL;

int DeadChickensCount = NULL;
int CurrentDeadChicken = NULL;

using namespace std;

int GetNextChickenId(void) {
	return nextChickenId++;
};


enum gender {
	male=0,
	female=1
};

class chicken {
private:
	int Id;
	string Name;
	gender Gender;
	chicken* Mother;
	chicken* Father;


public:
	chicken(void) {
		/// Default Constructor
		Id = GetNextChickenId();
		Name = "unknown";
		//Gender =;
		Mother = nullptr;
		Father = nullptr;
		LiveChickensCount++;
	};
	chicken(string name, gender gender, chicken* mother, chicken* father) { 
		Id = GetNextChickenId();
		Name = name;
		Gender = gender;
		Mother = mother;
		Father = father;
	};
	string getName(void) {
		return Name;
	};
	void setName(string name) {
		Name = name;
	};
	chicken* getMother(void) {
		return Mother;
	};
	void setMother(chicken* mother) {
		Mother = mother;
	};
	chicken* getFather(void) {
		return Father;
	};
	bool setFather(chicken* father) {
		Father = father;
	};
	gender getGender(void) {
		return Gender;
	};
	bool setGender(gender gender) {
		Gender = gender;
	};
};


int main(int argc, char * argv[]) {
	cout << "Hello world!";


	// Create the father of everything (Id = -1 )
	chicken* godChicken = new chicken("God", male, nullptr, nullptr);

	// Create array for all MORTAL chickens

	chicken* ptrChickens;
	ptrChickens = new chicken[MAX_CHICKENS];

	// Create array for all LIVE chickens

	chicken* ptrLiveChickens;
	ptrLiveChickens = new chicken[MAX_CHICKENS];

	// Create first breeding pair

	ptrChickens[nextChickenId] = chicken("Adam", male, godChicken, godChicken);
	ptrChickens[nextChickenId] = chicken("Eve", female, godChicken, godChicken);




	return 0;
}