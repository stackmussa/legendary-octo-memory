#ifndef CLASSES_H
#define CLASSES_H
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <ctime>
#include <fstream>
#include <cmath>
using namespace std;

//Name: Mussa Raza, Roll Number: 24I-3022, Project#1

void clearCin() {
	cin.clear();
	while (cin.get() != '\n');
}
class Pet {
protected:
	int HP;
	int MaxHP;
	int TrainingPoints;
	int Defense;
	int AttackPower;
	int Speed;
	int Level;
	int stun;
	int petCount;
	bool isStun;
	string Abt[2];
	string Name;
	string ROLE;
	string Type;
	
public:
	Pet(int Defense, int Speed, int Attack, int HP, string Name, string Type) :
		HP(HP), MaxHP(HP), Defense(Defense), Speed(Speed), Name(Name)
		, Type(Type), TrainingPoints(1), Level(1), AttackPower(Attack), petCount(0), isStun(false), stun(1) {
	}
	
	int getHP() {
		return HP;
	}
	int getpetCount() {
		return petCount;
	}
	void lostTP() {
		TrainingPoints = TrainingPoints + 1;
	}
	bool getStun() {
		return isStun;
	}
	int getMaxHP() {
		return MaxHP;
	}
	int getTrainingPoints() {
		return TrainingPoints;
	}int getDefense() {
		return Defense;
	}
	int getAttackPower() {
		return AttackPower;
	}
	int getSpeed() {
		return Speed;
	}
	int getLevel() {
		return Level;
	}
	string getName() {
		return Name;
	}
	string getType() {
		return Type;
	}
	void setRole(string role) {
		ROLE = role;
	}
	string getRole() {
		return ROLE;
	}
	void decrementStun() {
		if (isStun) {
			stun--;
			if (stun <= 0) {
				isStun = false;
				cout << Name << " is no longer stunned." << endl;
			}
		}
	}
	void levelUp() {
		Level = Level + 1;
		HP = MaxHP;
		Defense = Defense + 2;
		Speed = Speed + 1;
		TrainingPoints = TrainingPoints + 3;
		AttackPower = AttackPower + 2;
	}
	void setHP(int HP) {
		this->HP = HP;
	}
	void setMaxHP(int MaxHP) {
		this->MaxHP = MaxHP;
	}
	void setTrainingPoints(int TrainingPoints) {
		this->TrainingPoints = TrainingPoints;
	}
	void setDefense(int Defense) {
		this->Defense = Defense;
	}
	void setAttackPower(int AttackPower) {
		this->AttackPower = AttackPower;
	}
	void setSpeed(int Speed) {
		this->Speed = Speed;
	}
	void DealDamage(int damage) {
		HP = HP - damage;
		if (HP < 0) {
			HP = 0;
		}
	}
	void setName(string Name) {
		this->Name = Name;
	}
	void setType(string Type) {
		this->Type = Type;
	}
	void setStun(bool isStun) {
		this->isStun = isStun;
	}
	void DefenseManagement(int amount) {
		Defense = Defense + amount;
		if (Defense < 0) {
			Defense = 0;
		}
	}
	void AttackManagement(int amount) {
		AttackPower = AttackPower + amount;
		if (AttackPower < 0) {
			AttackPower = 0;
		}
	}
	void SpeedManagement(int amount) {
		Speed = Speed + amount;
		if (Speed < 0) {
			Speed = 0;
		}
	}
	void HealHP(int amount) {
		HP = HP + amount;
		if (HP > MaxHP) {
			HP = MaxHP;
		}
	}
	void Attack(Pet& opponent) {
		if (isStun == true) {
			cout << opponent.getName() << " Has been Stunned by " << Name << endl;
			stun -= 1;
			if (stun <= 0) {
				isStun = false;
				cout << Name << " is not Stunned anymore & can attack." << endl;
			}
		}
		int damage = abs (AttackPower - (opponent.getDefense()/2));
		//int damage = abs(AttackPower);

		if (damage < 0) {
			damage = 0;
		}
		opponent.DealDamage(damage);
		cout << Name << " attacks " << opponent.getName() << " &  deals " << damage << " damage" << endl;
	}
	// a pure virtual function that show that the class is abstract, and further classes would define it
	virtual void UseAbility(Pet& opponent, int flag) = 0;
	
	void trainPET() {
		if (TrainingPoints <= 0) {
			cout << "No Sufficient Training Points Available in order to train, Engange in some Battles to add Points." << endl;
			return;
		}
		else {
			int option;
			do {

				cout << "Press 1 to increase Health." << endl;
				cout << "Press 2 to increase Attack." << endl;
				cout << "Press 3 to increase Defense," << endl;
				cout << "Press 4 to increase Speed." << endl;
				cout << "Press 5 to Go Back to Main Menu." << endl;
				cout << "Enter your choice: ";
				cin >> option;
				switch (option) {
				case 1:
					MaxHP = MaxHP + 5;
					HP = HP + 5;
					TrainingPoints = TrainingPoints - 1;
					cout << "Yay!! " << Name << " has been increased in Health by 5." << endl;
					cout << Name << "'s Max Health is now: " << MaxHP << endl;
					cout << Name << "'s Current Health is now: " << HP << endl;
					break;
				case 2:
					AttackPower = AttackPower + 5;
					TrainingPoints = TrainingPoints - 1;
					cout << "Yay!! " << Name << " has been increased in Attack by 5." << endl;
					cout << Name << "'s Attack Power is now: " << AttackPower << endl;
					break;
				case 3:
					Defense = Defense + 5;
					TrainingPoints = TrainingPoints - 1;
					cout << "Yay!! " << Name << " has been increased in Defense by 5." << endl;
					cout << Name << "'s Defense is now: " << Defense << endl;
					break;
				case 4:
					Speed = Speed + 5;
					TrainingPoints = TrainingPoints - 1;
					cout << "Yay!! " << Name << " has been increased in Speed by 5." << endl;
					cout << Name << "'s Speed is now: " << Speed << endl;
					break;
				case 5:
					cout << "Going Back to Menu." << endl;

					return;
					break;
				}
				if (TrainingPoints <= 0) {
					cout << "No more training points remaining!" << endl;
					return;
				}
			} while (option != 5);
		}

	}
	void Stuned(int num, Pet& opponent) {
		opponent.isStun = true;
		opponent.stun = num;
		cout << opponent.getName() << " has been stunned for " << num << " turns and cannot attack till it." << endl;
	}
	void displayStats() {

		cout << endl << endl << "Current Statistics of Pet Type: " << Type << endl << endl;
		cout << "Pet's Name is: " << Name << endl;
		cout << "Pet's Type is: " << Type << endl;
		cout << "Pet's HP is: " << HP << "/" << MaxHP << endl;
		cout << "Pet's Attack Power is: " << AttackPower << endl;
		cout << "Pet's Defense: " << Defense << endl;
		cout << "Pet's Speed is: " << Speed << endl;
		cout << "Pet's Level is : " << Level << endl;
		cout << "Pet's Training Points is: " << TrainingPoints << endl;
		cout << "Pet's Attributes are the Following: -" << endl << endl;
		for (int i = 0; i < 2; i++) {
			cout << Abt[i] << ", ";
		}
		if (isStun) {
			cout << endl;
			cout << Name << " would be left stunned for " << stun << " turns." << endl;
		}

	}
	//Operator Overloading in order to determine the faster pet between 2.
	bool operator>(const Pet& other) const {
		return Speed > other.Speed;
	}
	~Pet() {
		
	}
};


