#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
using namespace std;

char bookGenre;
string bookGenreString;
char bookNumber;
string bookNumberString;
int bookQuantity;
string bookQuantityString;
char paymentConfirmation;
string paymentConfirmationString;
char paymentMethod;
string paymentMethodString;
string addOrders;
string moreOrders;
double paymentAmount;

int customerID = 0;
double subTotal = 0;
double taxAmount = 0;
double taxRate = 0.05;
double totalPayable = 0;
int orderTotalQuantities = 0;
string nextCustomer;
string returnMenu;

// Colour and text effects
const string RESET = "\033[0m"; // Reset to normal text
const string BOLD = "\033[1m";

const string RED = "\033[31m";
const string GREEN = "\033[32m";
const string YELLOW = "\033[33m";
const string BLUE = "\033[34m";
const string MAGENTA = "\033[35m";
const string CYAN = "\033[36m";

// Temporary data for book quantities (for future linking)
int dramaQuantities[] = { 18, 15, 22, 14, 17 };
int fictionQuantities[] = { 28, 23, 20, 26, 19 };
int nonFictionQuantities[] = { 24, 22, 20, 18, 23 };
int fantasyQuantities[] = { 35, 38, 32, 30, 33 };
int biographyQuantities[] = { 20, 18, 25, 16, 28 };

// Define the book data using arrays
const string dramaBooks[] = { "Death of a Salesman", "A Streetcar Named Desire", "Hamlet", "The Glass Menagerie", "Long Day's Journey Into Night" };
const string dramaAuthors[] = { "Arthur Miller", "Tennessee Williams", "William Shakespeare", "Tennessee Williams", "Eugene O'Neill" };
const double dramaPrices[] = { 19.50, 14.50, 9.50, 12.50, 18.75 };

const string fictionBooks[] = { "To Kill a Mockingbird", "1984", "Pride and Prejudice", "The Great Gatsby", "Moby Dick" };
const string fictionAuthors[] = { "Harper Lee", "George Orwell", "Jane Austen", "F. Scott Fitzgerald", "Herman Melville" };
const double fictionPrices[] = { 15.50, 13.45, 11.50, 14.25, 10.50 };

const string nonFictionBooks[] = { "Sapiens", "Becoming", "Educated", "The Immortal Life of Henrietta Lacks", "Outliers" };
const string nonFictionAuthors[] = { "Yuval Noah Harari", "Michelle Obama", "Tara Westover", "Rebecca Skloot", "Malcolm Gladwell" };
const double nonFictionPrices[] = { 21.00, 12.75, 18.50, 17.25, 15.75 };

const string fantasyBooks[] = { "The Hobbit", "Harry Potter and the Sorcerer's Stone", "The Name of the Wind", "A Song of Ice and Fire", "The Way of Kings" };
const string fantasyAuthors[] = { "J.R.R. Tolkien", "J.K. Rowling", "Patrick Rothfuss", "George R.R. Martin", "Brandon Sanderson" };
const double fantasyPrices[] = { 22.50, 21.00, 19.25, 25.50, 24.75 };

const string biographyBooks[] = { "Steve Jobs", "The Diary of a Young Girl", "Long Walk to Freedom", "The Story of My Life", "Becoming" };
const string biographyAuthors[] = { "Walter Isaacson", "Anne Frank", "Nelson Mandela", "Helen Keller", "Michelle Obama" };
const double biographyPrices[] = { 18.50, 12.50, 19.75, 11.25, 20.50 };

// Define arrays to store the order history
const int maxOrders = 100; // Define a maximum number of orders
string orderBookGenres[maxOrders];
string orderBookNumbers[maxOrders];
string orderBookNames[maxOrders];
string orderBookAuthors[maxOrders];
int orderQuantities[maxOrders];
double orderPrices[maxOrders]; // To store total price for each book order
double orderTotalPrices[maxOrders];
int orderCount = 0;


// For reports
int reportOrderTotalQuantities = 0;
string reportBookGenre[100];
double reportTotalPay[100];
double reportTotalEarn = 0;
int D_qty = 0;
int F_qty = 0;
int N_qty = 0;
int A_qty = 0;
int B_qty = 0;

// Maximum number of users
const int MAX_USERS = 100;
string users_id[MAX_USERS];
string users_password[MAX_USERS];
int user_count = 0;

// Main menu
bool logged_in = true;

// Function to generate the company logo
void company_logo() {
    cout << CYAN;
    cout << setw(15) << " " << "oooooooooooo       .o.        ooo        ooooo    .oooooo.    ooooo     ooo   .oooooo..o " << endl;
    cout << setw(15) << " " << "`888'     `8      .888.       `88.       .888'   d8P'  `Y8b   `888'     `8'  d8P'    `Y8 " << endl;
    cout << setw(15) << " " << " 888             .88888.       888b     d'888   888      888   888       8   Y88bo.      " << endl;
    cout << setw(15) << " " << " 888oooo8       .8' `888.      8 Y88. .P  888   888      888   888       8    `8Y8888o.  " << endl;
    cout << setw(15) << " " << " 888    8      .88ooo8888.     8  `888'   888   888      888   888       8        `8Y88b " << endl;
    cout << setw(15) << " " << " 888          .8'     `888.    8    Y     888   `88b    d88'   `88.    .8'   oo     .d8P " << endl;
    cout << setw(15) << " " << "o888o        o88o     o8888o  o8o        o888o   `Y8bood8P'      `YbodP'     88888888P'  " << endl;
    cout << RESET << endl;
}

// Login for user
bool login_user()
{
    string id, password;
    cout << "Enter ID: ";
    getline(cin, id);
    cout << "Enter password: ";
    getline(cin, password);

    // Loop through the user array and check if there is a matching ID and password
    for (int i = 0; i < user_count; i++)
    {
        if (users_id[i] == id && users_password[i] == password)
        {
            return true;  // Login successful
        }
    }

    return false;  // Login failed
}

// Function to exit
void exit_file(bool position_loop)
{
    bool character_valid = true;      //repeat the loop while the input character is not valid in the exit_input.
    char exit_input = ' '; //cin exit choice

    while (true)
    {
        company_logo();
        if (!character_valid)
        {
            cout << RED << "Invalid character, Please re-enter" << RESET << endl;
            character_valid = true;
        }

        cout << "Are You Sure To Exit? (Press Y = Yes or N = No) : ";
        cin >> exit_input;
        // measure the character can be handle in upper case and lower case
        exit_input = toupper(exit_input);

        switch (exit_input)
        {
            //exit the program
        case 'Y':
            system("CLS");
            company_logo();
            cout << setw(30) << " " << setfill('=') << setw(51) << '=' << setfill(' ') << endl;
            cout << setw(30) << " " << setw(43) << left << "|\t\tThanks for Using Our System !!!" << "|" << endl;
            cout << setw(30) << " " << setfill('=') << setw(51) << '=' << setfill(' ') << endl;
            exit(0);
            break;

            //continue the program
        case 'N':
            position_loop = false;
            system("CLS");
            cout << endl << endl;
            cout << setw(50) << " " << "Returning to the menu . . . . . . " << endl;
            cin.ignore();
            return;
            break;

            //Invalid char
        default:
            system("CLS");
            character_valid = false;
            break;

        }
    }
}

