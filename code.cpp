#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const int MENU_SIZE = 30;
const float DISCOUNT = 0.10;

void showWelcomeMessage() {
    cout << "=====================================\n";
    cout << "         Welcome to KN Cafe\n";
    cout << "=====================================\n\n";
}

void initializeMenu(string items[], float prices[]) {
    items[0] = "Espresso";        prices[0] = 250.0;
    items[1] = "Americano";       prices[1] = 200.0;
    items[2] = "Cappuccino";      prices[2] = 250.0;
    items[3] = "Latte";           prices[3] = 200.0;
    items[4] = "Mocha";           prices[4] = 250.0;
    items[5] = "Macchiato";       prices[5] = 200.0;
    items[6] = "Flat White";      prices[6] = 200.0;
    items[7] = "Cold Coffee";     prices[7] = 200.0;
    items[8] = "Black Tea";       prices[8] = 80.0;
    items[9] = "Green Tea";       prices[9] = 100.0;
    items[10] = "Masala Tea";     prices[10] = 150.0;
    items[11] = "Lemon Tea";      prices[11] = 150.0;
    items[12] = "Ginger Tea";     prices[12] = 100.0;
    items[13] = "Herbal Tea";     prices[13] = 150.0;
    items[14] = "Veg Sandwich";       prices[14] = 250.0;
    items[15] = "Chicken Sandwich";   prices[15] = 170.0;
    items[16] = "Grilled Cheese";     prices[16] = 160.0;
    items[17] = "Club Sandwich";      prices[17] = 180.0;
    items[18] = "Paneer Sandwich";    prices[18] = 200.0;
    items[19] = "Egg Sandwich";       prices[19] = 150.0;
    items[20] = "Small Water Bottle"; prices[20] = 60.0;
    items[21] = "Large Water Bottle"; prices[21] = 100.0;
    items[22] = "Chicken Biryani";    prices[22] = 220.0;
    items[23] = "Mutton Biryani";     prices[23] = 250.0;
    items[24] = "Veg Biryani";        prices[24] = 200.0;
    items[25] = "Veg Burger";         prices[25] = 150.0;
    items[26] = "Chicken Burger";     prices[26] = 150.0;
    items[27] = "Cheese Burger";      prices[27] = 100.0;
    items[28] = "Double Patty Burger";prices[28] = 150.0;
    items[29] = "Fish Burger";        prices[29] = 200.0;
}

void displayMenu(string items[], float prices[]) {
    cout << left << setw(5) << "No."
         << setw(25) << "Item"
         << setw(10) << "Price"
         << setw(15) << "Discounted Price\n";
    cout << "-------------------------------------------------------\n";

    for (int i = 0; i < MENU_SIZE; i++) {
        float discountedPrice = prices[i] * (1 - DISCOUNT);
        cout << left << setw(5) << (i + 1)
             << setw(25) << items[i]
             << fixed << setprecision(2)
             << setw(10) << prices[i]
             << discountedPrice << "\n";
    }
}

int main() {
    string menuItems[MENU_SIZE];
    float menuPrices[MENU_SIZE];
    showWelcomeMessage();
    initializeMenu(menuItems, menuPrices);
    displayMenu(menuItems, menuPrices);

    char choice;
    float totalBill = 0.0;

    do {
        int itemNumber;
        int quantity;

        cout << "\nEnter the item number you want to order (1-" << MENU_SIZE << "): ";
        cin >> itemNumber;
        if (itemNumber < 1 || itemNumber > MENU_SIZE) {
            cout << "Invalid item number. Please try again.\n";
            continue;
        }

        cout << "Enter quantity: ";
        cin >> quantity;
        if (quantity <= 0) {
            cout << "Invalid quantity. Please try again.\n";
            continue;
        }

        float price = menuPrices[itemNumber - 1];
        float discountedPrice = price * (1 - DISCOUNT);
        float cost = discountedPrice * quantity;

        totalBill += cost;

        cout << fixed << setprecision(2);
        cout << quantity << " x " << menuItems[itemNumber - 1]
             << " @ " << discountedPrice << " each = " << cost << "\n";

        cout << "Do you want to order more? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    cout << "\n==========================\n";
    cout << "Total bill amount: " << fixed << setprecision(2) << totalBill << "\n";
    cout << "Thank you for visiting KN Cafe!\n";
    cout << "Have a great day!\n";}

    