class Dragon : public Pet {
public:
	// passing supposidly the values of the dragon Defense, Speed ,Attack, HP
	Dragon(string Name) : Pet(14, 12, 25, 110, Name, "Dragon") {
		Abt[0] = "Fireball";
		Abt[1] = "Dragon's Roar";
	}
	void UseAbility(Pet& opponent, int flag) override {
		//	srand(time(0));
		// by taking random it means that the ability would be used randomly according to the Game Scenario for AI
		// else user asked for Player
		int Choice;
		
		if (flag == 1) {
			do {
				cout << endl << "Press 1 to Use Fireball Ability." << endl;
				cout << "Press 2 to Use Dragon's Roar Ability." << endl;
				cout << "Enter your choice: ";
				cin >> Choice;
				
			} while (Choice < 1 || Choice >2);
		}
		else {
			Choice = rand() % 2 + 1;
		}
		if (Choice == 1) {
			cout << Name << " uses Fireball Ability on " << opponent.getName() << "." << endl;
			int damage = static_cast<int>(AttackPower * 1.4);
			opponent.DealDamage(damage);
			cout << opponent.getName() << " deals with  " << damage << " amount of damage!" << endl;
		}
		else {
			cout << Name << " uses Dragon's Roar Ability on " << opponent.getName() << "." << endl;
			Stuned(2, opponent);
		}
	}
	
};
class Phoenix : public Pet {
protected:
	bool rebirth;
public:
	// passing supposidly the values of the dragon Defense, Speed , Attack, HP, rebirth being true is due to the availability of 1 re spawn
	Phoenix(string Name) : Pet(30, 10, 34, 95, Name, "Pheonix"), rebirth(true) {
		Abt[0] = { "Flame Healing" };
		Abt[1] = { "Rebirth" };
	}
	void UseAbility(Pet& opponent, int flag) {
		//srand(time(0));
		// by taking random it means that the ability would be used randomly according to the Game Scenario for AI
		// else user asked for Player
		int Choice;
		if(flag == 1){
			do {
				cout << endl << "Press 1 to Use Flame Healing Ability." << endl;
				cout << "Press 2 to Use Rebirth Ability." << endl;
				cout << "Enter your choice: ";
				cin >> Choice;
			} while (Choice < 1 || Choice >2);
		}
		else {
			Choice = rand() % 2 + 1;
		}
		if (Choice == 1) {
			cout << Name << " uses Flame Healing Ability."  << endl;
			int heal = 20;
			HP = HP + heal;
			if (HP > MaxHP) {
				HP = MaxHP;
			}
			cout << Name << " heals for " << heal << " amount of HP: " << HP << "/" << MaxHP << endl;
		}
		else {
			bool check = rebirthAvailablility();
			if (!rebirth) {
				cout << Name << " has already used Rebirth Ability." << endl;
			}
			else if ( HP <=0) {
				cout << Name << " uses Rebirth Ability!" << endl;
				rebirth = false;
				HP = MaxHP / 2;
				cout << Name << " has been reborn with " << HP << " HP!" << endl;
			}
			else {
				cout << Name << " has already used Rebirth Ability!" << endl;
			}
		}
	}
	bool rebirthAvailablility() const {
		return rebirth;
	}



};

class Unicorn : public Pet {
public:
	// passing supposidly the values of the dragon Defense, Speed ,Attack, HP
	Unicorn(string Name) : Pet(17, 30, 17, 70, Name, "Unicorn") {
		Abt[0] = { "Speed Burst" };
		Abt[1] = { "Magic Shield" };
	}
	void UseAbility(Pet& opponent, int flag) override {
		//srand(time(0));
		// by taking random it means that the ability would be used randomly according to the Game Scenario for AI
		// else user asked for Player
		int Choice ;
		if (flag == 1){
			do {
				cout << endl << "Press 1 to Use Speed Burst Ability." << endl;
				cout << "Press 2 to Use Magic Shield Ability." << endl;
				cout << "Enter your choice: ";
				cin >> Choice;
			} while (Choice < 1 || Choice >2);
		}
		else{
			Choice = rand() % 2 + 1;
		}
		if (Choice == 1) {
			cout << Name << " uses Speed Burst Ability on " << opponent.getName() << endl;
			int speedPlus = 10;
			Speed = Speed + speedPlus;
			cout << Name << "'s Speed increased to " << Speed << endl;
		}
		else {
			cout << Name << " uses Magic Shield Ability on " << opponent.getName() << endl;
			int defensePlus = 10;
			Defense = Defense + defensePlus;
			cout << Name << "'s Defense increased to " << Defense << endl;
		}
	}
	
};

class Griffin : public Pet {
protected:

public:
	// passing supposidly the values of the dragon Defense, Speed ,Attack, HP
	Griffin(string Name) : Pet(15, 15, 15, 100, Name, "Griffin") {
		Abt[0] = { "Claw Strike" };
		Abt[1] = { "Dive Bomb" };
	}
	void UseAbility(Pet& opponent, int flag) override {
		//srand(time(0));
		// by taking random it means that the ability would be used randomly according to the Game Scenario for AI
		// else user asked for Player
		int Choice;
		if (flag == 1){
			do {
				cout << endl << "Press 1 to Use Claw Strike Ability." << endl;
				cout << "Press 2 to Use Dive Bomb Ability." << endl;
				cout << "Enter your choice: ";
				cin >> Choice;
				
			} while (Choice < 1 || Choice >2);
		}
		else {
			Choice = rand() % 2 + 1;
		}
		if (Choice == 1) {
			cout << Name << " uses Claw Strike Ability on " << opponent.getName() << endl;
			int damage = static_cast<int>(AttackPower * 1.8);
			opponent.DealDamage(damage);
			cout << opponent.getName() << " deals with  " << damage << " amount of damage" << endl;
		}
		else {
			cout << Name << " uses Dive Bomb Ability on " << opponent.getName() << "!" << endl;
			int damage = static_cast<int>(AttackPower * 1.3);
			opponent.DealDamage(damage);
			opponent.Stuned(1, *this);
		}

	}
	
};





class Guild {
private:
	string Name;

	int memberCount;
	Pet* memberPets[10];
	//Player* Leader;
	string role;
	string roles[3] = { "tank", "healer", "damage dealer" };
public:
	Guild(string Name) : Name(Name), memberCount(0){
		
		for (int i = 0; i < 10; i++) {
			memberPets[i] = NULL;
		}	
	}
	string getName() {
		return Name;
	}
	void AddMember(Pet* pet, int roleIndex) {
		if (memberCount >= 10) {
			cout << "The Guild Is Full!" << endl;
			return;
		}

		else {
			pet->setRole(roles[roleIndex]);
			memberPets[memberCount] = pet;
			memberCount = memberCount + 1;
			cout << "The Pet " << pet->getName() << " has been added to the Guild & Role is: " << pet->getRole() << endl;
		}
		
	}
	