// Function to enter and validate book genre
bool enterBookGenre() {
    int validBookGenre = 0;
    do {
        cout << CYAN << "Select a genre from the following list:" << RESET << endl;
        cout << "1. [ D ] Drama" << endl;
        cout << "2. [ F ] Fiction" << endl;
        cout << "3. [ N ] Non-fiction" << endl;
        cout << "4. [ A ] Fantasy" << endl;
        cout << "5. [ B ] Biography" << endl;
        cout << "6. [ R ] Return to main menu" << endl;
        cout << "Type the genre name exactly as shown: ";
        getline(cin, bookGenreString);

        if (bookGenreString.length() > 1) {
            cout << "Input contains more than one character. Please input only one character" << endl;
            validBookGenre = 0;
        }
        else {
            // Convert the first character to a char
            bookGenre = bookGenreString[0];

            bookGenre = toupper(bookGenre); // Convert to uppercase for easier comparison

            switch (bookGenre) {
            case 'D':
                if (dramaQuantities[1] == 0 && dramaQuantities[2] == 0 && dramaQuantities[3] == 0 && dramaQuantities[4] == 0 && dramaQuantities[0] == 0) {
                    cout << RED << "Insufficient stock for this genre. Please wait for the next re-stock." << RESET << endl;
                    validBookGenre = 0;
                }
                else {
                    system("CLS");
                    cout << "Drama Books" << endl;
                    cout << "+------+---------------------------------------+---------------------------------+----------------+------------+" << endl;
                    cout << "|  No. |                Book Name              |              Author             |  Price ( RM )  |  Quantity  |" << endl;
                    cout << "+------+---------------------------------------+---------------------------------+----------------+------------+" << endl;
                    for (int i = 0; i < 5; ++i) {
                        cout << "| " << setw(4) << right << (i + 1)
                            << " | " << setw(37) << left << dramaBooks[i]
                            << " | " << setw(31) << left << dramaAuthors[i]
                            << " | " << setw(14) << right << fixed << setprecision(2) << dramaPrices[i]
                            << " | " << setw(10) << right << dramaQuantities[i] << " |" << endl;
                    }
                    cout << "+------+---------------------------------------+---------------------------------+----------------+------------+" << endl;
                    validBookGenre = 1;
                }
                break;
            case 'F':
                if (fictionQuantities[1] == 0 && fictionQuantities[2] == 0 && fictionQuantities[3] == 0 && fictionQuantities[4] == 0 && fictionQuantities[0] == 0) {
                    cout << RED << "Insufficient stock for this genre. Please wait for the next re-stock." << RESET << endl;
                    validBookGenre = 0;
                }
                else {
                    system("CLS");
                    cout << "Fiction Books" << endl;
                    cout << "+------+---------------------------------------+---------------------------------+----------------+------------+" << endl;
                    cout << "|  No. |                Book Name              |              Author             |  Price ( RM )  |  Quantity  |" << endl;
                    cout << "+------+---------------------------------------+---------------------------------+----------------+------------+" << endl;
                    for (int i = 0; i < 5; ++i) {
                        cout << "| " << setw(4) << right << (i + 1)
                            << " | " << setw(37) << left << fictionBooks[i]
                            << " | " << setw(31) << left << fictionAuthors[i]
                            << " | " << setw(14) << right << fixed << setprecision(2) << fictionPrices[i]
                            << " | " << setw(10) << right << fictionQuantities[i] << " |" << endl;
                    }
                    cout << "+------+---------------------------------------+---------------------------------+----------------+------------+" << endl;
                    validBookGenre = 1;
                }
                break;
            case 'N':
                if (nonFictionQuantities[1] == 0 && nonFictionQuantities[2] == 0 && nonFictionQuantities[3] == 0 && nonFictionQuantities[4] == 0 && nonFictionQuantities[0] == 0) {
                    cout << RED << "Insufficient stock for this genre. Please wait for the next re-stock." << RESET << endl;
                    validBookGenre = 0;
                }
                else {
                    system("CLS");
                    cout << "Non-Fiction Books" << endl;
                    cout << "+------+---------------------------------------+---------------------------------+----------------+------------+" << endl;
                    cout << "|  No. |                Book Name              |              Author             |  Price ( RM )  |  Quantity  |" << endl;
                    cout << "+------+---------------------------------------+---------------------------------+----------------+------------+" << endl;
                    for (int i = 0; i < 5; ++i) {
                        cout << "| " << setw(4) << right << (i + 1)
                            << " | " << setw(37) << left << nonFictionBooks[i]
                            << " | " << setw(31) << left << nonFictionAuthors[i]
                            << " | " << setw(14) << right << fixed << setprecision(2) << nonFictionPrices[i]
                            << " | " << setw(10) << right << nonFictionQuantities[i] << " |" << endl;
                    }
                    cout << "+------+---------------------------------------+---------------------------------+----------------+------------+" << endl;
                    validBookGenre = 1;
                }
                break;
            case 'A':
                if (fantasyQuantities[1] == 0 && fantasyQuantities[2] == 0 && fantasyQuantities[3] == 0 && fantasyQuantities[4] == 0 && fantasyQuantities[0] == 0) {
                    cout << RED << "Insufficient stock for this genre. Please wait for the next re-stock." << RESET << endl;
                    validBookGenre = 0;
                }
                else {
                    system("CLS");
                    cout << "Fantasy Books" << endl;
                    cout << "+------+---------------------------------------+---------------------------------+----------------+------------+" << endl;
                    cout << "|  No. |                Book Name              |              Author             |  Price ( RM )  |  Quantity  |" << endl;
                    cout << "+------+---------------------------------------+---------------------------------+----------------+------------+" << endl;
                    for (int i = 0; i < 5; ++i) {
                        cout << "| " << setw(4) << right << (i + 1)
                            << " | " << setw(37) << left << fantasyBooks[i]
                            << " | " << setw(31) << left << fantasyAuthors[i]
                            << " | " << setw(14) << right << fixed << setprecision(2) << fantasyPrices[i]
                            << " | " << setw(10) << right << fantasyQuantities[i] << " |" << endl;
                    }
                    cout << "+------+---------------------------------------+---------------------------------+----------------+------------+" << endl;
                    validBookGenre = 1;
                }
                break;
            case 'B':
                if (biographyQuantities[1] == 0 && biographyQuantities[2] == 0 && biographyQuantities[3] == 0 && biographyQuantities[4] == 0 && biographyQuantities[0] == 0) {
                    cout << RED << "Insufficient stock for this genre. Please wait for the next re-stock." << RESET << endl;
                    validBookGenre = 0;
                }
                else {
                    system("CLS");
                    cout << "Biography Books" << endl;
                    cout << "+------+---------------------------------------+---------------------------------+----------------+------------+" << endl;
                    cout << "|  No. |                Book Name              |              Author             |  Price ( RM )  |  Quantity  |" << endl;
                    cout << "+------+---------------------------------------+---------------------------------+----------------+------------+" << endl;
                    for (int i = 0; i < 5; ++i) {
                        cout << "| " << setw(4) << right << (i + 1)
                            << " | " << setw(37) << left << biographyBooks[i]
                            << " | " << setw(31) << left << biographyAuthors[i]
                            << " | " << setw(14) << right << fixed << setprecision(2) << biographyPrices[i]
                            << " | " << setw(10) << right << biographyQuantities[i] << " |" << endl;
                    }
                    cout << "+------+---------------------------------------+---------------------------------+----------------+------------+" << endl;
                    validBookGenre = 1;
                }
                break;

                // Secret return to main menu code 
            case 'R':
                if (orderCount == 0) {
                    customerID--;
                    system("CLS");
                    return false;
                    break;
                }
                else {
                    cout << RED << "There is a pending order. Please complete order to return to main menu." << RESET << endl;
                    validBookGenre = 0;
                    break;
                }
            default:
                validBookGenre = 0;
                cout << "Invalid book genre. Please enter a valid genre." << endl;
            }
        }
    } while (!validBookGenre);
    return validBookGenre;
}

