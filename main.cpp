/*
______________________________________________________________________________________________________
                                    C++ phone book console application by:
    YORDANOS SOLOMON

                            Description:
        This C++ program implements a simple phone book application. The application uses
    a class structure with two classes: Contact and PhoneBook. Contacts are stored in an
    array within the PhoneBook class, and the program allows users to perform various
    operations such as adding, modifying, searching, and deleting contacts.

    Note: The program assumes a maximum capacity of 100 contacts and uses a simple console-based interface.
_______________________________________________________________________________________________________
*/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

class Contact {
public:
    string firstName;
    string lastName;
    string phoneNumber;
    string address;
};

class PhoneBook{
private:
    Contact contactsArray[100];
    int currentSize;
public:
//default constructor that initialize the currentSize
    PhoneBook() {
        currentSize = 0;
}
//Function declaration
void readContactsFromFile();
void addContact();
void listContacts();
void mainMenu();
void goBack();
void writeContactsInFile();
void modifyContact();
void modifyContactField(Contact& contact);
void searchContact();
void searchContactBy(char option);
void selectContactToDelete();
};

//Main function
int main() {
    PhoneBook phoneBook;
    phoneBook.readContactsFromFile();
    phoneBook.mainMenu();
    phoneBook.writeContactsInFile();

    return 0;
}
//Function definition

void PhoneBook::readContactsFromFile() {
        ifstream input("contacts.txt");

        while (currentSize < 100 &&
               getline(input, contactsArray[currentSize].firstName, '|') &&
               getline(input, contactsArray[currentSize].lastName, '|') &&
               getline(input, contactsArray[currentSize].phoneNumber, '|') &&
               getline(input, contactsArray[currentSize].address)) {
            ++currentSize;
        }

        input.close();
}


void PhoneBook::writeContactsInFile() {
    ofstream output("contacts.txt");

    for (int i = 0; i < currentSize; ++i) {
        output << contactsArray[i].firstName << "|"
               << contactsArray[i].lastName << "|"
               << contactsArray[i].phoneNumber << "|"
               << contactsArray[i].address;
        if (i < currentSize - 1) {
            output << "\n";
        }
    }
    output.close();
}



void PhoneBook::goBack() {
    cout << "\n\n\t1.Go back to main menu.";
    cout << "\n\t2.Exit the phone book.";
    char number;
    cin >> number;
    cin.ignore();

    switch (number) {
    case '1':
      mainMenu();
      break;
    case '2':
      cout << "\n\tDo you want to save your changes before exiting? (y/n) ";
      char confirm;
      cin >> confirm;
      cin.ignore();

      if (confirm == 'y' || confirm == 'Y') {
        writeContactsInFile();
        cout << "\n\tContacts saved successfully!";
      }

      cout << "\n\tExiting the phone book!";
      exit(0);
      break;
    default:
      cout << "\n\tYou Entered a wrong number.";
      goBack();
      break;
  }
}

void PhoneBook::listContacts() {
    system("cls");
    cout << "\n\n\n\t\t\tContacts";

    if (currentSize == 0) {
    cout << "\n\n\tThe phone book is empty.";
    } else {
    cout << "\n\n\tThe contacts from the phone book are:\n\n\n\n";
    cout << setw(15) << left << "R.No"
         << setw(15) << left << "First Name"
         << setw(15) << left << "Last Name"
         << setw(15) << left << "Phone Number"
         << setw(20) << left << "Address" << endl;
    cout << "----------------------------------------------------------------------------" << endl;

    for (int i = 0; i < currentSize; ++i) {
        cout << setw(15) << left << i
             << setw(15) << left << contactsArray[i].firstName
             << setw(15) << left << contactsArray[i].lastName
             << setw(15) << left << contactsArray[i].phoneNumber
             << setw(15) << left << contactsArray[i].address << endl;
        }
    }
}
void PhoneBook::addContact() {
    char ch;
    do{
        if (currentSize < 100) {
        cout << "\n\n\n\t\t\tAdd a new contact\n";

        cout << "\n\tEnter the first name: ";
        getline(cin, contactsArray[currentSize].firstName);
        cout << "\n\tEnter the last name: ";
        getline(cin, contactsArray[currentSize].lastName);
        cout << "\n\tEnter the phone number: ";
        getline(cin, contactsArray[currentSize].phoneNumber);
        cout << "\n\tEnter the address: ";
        getline(cin, contactsArray[currentSize].address);
        currentSize++;
    } else {
        cout << "\n\tThe phone book is full. Cannot add more contacts.";
    }
    cout << "Do you want to add more contacts? (y/n)";
    cin >> ch;
    cin.ignore();
    }while(ch=='y' || ch=='Y');
}


