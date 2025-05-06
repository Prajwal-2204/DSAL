#include<iostream>
#include<iomanip>
using namespace std;

#define max 10

// Structure of Employee
struct employee {
    string name;
    long int employee_id;
    string designation;
    int salary;
};

int num = -1;
employee emp[max];

// Function to insert the data into
// the array of structures
void insert() {
    if (num >= max - 1) {
        cout << "Employee Table Full\n";
        return;
    }

    long int temp_id;
    cout << "Enter the Employee ID: ";
    cin >> temp_id;

    // Check for duplicate ID
    for (int i = 0; i <= num; i++) {
        if (emp[i].employee_id == temp_id) {
            cout << "Employee ID already exists!\n";
            return;
        }
    }

    num++;
    emp[num].employee_id = temp_id;

    cout << "Enter Name: ";
    cin.ignore(); // Clear newline before getline
    getline(cin, emp[num].name);

    cout << "Enter Designation: ";
    getline(cin, emp[num].designation);

    cout << "Enter Salary: ";
    cin >> emp[num].salary;

    cout << "Employee record added successfully!\n";
}

// Function to delete record at index i
void deleteIndex(int i) {
    for (int j = i; j < num; j++) {
        emp[j] = emp[j + 1];
    }
}

// Function to display all records
void displayAllRecords() {
    if (num == -1) {
        cout << "No records present!\n";
        return;
    }

    cout << endl << setw(5) << "ID" << setw(15) << "NAME"
         << setw(20) << "DESIGNATION" << setw(10) << "SALARY\n";
    for (int i = 0; i <= num; i++) {
        cout << setw(5) << emp[i].employee_id
             << setw(15) << emp[i].name
             << setw(20) << emp[i].designation
             << setw(10) << emp[i].salary << endl;
    }
}

// Function to delete a record
void deleteRecord() {
    int employee_id;
    cout << "Enter the Employee ID to Delete Record: ";
    cin >> employee_id;

    for (int i = 0; i <= num; i++) {
        if (emp[i].employee_id == employee_id) {
            deleteIndex(i);
            num--;
            cout << "Record deleted successfully.\n";
            return;
        }
    }

    cout << "Employee ID not found.\n";
}

// Function to search for a record
void searchRecord() {
    int employee_id;
    cout << "Enter the Employee ID to Search Record: ";
    cin >> employee_id;

    for (int i = 0; i <= num; i++) {
        if (emp[i].employee_id == employee_id) {
            cout << endl << setw(5) << "ID" << setw(15) << "NAME"
                 << setw(20) << "DESIGNATION" << setw(10) << "SALARY\n";
            cout << setw(5) << emp[i].employee_id
                 << setw(15) << emp[i].name
                 << setw(20) << emp[i].designation
                 << setw(10) << emp[i].salary << endl;
            return;
        }
    }

    cout << "Employee record not found.\n";
}

// Driver Code
int main() {
    int option = 0;

    while (option != 5) {
        cout << "\n----- Employee Management System -----\n";
        cout << "1. Insert New Record\n";
        cout << "2. Display All Records\n";
        cout << "3. Delete Record\n";
        cout << "4. Search Record by Employee ID\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> option;

        switch (option) {
            case 1:
                insert();
                break;
            case 2:
                displayAllRecords();
                break;
            case 3:
                deleteRecord();
                break;
            case 4:
                searchRecord();
                break;
            case 5:
                cout << "\n***** You have exited *****\n";
                break;
            default:
                cout << "Enter valid option!\n";
                break;
        }
    }

    return 0;
}


