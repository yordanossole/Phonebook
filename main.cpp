#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

fstream file;
string fileName = "vsfile";
char ch;
int SIZE = 100;

struct phonebook
{
    string fName;
    string pNo;
};

    void saveContact();
    void editContact();
    void showAllContact();
    void searchContact();
    void showFavContact();
    void deletContact();
    void favContact();

phonebook contacts[100];

void menu();
void inputValidator();

int main()
{
    cout << "\t Phonebook app" << endl;
    cout << "Enter your choice(1-8): " << endl;
    cout << "1) Save Contact" << endl;
    cout << "2) Edit Contact" << endl;
    cout << "3) Show All Contacts" << endl;
    cout << "4) Search Contact" << endl;
    cout << "5) Show Favorite Contact" << endl;
    cout << "6) Delete Contact" << endl;
    cout << "7) Exit App" << endl;
    cout << "8) " << endl;

    do
    {
        switch(ch)
        {
        case 1:
            saveContact();
            break;
        }
    }while(ch!=7);
   // contacts[0].saveContact();
    return 0;
}



void saveContact()
{
//    do{
        for(int i=0; i<SIZE; i++)
        {
            file.open(fileName, ios::out | ios::binary);
            if(file.is_open())
            {
                do
                {
                    cout << "Enter full name: ";
                    getline(cin, contacts[i].fName);
                    cout << "\nEnter phone number: ";
                    getline(cin, contacts[i].pNo);
                    cout << "Do you want to continue saving new contact: Yes(Y/y) or No(N/n): ";
                    cin >> ch;
                }while(ch == ('Y'||'y'));
            }
            else
            {
                cerr << "Unable to open the file!!!" << endl;
                exit(1);
            }
        }
        for(int i=0; i<SIZE; i++)
        {
            file.write((char*) &contacts[i], sizeof(phonebook));
        }

//        cout << "Do you want to continue saving new contact: Yes(Y/y) or No(N/n): ";
//        cin >> ch;
//    }while( ch == (Y||y));
}

void editContact()
{

}
/*
void phonebook::showAllContact()
{

}
void phonebook::searchContact()
{

}
void phonebook::showFavContact()
{

}
void phonebook::deletContact()
{

}
void phonebook::favContact()
{

}
*/