// Function to enter and validate book number
bool enterBookNumber() {
    int validBookNumber = 0;
    do {
        cout << CYAN << "Enter Book Number: " << RESET;
        getline(cin, bookNumberString);

        // Check if the string has more than one character
        if (bookNumberString.length() > 1) {
            cout << "Input contains more than one character. Please input only one number" << endl;
            validBookNumber = 0;
        }
        else {
            bookNumber = bookNumberString[0];
            // Check if the first character is a digit
            if (!isdigit(bookNumber)) {
                cout << "Input is not a number. Please enter a valid number." << endl;
                validBookNumber = 0;
            }
            else if (bookNumber >= '1' && bookNumber <= '5') {
                int bookIndex = stoi(bookNumberString) - 1;
                bookGenre = bookGenreString[0];
                bookGenre = toupper(bookGenre); // Convert to uppercase for easier comparison
                switch (bookGenre) {
                case 'D':
                    if (dramaQuantities[bookIndex] == 0) {
                        cout << RED << "Insufficient stock. Please wait for the next re-stock." << RESET << endl;
                        validBookNumber = 0;
                    }
                    else {
                        validBookNumber = 1;
                    }
                    break;
                case 'F':
                    if (fictionQuantities[bookIndex] == 0) {
                        cout << RED << "Insufficient stock. Please wait for the next re-stock." << RESET << endl;
                        validBookNumber = 0;
                    }
                    else {
                        validBookNumber = 1;
                    }
                    break;
                case 'N':
                    if (nonFictionQuantities[bookIndex] == 0) {
                        cout << RED << "Insufficient stock. Please wait for the next re-stock." << RESET << endl;
                        validBookNumber = 0;
                    }
                    else {
                        validBookNumber = 1;
                    }
                    break;
                case 'A':
                    if (fantasyQuantities[bookIndex] == 0) {
                        cout << RED << "Insufficient stock. Please wait for the next re-stock." << RESET << endl;
                        validBookNumber = 0;
                    }
                    else {
                        validBookNumber = 1;
                    }
                    break;
                case 'B':
                    if (biographyQuantities[bookIndex] == 0) {
                        cout << RED << "Insufficient stock. Please wait for the next re-stock." << RESET << endl;
                        validBookNumber = 0;
                    }
                    else {
                        validBookNumber = 1;
                    }
                    break;
                }
            }
            else {
                cout << "Invalid book number. Please enter a valid number." << endl;
                validBookNumber = 0;
            }
        }
    } while (!validBookNumber);
    return validBookNumber;
}

// Function to enter and validate book quantity
bool enterBookQuantity() {
    int validQuantity = 0;
    do {
        cout << CYAN << "Quantity: " << RESET;
        getline(cin, bookQuantityString);

        // Check if the input is empty
        if (bookQuantityString.empty()) {
            cout << "Quantity cannot be empty. Please enter a valid quantity." << endl;
        }
        else {
            if (bookQuantityString.length() <= 3) {
                validQuantity = 1;
                for (char const& c : bookQuantityString) {
                    if (!isdigit(c)) {
                        validQuantity = 0;
                        break;
                    }
                }
                if (validQuantity) {
                    bookQuantity = stoi(bookQuantityString);
                    if (bookQuantity > 0) {
                        int bookIndex = stoi(bookNumberString) - 1;
                        bookGenre = bookGenreString[0];
                        bookGenre = toupper(bookGenre); // Convert to uppercase for easier comparison
                        switch (bookGenre) {
                        case 'D':
                            if (bookQuantity <= dramaQuantities[bookIndex]) {
                                validQuantity = 1;
                            }
                            else {
                                cout << RED << "Insufficient stock. Please enter a smaller quantity." << RESET << endl;
                                validQuantity = 0;
                            }
                            break;
                        case 'F':
                            if (bookQuantity <= fictionQuantities[bookIndex]) {
                                validQuantity = 1;
                            }
                            else {
                                cout << RED << "Insufficient stock. Please enter a smaller quantity." << RESET << endl;
                                validQuantity = 0;
                            }
                            break;
                        case 'N':
                            if (bookQuantity <= nonFictionQuantities[bookIndex]) {
                                validQuantity = 1;
                            }
                            else {
                                cout << RED << "Insufficient stock. Please enter a smaller quantity." << RESET << endl;
                                validQuantity = 0;
                            }
                            break;
                        case 'A':
                            if (bookQuantity <= fantasyQuantities[bookIndex]) {
                                validQuantity = 1;
                            }
                            else {
                                cout << RED << "Insufficient stock. Please enter a smaller quantity." << RESET << endl;
                                validQuantity = 0;
                            }
                            break;
                        case 'B':
                            if (bookQuantity <= biographyQuantities[bookIndex]) {
                                validQuantity = 1;
                            }
                            else {
                                cout << RED << "Insufficient stock. Please enter a smaller quantity." << RESET << endl;
                                validQuantity = 0;
                            }
                            break;
                        }
                    }
                    else {
                        cout << "Quantity must be greater than 0. Please enter a valid quantity." << endl;
                        validQuantity = 0;
                    }
                }
                else {
                    cout << "Invalid quantity. Please enter a valid number." << endl;
                    validQuantity = 0;
                }
            }
            else {
                cout << "Quantity is too large. Please enter a smaller value" << endl;
                validQuantity = 0;
            }
        }
    } while (!validQuantity);
    return validQuantity;
}

