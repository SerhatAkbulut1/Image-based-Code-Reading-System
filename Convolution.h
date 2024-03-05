// Convolution.h

#ifndef CONVOLUTION_H
#define CONVOLUTION_H

#include "ImageMatrix.h"

// Class `Convolution`: Provides the functionality to convolve an image with
// a kernel. Padding is a bool variable, indicating whether to use zero padding or not.
class Convolution {
public:
    // Constructors and destructors
    Convolution(); // Default constructor
    Convolution(double** customKernel, int kernelHeight, int kernelWidth, int stride, bool padding); // Parametrized constructor for custom kernel and other parameters
    ~Convolution(); // Destructor

    Convolution(const Convolution &other); // Copy constructor
    Convolution& operator=(const Convolution &other); // Copy assignment operator

    // Convolve Function: Responsible for convolving the input image with a kernel and return the convolved image.
    ImageMatrix convolve(const ImageMatrix& input_image) const;

private:
    // Private member variables
    double** kernel; // The convolution kernel
    int kernelHeight; // Height of the kernel
    int kernelWidth; // Width of the kernel
    int stride; // Stride for the convolution
    bool padding; // Flag indicating whether to use padding or not
};

#endif // CONVOLUTION_H
