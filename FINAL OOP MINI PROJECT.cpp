#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Struct to represent a Book
struct Book
{
    string poNumber;   // Purchase Order Number
    string bookName;   // Book Name
    string authorName; // Author Name
    int stock;         // Number of copies available
};

// Global array to store books
Book library[50];
int N = 0; // Actual number of books in the library

// Function to accept book details
void acceptBooks()
{
    cout << "\n\t\t\t\t\t\t\t|-----------------------------------------------------------|\n";
    cout << "\t\t\t\t\t\t\t|               Add Books to the Library                    |\n";
    cout << "\t\t\t\t\t\t\t|-----------------------------------------------------------|\n";

    cout << "Enter the number of books to add (max 50): ";
    int newBooks;
    cin >> newBooks;

    if (N + newBooks > 50)
    {
        cout << "Library can hold a maximum of 50 books only.\n";
        newBooks = 50 - N; // Limit to the remaining capacity
    }

    for (int i = 0; i < newBooks; i++)
    {
        cout << "\nEnter details for book " << N + 1 << ":\n";
        cout << "P.O. Number: ";
        cin >> library[N].poNumber;
        cout << "Book Name: ";
        cin.ignore();
        getline(cin, library[N].bookName);
        cout << "Author Name: ";
        getline(cin, library[N].authorName);
        cout << "Enter Stock to Load: ";
        cin >> library[N].stock;
        N++;
    }
    cout << "Books added successfully!\n";
}

// Function to display all books
void displayBooks()
{
    if (N == 0)
    {
        cout << "\nLibrary is empty. No books to display.\n";
        return;
    }

    cout << "\n\t\t\t\t\t\t\t|---------------------------------------------------------------------------------------|\n";
    cout << "\t\t\t\t\t\t\t|                                   Library Book Details                                  |\n";
    cout << "\t\t\t\t\t\t\t|-----------------------------------------------------------------------------------------|\n\n";
    cout << "|-------------------------------------------------------------------------------------------------------|\n";
    cout << "| " << setw(12) << left << "P.O. Number"
         << "| " << setw(25) << left << "Book Name"
         << "| " << setw(20) << left << "Author Name"
         << "| " << setw(10) << left << "Stock" << "|\n";
    cout << "|-------------------------------------------------------------------------------------------------------|\n";

    for (int i = 0; i < N; i++)
    {
        cout << "| " << setw(12) << left << library[i].poNumber
             << "| " << setw(25) << left << library[i].bookName
             << "| " << setw(20) << left << library[i].authorName
             << "| " << setw(10) << left << library[i].stock << "|\n";
    }
    cout << "|------------------------------------------------------------------------------------------------------|\n";
}

