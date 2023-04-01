#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <mysql_connection.h>
#include <mysql_driver.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

using namespace std;
using namespace sql;

class Vehicle {
protected:
    string registration_number;
public:
    string get_registration_number() { return registration_number; }
    virtual void generate_number_plate() = 0;
};

class TypeA : public Vehicle {
private:
    static const char letters[];
public:
    void generate_number_plate() override {
        char first_letter = letters[rand() % 3];
        char second_letter = letters[rand() % 3];
        int number = rand() % 10000;
        registration_number = string(1, first_letter) + string(1, second_letter) + to_string(number);
    }
};
const char TypeA::letters[] = {'A', 'B', 'C'};

class TypeB : public Vehicle {
private:
    static const char letters[];
public:
    void generate_number_plate() override {
        char first_letter = letters[rand() % 3];
        char second_letter = letters[rand() % 3];
        int number = rand() % 10000;
        registration_number = string(1, first_letter) + string(1, second_letter) + to_string(number);
    }
};
const char TypeB::letters[] = {'D', 'E', 'F'};

class TypeC : public Vehicle {
private:
    static const char letters[];
public:
    void generate_number_plate() override {
        char first_letter = letters[rand() % 3];
        char second_letter = letters[rand() % 3];
        int number = rand() % 10000;
        registration_number = string(1, first_letter) + string(1, second_letter) + to_string(number);
    }
};
const char TypeC::letters[] = {'G', 'H', 'I'};

class TypeD : public Vehicle {
private:
    static const char letters[];
public:
    void generate_number_plate() override {
        char first_letter = letters[rand() % 3];
        char second_letter = letters[rand() % 3];
        int number = rand() % 10000;
        registration_number = string(1, first_letter) + string(1, second_letter) + to_string(number);
    }
};
const char TypeD::letters[] = {'J', 'K', 'L'};

class TypeE : public Vehicle {
private:
    static const char letters[];
public:
    void generate_number_plate() override {
        char first_letter = letters[rand() % 3];
        char second_letter = letters[rand() % 3];
        int number = rand() % 10000;
        registration_number = string(1, first_letter) + string(1, second_letter) + to_string(number);
    }
};
const char TypeE::letters[] = {'M', 'N', 'O'};

class TypeF : public Vehicle {
private:
    static const char letters[];
public:
    void generate_number_plate() override {
        char first_letter = letters[rand() % 3];
        char second_letter = letters[rand() % 3];
        int number = rand() % 10000;
        registration_number = string(1, first_letter) + string(1, second_letter) + to_string(number);
    }
};
const char TypeF::letters[] = {'P', 'Q', 'R'};

void display_info(ResultSet* res) {
    while (res->next()) {
        cout << "Name: " << res->getString("name") << endl;
        cout << "Age: " << res->getInt("age") << endl;
        cout << "Gender: " << res->getString("gender") << endl;
        cout << "Phone Number 1: " << res->getString("phone_number_1") << endl;
        cout << "Phone Number 2: " << res->getString("phone_number_2") << endl;
        cout << "ID Number: " << res->getString("id_number") << endl;
        cout << "Driver's License Number: " << res->getString("drivers_license_number") << endl;
        cout << "Email: " << res->getString("email") << endl;
        cout << "Make: " << res->getString("make") << endl;
        cout << "Model: " << res->getString("model") << endl;
        cout << "Year: " << res->getInt("year") << endl;
        cout << "License Plate: " << res->getString("license_plate") << endl << endl;
    }
}


void display_menu() {
    cout<< "1.Type A"<< endl;
    cout<< "2.Type B"<< endl;
    cout<< "3.Type C"<< endl;
    cout<< "4.Type D"<< endl;
    cout<< "5.Type E"<< endl;
    cout<< "6.Type F"<< endl;
}


int main() {
    try {
        // Prompt user for information
                string name, gender, phone_number_1, phone_number_2, id_number, drivers_license_number, email, model;
        int age, year,make;
        
        cout << "Enter your name: ";
        getline(cin, name);
        cout << "Enter your age: ";
        cin >> age<< endl;
        cout << "Enter your gender: ";
        cin >> gender<<endl;
        cout << "Enter your phone number 1: ";
        cin >> phone_number_1<<endl;
        cout << "Enter your phone number 2 (if any): ";
        cin >> phone_number_2<<endl;
        cout << "Enter your ID number: ";
        cin >> id_number<<endl;
        cout << "Enter your Driver's License number: ";
        cin >> drivers_license_number<<endl;
        cout << "Enter your email: ";
        cin >> email<<endl;
        cout << "Enter the model of your vehicle: ";
        cin >> model<<endl;
        cout << "Enter the year of your vehicle: ";
        cin >> year<<endl;
        cout << "Enter the make of your vehicle: ";
        display_menu();
        cin >> make<<endl;
        switch(make){
        	case 1:
        		vehicle_ptr = new TypeA();
        		break;
        	case 2:
        		vehicle_ptr = new TypeB();
        		break;
        	case 3:
        		vehicle_ptr = new TypeC();
        		break;
        	case 4:
        		vehicle_ptr = new TypeD();
        		break;
        	case 5:
        		vehicle_ptr = new TypeE();
        		break;
        	case 6:
        		vehicle_ptr = new TypeF();
        		break;
        	default:
        		cerr<<"Invalid decision"<< endl;
        		return 1;


		}
        
        
        display info();
    }
        
        return 0;
    }
/*void display_menu(){
cout<< "1.Type A"<< endl;
cout<< "2.Type B"<< endl;
cout<< "3.Type C"<< endl;
cout<< "4.Type D"<< endl;
cout<< "5.Type E"<< endl;
cout<< "6.Type F"<< endl;
}

int get_decision(){
int decision;

*/
