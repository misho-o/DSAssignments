
#include <iostream>
#include <string>
using namespace std;
//TASK 3:
struct Passenger {
    string name;
    Passenger* next;
    Passenger(string n) {
        name = n;
        next = NULL;
    }
};

void reserveTicket(Passenger*& head, string name) {
    Passenger* newNode = new Passenger(name);

    if (head == NULL || name < head->name) {
        newNode->next = head;
        head = newNode;
        cout << name << " has reserved a ticket.\n";
        return;
    }

    Passenger* temp = head;
    while (temp->next != NULL && temp->next->name < name)
        temp = temp->next;

    newNode->next = temp->next;
    temp->next = newNode;

    cout << name << " has reserved a ticket.\n";
}

// Cancel reservation
void cancelReservation(Passenger*& head, string name) {
    if (head == NULL) {
        cout << "No reservations found.\n";
        return;
    }

    if (head->name == name) {
        Passenger* toDelete = head;
        head = head->next;
        delete toDelete;
        cout << name << "'s reservation cancelled.\n";
        return;
    }

    Passenger* temp = head;
    while (temp->next != NULL && temp->next->name != name)
        temp = temp->next;

    if (temp->next == NULL) {
        cout << "Reservation not found for " << name << ".\n";
        return;
    }

    Passenger* toDelete = temp->next;
    temp->next = toDelete->next;
    delete toDelete;
    cout << name << "'s reservation cancelled.\n";
}

void checkReservation(Passenger* head, string name) {
    Passenger* temp = head;
    while (temp != NULL) {
        if (temp->name == name) {
            cout << name << " has a reservation.\n";
            return;
        }
        temp = temp->next;
    }
    cout << name << " does not have a reservation.\n";
}

void displayPassengers(Passenger* head) {
    if (head == NULL) {
        cout << "No passengers reserved.\n";
        return;
    }
    cout << "\nList of passengers:\n";
    Passenger* temp = head;
    while (temp != NULL) {
        cout << "- " << temp->name << endl;
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Passenger* head = NULL;
    int choice;
    string name;

    do {
        cout << "\n--- Airline Reservation Menu ---\n";
        cout << "1. Reserve a ticket\n";
        cout << "2. Cancel a reservation\n";
        cout << "3. Check reservation\n";
        cout << "4. Display passengers\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter passenger name: ";
            cin >> name;
            reserveTicket(head, name);
            break;
        case 2:
            cout << "Enter passenger name to cancel: ";
            cin >> name;
            cancelReservation(head, name);
            break;
        case 3:
            cout << "Enter passenger name to check: ";
            cin >> name;
            checkReservation(head, name);
            break;
        case 4:
            displayPassengers(head);
            break;
        case 5:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);

    return 0;
}

