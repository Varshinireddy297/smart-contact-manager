//---------------------SMART CONTACT MANAGER---------------------------
#include <bits/stdc++.h>
using namespace std;

// Structure to store each contact
struct Contact {
    string name;
    string phone;
    Contact* next; // pointer to next contact
};

// Stack structure to store deleted contacts (for undo)
struct Stack {
    Contact* top = NULL; // top of stack

    // Push deleted contact into stack
    void push(string name, string phone) {
        Contact* temp = new Contact;
        temp->name = name;
        temp->phone = phone;
        temp->next = top; // link to previous top
        top = temp;       // update top
    }

    // Check if stack is empty
    bool isEmpty() {
        return top == NULL;
    }

    // Pop last deleted contact
    Contact* pop() {
        if (isEmpty()) return NULL;

        Contact* temp = top;
        top = top->next; // move top down
        return temp;
    }
};

// Linked list to manage contacts
struct ContactList {
    Contact* head = NULL; // start of list
    Stack undoStack;      // stack for undo delete

    // Add new contact at end
    void addContact(string name, string phone) {
        Contact* newContact = new Contact;
        newContact->name = name;
        newContact->phone = phone;
        newContact->next = NULL;

        // If list is empty
        if (head == NULL) {
            head = newContact;
        } else {
            // Go to last node
            Contact* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newContact; // attach new node
        }

        cout << "Contact added successfully!\n";
    }

    // Display all contacts
    void displayContacts() {
        if (head == NULL) {
            cout << "No contacts available.\n";
            return;
        }

        Contact* temp = head;
        cout << "\nContact List:\n";

        // Traverse list
        while (temp != NULL) {
            cout << temp->name << " - " << temp->phone << endl;
            temp = temp->next;
        }
    }

    // Search contact by name
    void searchContact(string key) {
        Contact* temp = head;
        bool found = false;

        while (temp != NULL) {
            if (temp->name == key) {
                cout << "Found: " << temp->name << " - " << temp->phone << endl;
                found = true;
                break;
            }
            temp = temp->next;
        }

        if (!found) {
            cout << "Contact not found.\n";
        }
    }

    // Delete contact by name
    void deleteContact(string key) {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }

        Contact* temp = head;
        Contact* prev = NULL;

        // If first node is to be deleted
        if (temp->name == key) {
            head = temp->next;

            // Save deleted contact in stack
            undoStack.push(temp->name, temp->phone);

            cout << "Deleted successfully!\n";
            delete temp;
            return;
        }

        // Search for contact
        while (temp != NULL && temp->name != key) {
            prev = temp;
            temp = temp->next;
        }

        // If not found
        if (temp == NULL) {
            cout << "Contact not found.\n";
            return;
        }

        // Remove node
        prev->next = temp->next;

        // Save for undo
        undoStack.push(temp->name, temp->phone);

        cout << "Deleted successfully!\n";
        delete temp;
    }

    // Undo last delete
    void undoDelete() {
        if (undoStack.isEmpty()) {
            cout << "Nothing to undo.\n";
            return;
        }

        // Get last deleted contact
        Contact* restored = undoStack.pop();
        restored->next = NULL;

        // Add it back at end
        if (head == NULL) {
            head = restored;
        } else {
            Contact* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = restored;
        }

        cout << "Undo successful! Contact restored.\n";
    }

    // Sort contacts by name (simple bubble-like sort)
    void sortContacts() {
        if (head == NULL) return;

        for (Contact* i = head; i != NULL; i = i->next) {
            for (Contact* j = i->next; j != NULL; j = j->next) {
                // Compare names and swap data
                if (i->name > j->name) {
                    swap(i->name, j->name);
                    swap(i->phone, j->phone);
                }
            }
        }

        cout << "Contacts sorted successfully!\n";
    }
};

int main() {
    ContactList cl;
    int choice;
    string name, phone;

    while (true) {
        cout << "\n===== Smart Contact Manager =====\n";
        cout << "1. Add Contact\n";
        cout << "2. Display Contacts\n";
        cout << "3. Search Contact\n";
        cout << "4. Delete Contact\n";
        cout << "5. Undo Delete\n";
        cout << "6. Sort Contacts\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter name: ";
            cin >> name;
            cout << "Enter phone: ";
            cin >> phone;
            // Check if phone number is exactly 10 digits
            if (phone.length() != 10) {
              cout << "Error: Phone number must be exactly 10 digits!\n";
            } 
            else {
               cl.addContact(name, phone);
            }
            break;

        case 2:
            cl.displayContacts();
            break;

        case 3:
            cout << "Enter name to search: ";
            cin >> name;
            cl.searchContact(name);
            break;

        case 4:
            cout << "Enter name to delete: ";
            cin >> name;
            cl.deleteContact(name);
            break;

        case 5:
            cl.undoDelete();
            break;

        case 6:
            cl.sortContacts();
            break;

        case 7:
            cout << "Exiting...\n";
            return 0;

        default:
            cout << "Invalid choice!\n";
        }
    }
}
