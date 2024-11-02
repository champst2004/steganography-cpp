#include <iostream>
#include <fstream>
#include <bitset>
#include <limits>
using namespace std;

void setLSB(char &byte, int bit) {
    byte = (byte & 0xFE) | (bit & 1);
}

int getLSB(char byte) {
    return byte & 1;
}

void encodeMessageInImage(const string &imageFile, const string &message, const string &outputFile) {
    ifstream image(imageFile, ios::binary);
    ofstream output(outputFile, ios::binary);

    if (!image.is_open() || !output.is_open()) {
        cerr << "Error opening file!" << endl;
        return;
    }

    char header[54];
    image.read(header, 54);
    output.write(header, 54);

    string binaryMessage;
    for (char c : message) {
        binaryMessage += bitset<8>(c).to_string();
    }

    binaryMessage += "00000000";

    char pixel;
    size_t messageIndex = 0;

    while (image.get(pixel)) {
        if (messageIndex < binaryMessage.size()) {
            setLSB(pixel, binaryMessage[messageIndex] - '0');
            messageIndex++;
        }
        output.put(pixel);
    }

    image.close();
    output.close();

    cout << "Message encoded in " << outputFile << endl;
}

string decodeMessageFromImage(const string &imageFile) {
    ifstream image(imageFile, ios::binary);

    if (!image.is_open()) {
        cerr << "Error opening file!" << endl;
        return "";
    }

    image.seekg(54);

    string binaryMessage;
    char pixel;
    string message;

    while (image.get(pixel)) {
        binaryMessage += to_string(getLSB(pixel));

        if (binaryMessage.size() == 8) {
            char decodedChar = bitset<8>(binaryMessage).to_ulong();
            if (decodedChar == '\0') {
                break;
            }
            message += decodedChar;
            binaryMessage.clear();
        }
    }
    image.close();
    return message;
}

int main() {
    string imageFile = "input.bmp";
    string outputFile = "output.bmp";
    string message;
    int choice;
    do {
        printf("1. Encode\n2. Decode\n3. Exit\n");
        printf("Enter choice: ");
        if (!(cin >> choice)) {
            cout << "Invalid input! Please enter a number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }    
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        switch(choice) {
            case 1:
                printf("Enter message: ");
                getline(cin,  message);
                encodeMessageInImage(imageFile, message, outputFile);
                break;
            case 2:
                cout << "The message in the image is: " << decodeMessageFromImage(outputFile) << endl;
                break;
            case 3:
                printf("Thank you!\n");
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while(choice != 3);
    return 0;
}