void PhoneBook::modifyContact() {
    system("cls");
    cout << "\n\n\n\t\t\tModify a contact from the phone book";
    if (currentSize == 0) {
        cout << "\n\n\tThe phone book is empty.";
        return;
    }

    listContacts();

    cout << "\n\n\tEnter the number of the contact that you want to modify from the phone book: ";
    int number;
    cin >> number;
    cin.ignore();

    modifyContactField(contactsArray[number]);
}

void PhoneBook::modifyContactField(Contact& contact) {
    cout << "\n\tWhat do you want to modify in this contact?";
    cout << "\n\t1.Modify the first name";
    cout << "\n\t2.Modify the last name";
    cout << "\n\t3.Modify the phone number";
    cout << "\n\t4.Modify the address";
    cout << "\n\n\tEnter the number of the option you want:";

    char answer;
    cin >> answer;
    cin.ignore();
    string newInfo;
    switch (answer) {
        case '1':
            cout << "\n\tEnter the new first name: ";
            getline(cin, newInfo);
            contact.firstName = newInfo;
            break;
        case '2':
            cout << "\n\tEnter the new last name: ";
            getline(cin, newInfo);
            contact.lastName = newInfo;
            break;
        case '3':
            cout << "\n\tEnter the new phone number: ";
            getline(cin, newInfo);
            contact.phoneNumber = newInfo;
            break;
        case '4':
            cout << "\n\tEnter the new address: ";
            getline(cin, newInfo);
            contact.address = newInfo;
            break;
        default:
            cout << "\n\n\tYou Entered a wrong number.";
            break;
    }

    cout << "\n\n\tDo you want to modify anything else about this contact? ";
    cout << "\n\t1.Yes";
    cout << "\n\t2.No";
    cout << "\n\n\tEnter the number of the option you want:";
    char option;
    cin >> option;
    cin.ignore();

    switch (option) {
        case '1':
            modifyContactField(contact);
            break;
        case '2':
            break;
        default:
            cout << "\n\n\tYou Entered a wrong number.";
            break;
    }
}



void PhoneBook::searchContact() {
    system("cls");
    cout << "\n\n\n\t\t\tSearch for a specific contact\n";
    cout << "\n\t1.Search by first name";
    cout << "\n\t2.Search by last name";
    cout << "\n\t3.Search by phone number";
    cout << "\n\tEnter the number of the option you want : ";

    char number;
    cin >> number;
    cin.ignore();
    searchContactBy(number);
}

void PhoneBook::searchContactBy(char option) {
    system("cls");
    string searchText;

    switch (option) {
        case '1':
            cout << "\n\tEnter the first name or a part of it: ";
            getline(cin, searchText);

            for (int i = 0; i < currentSize; ++i) {
                if (searchText.length() <= contactsArray[i].firstName.length()) {
                bool match = true;

                for (int j = 0; j < searchText.length(); ++j) {
                    if (searchText[j] != contactsArray[i].firstName[j]) {
                        match = false;
                        break;
                    }
                }
                if (match) {
                    cout << setw(15) << left << "R.No"
                         << setw(15) << left << "First Name"
                         << setw(15) << left << "Last Name"
                         << setw(15) << left << "Phone Number"
                         << setw(20) << left << "Address" << endl;
                    cout << "----------------------------------------------------------------------------" << endl;

                    cout << setw(15) << left << i
                         << setw(15) << left << contactsArray[i].firstName
                         << setw(15) << left << contactsArray[i].lastName
                         << setw(15) << left << contactsArray[i].phoneNumber
                         << setw(15) << left << contactsArray[i].address << endl;
                    }else{
                    cout << "No match is found with: " << searchText << " input." << endl;
                    }
                }
            }
            break;
        case '2':
            cout << "\n\tEnter the last name or a part of it: ";
            getline(cin, searchText);

            for (int i = 0; i < currentSize; ++i) {
                if (searchText.length() <= contactsArray[i].lastName.length()) {
                bool match = true;

                for (int j = 0; j < searchText.length(); ++j) {
                    if (searchText[j] != contactsArray[i].lastName[j]) {
                        match = false;
                        break;
                    }
                }
                if (match) {
                    cout << setw(15) << left << "R.No"
                         << setw(15) << left << "First Name"
                         << setw(15) << left << "Last Name"
                         << setw(15) << left << "Phone Number"
                         << setw(20) << left << "Address" << endl;
                    cout << "----------------------------------------------------------------------------" << endl;

                    cout << setw(15) << left << i
                         << setw(15) << left << contactsArray[i].firstName
                         << setw(15) << left << contactsArray[i].lastName
                         << setw(15) << left << contactsArray[i].phoneNumber
                         << setw(15) << left << contactsArray[i].address << endl;
                    }else{
                    cout << "No match is found with: " << searchText << " input." << endl;
                    }
                }
            }
            break;
        default:
            cout << "\n\n\tYou Entered a wrong number.";
            break;
    }
}

