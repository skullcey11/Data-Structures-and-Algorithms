#include <iostream>
using namespace std;
void printRollNumbers(const int arr[], int n) {
    cout << "Current roll numbers:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Roll number of student " << i + 1 << ": " << arr[i] << endl;
    }
}
void insertAtPosition(int arr[], int& n, int position, int element, int maxSize) {
    if (n >= maxSize) {
        cout << "Array is full. Cannot insert new element." << endl;
        return;
    }
    if (position < 1 || position > n + 1) {
        cout << "Invalid position. Insertion failed." << endl;
        return;
    }

    for (int i = n; i >= position; i--) {
        arr[i] = arr[i - 1];
    }
    arr[position - 1] = element;
    n++;
}

void deleteAtPosition(int arr[], int& n, int position) {
    if (n <= 0) {
        cout << "Array is empty. Nothing to delete." << endl;
        return;
    }
    if (position < 1 || position > n) {
        cout << "Invalid position. Deletion failed." << endl;
        return;
    }

    for (int i = position - 1; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    n--;
}
void StudentRollNumbers() {
    const int MAX_SIZE = 100; 
    int arr[MAX_SIZE];
    int n; 

    cout << "Enter the number of students: ";
    cin >> n;

    if (n > MAX_SIZE) {
        cout << "Number of students exceeds maximum limit. Reducing to " << MAX_SIZE << "." << endl;
        n = MAX_SIZE;
    }

    // Input roll numbers
    for (int i = 0; i < n; i++) {
        cout << "Enter roll number for student " << i + 1 << ": ";
        cin >> arr[i];
    }

    // Display initial roll numbers
    printRollNumbers(arr, n);

    int choice, element, position;
    do {
        cout << "\nOptions:" << endl;
        cout << "1. Insert Roll Number at Beginning" << endl;
        cout << "2. Insert Roll Number at End" << endl;
        cout << "3. Insert Roll Number at Specific Position" << endl;
        cout << "4. Delete Roll Number at Beginning" << endl;
        cout << "5. Delete Roll Number at End" << endl;
        cout << "6. Delete Roll Number at Specific Position" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter roll number to insert at beginning: ";
                cin >> element;
                insertAtPosition(arr, n, 1, element, MAX_SIZE);
                break;
            case 2:
                cout << "Enter roll number to insert at end: ";
                cin >> element;
                insertAtPosition(arr, n, n + 1, element, MAX_SIZE);
                break;
            case 3:
                cout << "Enter roll number to insert: ";
                cin >> element;
                cout << "Enter position to insert at (1 to " << n + 1 << "): ";
                cin >> position;
                insertAtPosition(arr, n, position, element, MAX_SIZE);
                break;
            case 4:
                deleteAtPosition(arr, n, 1);
                break;
            case 5:
                deleteAtPosition(arr, n, n);
                break;
            case 6:
                cout << "Enter position to delete (1 to " << n << "): ";
                cin >> position;
                deleteAtPosition(arr, n, position);
                break;
            case 7:
                cout << "Exiting." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

        if (choice >= 1 && choice <= 6) {
            printRollNumbers(arr, n);
        }
    } while (choice != 7);
}

int main() {
    StudentRollNumbers();
    return 0;
}
