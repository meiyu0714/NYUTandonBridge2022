#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int AVERAGE_FUEL_ECONOMY = 25;

void printNames(const Person& p1) { //want to pass by reference for efficiency
	cout << "Person: " << p1.getName();
	if (p1.isMarried())
		cout << " is married to " << p1.getSpouseName();
	cout << endl;
}

class Person {
	string name;
	Person* spouse;
public:
	Person(string newName="Rumplestilkstein") : name(newName), spouse(nullptr) {}
	string getName() const { return name; }
	string getSpouseName() const { return ((this->spouse == nullptr) ? "(not married)" : spouse->name); }
	bool marry(Person& other);
	bool isMarried() const { return spouse != nullptr; }
};

bool Person::marry(Person& other) {
	cout << "this:" << this << endl;
	if (this->spouse != nullptr || other.spouse != nullptr)
		return false;
	spouse = &other; //Daniel marrying Gloria
	other.spouse = this; //Gloria marrying Daniel
	return true;
}

class BadIdea {
	int val;
public:
	BadIdea(int newVal) :val(newVal) {}
};

class Car {
	int odometer;
	double fuelTank;
public:
	//Car() :odometer(0), fuelTank(100) { cout << "Beep Beep, new car coming through!" << endl; }
	Car(int newOdometer = 0, double newFuelTank = 100) : odometer(newOdometer), fuelTank(newFuelTank) { cout << "Constructing car with odometer: " << odometer << endl; }
	
	/*
	Car() : odometer(0), fuelTank(100) { cout << "Constructing NEW car with odometer: " << odometer << endl; }
	Car(int newOdometer) : odometer(newOdometer), fuelTank(100) { cout << "Constructing USED car with odometer: " << odometer << <<"full fuel"<<endl; }
	Car(int newOdometer, double newFuelTank) : odometer(newOdometer), fuelTank(newFuelTank) { cout << "Constructing REALLY USED car with odometer: " << odometer << endl; }
	*/

	int getOdometer() const { return odometer; }
	double getFuelTank() const { return fuelTank; }
	bool outOfGas() const { return fuelTank == 0; }
	void fillErUp() { fuelTank = 100; }
	bool drive(int miles);
};

bool Car::drive(int miles) {
	double fuelRequired = miles / AVERAGE_FUEL_ECONOMY;
	if (fuelTank >= fuelRequired) {
		odometer += miles;
		fuelTank -= fuelRequired;
		return true;
	}
	else {
		int milesWeCanDrive = fuelTank * AVERAGE_FUEL_ECONOMY;
		odometer += milesWeCanDrive;
		fuelTank = 0;
		return false;
	}
}

class Dealership {
	Car forSale;
public:
	Dealership() :forSale(10000) { cout << "Constructing a dealership..." << endl; }
};


class Measurement {
	int feet;
	int inches;
	void normalize();
public:
	Measurement(int newInches = 0, int newFeet = 0) :feet(newFeet), inches(newInches) { normalize(); }
	int getFeet() const { return feet; }
	int getInches() const { return inches; }
	int getTotalInches() const { return feet * 12 + inches; }
	void setFeet(int newFeet) { feet = newFeet; }
	void setInches(int newInches) { inches = newInches; normalize(); }
	Measurement add(const Measurement& rhs) const { return *this + rhs; }

	Measurement operator++(int); //int means post-increment
	Measurement& operator++(); //pre-increment!
};


Measurement Measurement::operator++(int) {
	Measurement temp(*this); //copy myself into temp
	inches++;
	normalize();
	return temp;
}

Measurement& Measurement::operator++() {
	inches++;
	normalize();
	return *this;
}

Measurement operator+(const Measurement& lhs, const Measurement& rhs) {
	return lhs.getTotalInches() + rhs.getTotalInches();
	/*Measurement temp;
	temp.setInches(lhs.getTotalInches() + rhs.getTotalInches());
	return temp;*/
}

void Measurement::normalize() {
	feet += (inches / 12);
	inches %= 12;
}

int main() {
	Measurement m1(5);
	Measurement m2(10);

	Measurement m3 = m1 + m2;
	m3 = m1.add(m2); //the "Java" way

	m3 = 5 + m1; //doesn't work if operator+ is member.

	/*
	Person daniel("Daniel");
	cout << "Daniel's address: " << &daniel << endl;
	Person gloria("Gloria");
	*/
	//daniel.marry(gloria);

	//BadIdea b1(100);
	//vector<BadIdea> vba;



	/*Dealership honestAbe;

	Car herbie; //Default constructor
	cout << "Odometer: " << herbie.getOdometer() << endl;

	Car tooFurious(5000); //one argument constructor
	Car twoFast(10000, 50); //two argument constructor
	*/
	/*int x = 100;
	int * y = &x;
	int ** z = &y;

	cout << **z << endl; //100*/

	int x;
	int y;

	x = 5;
	y = (x++); //post-incrementation, returns a COPY OF the original value of x
	cout << "X: " << x << "\tY: " << y << endl; //x: 6	y: 5

	x = 5;
	y = (++x); //pre-incrementation, returns x
	cout << "X: " << x << "\tY: " << y << endl; //x: 6	y: 6

	++(++x); //double increment!!!

	x = 5;
	//(x++)++; //doesn't work because 5++ doesn't make any sense!

	(++x)++;

}