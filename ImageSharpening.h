#ifndef IMAGE_SHARPENING_H
#define IMAGE_SHARPENING_H

#include "ImageMatrix.h"
#include "Convolution.h"

class ImageSharpening {
public:
    // Constructors and destructor
    ImageSharpening(); // Default constructor
    ~ImageSharpening(); // Destructor

    // Sharpen the input image using a blurring kernel and a scaling factor 'k'
    ImageMatrix sharpen(const ImageMatrix& input_image, double k);

private:
    // Private member variables
    double** blurringKernel;
    int kernelHeight;
    int kernelWidth;
};

#endif // IMAGE_SHARPENING_H