void PhoneBook::selectContactToDelete() {
    system("cls");
    cout << "\n\n\n\t\t\tDelete a contact from the phone book";
    if (currentSize == 0) {
        cout << "\n\n\tThe phone book is empty.";
        return;
    }

    listContacts();

    cout << "\n\n\tEnter the number of the contact that you want to delete from the phone book: ";
    int number;
    cin >> number;
    cin.ignore();

    if (number >= 0 && number < currentSize) {
        // Shift contacts to remove the selected one
        for (int i = number; i < currentSize - 1; ++i) {
            contactsArray[i] = contactsArray[i + 1];
        }
        currentSize--;

        cout << "\n\tThe contact has been deleted.";
    } else {
        cout << "\n\tYou Entered a wrong number.";
    }
}


void PhoneBook::mainMenu() {
    system("cls");
    system("color F9");


     cout << "                         /$$                                           \n";
     cout << "                        | $$                                           \n";
     cout << " /$$  /$$  /$$  /$$$$$$ | $$  /$$$$$$$  /$$$$$$  /$$$$$$/$$$$   /$$$$$$ \n";
     cout << "| $$ | $$ | $$ /$$    $$| $$ /$$______//$$    $$| $$_  $$_  $$ /$$__  $$\n";
     cout << "| $$ | $$ | $$| $$$$$$$$| $$| $$      | $$  \\ $$| $$ \\ $$ \\ $$|$$$$$$\n";
     cout << "| $$ | $$ | $$| $$_/| $$| $$| $$      | $$|  $$ | $$ | $$ | $$_/$$  \n";
     cout << "|  $$$$$/$$$$/|  $$$$$$$| $$|  $$$$$$$|  $$$$$$/| $$ | $$ | $$|  $$$$$$$  \n";
     cout << " \\_/\_/  \\_/|/ \\_/ \\__/ |/ |/ |/ \\___/ \_____/ |__/ |__/ |_/ \_____/\n";
     cout << "                                                                          \n";
     cout << "                                                                          \n";
     cout << "                                                                          \n";
    cout << "\n\n\n\t\t\tPhone Book. Main Menu";
    cout << "\n\n\tChoose an option by inserting the number of the option:\n";
    cout << "\n\t1.List all the contacts";
    cout << "\n\t2.Add a new contact";
    cout << "\n\t3.Modify a contact";
    cout << "\n\t4.Delete a contact";
    cout << "\n\t5.Search for a contact";
    cout << "\n\t6.Exit the phone book";
    cout << "\n\n\tEnter the number of the option you want:";
    char option;
    cin >> option;
    cin.ignore();

    switch (option) {
        case '1':
            listContacts();
            break;
        case '2':
            addContact();
            writeContactsInFile();
            break;
        case '3':
            modifyContact();
             writeContactsInFile();
            break;
        case '4':
            selectContactToDelete();
            writeContactsInFile();
            break;
        case '5':
            searchContact();
            break;
        case '6':
            writeContactsInFile();
            return;
        default:
            cout << "\n\n\tYou Entered a wrong number.";
            break;
    }
    goBack();
}
