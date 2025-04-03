#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

void showMainMenu() {
    cout << "\n====================================\n";
    cout << "  Tervetuloa Pullonpalautusjarjestelmaan!  \n";
    cout << "====================================\n";
    cout << "1 - Aloita palautus\n";
    cout << "0 - Lopeta\n";
    cout << "Valitse: ";
}

void showRecycleMenu() {
    cout << "\n------------------------------------\n";
    cout << " Valitse palautettava pakkaus:\n";
    cout << "1 - Pullo 0.33L (0.10e)\n";
    cout << "2 - Pullo 0.50L (0.20e)\n";
    cout << "3 - Pullo 1.50L (0.40e)\n";
    cout << "4 - Tolkki 0.33L (0.15e)\n";
    cout << "5 - Tolkki 0.50L (0.15e)\n";
    cout << "6 - Lopeta ja tulosta kuitti\n";
    cout << "Valitse: ";
}

void printReceipt(int countSmall, int countMedium, int countLarge, int countCanSmall, int countCanLarge, double totalAmount) {
    ofstream receiptFile("kuitit.txt", ios::app); // Avaa tiedoston lisäystilassa

    string receipt = "\n========== KUITTI ==========\n";
    receipt += "Pullo 0.33L  x " + to_string(countSmall) + " = " + to_string(countSmall * 0.10) + "e\n";
    receipt += "Pullo 0.50L  x " + to_string(countMedium) + " = " + to_string(countMedium * 0.20) + "e\n";
    receipt += "Pullo 1.50L  x " + to_string(countLarge) + " = " + to_string(countLarge * 0.40) + "e\n";
    receipt += "Tolkki 0.33L x " + to_string(countCanSmall) + " = " + to_string(countCanSmall * 0.15) + "e\n";
    receipt += "Tolkki 0.50L x " + to_string(countCanLarge) + " = " + to_string(countCanLarge * 0.15) + "e\n";
    receipt += "---------------------------------\n";
    receipt += "Yhteensa: " + to_string(totalAmount) + "e\n";
    receipt += "Kiitos palautuksesta!\n";
    receipt += "===========================\n";

    cout << receipt;
    receiptFile << receipt; // Kirjoitetaan kuitti tiedostoon
    receiptFile.close();
}

void recyclingLoop() {
    int choice;
    int countSmall = 0, countMedium = 0, countLarge = 0, countCanSmall = 0, countCanLarge = 0;
    double totalAmount = 0.0;

    while (true) {
        showRecycleMenu();
        cin >> choice;

        if (choice == 1) { countSmall++; totalAmount += 0.10; }
        else if (choice == 2) { countMedium++; totalAmount += 0.20; }
        else if (choice == 3) { countLarge++; totalAmount += 0.40; }
        else if (choice == 4) { countCanSmall++; totalAmount += 0.15; }
        else if (choice == 5) { countCanLarge++; totalAmount += 0.15; }
        else if (choice == 6) {
            printReceipt(countSmall, countMedium, countLarge, countCanSmall, countCanLarge, totalAmount);
            break;
        }
        else {
            cout << "Virheellinen valinta, yrita uudelleen.\n";
        }
    }
}

int main() {
    int choice;

    while (true) {
        showMainMenu();
        cin >> choice;

        if (choice == 1) {
            recyclingLoop();
        }
        else if (choice == 0) {
            cout << "Ohjelma suljetaan. Kiitos ja nakemiin!\n";
            break;
        }
        else {
            cout << "Virheellinen valinta, yrita uudelleen.\n";
        }
    }

    return 0;
}