// Function to confirm the order
bool confirmOrder() {
    int validOrder = 0;
    cout << "Confirm this order (\033[32mY\033[0m/\033[31mN\033[0m)? ";
    getline(cin, addOrders);

    if (addOrders == "Y" || addOrders == "N" || addOrders == "y" || addOrders == "n") {
        if (addOrders == "Y" || addOrders == "y") {
            orderQuantities[orderCount] = bookQuantity;
            int bookIndex = stoi(bookNumberString) - 1;
            bookGenre = bookGenreString[0];
            bookGenre = toupper(bookGenre); // Convert to uppercase for easier comparison
            switch (bookGenre) {
            case 'D':
                orderBookGenres[orderCount] = "Drama";
                orderBookNumbers[orderCount] = bookNumber;
                orderBookNames[orderCount] = dramaBooks[bookIndex];
                orderBookAuthors[orderCount] = dramaAuthors[bookIndex];
                orderPrices[orderCount] = dramaPrices[bookIndex];
                orderTotalPrices[orderCount] = dramaPrices[bookIndex] * orderQuantities[orderCount];
                dramaQuantities[bookIndex] -= bookQuantity; // Update available drama quantity
                D_qty += bookQuantity;//store for report
                break;
            case 'F':
                orderBookGenres[orderCount] = "Fiction";
                orderBookNumbers[orderCount] = bookNumber;
                orderBookNames[orderCount] = fictionBooks[bookIndex];
                orderBookAuthors[orderCount] = fictionAuthors[bookIndex];
                orderPrices[orderCount] = fictionPrices[bookIndex];
                orderTotalPrices[orderCount] = fictionPrices[bookIndex] * orderQuantities[orderCount];
                fictionQuantities[bookIndex] -= bookQuantity; // Update available fiction quantity
                F_qty += bookQuantity;
                break;
            case 'N':
                orderBookGenres[orderCount] = "Non-Fiction";
                orderBookNumbers[orderCount] = bookNumber;
                orderBookNames[orderCount] = nonFictionBooks[bookIndex];
                orderBookAuthors[orderCount] = nonFictionAuthors[bookIndex];
                orderPrices[orderCount] = nonFictionPrices[bookIndex];
                orderTotalPrices[orderCount] = nonFictionPrices[bookIndex] * orderQuantities[orderCount];
                nonFictionQuantities[bookIndex] -= bookQuantity; // Update available non fiction quantity
                N_qty += bookQuantity;
                break;
            case 'A':
                orderBookGenres[orderCount] = "Fantasy";
                orderBookNumbers[orderCount] = bookNumber;
                orderBookNames[orderCount] = fantasyBooks[bookIndex];
                orderBookAuthors[orderCount] = fantasyAuthors[bookIndex];
                orderPrices[orderCount] = fantasyPrices[bookIndex];
                orderTotalPrices[orderCount] = fantasyPrices[bookIndex] * orderQuantities[orderCount];
                fantasyQuantities[bookIndex] -= bookQuantity; // Update available fantasy quantity
                A_qty += bookQuantity;
                break;
            case 'B':
                orderBookGenres[orderCount] = "Biography";
                orderBookNumbers[orderCount] = bookNumber;
                orderBookNames[orderCount] = biographyBooks[bookIndex];
                orderBookAuthors[orderCount] = biographyAuthors[bookIndex];
                orderPrices[orderCount] = biographyPrices[bookIndex];
                orderTotalPrices[orderCount] = biographyPrices[bookIndex] * orderQuantities[orderCount];
                biographyQuantities[bookIndex] -= bookQuantity; // Update available biography quantity
                B_qty += bookQuantity;
                break;
            }
            orderCount++;
            validOrder = 1;
        }
        else {
            validOrder = 1;
        }
    }
    else {
        cout << "Invalid input. Please enter 'Y' or 'N'." << endl;
        validOrder = 0;
    }
    return validOrder;
}

// Function to print invoice for the customer
void printInvoice() {
    cout << right << "-------------------------------------------------------------------------------------------------------------------------------\n";
    cout << setw(78) << "             FAMOUS            \n";
    cout << setw(78) << "1234, Jalan Raya, Taman Bandar,\n";
    cout << setw(78) << " 10450, Pulau Pinang, Malaysia \n";
    cout << setw(78) << "       Tel: 012-3456789        \n\n";
    cout << "===============================================================================================================================\n";
    cout << setw(79) << "            INVOICE            \n\n";
    cout << "===============================================================================================================================\n";
    cout << setw(6) << left << "No."
        << setw(15) << left << "Genre"
        << setw(42) << left << "Book Name"
        << setw(25) << left << "Author"
        << setw(10) << left << "Qty"
        << setw(13) << left << "Amount(RM)"
        << "Total Amount(RM)\n";
    cout << "-------------------------------------------------------------------------------------------------------------------------------\n";
    for (int i = 0; i < orderCount; ++i) {
        cout << setw(6) << left << (i + 1)
            << setw(15) << left << orderBookGenres[i]
            << setw(42) << left << orderBookNames[i]
            << setw(25) << left << orderBookAuthors[i]
            << setw(10) << left << orderQuantities[i]
            << setw(13) << fixed << setprecision(2) << orderPrices[i]
            << fixed << setprecision(2) << orderTotalPrices[i] << endl;
    }
    for (int i = 0; i < orderCount; ++i) {
        subTotal += orderTotalPrices[i];
        orderTotalQuantities += orderQuantities[i];
    }
    taxAmount = subTotal * taxRate;
    totalPayable = subTotal + taxAmount;

    cout << "-------------------------------------------------------------------------------------------------------------------------------\n";
    cout << setw(111) << left << "SUBTOTAL:" << subTotal << setprecision(2) << "\n";
    cout << setw(111) << left << "TAX (5%):" << taxAmount << setprecision(2) << "\n";
    cout << "-------------------------------------------------------------------------------------------------------------------------------\n";
    cout << "TOTAL ITEMS(" << orderTotalQuantities << ")" << "\n";
    cout << setw(111) << left << "TOTAL PAYABLE:" << totalPayable << setprecision(2) << "\n";
    cout << "                                        Thank you for your purchase at Famous Book Store!                                      \n";
}