	void ViewMembers() {
		if (memberCount >= 3) {
			for (int i = 0; i < memberCount; i++) {
				memberPets[i]->displayStats();
				cout << "The Role of " << memberPets[i]->getName() << " is : " << memberPets[i]->getRole() << endl;
			}
		}
		else {
			cout << "Atleast, there should be 3 Pets to form a Guild.";
			return;
		}
	}
	void engangeWar(string name, Guild oppoenent) {
		cout << name << " Guild is Engaging in War with " << oppoenent.getName() << " Guild." << endl;
	}
	void Rewards() {
		for (int i = 0; i < memberCount; i++) {
			memberPets[i]->levelUp();
			cout << memberPets[i]->getName() << " has leveled up!" << endl;
		}
	}
	int getMemberCount() const { return memberCount; }
	Pet* getMember(int index) const {
		return (index >= 0 && index < memberCount) ? memberPets[index] : NULL;
	}
	~Guild() {
		
		for (int i = 0; i < 10; i++) {
        memberPets[i] = NULL;
    }
	}
};
class Player {
private:
	int ID;
	int GUILDWINS;
	int wins;
	int Money;
	int LEVEL;
	int itemCount;
	int PetCount;
	int GuildCount;
	int GuildID;
	int WIN1v1;
	int WIN2v2;
	Guild* guilds[10];
	struct inventoryItems {
		string Name;
		int Quantity;
	};
	inventoryItems inventory[4];
	Pet* pets[10];
	string Name;
	string GuildName;
	

public:
	Player(string Name, int ID) : Name(Name), ID(ID), Money(1000), LEVEL(1), GUILDWINS(0), itemCount(4), PetCount(0), GuildCount(0), GuildID(0) {
		// Initialize guilds and pets to nullptr
		for (int i = 0; i < 10; i++) {
			pets[i] = NULL;
		}
		for (int i = 0; i < 10; i++) {
			guilds[i] = NULL;
		}
		inventory[0] = { "Health Potion", 3 };
		inventory[1] = { "Attack Boost", 2 };
		inventory[2] = { "Defense Boost", 2 };
		inventory[3] = { "Speed Boost", 1 };
	}
	void LevelUP() {
		LEVEL = LEVEL + 1;
	}
	void AddWins() {
		wins = wins + 1;
	}
	void Add1v1Wins() {
		WIN1v1 = WIN1v1 + 1;
	}
	void Add2v2Wins() {
		WIN2v2 = WIN2v2 + 1;
	}
	int getWins() {
		return wins;
	}
	int get1v1Wins() {
		return WIN1v1;
	}
	int get2v2Wins() {
		return WIN2v2;
	}
	void setGuildName(string gn) {
		GuildName = gn;
	}
	string getGuildName() {
		return GuildName;
	}
	int getPetCount() {
		return PetCount;
	}
	int getMoney() {
		return Money;
	}
	string getName() {
		return Name;
	}
	int getPlayerLevel() {
		return LEVEL;
	}
	void addMoney(int amount) {
		Money = Money + amount;
	}
	void displayPet() {
		if (PetCount == 0) {
			cout << "Player Shall Adopt Some Pets Before." << endl << endl;
		}
		else {
			for (int i = 0; i < PetCount; i++) {
				pets[i]->displayStats();
				cout << endl;
			}
		}
	}

	void AdoptPet(Pet* pet) {
		// function to Adopt a pet
		if (PetCount < 10) {
			pets[PetCount] = pet;
			PetCount = PetCount + 1;
			cout << Name << " has adopted a new pet: " << pet->getName() << endl;
		}
		else {
			cout << "No more Space to accomodate Pets." << endl;
			delete pet;
		}
	}
	Pet* getPet(int index) {
		//returns a pet, when asked
		if (index >= 0 && index < PetCount) {
			return pets[index];
		}
		else {
			cout << "Invalid index." << endl;
			return NULL;
		}
	}
	
	void TrainPets() {
		if (PetCount == 0) {
			cout << "Player Shall Adopt Some Pets Before." << endl << endl;
			return;
		}
		displayPet();
		cout << "Select pet to train (1-" << PetCount << "): ";
		int choice;
		while (!(cin >> choice) || choice < 1 || choice > PetCount) {
			cout << "Invalid input. Please try again: ";
			clearCin();
		}

		Pet* pet = pets[choice - 1];

		if (pet->getTrainingPoints() <= 0) {
			cout << pet->getName() << " has no training points available!" << endl;
			return;
		}
		pet->trainPET();
		
	}


