#include <iostream>
#include <cstring>
using namespace std;

class Train {
    private :
        int trainNumber;
        char trainName[50];
        char source[50];
        char destination[50];
        char trainTime[10];
        static int trainCount; 

    public :
        Train() {
            trainNumber = 0;
            strcpy(trainName, "");
            strcpy(source, "");
            strcpy(destination, "");
            strcpy(trainTime, "");
            trainCount++;
        }

        Train(int number, const char* name, const char* src, const char* dest, const char* time) {
            trainNumber = number;
            strcpy(trainName, name);
            strcpy(source, src);
            strcpy(destination, dest);
            strcpy(trainTime, time);
            trainCount++;
        }


        ~Train() {
            trainCount--;
        }


        void setTrainNumber(int number) { 
            trainNumber = number; 
        }
        int getTrainNumber() { 
            return trainNumber; 
        }


        void setTrainName(const char* name) { 
            strcpy(trainName, name); 
        }
        char *getTrainName() { 
            return trainName; 
        }


        void setSource(const char* src) { 
            strcpy(source, src); 
        }
        char *getSource() { 
            return source; 
        }


        void setDestination(const char* dest) { 
            strcpy(destination, dest); 
        }
        char *getDestination() { 
            return destination; 
        }


        void setTrainTime(const char* time) { 
            strcpy(trainTime, time); 
        }
        char *getTrainTime() { 
            return trainTime; 
        }

        void inputTrainDetails() {
            cout << "Enter Train Number :- ";
            cin >> trainNumber;
            cout << "Enter Train Name :- ";
            cin >> trainName;
            cout << "Enter Source :- ";
            cin >> source;
            cout << "Enter Destination :- ";
            cin >> destination;
            cout << "Enter Train Time :- ";
            cin >> trainTime;
        }

        void displayTrainDetails() {
            cout << "Train Number :- " << trainNumber << endl;
            cout << "Train Name :- " << trainName << endl;
            cout << "Source :- " << source << endl;
            cout << "Destination :- " << destination << endl;
            cout << "Train Time :- " << trainTime << endl;
        }
        static int getTrainCount() { 
            return trainCount; 
        }
};


class RailwaySystem {
    private :
        Train trains[100];
        int totalTrains;

    public :
        RailwaySystem() {
            totalTrains = 0;
        }

        void addTrain() {
            if (totalTrains < 100) {
                trains[totalTrains].inputTrainDetails();
                totalTrains++;
            } 
            else {
                cout << "warning !!! Train storage is full" << endl;
            }
        }

        void displayAllTrains() {
            if (totalTrains == 0) {
                cout << "No Records of train available" << endl;
                return 0;
            }
            for (int i = 0 ; i < totalTrains ; i++) {
                cout << "Train " << i + 1 << " Record :-" << endl;
                trains[i].displayTrainDetails();
                cout << "-----------------------------------------" << endl;
            }
        }

        void searchTrainByNumber(int number) {
            int found = 0;   // 0 = not found, 1 = found
            for (int i = 0; i < totalTrains; i++) {
                if (trains[i].getTrainNumber() == number) {
                    cout << "Train found !!!" << endl;
                    trains[i].displayTrainDetails();
                    found = 1;
                    break;
                }
            }
            if (found == 0) {
                cout << "Train with number " << number << " not found!" << endl;
            }
        }
};

int main() {
    RailwaySystem system;
    int choice, searchNumber;

    cout << endl << endl << "Initially, Enter Records for 3 trains Compulsary :- " << endl;
    for (int i = 0; i < 3; i++) {
        cout << endl << "--- Train " << i + 1 << " ---" << endl;
        system.addTrain();
    }

    do {
        cout << endl << "---- Railway Reservation System Menu ----" << endl << endl;
        cout << "1> Add New Train" << endl;
        cout << "2> Display Train Records" << endl;
        cout << "3> Search Train by Number" << endl;
        cout << "4> Exit" << endl << endl;
        cout << "-----------------------------------------" << endl;
        cout << "Enter your choice :- ";
        cin >> choice;
        cout << "-----------------------------------------" << endl;

        switch (choice) {
        case 1 : // Add New Train
            system.addTrain();
            break;
        case 2 : // Display Train Records
            system.displayAllTrains();
            break;
        case 3 : // Search Train by Number
            cout << "Enter Train Number to search :- ";
            cin >> searchNumber;
            system.searchTrainByNumber(searchNumber);
            break;
        case 4 : // Exit
            cout << "Exiting the system. Goodbye!" << endl;
            break;
        default : // Invalid choice
            cout << "Invalid choice !!! Try again " << endl;
        }
    } while (choice != 4);

    return 0;
}
