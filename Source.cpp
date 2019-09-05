#include <string>
#include <iostream>

const int MAX_CHICKENS = 100;
//const int MAX_LIVECHICKENS = 100;
//const int MAX_DEADCHICKENS = 100;

int nextChickenId=-2;

//int nextLiveChickenId = -1;
int LiveChickensCount = -1;
int CurrentLiveChicken = NULL;

//int DeadChickensCount = NULL;
//int CurrentDeadChicken = NULL;

using namespace std;

// Returns nextChickenId and increments by 1
int GetNextChickenId(void) {
	return nextChickenId++;
};


enum gender {
	unsexed = 0,
	male	= 1,
	female	= 2
};

/*Life states:
0 = unknown
1 = egg
2 = juvenile
3 = adult
4 = elder
5 = dead*/
enum lifeState {
	unknown = 0,
	egg = 1,
	juvenile = 2,
	adult = 3,
	elder = 4,
	dead = 5
};

class chicken {
private:
	int Id;
	string Name;
	gender Gender;
	chicken* Mother;
	chicken* Father;
	lifeState LifeState;


public:
	// Default Constructor
	// Full init
	 chicken(string name, gender gender, chicken* mother, chicken* father, lifeState lifeState) { 
		Id = GetNextChickenId();
		Name = name;
		Gender = gender;
		Mother = mother;
		Father = father;
		LifeState = lifeState;
		LiveChickensCount++;
	};
	 chicken(void) {
		 Id = NULL;
		 Name = "";
		 Gender = unsexed;
		 Mother = nullptr;
		 Father = nullptr;
		 LifeState = unknown;
	 };
	 int getId(void) {
		return Id;
	};
	string getName(void) {
		return Name;
	};
	bool setName(string name) {
		Name = name;
	};
	chicken* getMother(void) {
		return Mother;
	};
	bool setMother(chicken* mother) {
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
	lifeState getLifeState(void) {
		return LifeState;
	};
	bool setLifeState(lifeState lifeState) {
		LifeState = lifeState;
	};
};


int main(int argc, char * argv[]) {

	// Create the father of everything (Id = -1 )
	chicken* godChicken = new chicken("God", unsexed, nullptr, nullptr, unknown);

	// Array for all MORTAL chickens
	chicken* chickens[MAX_CHICKENS];

	chicken** ptrChickens = chickens;

	// Create first breeding pair
	chickens[nextChickenId] = new chicken("Adam", male, godChicken, godChicken, adult);
	chickens[nextChickenId] = new chicken("Eve", female, godChicken, godChicken, adult);

	int y = 0;

	for (int x = 0; x < LiveChickensCount; x++) {
		// NB: whitespace exists at the end of each line.  Whitespace between strings is concatenated.
		chicken* c = chickens[x];

		printf("ptrChickens[%d]\n" 
			"Id = %d;\n" 
			"Name = %s;\n" 
			"Gender = xxx;\n" 
			"Mother = xxx;\n" 
			"Father = xxx;\n"                                     // use of ".c_str()" required to render strings
			"LifeState = unknown;\n\n", x, c->getId(), c->getName().c_str(), c->getGender());
			//c.getId(), c.getName());

	}
		return 0;
	
}