// Student Menu
void studentMenu()
{
    int studentChoice;
    string tempName, tempAuthor;
    int days;

    do
    {
        cout << "\n\t\t\t\t\t\t\t---------------------------------------------------|\n";
        cout << "\t\t\t\t\t\t\t|                  Student Menu                      |\n";
        cout << "\t\t\t\t\t\t\t|----------------------------------------------------|\n";
        cout << "\t\t\t\t\t\t\t|                        1. Borrow Book              |\n";
        cout << "\t\t\t\t\t\t\t|                        2. Return Book & pay fees   |\n";
        cout << "\t\t\t\t\t\t\t|                        3. View Library             |\n";
        cout << "\t\t\t\t\t\t\t|                        4. Exit                     |\n";
        cout << "\t\t\t\t\t\t\t|----------------------------------------------------|\n";
        cout << "Enter your choice: ";
        cin >> studentChoice;

        switch (studentChoice)
        {
        case 1: // Borrow Book
        {
            cout << "Enter Book name: ";
            cin.ignore();
            getline(cin, tempName);
            cout << "Enter Author name: ";
            getline(cin, tempAuthor);

            bool bookFound = false;
            for (int i = 0; i < N; i++)
            {
                if (library[i].bookName == tempName && library[i].authorName == tempAuthor && library[i].stock > 0)
                {
                    cout << "Book is available!\n";
                    library[i].stock--;
                    cout << "How many days do you want to borrow the book? (1 day = 5 Rupees): ";
                    cin >> days;
                    cout << "You need to pay " << days * 5 << " Rupees.\n";
                    bookFound = true;
                    break;
                }
            }
            if (!bookFound)
                cout << "Book not available or out of stock.\n";
            break;
        }
        case 2: // Return Book
        {
            cout << "Enter Book name to return: ";
            cin.ignore();
            getline(cin, tempName);
            cout << "Enter Author name: ";
            getline(cin, tempAuthor);

            int days, totalAmount;
            bool bookFound = false;
            for (int i = 0; i < N; i++)
            {
                if (library[i].bookName == tempName && library[i].authorName == tempAuthor)
                {
                    cout << "Enter the number of days the book was borrowed: ";
                    cin >> days;
                    totalAmount = days * 5;

                    string answer;
                    cout << "Total amount to pay: " << totalAmount << " Rupees.\n";
                    cout << "Do you want to pay? (yes/no): ";
                    cin >> answer;

                    if (answer == "yes")
                    {
                        library[i].stock++;
                        cout << "\n\t\t\t\t\t\t\t|----------------------------------------------------------|\n";
                        cout << "\t\t\t\t\t\t\t|                      SANJIVANI LIBRARY                   |\n";
                        cout << "\t\t\t\t\t\t\t|                       PAYMENT RECEIPT                    |\n";
                        cout << "\t\t\t\t\t\t\t|----------------------------------------------------------|\n";
                        cout << "\t\t\t\t\t\t\t| Book Title         : " << tempName << "\n";
                        cout << "\t\t\t\t\t\t\t| Author             : " << tempAuthor << "\n";
                        cout << "\t\t\t\t\t\t\t| Borrow Duration    : " << days << " days\n";
                        cout << "\t\t\t\t\t\t\t| Borrow Fee         : " << totalAmount << " Rupees\n";
                        cout << "\t\t\t\t\t\t\t| Payment Status     : Completed\n";
                        cout << "\t\t\t\t\t\t\t|----------------------------------------------------------|\n";
                        cout << "\t\t\t\t\t\t\t|                Thank you for using our library!          |\n";
                        cout << "\t\t\t\t\t\t\t|----------------------------------------------------------|\n";
                    }
                    else
                    {
                        cout << "Payment not completed.\n";
                    }
                    bookFound = true;
                    break;
                }
            }
            if (!bookFound)
                cout << "No such book to return.\n";
            break;
        }
        case 3: // View Library
            displayBooks();
            break;
        case 4: // Exit
            cout << "Exiting Student Menu...\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (studentChoice != 4);
}

// Teacher Menu
void teacherMenu()
{
    int teacherChoice;
    do
    {
        cout << "\n\t\t\t\t\t\t\t|-----------------------------------------------------------|\n";
        cout << "\t\t\t\t\t\t\t| 1. Add Books to Library                                   |\n";
        cout << "\t\t\t\t\t\t\t| 2. View All Books                                         |\n";
        cout << "\t\t\t\t\t\t\t| 3. Exit                                                   |\n";
        cout << "\t\t\t\t\t\t\t|-----------------------------------------------------------|\n";
        cout << "Enter your choice: ";
        cin >> teacherChoice;

        switch (teacherChoice)
        {
        case 1:
            acceptBooks();
            break;
        case 2:
            displayBooks();
            break;
        case 3:
            cout << "Exiting Teacher Menu...\n";
            break;
        default:
            cout << "Invalid choice! Please try again.\n";
        }
    } while (teacherChoice != 3);
}

// Login Page
void Login_page()
{
    int choice;
    cout << "\t\t\t\t\t\t\t|-----------------------------------------------------------|\n";
    cout << "\t\t\t\t\t\t\t|                 WELCOME TO SANJIVANI LIBRARY              |\n";
    cout << "\t\t\t\t\t\t\t|-----------------------------------------------------------|\n\n\n";
    do
    {

        cout << "\t\t\t\t\t\t\t|-----------------------------------------------------------|\n";
        cout << "\t\t\t\t\t\t\t| 1. Teacher Login                                          |\n";
        cout << "\t\t\t\t\t\t\t| 2. Student Login                                          |\n";
        cout << "\t\t\t\t\t\t\t| 3. Exit                                                   |\n";
        cout << "\t\t\t\t\t\t\t|-----------------------------------------------------------|\n\n\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 2:
        {
            string studentName, studentPass;
            cout << "Enter Your Name: ";
            cin >> studentName;
            cout << "Enter Password: ";
            cin >> studentPass;

            if (studentPass == "student123")
            {
                cout << "\n\t\t\t\t\t\t\t|-----------------------------|\n";
                cout << "\t\t\t\t\t\t\t|      LOGIN SUCCESSFUL       |\n";
                cout << "\t\t\t\t\t\t\t|-----------------------------|\n";
                studentMenu();
            }
            else
            {
                cout << "Wrong Password! Please try again.\n";
            }
            break;
        }
        case 1:
        {
            string teacherName, teacherPass;
            cout << "Enter Your Name: ";
            cin >> teacherName;
            cout << "Enter Password: ";
            cin >> teacherPass;

            if (teacherPass == "teacher123")
            {
                cout << "\n\t\t\t\t\t\t\t|-----------------------------|\n";
                cout << "\t\t\t\t\t\t\t|      LOGIN SUCCESSFUL       |\n";
                cout << "\t\t\t\t\t\t\t|-----------------------------|\n\n\n";
                teacherMenu();
            }
            else
            {
                cout << "Wrong Password! Please try again.\n";
            }
            break;
        }
        case 3:
            cout << "Exiting Library System. Thank you!\n";
            break;
        default:
            cout << "Invalid choice! Please try again.\n";
            break;
        }
    } while (choice != 3);
}

// Main Function
int main()
{
    Login_page();
    return 0;
}