// Function to print receipt
void printReceipt() {
    cout << right << "-------------------------------------------------------------------------------------------------------------------------------\n";
    cout << setw(78) << "             FAMOUS            \n";
    cout << setw(78) << "1234, Jalan Raya, Taman Bandar,\n";
    cout << setw(78) << " 10450, Pulau Pinang, Malaysia \n";
    cout << setw(78) << "       Tel: 012-3456789        \n\n";
    cout << "===============================================================================================================================\n";
    cout << setw(79) << "            RECEIPT            \n\n";
    cout << "===============================================================================================================================\n";
    cout << setw(6) << left << "No."
        << setw(15) << left << "Genre"
        << setw(42) << left << "Book Name"
        << setw(25) << left << "Author"
        << setw(10) << left << "Qty"
        << setw(13) << left << "Amount(RM)"
        << "Total Amount(RM)\n";
    cout << "-------------------------------------------------------------------------------------------------------------------------------\n";
    for (int i = 0; i < orderCount; ++i) {
        cout << setw(6) << left << (i + 1)
            << setw(15) << left << orderBookGenres[i]
            << setw(42) << left << orderBookNames[i]
            << setw(25) << left << orderBookAuthors[i]
            << setw(10) << left << orderQuantities[i]
            << setw(13) << fixed << setprecision(2) << orderPrices[i]
            << fixed << setprecision(2) << orderTotalPrices[i] << endl;
        reportBookGenre[i] = orderBookGenres[i];
        reportTotalPay[i] = orderTotalPrices[i];

    }

    cout << "-------------------------------------------------------------------------------------------------------------------------------\n";
    cout << setw(111) << left << "SUBTOTAL:" << subTotal << setprecision(2) << "\n";
    cout << setw(111) << left << "TAX (5%):" << taxAmount << setprecision(2) << "\n";
    cout << "-------------------------------------------------------------------------------------------------------------------------------\n";
    cout << "TOTAL ITEMS(" << orderTotalQuantities << ")" << "\n";
    cout << setw(111) << left << "TOTAL PAYABLE:" << totalPayable << setprecision(2) << "\n\n";
    cout << "-------------------------------------------------------------------------------------------------------------------------------\n";
    switch (paymentMethod) {
    case('E'):
        cout << setw(21) << left << "Payment Method: " << "E-wallet" << "\n";
        cout << setw(21) << left << "Payment Amount: " << "RM " << paymentAmount << setprecision(2) << "\n";
        cout << setw(21) << left << "Change        : " << "RM " << paymentAmount - totalPayable << setprecision(2) << endl;
        break;
    case('C'):
        cout << setw(21) << left << "Payment Method: " << "Credit Card" << "\n";
        cout << setw(21) << left << "Payment Amount: " << "RM " << paymentAmount << setprecision(2) << "\n";
        cout << setw(21) << left << "Change        : " << "RM " << paymentAmount - totalPayable << setprecision(2) << endl;
        break;
    case ('D'):
        cout << setw(21) << left << "Payment Method: " << "Debit Card" << "\n";
        cout << setw(21) << left << "Payment Amount: " << "RM " << paymentAmount << setprecision(2) << "\n";
        cout << setw(21) << left << "Change        : " << "RM " << paymentAmount - totalPayable << setprecision(2) << endl;
        break;
    case('M'):
        cout << setw(21) << left << "Payment Method: " << "Cash" << "\n";
        cout << setw(21) << left << "Payment Amount: " << "RM " << paymentAmount << setprecision(2) << "\n";
        cout << setw(21) << left << "Change        : " << "RM " << paymentAmount - totalPayable << setprecision(2) << endl;
        break;
    }
    cout << "                                        Thank you for your purchase at Famous Book Store!                                      \n";
}

// Function for payment confirmation
bool confirmPayment() {
    int validConfirmation = 0;
    do {
        cout << "Do you want to confirm payment? (\033[32mY\033[0m/\033[31mN\033[0m) ";
        getline(cin, paymentConfirmationString);

        if (paymentConfirmationString.length() > 1) {
            cout << "Input contains more than one character. Please input only one character" << endl;
            validConfirmation = 0;
        }
        else {
            paymentConfirmation = paymentConfirmationString[0];
            paymentConfirmation = toupper(paymentConfirmation);
            switch (paymentConfirmation) {
            case 'Y':
                do {
                    cout << "Select payment method (E = e-Wallet, C = Credit Card, D = Debit Card, M = Cash): ";
                    getline(cin, paymentMethodString);

                    if (paymentMethodString.length() > 1) {
                        cout << "Input contains more than one character. Please input only one character" << endl;
                        validConfirmation = 0;
                    }
                    else {
                        paymentMethod = paymentMethodString[0];
                        paymentMethod = toupper(paymentMethod);
                        switch (paymentMethod) {
                        case 'E':
                            cout << "Payment method: e-Wallet" << endl;
                            do {
                                cout << "Payment Amount: RM ";
                                cin >> paymentAmount;
                                cin.ignore();
                                if (paymentAmount < totalPayable) {
                                    cout << RED << "Insufficient payment amount. Please pay the correct amount." << RESET << endl;
                                    validConfirmation = 0;
                                }
                                else {
                                    validConfirmation = 1;
                                }
                            } while (!validConfirmation);
                            validConfirmation = 1;
                            break;
                        case 'C':
                            cout << "Payment method: Credit Card" << endl;
                            do {
                                cout << "Payment Amount: RM ";
                                cin >> paymentAmount;
                                cin.ignore();
                                if (paymentAmount < totalPayable) {
                                    cout << RED << "Insufficient payment amount. Please pay the correct amount." << RESET << endl;
                                    validConfirmation = 0;
                                }
                                else {
                                    validConfirmation = 1;
                                }
                            } while (!validConfirmation);
                            validConfirmation = 1;
                            break;
                        case 'D':
                            cout << "Payment method: Debit Card" << endl;
                            do {
                                cout << "Payment Amount: RM ";
                                cin >> paymentAmount;
                                cin.ignore();
                                if (paymentAmount < totalPayable) {
                                    cout << RED << "Insufficient payment amount. Please pay the correct amount." << RESET << endl;
                                    validConfirmation = 0;
                                }
                                else {
                                    validConfirmation = 1;
                                }
                            } while (!validConfirmation);
                            validConfirmation = 1;
                            break;
                        case 'M':
                            cout << "Payment method: Cash" << endl;
                            do {
                                cout << "Payment Amount: RM ";
                                cin >> paymentAmount;
                                cin.ignore();
                                if (paymentAmount < totalPayable) {
                                    cout << RED << "Insufficient payment amount. Please pay the correct amount." << RESET << endl;
                                    validConfirmation = 0;
                                }
                                else {
                                    validConfirmation = 1;
                                }
                            } while (!validConfirmation);
                            validConfirmation = 1;
                            break;
                        default:
                            cout << "Invalid payment method selected." << endl;
                            validConfirmation = 0;
                        }
                    }
                } while (!validConfirmation);
                system("CLS");
                printReceipt();
                break;
            case 'N':
                for (int i = 0; i < orderCount; i++) {
                    customerID--;
                    bookGenreString = orderBookGenres[i];
                    bookGenre = bookGenreString[0];
                    bookGenre = toupper(bookGenre); // Convert to uppercase for easier comparison
                    int bookIndex = stoi(orderBookNumbers[i]) - 1;
                    switch (bookGenre) {
                    case 'D':
                        dramaQuantities[bookIndex] += orderQuantities[i]; // Update available drama quantity
                        D_qty -= bookQuantity;
                        break;
                    case 'F':
                        fictionQuantities[bookIndex] += orderQuantities[i]; // Update available fiction quantity
                        F_qty -= bookQuantity;
                        break;
                    case 'N':
                        nonFictionQuantities[bookIndex] += orderQuantities[i]; // Update available non fiction quantity
                        N_qty -= bookQuantity;
                        break;
                    case 'A':
                        fantasyQuantities[bookIndex] += orderQuantities[i]; // Update available fantasy quantity
                        A_qty -= bookQuantity;
                        break;
                    case 'B':
                        biographyQuantities[bookIndex] += orderQuantities[i]; // Update available biography quantity
                        B_qty -= bookQuantity;
                        break;
                    }
                    reportOrderTotalQuantities -= orderTotalQuantities;
                    reportTotalEarn -= totalPayable;
                }
                validConfirmation = 1;
                break;
            default:
                cout << "Invalid payment confirmation. Please enter a valid payment confirmation." << endl;
                validConfirmation = 0;
            }
        }
    } while (!validConfirmation);
    return validConfirmation;
}