	void DisplayInventory() {
		// displaying inventory
		cout << "Player's Inventory:" << endl;
		cout << "Money in Wallet: $" << Money << endl;
		for (int i = 0; i < itemCount; i++) {
			cout << i + 1 << " Name: " << inventory[i].Name << ", Quantity: " << inventory[i].Quantity << endl;
		}
	}
	void UtilizeItem(string item, Pet*& pet) {
		// this function would help us in terms of utilizing and item between the fights
		bool found = false;
		int index = -1;
		for (int i = 0; i < itemCount; i++) {
			if (inventory[i].Name == item) {
				index = i;
				break;
			}
		}
		if (index == -1 || inventory[index].Quantity <= 0 ) {
			cout << "Cannot use the item " << item << " as it is not available in the inventory." << endl;
			return;
		}
		if (item == "Health Potion" || item == "1") {
			pet->HealHP(40);
			inventory[index].Quantity = inventory[index].Quantity - 1;
			cout << "HP Boosted by " << 40 << ", HP of the Pet is now: " << pet->getHP() << endl;
		}
		else if (item == "Attack Boost" || item == "2") {
			pet->AttackManagement(12);
			inventory[index].Quantity = inventory[index].Quantity - 1;
			cout << "Attack Boosted by " << 12 << ", Attack Power of the Pet is now: " << pet->getAttackPower() << endl;
		}
		else if (item == "Defense Boost" || item == "3") {
			pet->DefenseManagement(10);
			inventory[index].Quantity = inventory[index].Quantity - 1;
			cout << "Defense Boosted by " << 10 << ", Defense of the Pet is now: " << pet->getDefense() << endl;
		}
		else if (item == "Speed Boost" || item == "4") {
			pet->SpeedManagement(8);
			inventory[index].Quantity = inventory[index].Quantity - 1;
			cout << "Speed Boosted by " << 8 << ", Speed of the Pet is now: " << pet->getSpeed() << endl;
		}
		else {
			cout << "Invalid item name." << endl;
		}
	}
	void AddToInventory(int index) {
		//Handing Things to add into the inventory
		if (index >= 0 && index < 4) {
			inventory[index].Quantity = inventory[index].Quantity + 1;
			cout << "Successfully Added " << inventory[index].Name << " to inventory\n. Quantity is: " << inventory[index].Quantity << endl;
		}
		else {
			cout << "Invalid item index." << endl;
		}
	}
	void AssembleGuild() {
		// Creation of Guild Starts from here
		if (PetCount >= 3) {
			cout << "Assign Your Guild a Name: ";
			cin.ignore();
			getline(cin, GuildName);
			guilds[GuildCount++] = new Guild(GuildName);
			cout << "Guild " << GuildName << " has been created." << endl;
		}
		else {
			cout << "There Should Be Atleast 3 Pets to Encounter in a Guild." << endl;
		}
	}
	void AddPetsToGuild() {
		if (GuildCount == 0) {
			cout << "Player Shall Create a Guild Before." << endl << endl;
			return;
		}
		cout << "Select a guild first:" << endl;
		for (int i = 0; i < GuildCount; i++) {
			cout << i + 1 << ": " << guilds[i]->getName() << endl;
		}
		int guildChoice;
		do {
			cout << "Eneter Your Choice: ";
			cin >> guildChoice;
		} while (guildChoice <0 || guildChoice > GuildCount);

		for (int i = 0; i < GuildCount; i++) {
			guilds[i]->ViewMembers();
		}
		cout << endl;
		cout << "Available pets:" << endl;
		for (int i = 0; i < PetCount; i++) {
			bool alreadyInGuild = false;
			for (int j = 0; j < guilds[guildChoice - 1]->getMemberCount(); j++) {
				if (guilds[guildChoice - 1]->getMember(j) == pets[i]) {
					alreadyInGuild = true;
					break;
				}
			}
			if (!alreadyInGuild) {
				cout << i + 1 << ". " << pets[i]->getName() << endl;
			}
		}

		int choice;
		do{
			cout << "Select a Pet to add to the Guild (1-" << PetCount << "): ";
			cin >> choice;
		} while (choice <0 || choice >PetCount);	
		for (int i = 0; i < guilds[guildChoice - 1]->getMemberCount(); i++) {
			if (guilds[guildChoice - 1]->getMember(i) == pets[choice - 1]) {
				cout << "This pet is already in the guild." << endl;
				return;
			}
		}
		int roleIndex;
		do{
			cout << "Press 1 to Select Tank Role." << endl;
			cout << "Press 2 to Select Healer Role." << endl;
			cout << "Press 3 to Select Damage Dealer Role." << endl;
			cout << "Select The Role of This Pet: ";
			cin >> roleIndex;
		} while (roleIndex < 1 || roleIndex>3);
		guilds[guildChoice - 1]->AddMember(pets[choice - 1], roleIndex);
		//cout << "The Pet " << pets[choice - 1]->getName() << " has been added to the Guild & Role is: " << pets[choice - 1]->getRole() << endl;
	}
	void DisplayGuild() {
		if (GuildCount == 0) {
			cout << "Player Shall Create a Guild Before." << endl << endl;
			return;
		}
		else if (PetCount < 3) {
			cout << "There Should be Atleast 3 pets to be in a Guild." << endl;		
		}
		for (int i = 0; i < GuildCount; i++) {
			guilds[i]->ViewMembers();
		}

	}
	Guild* getGuild(int index) const {
		return (index >= 0 && index < GuildCount) ? guilds[index] : NULL;
	}
	string getSaveFileName() const {
		ostringstream flag;
		flag << Name << "_save.txt";
		return flag.str();
	}
	void SaveFile() {
		// this function saves Details of player,pets, Guilds respectively
		ofstream file(getSaveFileName());
		if (file.is_open()) {
			file << Name << endl << endl;
			file << "INFO:-" << endl;
			file << "Name: " << Name << endl;
			file << "Money: $" << Money << endl;
			file << "Level: " << LEVEL << endl;
			file << "Pet Count: " << PetCount << endl;
			file << "Guild Count: " << GuildCount << endl;
			file << "Player's Victoris Overall: " << wins << endl;
			file << "Player's 1v1 Victories Overall: " << WIN1v1 << endl;
			file << "Player's 2v2 Victories Overall: " << WIN2v2 << endl;
			file << "Player's Guild Victories Overall: " << GUILDWINS << endl;
			file << endl << "Player's Pet Details:- " << endl << endl;
			for (int i = 0; i < PetCount; i++) {
				file << "Type: " << pets[i]->getType() << endl;
				file <<"Name: " << pets[i]->getName() << endl;
				file << "HP: " << pets[i]->getHP() << endl;
				file << "Max HP: " << pets[i]->getMaxHP() << endl;
				file << "Attack Power: " << pets[i]->getAttackPower() << endl;
				file << "Defense: " << pets[i]->getDefense() << endl;
				file << "Speed: " << pets[i]->getSpeed() << endl;
				file << "Level: " << pets[i]->getLevel() << endl;
				file << "Training Points: " << pets[i]->getTrainingPoints() << endl << endl;
			}
			if (GuildCount > 0) {
				file << "Player's Guild Details:- " << endl << endl;
				file << "Guild Name: " << GuildName << endl;
				for (int i = 0; i < GuildCount; i++) {
					file << "Guild Name: " << guilds[i]->getName() << endl;
					file << "Member Count: " << guilds[i]->getMemberCount() << endl;
					for (int j = 0; j < guilds[i]->getMemberCount(); j++) {
						file << "Member Pet Name: " << guilds[i]->getMember(j)->getName() << endl;
						file << "Role: " << guilds[i]->getMember(j)->getRole() << endl;
					}
				}
			}
			file << endl << "Player's Inventory Details:-";
			for (int i = 0; i < 4; i++) {
				file << "Item Name: " << inventory[i].Name << endl;
				file << "Item Quantity: " << inventory[i].Quantity << endl;
			}
			file.close();
			cout << "Game Saved Successfully to " << getSaveFileName() << endl;
		}
		else {
			cout << "No Such File Found." << endl;
		}
	}
	bool LoadFromFile() {
		// ensures loading data from File
		ifstream inFile(getSaveFileName());
		if (!inFile.is_open()) {
			cout << "No saved game found for " << Name << "." << endl;
			return false;
		}
		for (int i = 0; i < PetCount; i++) {
			delete pets[i];
		}
		for (int i = 0; i < GuildCount; i++) {
			delete guilds[i];
		}
		PetCount = 0;
		GuildCount = 0;

		getline(inFile, Name);
		inFile >> Money >> LEVEL >> PetCount >> GuildCount >> WIN1v1 >> WIN2v2;
		inFile.ignore();

		for (int i = 0; i < PetCount; i++) {
			string type, name;
			int hp, maxHP, attack, defense, speed, level, tp;
			bool isStun;

			getline(inFile, type);
			getline(inFile, name);
			inFile >> hp >> maxHP >> attack >> defense >> speed >> level >> tp >> isStun;
			inFile.ignore();

			Pet* pet = NULL;
			if (type == "Dragon") pet = new Dragon(name);
			else if (type == "Phoenix") pet = new Phoenix(name);
			else if (type == "Unicorn") pet = new Unicorn(name);
			else if (type == "Griffin") pet = new Griffin(name);

			if (pet) {
				pet->setHP(hp);
				pet->setMaxHP(maxHP);
				pet->setAttackPower(attack);
				pet->setDefense(defense);
				pet->setSpeed(speed);
				pet->setTrainingPoints(tp);
				pet->setStun(isStun);
				for (int lvl = 1; lvl < level; lvl++) {
					pet->levelUp();
				}
				pets[i] = pet;
			}
		}

		// Load guilds
		for (int i = 0; i < GuildCount; i++) {
			string guildName;
			int memberCount;

			getline(inFile, guildName);
			inFile >> memberCount;
			inFile.ignore();

			guilds[i] = new Guild(guildName);

			for (int j = 0; j < memberCount; j++) {
				string petName, role;
				getline(inFile, petName);
				getline(inFile, role);

				// Find the pet by name
				for (int k = 0; k < PetCount; k++) {
					if (pets[k]->getName() == petName) {
						int roleIndex = 0;
						if (role == "tank") roleIndex = 0;
						else if (role == "healer") roleIndex = 1;
						else if (role == "damage dealer") roleIndex = 2;

						guilds[i]->AddMember(pets[k], roleIndex);
						break;
					}
				}
			}
		}

		// Load inventory
		for (int i = 0; i < 4; i++) {
			getline(inFile, inventory[i].Name);
			inFile >> inventory[i].Quantity;
			inFile.ignore();
		}

		inFile.close();
		cout << "Game loaded successfully from " << getSaveFileName() << "!" << endl;
		return true;
	}
	
