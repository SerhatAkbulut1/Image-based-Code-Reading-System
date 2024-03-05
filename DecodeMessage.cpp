// DecodeMessage.cpp

#include "DecodeMessage.h"
#include <iostream>
#include "cmath"
#include <string>
// Default constructor
DecodeMessage::DecodeMessage() {
    // Nothing specific to initialize here
}

// Destructor
DecodeMessage::~DecodeMessage() {
    // Nothing specific to clean up
}
// Convert a binary string to an integer
int DecodeMessage::stringToBinary(std::string &string) {
    int number = 0;
    // Iterate through the binary string from right to left
    for (int i = string.length() - 1; i >= 0; i--) {
        if (string[i] == '1') {
            number += static_cast<int>(std::pow(2, string.length() - 1 - i));
        }
    }

    return number;
}
// Decode a message from an ImageMatrix using edgePixels
std::string DecodeMessage::decodeFromImage(const ImageMatrix& image, const std::vector<std::pair<int, int>>& edgePixels) {
    std::string binaryCode = "";

    // Loop through the edge pixels
    for (size_t index = 0; index < edgePixels.size(); ++index) {
        int i = edgePixels[index].first;
        int j = edgePixels[index].second;

        // Get the value from the image at pixel (i, j)
        double Value = image.get_data(i, j);
        int number = (int) Value;

        std::string binary;

        // Convert the number to binary representation
        if(number == 0){
            binary = "0";
        }
        while (number > 0) {
            if (number % 2 == 0) {
                binary = "0" + binary;
            } else {
                binary = "1" + binary;
            }
            number /= 2;
        }
        binaryCode += binary.at(binary.length()-1);
    }
    // Make sure the binary code has a length that is a multiple of 7
    if(binaryCode.length()% 7 == 0){
        binaryCode = binaryCode;
    }else{
        int neededValue = 7 - binaryCode.length() % 7;
        for (int i = 0; i < neededValue; i++) {
            binaryCode.insert(0, "0");
        }
    }
    // Convert binary to ASCII and return the decoded message
    std::string message = binaryToASCII(binaryCode);

    return message;
}
// Convert a binary string to an ASCII string
std::string DecodeMessage::binaryToASCII(const std::string &binaryString) {
    std::string decodeMessage = "";
    // Process the binary string in chunks of 7 bits
    for (int i = 0; i < binaryString.length(); i += 7) {
        std::string subStr = binaryString.substr(i, 7);;

        // Convert the 7-bit binary substring to an integer
        int Value = stringToBinary(subStr);

        // Adjust the value if it's out of the ASCII character range
        if (Value <= 32) {
            Value += 33;
        }
        if (Value >= 127) {
            Value = 126;
        }

        // Convert the integer value to its corresponding ASCII character
        char Char = static_cast<char>(Value);
        decodeMessage += Char;

    }
    return decodeMessage;
}


