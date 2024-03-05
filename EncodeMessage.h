#ifndef ENCODE_MESSAGE_H
#define ENCODE_MESSAGE_H

#include <string>
#include <vector>
#include "ImageMatrix.h"

// Class `EncodeMessage`: Provides the functionality to encode a message into an image.
class EncodeMessage {
public:
    // Constructors and destructors
    EncodeMessage(); // Default constructor
    ~EncodeMessage(); // Destructor

    // Encode a message into an image and return the encoded ImageMatrix
    ImageMatrix encodeMessageToImage(const ImageMatrix& img, const std::string& message, const std::vector<std::pair<int, int>>& positions);

    // Check if a number is prime
    bool isPrime(int number);

    // Calculate a Fibonacci number
    int fibonacciNumber(int number);

    // Convert an integer to a binary string
    std::string intToBinary(int number);

    // Convert a string to a binary number
    int stringToBinary(std::string& string);

private:
    // Any private helper functions or variables if necessary
};

#endif // ENCODE_MESSAGE_H
