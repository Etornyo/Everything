#include <iostream>
#include <string>
#include <sqlite3.h>
#include <cstdlib>
#include <ctime>

using namespace std;
//Plate generation function
string generatePlateNumber() {
    string plateNumber = "";
    srand(time(NULL)); // Seed the random number generator with the current time
    for (int i = 0; i < 3; i++) {
        char letter = 'A' + rand() % 26; // Generate a random uppercase letter
        plateNumber += letter;
    }
    for (int i = 0; i < 3; i++) {
        char digit = '0' + rand() % 10; // Generate a random digit
        plateNumber += digit;
    }
    return plateNumber;
}


class Vehicle {
private:
    string make;
    string model;
    int year;
    string color;
    string plateNumber;
public:
    Vehicle(string mk, string mdl, int yr, string clr, string ptnum) {
        make = mk;
        model = mdl;
        year = yr;
        color = clr;
        plateNumber = ptnum;
    }
    string getMake() {
        return make;
    }
    string getModel() {
        return model;
    }
    int getYear() {
        return year;
    }
    string getColor() {
        return color;
    }
    string getPlateNumber() {
        return plateNumber;
    }
};


int main() {
	//database coding
	   sqlite3 *db;
   char *zErrMsg = 0;
   int rc;

   // Open the database
   rc = sqlite3_open("vehicle_reg.db", &db);

   if( rc ) {
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      return(0);
   } else {
      fprintf(stdout, "Opened database successfully\n");
   }

   // Create a table for vehicle registration
   char *sql = "CREATE TABLE VehicleReg("  \
         "ID INT PRIMARY KEY     NOT NULL," \
         "NAME           TEXT    NOT NULL," \
         "AGE            INT     NOT NULL," \
         "GENDER         CHAR(1) NOT NULL," \
         "VEHICLE_TYPE   TEXT    NOT NULL," \
         "LICENSE_NUMBER TEXT    NOT NULL," \
         "EXPIRY_DATE    DATE    NOT NULL);";

   rc = sqlite3_exec(db, sql, 0, 0, &zErrMsg);

   if( rc != SQLITE_OK ){
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   } else {
      fprintf(stdout, "Table created successfully\n");
   }

   // Insert data into the table
   sql = "INSERT INTO VehicleReg (ID, NAME, AGE, GENDER, VEHICLE_TYPE, LICENSE_NUMBER, EXPIRY_DATE) " \
         "VALUES (1, 'John Doe', 30, 'M', 'Car', 'ABC123', '2023-12-31'); " \
         "INSERT INTO VehicleReg (ID, NAME, AGE, GENDER, VEHICLE_TYPE, LICENSE_NUMBER, EXPIRY_DATE) " \
         "VALUES (2, 'Jane Doe', 28, 'F', 'Motorcycle', 'DEF456', '2024-06-30'); ";

   rc = sqlite3_exec(db, sql, 0, 0, &zErrMsg);

   if( rc != SQLITE_OK ){
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   } else {
      fprintf(stdout, "Data inserted successfully\n");
   }

   // Close the database
   sqlite3_close(db);

    string make, model, color, plateNumber;
    int year;
    cout << "Enter vehicle make: ";
    cin >> make;
    cout << "Enter vehicle model: ";
    cin >> model;
    cout << "Enter vehicle year: ";
    cin >> year;
    cout << "Enter vehicle color: ";
    cin >> color;

    plateNumber = generatePlateNumber();

    Vehicle vehicle(make, model, year, color, plateNumber);

    cout << "\nVehicle Registration Information" << endl;
    cout << "Make: " << vehicle.getMake() << endl;
    cout << "Model: " << vehicle.getModel() << endl;
    cout << "Year: " << vehicle.getYear() << endl;
    cout << "Color: " << vehicle.getColor() << endl;
    cout << "Plate Number: " << vehicle.getPlateNumber() << endl;

    return 0;
}