	~Player() {
		for (int i = 0; i < PetCount; i++) {
			bool inGuild = false;
			for (int j = 0; j < GuildCount; j++) {
				if (guilds[j]) {
					for (int k = 0; k < guilds[j]->getMemberCount(); k++) {
						if (guilds[j]->getMember(k) == pets[i]) {
							inGuild = true;
							break;
						}
					}
				}
				if (inGuild) break;
			}
			if (!inGuild && pets[i]) {
				delete pets[i];
			}
			pets[i] = NULL;
		}
			for (int i = 0; i < GuildCount; i++) {
			if (guilds[i]) {
				delete guilds[i];
				guilds[i] = NULL;
			}
		}
	}
};
class Shop {
private:
	int itemCount;
	int itemPrice;
	struct ShopItems {
		string Name;
		int Price;
	};
	ShopItems items[4] = {
		{ "Health Potion", 100 },
		{ "Attack Boost", 150 },
		{ "Defense Boost", 150 },
		{ "Speed Boost", 200 }
	};

public:
	// Constructor for Shop
	Shop() : itemCount(4), itemPrice(0) {
	}
	void ShowItems() {
		cout << "Following Items are Available in the Shop:-" << endl;
		for (int i = 0; i < itemCount; i++) {
			cout << "Item: " << items[i].Name << " Price: $" << items[i].Price << endl;
		}

	}
	bool PurchaseItems(string itemName, Player& p) {
		for (int i = 0; i < itemCount; i++) {
			if (items[i].Name == itemName) {
				if (p.getMoney() >= items[i].Price) {
					p.addMoney(-items[i].Price);
					p.AddToInventory(i);
					cout << endl << endl << "The Player " << p.getName() << " has Successfully purchased "
						<< items[i].Name << " for " << items[i].Price << endl;
					return true;
				}
				else {
					cout << "No Enough Money to Purchase " << items[i].Name << " the Player has only $" << p.getMoney() << endl;
					return false;
				}
			}
		}
		cout << "Item not found in the shop." << endl;
		return false;
	}

	~Shop() {

	}
};


class AI {
private:
	string Name;
	Pet** pets;
	int petCount;
public:
	// AI Bot Constructor
	AI(string Name) : Name(Name), petCount(0), pets(NULL) {

		AddPet(new Dragon("AI Dragon"));
		AddPet(new Phoenix("AI Phoenix"));
		AddPet(new Unicorn("AI Unicorn"));
		AddPet(new Griffin("AI Griffin"));

	}
	string getName() {
		return Name;
	}
	Pet* getRandomPet() {
		// this function is used to select a random pet from the AI's collection, handles the scenaior for availability
		// of the pet and if the pet is dead or not
		if (petCount == 0) return NULL;
		for (int i = 0; i < petCount; ++i) {
			int index = rand() % petCount;
			if (pets[index]->getHP() > 0) {
				return pets[index];
			}
		}
		cout << "No alive pets available for AI." << endl;
		return NULL;
	}
	
	void AddPet(Pet* pet) {
		// this function is usedd to add a new pet to the AI's collection, randomly accessing a pet
		// out of the collection of 4 in game pets
		if (petCount<10){
			Pet** newPets = new Pet * [petCount + 1];
			for (int i = 0; i < petCount; i++) {
				newPets[i] = pets[i];
			}
			newPets[petCount] = pet;
			delete[] pets;
			pets = newPets;
			petCount = petCount + 1;
		}
		else {
			cout << "too much pets for AI." << endl;
		}
	}
	
	void ShowPets() {
		cout << "AI's Pets are: " << endl;
		for (int i = 0; i < petCount; i++) {
			pets[i]->displayStats();
			cout << endl;
		}
	}
	void MakeMove(Pet* playerPet, Pet* botPet) {
		// this function determins what would be the in game move for the bot pet to the player's pet
		if (playerPet->getHP() <= 0) {
			cout << "Player Bot has Died." << endl;
			return;
		}
		if (botPet->getHP() <= 0) {
			cout << "AI has Died." << endl;
			return;
		}
		//srand(time(0));
		int index = (rand() % (10 - 1 + 1)) + 1;
		if (index <= 5) {
			botPet->Attack(*playerPet);
		}
		else if (index > 5 && index <= 8) {
			botPet->UseAbility(*playerPet, 0);
		}
		else {
			cout << botPet->getName() << " is making it's next move." << endl;
		}
	}
	// Destructor of AI Class
	~AI() {
		for (int i = 0; i < petCount; i++) {
			delete pets[i];
			pets[i] = NULL;
		}
		delete[] pets;
		pets = NULL;
	}
};

class Arena {
private:
	Player player;
	AI Bot;
	int type;
	int Counter;
	int WinCounter1v1;
	int WinCounter2v2;
	string Venu;

	
public:
	Arena(Player &player, AI &Bot) : player(player), Bot(Bot), Counter(0) , WinCounter1v1(0), WinCounter2v2(0){}
	void ArenaInterface() {
		int choice;
		do {

			cout << "Press 1 for a 1v1 Battle." << endl;
			cout << "Press 2 for a 2v2 Battle." << endl;
			cout << "Press 3 for Guild War." << endl<< endl;
			cout << "Enter Your Choice: ";
			while (!(cin >> choice)) {
				cout << "Invalid input. Please enter a number: ";
				cin.clear();
				while (cin.get() != '\n');
			}
			cout << endl;
			switch (choice) {
			case 1:
				start1v1();
				break;
			case 2:
				start2v2();
				break;
			case 3:
				break;
			}
		} while (choice < 1 || choice > 3);

	}
	