// Function to generate Daily Sales Report
void salesReport() {
    cout << right << setw(68) << "             FAMOUS            \n";
    cout << setw(68) << "1234, Jalan Raya, Taman Bandar,\n";
    cout << setw(68) << " 10450, Pulau Pinang, Malaysia \n";
    cout << setw(68) << "       Tel: 012-3456789        \n\n";
    cout << "------------------------------------------------------------------------------------------------------------------\n";
    cout << BOLD << BLUE << setw(63) << right << "Daily Book Sales Report" << RESET << endl;
    cout << "------------------------------------------------------------------------------------------------------------------\n";
    cout << left << setw(15) << "Total book sold today :";
    cout << reportOrderTotalQuantities << endl;
    cout << " \nTotal Profit          :";
    cout << reportTotalEarn << endl;
    cout << "\nCustomer today        :" << customerID << endl;
    cout << "------------------------------------------------------------------------------------------------------------------\n\n";
}

// Function to generate Daily Book Genre Sales Report
void bestNworstSalesReport() {
    int largest;//the most book quantity sold
    string bestGenre;//the most best book genre sold
    cout << right << setw(68) << "             FAMOUS            \n";
    cout << setw(68) << "1234, Jalan Raya, Taman Bandar,\n";
    cout << setw(68) << " 10450, Pulau Pinang, Malaysia \n";
    cout << setw(68) << "       Tel: 012-3456789        \n\n";
    cout << "------------------------------------------------------------------------------------------------------------------\n";
    cout << BOLD << BLUE << setw(71) << right << "Daily Book Genre Sales Report\n" << RESET;
    cout << "------------------------------------------------------------------------------------------------------------------\n";
    cout << left << setw(15) << "Books Genre  " << right << "|" << left << setw(31) << " Number of Books Sold" << endl;
    cout << "------------------------------------------------------------------------------------------------------------------\n";
    cout << "Drama            " << D_qty << endl;
    cout << "Fiction          " << F_qty << endl;
    cout << "Non-Fiction      " << N_qty << endl;
    cout << "Fantasy          " << A_qty << endl;
    cout << "Biography        " << B_qty << endl;
    cout << "------------------------------------------------------------------------------------------------------------------\n\n\n\n";


    // Determine the best book genre sold and best book quantity sold
    largest = D_qty;
    bestGenre = "Drama";

    if (F_qty > largest) {
        largest = F_qty;
        bestGenre = "Fiction";
    }
    if (N_qty > largest) {
        largest = N_qty;
        bestGenre = "Non-Fiction";
    }
    if (A_qty > largest) {
        largest = A_qty;
        bestGenre = "Fantasy";
    }
    if (B_qty > largest) {
        largest = B_qty;
        bestGenre = "Biography";
    }

    // Now "largest" holds the highest quantity. We need to check if there are ties
    bool tieDrama = (D_qty == largest);
    bool tieFiction = (F_qty == largest);
    bool tieNonFiction = (N_qty == largest);
    bool tieFantasy = (A_qty == largest);
    bool tieBiography = (B_qty == largest);

    // Generate the best-selling book genre
    cout << "==================================================================================================================\n";
    cout << BOLD << GREEN << setw(66) << right << "Best-Selling Book Genre\n" << RESET;
    cout << "==================================================================================================================\n";
    cout << left << setw(15) << "Book Genre"
        << right << "|" << " Books Sold" << endl;
    cout << "==================================================================================================================\n";
    // Determine if there is a tie and handle accordingly
    if (tieDrama || tieFiction || tieNonFiction || tieFantasy || tieBiography) {
        if (tieDrama)cout << "Drama" << "            " << GREEN << largest << RESET << endl;
        if (tieFiction)cout << "Fiction" << "          " << GREEN << largest << RESET << endl;
        if (tieNonFiction)cout << "Non-Fiction" << "      " << GREEN << largest << RESET << endl;
        if (tieFantasy)cout << "Fantasy" << "          " << GREEN << largest << RESET << endl;
        if (tieBiography)cout << "Biography" << "        " << GREEN << largest << RESET << endl;
        cout << endl;
    }
    else {
        cout << bestGenre << "            " << largest << endl;
    }
    cout << "==================================================================================================================\n\n";


    //worst selling report


    // Determine the worst book genre sold and best book quantity sold
    int smallest = D_qty;
    string worstGenre = "Drama";

    //Determine whether have two or more same smallest number
    if (F_qty < smallest) {
        smallest = F_qty;
        worstGenre = "Fiction";
    }
    if (N_qty < smallest) {
        smallest = N_qty;
        worstGenre = "Non-Fiction";
    }
    if (A_qty < smallest) {
        smallest = A_qty;
        worstGenre = "Fantasy";
    }
    if (B_qty < smallest) {
        smallest = B_qty;
        worstGenre = "Biography";
    }

    // Now "smallest" holds the lowest quantity. We need to check if there are ties
    tieDrama = (D_qty == smallest);
    tieFiction = (F_qty == smallest);
    tieNonFiction = (N_qty == smallest);
    tieFantasy = (A_qty == smallest);
    tieBiography = (B_qty == smallest);

    // Generate the worst-selling book genre
    cout << "\n\n\n==================================================================================================================\n";
    cout << BOLD << RED << setw(66) << right << "Worst-Selling Book Genre\n" << RESET;
    cout << "==================================================================================================================\n";
    cout << left << setw(15) << "Book Genre"
        << right << "|" << " Books Sold" << endl;
    cout << "==================================================================================================================\n";
    // Determine if there is a tie and handle accordingly
    if (tieDrama || tieFiction || tieNonFiction || tieFantasy || tieBiography) {
        if (tieDrama)cout << "Drama" << "            " << RED << smallest << RESET << endl;
        if (tieFiction)cout << "Fiction" << "          " << RED << smallest << RESET << endl;
        if (tieNonFiction)cout << "Non-Fiction" << "      " << RED << smallest << RESET << endl;
        if (tieFantasy)cout << "Fantasy" << "          " << RED << smallest << RESET << endl;
        if (tieBiography)cout << "Biography" << "        " << RED << smallest << RESET << endl;
        cout << endl;
    }
    else {
        cout << worstGenre << "            " << smallest << endl;
    }
    cout << "==================================================================================================================\n\n";

}

