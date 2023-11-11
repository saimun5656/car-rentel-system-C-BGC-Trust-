#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Car {
public:
    string make;
    string model;
    bool isRented;

    Car(const string& make, const string& model) {
        this->make = make;
        this->model = model;
        this->isRented = false;
    }
};

class CarRentalSystem {
public:
    vector<Car> cars;
    string ownerPasskey = "passkey";  // Set your own passkey

    CarRentalSystem() {
        // Add some default cars to the list
        cars.push_back(Car("Toyota", "Camry"));
        cars.push_back(Car("Honda", "Civic"));
        cars.push_back(Car("Ford", "Focus"));
    }

    void listAllCars() {
        cout << "List of All Cars:" << endl;
        for (int i = 0; i < cars.size(); i++) {
            cout << i + 1 << ". " << cars[i].make << " " << cars[i].model;
            if (cars[i].isRented) {
                cout << " (Rented)";
            }
            cout << endl;
        }
    }

    void listUnrentedCars() {
        cout << "List of Unrented Cars:" << endl;
        for (int i = 0; i < cars.size(); i++) {
            if (!cars[i].isRented) {
                cout << i + 1 << ". " << cars[i].make << " " << cars[i].model << endl;
            }
        }
    }

    void listRentedCars() {
        cout << "List of Rented Cars:" << endl;
        for (int i = 0; i < cars.size(); i++) {
            if (cars[i].isRented) {
                cout << i + 1 << ". " << cars[i].make << " " << cars[i].model << endl;
            }
        }
    }

    void addCar(const string& make, const string& model, const string& passkey) {
        if (passkey == ownerPasskey) {
            Car newCar(make, model);
            cars.push_back(newCar);
            cout << "Car added successfully." << endl;
        } else {
            cout << "Invalid passkey. Car not added." << endl;
        }
    }

    void rentCar(int carIndex) {
        if (carIndex >= 0 && carIndex < cars.size()) {
            if (!cars[carIndex].isRented) {
                cars[carIndex].isRented = true;
                cout << "Car rented successfully." << endl;
            } else {
                cout << "Car is already rented." << endl;
            }
        } else {
            cout << "Invalid car index." << endl;
        }
    }

    void returnCar(int carIndex) {
        if (carIndex >= 0 && carIndex < cars.size()) {
            if (cars[carIndex].isRented) {
                cars[carIndex].isRented = false;
                cout << "Car returned successfully." << endl;
            } else {
                cout << "Car is not rented." << endl;
            }
        } else {
            cout << "Invalid car index." << endl;
        }
    }
};

int main() {
    CarRentalSystem rentalSystem;

    int choice;
    while (true) {
        cout << "Car Rental System Menu:" << endl;
        cout << "1. List of All Cars" << endl;
        cout << "2. Add New Car for Rent" << endl;
        cout << "3. Rent a Car" << endl;
        cout << "4. Return a Car" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            rentalSystem.listAllCars();
        } else if (choice == 2) {
            string make, model, passkey;
            cout << "Enter the owner's passkey: ";
            cin >> passkey;
            if (passkey == rentalSystem.ownerPasskey) {
                cout << "Enter the make of the car: ";
                cin >> make;
                cout << "Enter the model of the car: ";
                cin >> model;
                rentalSystem.addCar(make, model, passkey);
            } else {
                cout << "Invalid passkey. Car not added." << endl;
            }
        } else if (choice == 3) {
            rentalSystem.listUnrentedCars();
            int carIndex;
            cout << "Enter the index of the car to rent: ";
            cin >> carIndex;
            rentalSystem.rentCar(carIndex - 1);  // Adjust for 0-based index
        } else if (choice == 4) {
            rentalSystem.listRentedCars();
            int carIndex;
            cout << "Enter the index of the car to return: ";
            cin >> carIndex;
            rentalSystem.returnCar(carIndex - 1);  // Adjust for 0-based index
        } else if (choice == 5) {
            break;
        }
    }

    return 0;
}
