#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

// Function to remove the first word from each string in the vector
void remove_first_word(vector<string>& lines) {
    for (string& line : lines) {
        size_t pos = line.find(' ');
        if (pos != string::npos) {
            line = line.substr(pos + 1);
        }
    }
}

int main() {
    char choice;
    string input;
    vector<string> lines; // Vector to store lines of text
    do {
        // Menu display
        cout << "\nMenu:\n";
        cout << "1 - Enter lines of text\n";
        cout << "2 - Remove the first word from each line\n";
        cout << "3 - Display the result\n";
        cout << "4 - Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        system("cls");

        switch (choice) {
        case '1':
            // Enter lines of text
            cout << "Enter lines of text (Enter a blank line to stop):\n";
            cin.ignore(); // Clear input buffer
            while (getline(cin, input) && !input.empty()) {
                lines.push_back(input);
            }
            break;
        case '2':
            // Remove the first word from each line
            remove_first_word(lines);
            cout << "First word removed from each line." << endl;
            break;
        case '3':
            // Display the result
            cout << "Result:\n";
            for (const auto& line : lines) {
                cout << line << endl;
            }
            break;
        case '4':
            // Exit the program
            cout << "Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != '4');

    return 0;
}