// Function to generate Stock Report
void stockReport() {

    cout << right << setw(68) << "             FAMOUS            \n";
    cout << setw(68) << "1234, Jalan Raya, Taman Bandar,\n";
    cout << setw(68) << " 10450, Pulau Pinang, Malaysia \n";
    cout << setw(68) << "       Tel: 012-3456789        \n\n";
    cout << "------------------------------------------------------------------------------------------------------------------\n";
    cout << BOLD << BLUE << setw(57) << right << "Stock Report\n" << RESET;
    cout << "------------------------------------------------------------------------------------------------------------------\n";
    cout << "      " << "Book Names" << "                             " << "Book Authors" << "                        " << left << "Books Left" << endl;
    cout << "------------------------------------------------------------------------------------------------------------------\n";
    cout << RED << "Drama:\n" << RESET;
    for (int i = 0; i < 5; ++i) {
        cout << setw(4) << right << (i + 1) << "  "
            << setw(39) << left << dramaBooks[i]
            << setw(31) << left << dramaAuthors[i]
            << setw(10) << right << dramaQuantities[i] << endl;
    }
    cout << "------------------------------------------------------------------------------------------------------------------\n";
    cout << GREEN << "Fiction:\n" << RESET;
    for (int i = 0; i < 5; ++i) {
        cout << setw(4) << right << (i + 1) << "  "
            << setw(39) << left << fictionBooks[i]
            << setw(31) << left << fictionAuthors[i]
            << setw(10) << right << fictionQuantities[i] << endl;
    }
    cout << "------------------------------------------------------------------------------------------------------------------\n";
    cout << YELLOW << "Non-Fiction:\n" << RESET;
    for (int i = 0; i < 5; ++i) {
        cout << setw(4) << right << (i + 1) << "  "
            << setw(39) << left << nonFictionBooks[i]
            << setw(31) << left << nonFictionAuthors[i]
            << setw(10) << right << nonFictionQuantities[i] << endl;
    }
    cout << "------------------------------------------------------------------------------------------------------------------\n";
    cout << BLUE << "Fantasy:\n" << RESET;
    for (int i = 0; i < 5; ++i) {
        cout << setw(4) << right << (i + 1) << "  "
            << setw(39) << left << fantasyBooks[i]
            << setw(31) << left << fantasyAuthors[i]
            << setw(10) << right << fantasyQuantities[i] << endl;
    }
    cout << "------------------------------------------------------------------------------------------------------------------\n";
    cout << MAGENTA << "Biography:\n" << RESET;
    for (int i = 0; i < 5; ++i) {
        cout << setw(4) << right << (i + 1) << "  "
            << setw(39) << left << biographyBooks[i]
            << setw(31) << left << biographyAuthors[i]
            << setw(10) << right << biographyQuantities[i] << endl;
    }
    cout << "------------------------------------------------------------------------------------------------------------------\n\n\n\n";

}

// Function for the main menu to execute the order entry
void orderEntry() {
    while (true) {
        cout << BOLD << "===========================" << RESET << endl;
        customerID++;
        cout << YELLOW << "Customer " << customerID << RESET << endl << endl;
        int orderNumber = 1;

        do {
            cout << "Order " << orderNumber << endl;

            if (enterBookGenre()) {
                if (enterBookNumber()) {
                    if (enterBookQuantity()) {
                        cout << GREEN << "Order entered successfully." << RESET << endl;
                    }
                }
            }
            else {
                company_logo();
                cout << setw(30) << " " << setw(50) << left << "|\tThanks for Using Our System !!!" << "|" << endl;
                return;
            }

            // Display entered details
            cout << "---------------------" << endl;
            cout << BOLD << "-= Entered Order Information =-" << RESET << endl;
            cout << "Book Genre: " << bookGenre << endl;
            cout << "Book Number: " << bookNumber << endl;
            cout << "Quantity: " << bookQuantity << endl;

            // Confirmation
            while (!confirmOrder());

            // Ask if there are more orders
            do {
                cout << "Do you want to add another order (\033[32mY\033[0m/\033[31mN\033[0m)? ";
                getline(cin, moreOrders);

                if (moreOrders != "Y" && moreOrders != "N" && moreOrders != "y" && moreOrders != "n") {
                    cout << "Invalid input. Please enter 'Y' or 'N'." << endl;
                }
            } while (moreOrders != "Y" && moreOrders != "N" && moreOrders != "y" && moreOrders != "n");
            system("CLS");
            if (moreOrders == "Y" || moreOrders == "y") {
                orderNumber++;
            }
        } while (moreOrders == "Y" || moreOrders == "y");

        system("CLS");

        if (orderCount == 0) {
            customerID--;
            int i = 0;
            orderBookGenres[i] = ""; // Setting each element to an empty string
            orderBookNames[i] = "";
            orderBookAuthors[i] = "";
            orderBookNumbers[i] = "";
            orderQuantities[i] = 0;
            orderPrices[i] = 0;
            orderCount = 0;
            subTotal = 0;
            return;
        }
        else
            // Function to print the invoice
            printInvoice();

        // Function to confirm payment
        confirmPayment();

        // Calculations for report
        reportOrderTotalQuantities += orderTotalQuantities;
        reportTotalEarn += totalPayable;

        do {
            cout << "Do you want to go to the next customer (\033[32mY\033[0m/\033[31mN\033[0m)? ";
            getline(cin, nextCustomer);

            if (nextCustomer != "Y" && nextCustomer != "N" && nextCustomer != "y" && nextCustomer != "n") {
                cout << "Invalid input. Please enter 'Y' or 'N'." << endl;
            }
        } while (nextCustomer != "Y" && nextCustomer != "N" && nextCustomer != "y" && nextCustomer != "n");

        for (int i = 0; i <= orderCount; ++i) {
            orderBookGenres[i] = ""; // Setting each element to an empty string
            orderBookNames[i] = "";
            orderBookAuthors[i] = "";
            orderBookNumbers[i] = "";
            orderQuantities[i] = 0;
            orderPrices[i] = 0;
            orderCount = 0;
            subTotal = 0;
            orderTotalQuantities = 0;
        }

        if (nextCustomer == "N" || nextCustomer == "n")
            return;

        system("CLS");
    }
}

