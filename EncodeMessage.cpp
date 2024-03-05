#include "EncodeMessage.h"
#include <cmath>
#include <iostream>

// Default Constructor
EncodeMessage::EncodeMessage() {
    // Constructor, nothing specific to initialize here
}

// Destructor
EncodeMessage::~EncodeMessage() {
    // Destructor, nothing specific to clean up
}

// Convert a binary string to an integer
int EncodeMessage::stringToBinary(std::string &string) {
    int number = 0;

    for (int i = string.length() - 1; i >= 0; i--) {
        if (string[i] == '1') {
            number += static_cast<int>(std::pow(2, string.length() - 1 - i));
        }
    }

    return number;
}

// Convert an integer to a binary string
std::string EncodeMessage::intToBinary(int number) {
    std::string binaryCode = "";
    if (number == 0) {
        binaryCode = "0";
    }
    while (number > 0) {
        if (number % 2 == 0) {
            binaryCode = "0" + binaryCode;
        } else {
            binaryCode = "1" + binaryCode;
        }
        number /= 2;
    }
    return binaryCode;
}

// Check if a number is prime
bool EncodeMessage::isPrime(int n) {
    if (n <= 1) {
        return false;
    }

    for (int i = 2; i <= n / 2; i++) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

// Calculate a Fibonacci number
int EncodeMessage::fibonacciNumber(int number) {
    if (number <= 0) {
        return 0;
    }

    if (number == 1 || number == 2) {
        return 1;
    }

    int first = 1;
    int second = 1;
    int result = 0;

    for (int i = 3; i <= number; i++) {
        result = first + second;
        first = second;
        second = result;
    }

    return result;
}

// Encode a message into an image matrix
ImageMatrix EncodeMessage::encodeMessageToImage(const ImageMatrix &img, const std::string &message, const std::vector<std::pair<int, int>>& positions) {
    ImageMatrix encodeImg = img;
    std::string modifiedMessage = message;
    std::cout << modifiedMessage << std::endl;

    // Modify the message based on prime indices and Fibonacci values
    for (int i = 0; i < modifiedMessage.length(); i++) {
        if (isPrime(i)) {
            int value = static_cast<int>(modifiedMessage[i]);
            value += fibonacciNumber(i);
            if (value <= 32) {
                value += 33;
            } else if (value >= 127) {
                value = 126;
            }
            char new_char = static_cast<char>(value);
            modifiedMessage[i] = new_char;
            std::cout << modifiedMessage << std::endl;
        }
    }

    // Shift characters in the message
    int shiftAmount = modifiedMessage.length() / 2;
    if (shiftAmount > 0) {
        std::string temp = modifiedMessage;
        for (int i = 0; i < modifiedMessage.length(); i++) {
            modifiedMessage[(i + shiftAmount) % modifiedMessage.length()] = temp[i];
        }
    }

    std::string binaryCode = "";
    // Convert characters in the message to binary
    for (int i = 0; i < modifiedMessage.length(); i++) {
        int newValue = static_cast<int>(modifiedMessage[i]);
        binaryCode += intToBinary(newValue);
    }

    int i = 0; // Message index

    // Create a new image with new codes
    for (const std::pair<int, int>& position : positions) {
        int x = position.first;
        int y = position.second;

        if (i < binaryCode.length()) {
            double code = encodeImg.get_data(x, y);
            int Code = static_cast<int>(code);
            std::string lastBinary = intToBinary(Code);
            lastBinary.at(lastBinary.length() - 1) = binaryCode.at(i);
            i++;
            int newCode = stringToBinary(lastBinary);
            encodeImg.set_data(x, y, static_cast<double>(newCode));
        } else {
            return encodeImg;
        }
    }

    return encodeImg;
}