	void spawnrandomItems(Pet*& playerPet, Pet*& botPet, int flag) {
		int random;
		random = ( rand() % (4 - 1+1))+1;
		switch (random) {
		case 1:
			if (flag == 1) {
				cout << endl;
				cout << playerPet->getName() << " has found a Health Potion!" << endl;
				playerPet->HealHP(25);
				cout << "HP of the Player Pet is now: " << playerPet->getHP() << endl;
			}
			else {
				cout << botPet->getName() << " has found a Health Potion!" << endl;
				botPet->HealHP(25);
				cout << "HP of Bot Pet is now: " << botPet->getHP() << endl;

			}
			break;
		case 2:
			if (flag == 1) {
				cout << endl;
				cout << playerPet->getName() << " has found an Attack Boost!" << endl;
				playerPet->AttackManagement(10);
				cout << "Attack Power of the Player Pet is now: " << playerPet->getAttackPower() << endl;
			}
			else {
				cout << botPet->getName() << " has found an Attack Boost!" << endl;
				botPet->AttackManagement(10);
				cout << "Attack Power of Bot Pet is now: " << botPet->getAttackPower() << endl;
			}
			break;
		case 3:
			if (flag == 1) {
				cout << endl;
				cout << playerPet->getName() << " has found a Defense Boost!" << endl;
				playerPet->DefenseManagement(10);
				cout << "Defense of the Player Pet is now: " << playerPet->getDefense() << endl;
			}
			else {
				cout << botPet->getName() << " has found a Defense Boost!" << endl;
				botPet->DefenseManagement(10);
				cout << "Defense of Bot Pet is now: " << botPet->getDefense() << endl;
			}
			break;
		case 4:
			cout << "Sike!! there was nothing in the Mystery Box." << endl;
		}
	}
	void getSTATS(Pet* pets) {
		pets->displayStats();
	}
	bool isDead(Pet* pets) {
		// this function checks if the pet is alive or not
		return pets->getHP() <= 0;

		/*else {
			return true;
		}*/
	}
	void resolveStun(Pet* pet) {
		if (pet->getStun()) {
			// Pet is stunned; decrease stun duration.
			pet->decrementStun();  
			if (pet->getHP() > 0) {
				cout << pet->getName() << " is still stunned.\n";
			}
		}
	}
	void start1v1() {
		if (player.getPetCount() < 1) {
			cout << "You must adopt at least one pet to enter the arena.\n";
			return;
		}
		player.displayPet();
		int choice;
		cout << endl <<"Select your pet by index (1 - " << player.getPetCount() << "): ";
		while (!(cin >> choice) || choice < 1 || choice > player.getPetCount()) {
			cout << "Invalid input. Please enter a valid number: ";
			cin.clear();
			while (cin.get() != '\n');
		}
		
		if (choice < 1 || choice > player.getPetCount()) {
			cout << "Invalid choice.\n";
			return;
		}

		Pet* playerPet = player.getPet(choice - 1);
		
		Pet* botPet = Bot.getRandomPet();

		if (!botPet) {
			cout << "Bot has no available pets to battle.\n";
			return;
		}

		cout <<endl <<"Battle Starts: " << playerPet->getName() << " vs " << botPet->getName() << endl;

		while (playerPet->getHP() > 0 && botPet->getHP() > 0) {
			resolveStun(playerPet);
			resolveStun(botPet);
			if (playerPet->getSpeed() >= botPet->getSpeed()) {
				if (rand() % 3 == 0) {
					cout << endl << "Mystery Box Dropping for Player, Press enter to Availl! ";
					cin.get();
					cin.get();
					spawnrandomItems(playerPet, botPet, 1);
				}
				cout << "Player's Turn: " << endl;
				turn(playerPet, botPet);
				cout << "After Player's Attack Stats of AI: " << endl << endl;
				botPet->displayStats();
				if (botPet->getHP() > 0)
					Bot.MakeMove(playerPet, botPet);
			}
			else {
				cout << "AI's Turn: " << endl;
				Bot.MakeMove(playerPet, botPet);
				if (rand() % 3 == 0) {
					cout << endl << "Mystery Box Dropping for AI Bot, Press enter to Availl! ";
					spawnrandomItems(playerPet, botPet, 0);
				}
				cout << "After AI's Attack Stats of Player: " << endl << endl;
				playerPet->displayStats();
				cout << endl << endl;
				if (playerPet->getHP() > 0)
					turn(playerPet, botPet);
			}
		}
		playerPet->setStun(false);
		botPet->setStun(false);

		// Result
		if (playerPet->getHP() <= 0 && botPet->getHP() <= 0) {
			cout << "\nIt’s a draw!\n";
			player.addMoney(50);
			playerPet->lostTP();
		}
		else if (playerPet->getHP() > 0) {
			cout << "\nYou win!\n";
			player.addMoney(100);
			playerPet->levelUp();
			player.Add1v1Wins();
			player.AddWins();
			player.LevelUP();
			cout << "Yay!, Player got Leveled Up!" << endl;
		}
		else {
			cout << "\nYou lost.\n";
			player.addMoney(20);
			playerPet->lostTP(); 
		}
		playerPet->displayStats();
	
		player.SaveFile();
	}