// Function for main menu
void mainMenu() {
    //variable
    string position = " ";   //variable to verify staff or manager
    string input = " ";      //input to choose the type of user system
    bool define_loop = false;  //define user is staff or manager
    bool wrong_choice_valid = true;
    bool position_loop = false;     //repeat manager and staff menu loop

    //define customer or staff
    while (!define_loop)
    {
        company_logo();
        //define user is customer or staff
        cout << setw(30) << " " << setfill('=') << setw(51) << '=' << setfill(' ') << endl;
        cout << setw(30) << " " << setw(50) << left << "| Welcome To Famous Bookstore" << "|" << endl;
        cout << setw(30) << " " << setw(50) << left << "|\t  1. Manager" << "|" << endl;
        cout << setw(30) << " " << setw(50) << left << "|\t  2. Staff" << "|" << endl;
        cout << setw(30) << " " << setfill('=') << setw(51) << '=' << setfill(' ') << endl;

        if (!wrong_choice_valid)
        {
            cout << setw(30) << " " << RED << "Wrong choice. Please re-enter your choice" << RESET << endl;
            wrong_choice_valid = true;
        }

        if (!logged_in)
        {
            cout << setw(30) << " " << RED << "Invalid ID or password! Please try again." << RESET << endl;
            logged_in = true;
        }

        cout << setw(30) << " " << "Choice: ";
        getline(cin, position);

        //Manager Menu
        if (position == "1")
        {
            define_loop = true;
            position_loop = false;  //reset the position_loop for the Manager Menu
            system("CLS");
            logged_in = false;

            //manager id and password
            users_id[0] = { "user123" };
            users_password[0] = { "password" };
            users_id[1] = { "ashton0718" };
            users_password[1] = { "ashton060718" };
            users_id[2] = { "darren1006" };
            users_password[2] = { "darren061006" };
            users_id[3] = { "zhaomin0619" };
            users_password[3] = { "tzm060619" };
            users_id[4] = { "weibo0901" };
            users_password[4] = { "lwb060901" };
            user_count = 5;

            company_logo();
            while (!logged_in)
            {
                logged_in = login_user();

                if (logged_in)
                {
                    cout << "Login successful!" << endl;
                    // Proceed to Manager Menu
                }
                else
                {
                    system("CLS");
                    logged_in = false;
                    return;
                }
            }

            //Manager Menu
            while (!position_loop)
            {
                system("CLS");
                company_logo();
                //first page
                cout << setw(30) << " " << setfill('=') << setw(51) << '=' << setfill(' ') << endl;
                cout << setw(30) << " " << setw(50) << left << "| Welcome to Famous Menu:" << "|" << endl;
                cout << setw(30) << " " << setw(50) << left << "|" << "|" << endl;
                cout << setw(30) << " " << setw(50) << left << "|         1. Order Entry" << "|" << endl;
                cout << setw(30) << " " << setw(50) << left << "|         2. Daily Book Sales Report " << "|" << endl;
                cout << setw(30) << " " << setw(50) << left << "|         3. Best and Worst Book Genre Sold" << "|" << endl;
                cout << setw(30) << " " << setw(50) << left << "|         4. Stock Report" << "|" << endl;
                cout << setw(30) << " " << setw(50) << left << "|         5. Return to position menu" << "|" << endl;
                cout << setw(30) << " " << setw(50) << left << "|         6. Exit the system" << "|" << endl;
                cout << setw(30) << " " << setfill('=') << setw(51) << '=' << setfill(' ') << endl;

                //display when invalid choice is cin
                if (!wrong_choice_valid)
                {
                    cout << setw(30) << " " << RED << "Invalid choice. Please re-enter" << RESET << endl;
                    wrong_choice_valid = true;
                }
                cout << setw(30) << " " << "Choice: ";
                getline(cin, input);

                //order entry
                if (input == "1")
                {
                    position_loop = true;
                    system("CLS");
                    orderEntry();
                }

                //salesReport
                else if (input == "2")
                {
                    position_loop = false;
                    system("CLS");
                    salesReport();
                    do {
                        cout << "Input \033[32mY\033[0m to return to manager menu:  ";
                        getline(cin, returnMenu);

                        if (returnMenu != "Y" && returnMenu != "y") {
                            cout << "Invalid input. Please enter 'Y' to exit." << endl;
                        }
                    } while (returnMenu != "Y" && returnMenu != "y");
                }

                //bestNworstSalesReport
                else if (input == "3")
                {
                    position_loop = false;
                    system("CLS");
                    bestNworstSalesReport();

                    do {
                        cout << "Input \033[32mY\033[0m to return to manager menu:  ";
                        getline(cin, returnMenu);

                        if (returnMenu != "Y" && returnMenu != "y") {
                            cout << "Invalid input. Please enter 'Y' to exit." << endl;
                        }
                    } while (returnMenu != "Y" && returnMenu != "y");
                }

                // stockReport
                else if (input == "4")
                {
                    position_loop = false;
                    system("CLS");
                    stockReport();

                    do {
                        cout << "Input \033[32mY\033[0m to return to manager menu:  ";
                        getline(cin, returnMenu);

                        if (returnMenu != "Y" && returnMenu != "y") {
                            cout << "Invalid input. Please enter 'Y' to exit." << endl;
                        }
                    } while (returnMenu != "Y" && returnMenu != "y");
                }

                // Return to position menu
                else if (input == "5")
                {
                    define_loop = false;
                    position_loop = true;
                    wrong_choice_valid = true;
                    system("CLS");
                }

                // Exit
                else if (input == "6")
                {
                    system("CLS");
                    exit_file(position_loop);
                    wrong_choice_valid = true;
                }

                else
                {
                    system("CLS");
                    wrong_choice_valid = false;
                }
            }
        }

        //Staff Menu
        else if (position == "2")
        {
            define_loop = true;
            position_loop = false;      //Reset the position_loop for the staff menu

            //Verify Staff

            while (!position_loop)
            {
                system("CLS");
                company_logo();
                //first page
                cout << setw(30) << " " << setfill('=') << setw(51) << '=' << setfill(' ') << endl;
                cout << setw(30) << " " << setw(50) << left << "| Welcome to Famous Staff Menu:" << "|" << endl;
                cout << setw(30) << " " << setw(50) << left << "|" << "|" << endl;
                cout << setw(30) << " " << setw(50) << left << "|         1. Order Entry" << "|" << endl;
                cout << setw(30) << " " << setw(50) << left << "|         2. Return to position menu" << "|" << endl;
                cout << setw(30) << " " << setw(50) << left << "|         3. Exit the system" << "|" << endl;
                cout << setw(30) << " " << setfill('=') << setw(51) << '=' << setfill(' ') << endl;
                //display invalid choice when cin wrong input
                if (!wrong_choice_valid)
                {
                    cout << setw(30) << " " << RED << "Invalid choice. Please re-enter" << RESET << endl;
                    wrong_choice_valid = true;
                }
                cout << setw(30) << " " << "Choice: ";
                getline(cin, input);

                //order entry
                if (input == "1") {
                    position_loop = true;
                    system("CLS");
                    orderEntry();
                }

                // Return to position menu
                else if (input == "2")
                {
                    define_loop = false;
                    position_loop = true;
                    wrong_choice_valid = true;
                    system("CLS");
                }

                //Exit
                else if (input == "3")
                {
                    system("CLS");
                    exit_file(position_loop);
                    wrong_choice_valid = true;
                }

                //Invalid choice in staff menu
                else
                {
                    system("CLS");
                    wrong_choice_valid = false;
                }
            }
        }

        //Invalid position input
        else
        {
            system("CLS");
            wrong_choice_valid = false;
        }
    }
}