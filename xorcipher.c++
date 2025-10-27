#include <iostream>
#include <fstream>
#include <string>
#include <bitset>
using namespace std;

string XOR(const string& binary, const string& key) {
    string result = "";
    if(binary.length() == key.length()){
        for(size_t i = 0; i < binary.length(); i++){
            char r = ((binary[i] - '0') ^ (key[i] - '0')) + '0';
            result += r;
        }
    }
    return result;
}

string pad_key(int key) {
    string modified_key = to_string(key);
    string newkey = "";
    for (char c : modified_key) {
        for (int j = 0; j < 8; j++)
            newkey += c;
    }
    return newkey;
}

string str_to_bin(const string& line) {
    string binary_rep = "";
    for(char c : line){
        bitset<8> bits(c);
        binary_rep += bits.to_string();
    }
    return binary_rep;
}

string bin_to_str(const string& binary) {
    string text = "";
    for(size_t i = 0; i < binary.length(); i += 8){
        bitset<8> bits(binary.substr(i,8));
        char c = static_cast<char>(bits.to_ulong());
        text += c;
    }
    return text;
}

string decipher(const string& ciphered, int key) {
    string padded_key = pad_key(key);
    return XOR(ciphered, padded_key);
}

int main() {
    string filename, outputfile;
    int key, choice;
    ifstream inputfile;
    ofstream outfile;
    string line, temp_var;

    cout << "Please enter the file name: ";
    cin >> filename;

    inputfile.open(filename);
    if(!inputfile.is_open()){
        cout << "Error opening the file." << endl;
        return 1;
    }

    temp_var = "";
    while(getline(inputfile, line)){
        temp_var += line;
    }
    inputfile.close();

    cout << "Please enter the key (number of digits must match number of characters in message): ";
    cin >> key;

    string key_str = to_string(key);
    while(key_str.length() != temp_var.length()){
        cout << "Key length does not match message length. Try again: ";
        cin >> key;
        key_str = to_string(key);
    }

    cout << "Enter 0 for encryption, 1 for decryption: ";
    cin >> choice;

    switch(choice){
        case 0: { 
            string binary_rep = str_to_bin(temp_var);
            string padded_key = pad_key(key);
            string ciphered = XOR(binary_rep, padded_key);

            cout << "Ciphered Message (binary): " << ciphered << endl;

            cout << "Enter output file name to save cipher: ";
            cin >> outputfile;
            outfile.open(outputfile);
            outfile << ciphered;
            outfile.close();

            cout << "Encryption done. Cipher saved to " << outputfile << endl;
            break;
        }
        case 1: { 
            string ciphered = temp_var; 
            string decrypted_binary = decipher(ciphered, key);
            string original_message = bin_to_str(decrypted_binary);

            cout << "Decrypted message: " << original_message << endl;

            cout << "Enter output file name to save decrypted message: ";
            cin >> outputfile;
            outfile.open(outputfile);
            outfile << original_message;
            outfile.close();

            cout << "Decryption done. Message saved to " << outputfile << endl;
            break;
        }
        default:
            cout << "Invalid selection. Exiting..." << endl;
    }

    return 0;
}
