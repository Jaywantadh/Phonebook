/*
***Problem Statement: Phonebook Directory***

Problem Description:-
You are tasked with developing a phonebook directory program that allows users to manage their contacts. 
The program should provide various functionalities, including adding new contacts, searching for contacts, 
listing all contacts, modifying existing contacts, and deleting contacts. The goal is to create an efficient
and user-friendly phonebook directory application.

***Algorithm: Phonebook Directory***

Step 1: Define Constants
   - Define MAX_CONTACTS as the maximum number of contacts the program can store.

Step 2: Define Data Structure
   - Create a structure Contact to represent a contact with fields:
     - name (string): the name of the contact
     - address (string): the address of the contact
     - gender (string): the gender of the contact
     - gmail (string): the Gmail address of the contact
     - phone (double): the phone number of the contact

Step 3: Initialize Global Variables
   - Create a global array of Contacts called contacts.
   - Initialize contactCount to 0, representing the number of contacts stored.

Step 4: Define Function Prototypes
   - Define function prototypes for the following functions:
     - menu(): Display a menu and handle user choices.
     - addContact(): Add a new contact to the phonebook.
     - searchContact(): Search for a contact by name.
     - listContacts(): List all contacts in the phonebook.
     - modifyContact(): Modify an existing contact.
     - deleteContact(): Delete an existing contact.
     - exitProgram(): Perform cleanup and exit the program.

Step 5: Implement the main() Function
   - Initialize the program by calling menu().

Step 6: Implement menu() Function
   - Display a menu with options for the user to choose.
   - Use a loop to continuously prompt the user for their choice.
   - Depending on the choice, call the corresponding function.
   - Exit the program if the user chooses to exit.

Step 7: Implement addContact() Function
   - Check if there is space for a new contact in the contacts array.
   - Prompt the user to enter contact details (name, address, gender, Gmail, phone).
   - Add the new contact to the contacts array and increment contactCount.
   - Display a success message if added, or an error message if the contact list is full.

Step 8: Implement searchContact() Function
   - Prompt the user to enter the name to search for.
   - Iterate through the contacts array to search for contacts with matching names.
   - Display the details of found contacts.
   - Display a message if no contacts are found.

Step 9: Implement listContacts() Function
   - Iterate through the contacts array and list all stored contacts.
   - Display a message if no contacts are found.

Step 10: Implement modifyContact() Function
   - Prompt the user to enter the name of the contact to modify.
   - Search for the contact with a matching name in the contacts array.
   - If found, prompt the user to enter new contact details and update the contact.
   - Display a success message if modified, or an error message if the contact is not found.

Step 11: Implement deleteContact() Function
   - Prompt the user to enter the name of the contact to delete.
   - Search for the contact with a matching name in the contacts array.
   - If found, remove the contact and shift the remaining contacts.
   - Display a success message if deleted, or an error message if the contact is not found.

Step 12: Implement exitProgram() Function
   - Perform any necessary cleanup operations.
   - Display a farewell message and exit the program.

Step 13: End of Algorithm



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function name: Menu Driven Phonebook  
//  Description:The technical function of the phonebook directory program is to provide users with the 
//              the ability to add,search,list,modify and delete contacts, as well as gradually exit the program,
//              enabling efficient managment of contact innformation.
//  Input: Set of Strings and Integer 
//  Output: The saved return of String and Interger
//  Author: Jaywant Sandeep Adhau
//  Date: 04/10/2023(clock-24H)
//  (Update:05/10/2023|Time:23:05[IST])        
//  (Update:07/10/2023|Time:23:05[IST])
//  (Update:08/10/2023|Time:02:22[IST])
//  (Update:08/10/2023|Time:14:58[IST])
//
//
//
//
//
//
//
//
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Constants
#define MAX_CONTACTS 100

// Structure to represent a contact
typedef struct
{
    char name[100];
    char address[100];
    char gender[8];
    char gmail[100];
    double phone;
} Contact;

// Global variables
Contact contacts[MAX_CONTACTS]; // Array to store contacts
int contactCount = 0;           // Number of contacts currently stored

// Function prototypes
void menu(void);
void addContact(void);
void searchContact(void);
void listContact(void);
void modifyContact(void);
void deleteContact(void);
void exitProgram(void);

// Display a menu and handle user choices
void menu()
{
    int choice;
    while (1)
    {
        // Display menu options and prompt for user input
        printf("\nPHONEBOOK DICTIONARY\n");
        printf("1. Add New Contact\n");
        printf("2. Search The Contact\n");
        printf("3. List Contacts\n"); // Corrected the option number
        printf("4. Modify a Contact\n");
        printf("5. Delete a Contact\n"); // Corrected the option number
        printf("6. EXIT\n");             // Corrected the option number
        printf("ENTER YOUR CHOICE: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addContact();
            break;
        case 2:
            searchContact();
            break;
        case 3:
            listContact();
            break;
        case 4:
            modifyContact();
            break;
        case 5:
            deleteContact();
            break;
        case 6:
            exitProgram();
            break;
        default:
            printf("INVALID REQUEST MADE,\nYou may wanna try again?\n");
            break;
        }
    }
}

// Add a new contact to your phonebook
void addContact()
{
    // Check if there is space for a new contact
    if (contactCount < MAX_CONTACTS)
    {
        // Prompt the user to enter contact details
        printf("Enter the details below\n");
        Contact newContact;
        printf("Name: ");
        scanf("%s", newContact.name);
        printf("\nAddress: "); // Corrected the prompt message
        scanf("%s", newContact.address);
        printf("\nGender: ");
        scanf("%s", newContact.gender);
        printf("\nGmail: ");
        scanf("%s", newContact.gmail);
        printf("\nPhone number: ");
        scanf("%lf", &newContact.phone);

        // Add the new contact to the contacts array and increment the count
        contacts[contactCount++] = newContact;
        printf("\nContact added successfully!\n");
    }
    else
    {
        printf("Sorry! The Contact List Is Full!\n");
    }
}

// Search for a contact by name
void searchContact()
{
    // Prompt the user to enter the name to search for
    char searchName[100];
    printf("Enter the name to Search: ");
    scanf("%s", searchName);

    int found = 0;
    for (int i = 0; i < contactCount; i++)
    {
        // Perform a case-insensitive partial search using strstr
        if (strstr(contacts[i].name, searchName) != NULL)
        {
            found = 1;
            // Display the found contact's details
            printf("Contact found!\n");
            printf("Name: %s\n", contacts[i].name);
            printf("Address: %s\n", contacts[i].address);
            printf("Gender: %s\n", contacts[i].gender);
            printf("Gmail: %s\n", contacts[i].gmail);
            printf("Phone number: %.lf\n", contacts[i].phone); // Corrected the format specifier
        }
    }
    if (!found)
    {
        printf("Contact not found!\n");
    }
}

// List all the contacts in the phonebook
void listContact()
{
    // Iterate through the contacts array and list all stored contacts
    for (int i = 0; i < contactCount; i++)
    {
        printf("Contact %d:\n", i + 1);
        printf("Name: %s\n", contacts[i].name);
        printf("Address: %s\n", contacts[i].address);
        printf("Gender: %s\n", contacts[i].gender);
        printf("Gmail: %s\n", contacts[i].gmail);
        printf("--------------------------------\n");
    }
    if (contactCount == 0)
    {
        printf("No Contacts found.\n");
    }
}

// Modify a previously made contact
void modifyContact()
{
    // Prompt user to enter the contact name to modify
    char searchName[100];
    printf("Enter the name to modify: ");
    scanf("%s", searchName);

    int found = 0;
    for (int i = 0; i < contactCount; i++)
    {
        // Check if the contact matches with the searched contact
        if (strcmp(contacts[i].name, searchName) == 0)
        {
            found = 1;
            printf("Enter the new contact details here\n");
            printf("Name: ");
            scanf("%s", contacts[i].name);
            printf("Address: ");
            scanf("%s", contacts[i].address);
            printf("Gender: ");
            scanf("%s", contacts[i].gender);
            printf("Gmail: ");
            scanf("%s", contacts[i].gmail);
            printf("Phone number: ");
            scanf("%lf", &contacts[i].phone);

            printf("YOUR CONTACT HAS BEEN MODIFIED SUCCESSFULLY!\n");
        }
    }
    if (!found)
    {
        printf("Contact not found, Try again!\n");
    }
}

// Delete a contact
void deleteContact()
{
    // Prompt user to enter the contact name to delete
    char searchName[100];
    printf("Enter the name to Delete: ");
    scanf("%s", searchName);

    int found = 0;
    for (int i = 0; i < contactCount; i++)
    {
        // Check if the given name matches with the existing contact
        if (strcmp(contacts[i].name, searchName) == 0)
        {
            found = 1;
            // Shift all the contacts one position back
            for (int j = i; j < contactCount - 1; j++)
            {
                contacts[j] = contacts[j + 1];
            }

            contactCount--; // Decrement the count of contacts by one
            printf("YOUR CONTACT HAS BEEN SUCCESSFULLY DELETED!!\n");
        }
    }
    if (!found)
    {
        printf("The contact you've entered is not in this phonebook, please try again!\n");
    }
}

// Perform a clear clean-up and exit
void exitProgram()
{
    // Perform cleanup or any other necessary operations before exiting
    printf("Thank you for using Phonebook,\nHave a Great day!\n");
    exit(0);
}

int main()
{
    // Entry point of the program
    menu();
    return 0;
}

/*
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
***TEST CASES***
CASE 1: 
PHONEBOOK DICTIONARY
1. Add New Contact
2. Search The Contact
3. List Contacts
4. Modify a Contact
5. Delete a Contact
6. EXIT
ENTER YOUR CHOICE: 1
Enter the details below
Name: jay

Address: kjsdflkdsjf

Gender: male

Gmail: jay123@gmail.com

Phone number: 9545014449

Contact added successfully!

PHONEBOOK DICTIONARY
1. Add New Contact
2. Search The Contact
3. List Contacts
4. Modify a Contact
5. Delete a Contact
6. EXIT
ENTER YOUR CHOICE: 2
Enter the name to Search: jay
Contact found!
Name: jay
Address: kjsdflkdsjf
Gender: male
Gmail: jay123@gmail.com
Phone number: 9545014449

PHONEBOOK DICTIONARY
1. Add New Contact
2. Search The Contact
3. List Contacts
4. Modify a Contact
5. Delete a Contact
6. EXIT
ENTER YOUR CHOICE: 3
Contact 1:
Name: jay
Address: kjsdflkdsjf
Gender: male
Gmail: jay123@gmail.com
--------------------------------

PHONEBOOK DICTIONARY
1. Add New Contact
2. Search The Contact
3. List Contacts
4. Modify a Contact
5. Delete a Contact
6. EXIT
ENTER YOUR CHOICE: 4
Enter the name to modify: jay
Enter the new contact details here
Name: jaya
Address: ldakdaslkj
Gender: female
Gmail: jaya123@gmail.com
Phone number: 9552277674
YOUR CONTACT HAS BEEN MODIFIED SUCCESSFULLY!

PHONEBOOK DICTIONARY
1. Add New Contact
2. Search The Contact
3. List Contacts
4. Modify a Contact
5. Delete a Contact
6. EXIT
ENTER YOUR CHOICE: 3
Contact 1:
Name: jaya
Address: ldakdaslkj
Gender: female
Gmail: jaya123@gmail.com
--------------------------------

PHONEBOOK DICTIONARY
1. Add New Contact
2. Search The Contact
3. List Contacts
4. Modify a Contact
5. Delete a Contact
6. EXIT
ENTER YOUR CHOICE: 5
Enter the name to Delete: jaya
YOUR CONTACT HAS BEEN SUCCESSFULLY DELETED!!

PHONEBOOK DICTIONARY
1. Add New Contact
2. Search The Contact
3. List Contacts
4. Modify a Contact
5. Delete a Contact
6. EXIT
ENTER YOUR CHOICE: 6
Thank you for using Phonebook,
Have a Great day!

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
*/