	void turn(Pet* playerPet, Pet* botPet) {
		int choice;
		while (true) {
			cout << "Press 1 to Attack." << endl;
			cout << "Press 2 to Use Ability." << endl;
			cout << "Press 3 to Use an Item." << endl;
			while (!(cin >> choice) || choice < 1 || choice > 3) {
				cout << "Invalid input. Please enter a number between 1 and 3: ";
				cin.clear();
				while (cin.get() != '\n');
			}
			cin.ignore();
			
			cout << endl << endl;
			switch (choice) {
			case 1:
				playerPet->Attack(*botPet);
				return;
			case 2:
				playerPet->UseAbility(*botPet,1);
				return;
			case 3: {
				player.DisplayInventory();
				cout << "Enter item name: ";
				string item;
				cin.ignore();
				getline(cin, item);
				player.UtilizeItem(item, playerPet);
				return;
			}
			default:
				cout << "Invalid option. Try again.\n";
			}
		}
	}
	void start2v2() {
		//this function is fully responsible for 2v2 fights
		Pet* playerPets[2] = { NULL, NULL };
		Pet* botPets[2] = { NULL, NULL };
		bool won =false;
	
		if (player.getPetCount() >= 2) {
			cout << "Welcome to 2v2 Battle" << endl;
			int teamSize = 2;
			int turns = 1;
			player.displayPet();
			cout << endl << endl;
			int choice1, choice2;
			do {
				cout << "Select 2 Pets to Battle from the Following Count 1 - " << player.getPetCount() << endl;
				cout << "Choose 1st Pet: " << endl;
				while (!(cin >> choice1) || choice1 < 1 || choice1 > player.getPetCount()) {
					cout << "Invalid input. Please enter a valid pet index: ";
					cin.clear();
					while (cin.get() != '\n');
				}
				
				cout << "Choose 2nd Pet: " << endl;
				while (!(cin >> choice2) || choice2 < 1 || choice2 > player.getPetCount() || choice2 == choice1) {
					cout << "Invalid input or duplicate pet. Try again: ";
					cin.clear();
					while (cin.get() != '\n');
				}
				if (choice1 == choice2) {
					cout << "Cannot select the same pet twice, try again." << endl;
				}
				
			} while (choice1 == choice2 );

			cout << "Player Has Selected Their Pets: " << endl;

			playerPets[0] = player.getPet(choice1 - 1);
			playerPets[1] = player.getPet(choice2 - 1);

			cout << "AI is Selecting Pets: " << endl;
			botPets[0] = Bot.getRandomPet();
			do {
				botPets[1] = Bot.getRandomPet();

			} while (botPets[1] == botPets[0]);
			if (!botPets[0] || !botPets[1]) {
				cout << "Bot has no available pets!" << endl;
			}
			cout << endl << "2v2 Battle is Starting" << endl << endl;
			cout << endl << endl << endl << "Showing Opponent Pets Stats: " << endl;
			for (int i = 0; i < 2; i++) {
				if (!isDead(botPets[i])) {
					botPets[i]->displayStats();
				}
			}
			while (true) {
				cout << "Turn Number: " << turns++ << endl;
				cout << endl << endl;
				bool playerDead = isDead(playerPets[0]) && isDead(playerPets[1]);
				bool botDead = isDead(botPets[0]) && isDead(botPets[1]);
				// i am checking winning condition for both teams here
				if (playerDead || botDead) {
					if (playerDead && botDead) {
						cout << "It is a draw Between Both Teams" << endl;
						player.addMoney(80);
						cout << player.getName() << " earned $80" << endl;
						break;
					}
					else if (playerDead) {
						cout << "Player Team has Lost the Battle." << endl;
						for (int i = 0; i < 2; i++) {
							if (botPets[i]->getHP() > 0) {
								botPets[i]->levelUp();
							}
						}
						break;
					}
					else {
						cout << "Bot Team has Lost the Battle." << endl;
						for (int i = 0; i < 2; i++) {
							if (playerPets[i]->getHP() > 0) {
								playerPets[i]->levelUp();
								won = true;
							}
						}

						break;
					}
					if (won == true) {
						player.addMoney(160);
						cout << player.getName() << " earned $160" << endl;
						player.Add2v2Wins();
						player.AddWins();
						player.LevelUP();
						cout << "Yay!, You Leveled Up!" << endl;
					}
					else if (!won) {
						player.addMoney(40);
						cout << player.getName() << " earned $40" << endl;
					}
				}
				// logic for Player's Turn 
				for (int i = 0; i < 2; i++) {
					// skips the dead pet
					if (isDead(playerPets[i])) {
						continue;
					}
					resolveStun(playerPets[i]);
					for (int i = 0; i < 2; i++) {
						playerPets[i]->displayStats();
					}
					cout << endl <<endl << "Player's Turn for Pet " << playerPets[i]->getName() << endl;
					if (rand() % 3 == 0) {
						cout << endl << "Mystery Box Dropping for Player, Press enter to Availl! ";
						cin.get();
						spawnrandomItems(playerPets[i], botPets[0], 1);
					}
					cout << endl << "Select Opponent's Pet to Attack: " << endl;
					
					Counter = 0;
					for (int j = 0; j < 2; j++) {
						if (!isDead(botPets[j])) {
							cout << "Opponent's Pet Number " << j+1<< " Name: " << botPets[j]->getName() << endl;
							cout << "Opponent's Pet Number " << j+1<< " Health: " << botPets[j]->getHP() << "/" << botPets[j]->getMaxHP() << endl;
							cout << "Opponent's Pet Number " << j+1 << " Attack Power: "  << botPets[j]->getAttackPower() << endl << endl<< endl  << endl;
							Counter = Counter + 1;
						}
					}
					int attackPet;
					while (true) {
						cout << "Select Opponent's Pet to Attack from the Following Count 1 - " << Counter << endl;
						if (!(cin >> attackPet)) {
							cout << "Invalid input. Please enter a number: ";
							cin.clear();
							while (cin.get() != '\n');
							continue;
						}
						
						if (botPets[attackPet - 1]->getHP() <=0) {
							cout << "Selected Pet is Dead, Please select another." << endl;
							continue;
						}
						if (attackPet >= 1 && attackPet <= 2 && !isDead(botPets[attackPet - 1])) {
							break;
						}
						else {
							cout << "Invalid Input, Please select a valid Pet." << endl;
						}
					}


					turn(playerPets[i], botPets[attackPet - 1]);
					if (botPets[attackPet - 1]->getHP() <= 0) {
						cout << "Opponent's Pet " << botPets[attackPet - 1]->getName() << " has been knocked out!" << endl;
					}
					if (isDead(botPets[0]) && isDead(botPets[1])) {
						// opponent team has been completely knocked out
						break;
					}

				}
				//logic for Bot's Turn
				for (int i = 0; i < 2; i++) {
					// skips the dead pet
					if (isDead(botPets[i])) {
						continue;
					}
					resolveStun(botPets[i]);
					cout << endl << "Bot's Turn for Pet " << botPets[i]->getName() << endl;
					if (rand() % 3 == 0) {
						cout << endl << "Mystery Box Dropping for AI Bot.";
						
						spawnrandomItems(playerPets[0], botPets[i], 0);
					}
					int attackPet = rand() % 2;
					while (isDead(playerPets[attackPet])) {
						attackPet = rand() % 2;
					}
					Bot.MakeMove(playerPets[attackPet], botPets[i]);
					if (playerPets[attackPet]->getHP() <= 0) {
						cout << "Player's Pet " << playerPets[attackPet]->getName() << " has been knocked out!" << endl;
					}
					if (isDead(playerPets[0]) && isDead(playerPets[1])) {
						// player team has been completely knocked out
						break;
					}

				}



			}

		}
		else {
			cout << "Player Shall have 2 Pets in order to Play 2v2." << endl;
			return;
		}
		for (int i = 0; i < 2; i++) {
			if (playerPets[i]) playerPets[i]->setStun(false);
			if (botPets[i]) botPets[i]->setStun(false);
		}
		player.SaveFile();

	}
	
};

