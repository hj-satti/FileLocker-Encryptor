#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void encryptFile(string filename, string password) {
    ifstream input(filename);
    ofstream output("encrypted.txt");

    char ch;
    int i = 0;

    while (input.get(ch)) {
        ch += password[i % password.length()];
        output.put(ch);
        i++;
    }

    input.close();
    output.close();
    cout << "✅ File encrypted successfully as 'encrypted.txt'.\n";
}

void decryptFile(string filename, string password) {
    ifstream input(filename);
    ofstream output("decrypted.txt");

    char ch;
    int i = 0;

    while (input.get(ch)) {
        ch -= password[i % password.length()];
        output.put(ch);
        i++;
    }

    input.close();
    output.close();
    cout << "✅ File decrypted successfully as 'decrypted.txt'.\n";
}

int main() {
    int choice;
    string filename, password;

    cout << "===== FILE LOCKER & ENCRYPTOR =====\n";
    cout << "1. Encrypt a file\n";
    cout << "2. Decrypt a file\n";
    cout << "Enter your choice (1 or 2): ";
    cin >> choice;
    cin.ignore();

    cout << "Enter filename: ";
    getline(cin, filename);
    cout << "Enter password: ";
    getline(cin, password);

    if (choice == 1) {
        encryptFile(filename, password);
    } else if (choice == 2) {
        decryptFile(filename, password);
    } else {
        cout << "❌ Invalid choice.\n";
    }

    return 0;
}
