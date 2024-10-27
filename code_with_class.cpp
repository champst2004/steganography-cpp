#include <iostream>
#include <fstream>
#include <bitset>
using namespace std;

class BitManip {
public:
    string imageFile;
    string outputFile;

    void setLSB(char &byte, int bit) {
        byte = (byte & 0xFE) | (bit & 1);
    }

    int getLSB(char byte) {
        return byte & 1;
    }
};

class Stegano : public BitManip {
    public:
    void encodeMessage(const string &message){
        cout << "Enter input file name: ";
        getline(cin, imageFile);
        cout << "Enter output file name: ";
        getline(cin, outputFile);

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

    string decodeMessage(){
        string decode;
        cout << "Enter file name to decode from: ";
        getline(cin, decode);

        ifstream image(decode, ios::binary);

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
};

int main() {
    string message;
    int choice;

    Stegano img;

    do {
        cout << "1. Encode\n2. Decode\n3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "Enter message: ";
                getline(cin, message);
                img.encodeMessage(message);
                break;
            case 2:
                cout << "The message in the image is: " << img.decodeMessage() << endl;
                break;
            case 3:
                printf("Thank you!\n");
                break;
            default:
                cout << "Invalid choice" << endl;
        }
    } while (choice != 3);
    return 0;
}