class Game {
	// this is the most important class of the game, handles each aspect of the game
private:
	Player player;
	AI bot;
	Shop shop;
	bool runningState;
	
public:
	// constructor of Game class
	Game(string username) : player(username, 1), bot("AI Bot"), shop() {
		runningState = true;
	}
	void LoadingGame() {
		if (player.LoadFromFile()) {
			cout << "Welcome Back " << player.getName() << endl;
		}
		else {
			//cout << "No Saved Game Found for "<<player.getName() << ", Starting a New Game." << endl;
		}
	}
	void AutoSave() {
		player.SaveFile();
	}
	void GuildManagement() {
		int option;
		do {
			cout << endl << endl;
			cout << "Press 1 to Create a Guild." << endl;
			cout << "Press 2 to Add Pets to Guild." << endl;
			cout << "Press 3 to View Guild." << endl;
			cout << "Press 4 to Exit." << endl;
			cout << "Enter Your Choice: ";
			cin >> option;
			if (cin.fail()) {
				cin.clear();
				while (cin.get() != '\n');
				cout << "Invalid Input, must be a Number Ranging from 1-4." << endl;
			}
			switch (option) {
			case 1:
				if(player.getPetCount()>=3){
					player.AssembleGuild();
				}
				else {
					cout << "There Should Be Atleast 3 Pets to Form a Guild." << endl;
				}
				break;
			case 2:
				if (player.getPetCount() >= 3) {
					player.AddPetsToGuild();
				}
				else {
					cout << "There Should Be Atleast 3 Pets to Form a Add To Guild." << endl;
				}
				break;
			case 3:
				if (player.getPetCount() >= 3) {
					player.DisplayGuild();
				}
				else {
					cout << "There Should Be Atleast 3 Pets to Display a  Guild." << endl;
				}				
				break;
			case 4:
				mainMenu();
				break;
			}
		} while (option < 1 || option > 4);
	}
	void CreatingPet() {
		string petName;
		int choose;
		do {
			cout << endl << endl;
			cout << "Pet Adopting Menu: " << endl;
			cout << endl;
			cout << "Press 1 to Apdot Dragon." << endl;
			cout << "Press 2 to Adopt Phoenix." << endl;
			cout << "Press 3 to Adopt Unicorn." << endl;
			cout << "Press 4 to Adopt Griffin." << endl;
			cout << "Press 5 to return to Main Menu." << endl;
			cout << "Enter Your Choice: ";
			cin >> choose;
			if (cin.fail()) {
				cin.clear();
				while (cin.get() != '\n');
				cout << "Invalid Input, must be a Number Ranging from 1-5." << endl;
			}
			switch (choose) {
			case 1:
			{
				cout << endl;
				cout << "Give Your Pet a Name: ";
				cin.ignore();
				getline(cin, petName);
				player.AdoptPet(new Dragon(petName));
				cout << endl << endl;
				break;
			}
			case 2:
			{
				cout << endl;
				cout << "Give Your Pet a Name: ";
				cin.ignore();
				getline(cin, petName);
				player.AdoptPet(new Phoenix(petName));
				cout << endl << endl;
				break;
			}
			case 3:
			{
				cout << endl;
				cout << "Give Your Pet a Name: ";
				cin.ignore();
				getline(cin, petName);
				player.AdoptPet(new Unicorn(petName));
				cout << endl << endl;
				break;
			}
			case 4:
			{
				cout << endl;
				cout << "Give Your Pet a Name: ";
				cin.ignore();
				getline(cin, petName);
				player.AdoptPet(new Griffin(petName));
				cout << endl << endl;
				break;
			}
			case 5:
				cout << endl << endl;
				mainMenu();
				break;

			}
		} while (choose < 1 || choose > 5);
	

	}
	void DisplayPetMenu() {
		// this function is used to display the pet menu
		int option;
		do {
			cout << endl << endl;
			cout << "Press 1 to Adopt Pet." << endl;
			cout << "Press 2 to Train Pets." << endl;
			cout << "Press 3 to View Pets." << endl;
			cout << "Press 4 to Exit." << endl;
			cout << "Enter Your Choice: ";
			cin >> option;
			if (cin.fail()) {
				cin.clear();
				while (cin.get() != '\n');
				cout << "Invalid Input, must be a Number Ranging from 1-4." << endl;
			}
			switch (option) {
			case 1:
			{
				//CreatingPet();
				string petName;
				int choose;
				do {
					cout << endl << endl;
					cout << "Pet Adopting Menu: " << endl;
					cout << endl;
					cout << "Press 1 to Apdot Dragon." << endl;
					cout << "Press 2 to Adopt Phoenix." << endl;
					cout << "Press 3 to Adopt Unicorn." << endl;
					cout << "Press 4 to Adopt Griffin." << endl;
					cout << "Press 5 to return to Main Menu." << endl;
					cout << "Enter Your Choice: ";
					cin >> choose;
					if (cin.fail()) {
						cin.clear();
						cin.ignore();
						cout << "Invalid Input, must be a Number Ranging from 1-5." << endl;
					}
					switch (choose) {
					case 1:
					{
						cout << endl;
						cout << "Give Your Pet a Name: ";
						cin.ignore();
						getline(cin, petName);
						player.AdoptPet(new Dragon(petName));
						cout << endl << endl;
						break;
					}
					case 2:
					{
						cout << endl;
						cout << "Give Your Pet a Name: ";
						cin.ignore();
						getline(cin, petName);
						player.AdoptPet(new Phoenix(petName));
						cout << endl << endl;
						break;
					}
					case 3:
					{
						cout << endl;
						cout << "Give Your Pet a Name: ";
						cin.ignore();
						getline(cin, petName);
						player.AdoptPet(new Unicorn(petName));
						cout << endl << endl;
						break;
					}
					case 4:
					{
						cout << endl;
						cout << "Give Your Pet a Name: ";
						cin.ignore();
						getline(cin, petName);
						player.AdoptPet(new Griffin(petName));
						cout << endl << endl;
						break;
					}
					case 5:
						cout << endl << endl;
						mainMenu();
						break;

					}
				} while (choose < 1 || choose > 5);
				break;
			}
			case 2:
			{
				player.TrainPets();
				break;
			}
			case 3:
			{
				player.displayPet();
				break;
			}
			case 4:
			{
				mainMenu();
			}
				break;
			
			}
		} while (option <  1 || option > 4);
	}
	void state() {
		cout << "Welcome to Magical Pets Kingdom" << endl << endl;

		while (runningState) {
			mainMenu();
		}
	}

	void mainMenu() {
		int choice;
		do {
			cout << endl << endl;
			cout << "Main Menu:" << endl;
			cout << endl ;
			cout << "Press 1 for Pets Management System." << endl;
			cout << "Press 2 for Arena." << endl;
			cout << "Press 3 for Guild Management System." << endl;
			cout << "Press 4 for Shop Management System" << endl;
			cout << "Press 5 to Load Game." << endl;
			cout << "Press 6 for Leaderboard." << endl;
			cout << "Press 7 to Exit the Game." << endl;
			cout << "Enter your choice: ";
			cin >> choice;
			if (cin.fail()) {
				cin.clear();
				while (cin.get() != '\n');
				cout << "Invalid Input, must be a Number Ranging from 1-7." << endl;
			}
			switch (choice) {
			case 1:
			{
				DisplayPetMenu();
				break;
			}
			case 2:
			{
				if (player.getPetCount() > 0) {
					Arena battleField(player, bot);
					cout << endl;
					battleField.ArenaInterface();
				}
				else {
					cout << player.getName() << " Shall Adopt Some Pets Before." << endl;
				}
				break;
			}
			case 3:
			{
				GuildManagement();
				break;
			}
			case 4:
			{
				ShopManagment();
				break;
			}
			case 5:
			{
				LoadingGame();
				break;
			}
			case 6:
			{
				break;
			}
			case 7:
			{
				AutoSave();
				
				cout <<"Successfully Saved file for " << player.getName() << endl << "Exiting the game..." << endl;
				runningState = false;
				break;
			}

			}
		} while (choice < 1 || choice > 7);
	}
	void ShopManagment() {
		// handles for the shop management system
		cout <<endl  <<"Welcome to the Shop" << endl << endl;
		shop.ShowItems();
		cout << endl << player.getName() <<" has Money in Wallet: $" << player.getMoney() << endl << endl;
		int opt;
		do {
			cout << "Press 1 to Purchase Items." << endl;
			cout << "Press 2 to Open Inventory." << endl;
			cout << "Press 3 to Exit." << endl;
			cout << "Enter your choice: ";
			cin >> opt;
			if (cin.fail()) {
				cin.clear();
				while (cin.get() != '\n');
				cout << "Invalid Input, must be a Number Ranging from 1-3." << endl;
			}
			switch (opt){
			case 1:
			{
				string item;
				cout << "Enter the name of the item you want to purchase: ";
				cin.ignore();
				getline(cin, item);

				if (shop.PurchaseItems(item, player)) {
				}
				else {	
					cout << "Failed to purchase item." << endl;
				}
				break;
			}
			case 2:
				{
				cout << endl;
				player.DisplayInventory();
				break;
				}
			}
		} while (opt < 1 || opt > 3);
		

	}
};

#endif 