#include "ImageSharpening.h"

// Default constructor
ImageSharpening::ImageSharpening() {
    // Constructor, no specific initialization needed here
}

// Destructor
ImageSharpening::~ImageSharpening() {
    // Destructor for cleaning up allocated memory
    for (int i = 0; i < kernelHeight; i++) {
        delete[] blurringKernel[i];
    }
    delete[] blurringKernel;
}

// Apply image sharpening to the input image using a sharpening kernel
ImageMatrix ImageSharpening::sharpen(const ImageMatrix& input_image, double k) {
    // Define a 3x3 blurring kernel
    kernelHeight = 3;
    kernelWidth = 3;

    // Allocate memory for the blurring kernel
    blurringKernel = new double*[kernelHeight];
    for (int i = 0; i < kernelHeight; i++) {
        blurringKernel[i] = new double[kernelWidth];
    }

    // Initialize the blurring kernel with values for image blurring
    for (int i = 0; i < kernelHeight; i++) {
        for (int j = 0; j < kernelWidth; j++) {
            blurringKernel[i][j] = 1.0 / 9.0;
        }
    }

    // Create a convolution object for blurring
    Convolution Convolve(blurringKernel, kernelHeight, kernelWidth, 1, true);

    // Convolve the input image to get a blurred image
    ImageMatrix BlurredImage = Convolve.convolve(input_image);
    ImageMatrix SharpImg(input_image.get_height(), input_image.get_width());

    // Apply image sharpening by combining the original and blurred images
    for (int i = 0; i < input_image.get_height(); i++) {
        for (int j = 0; j < input_image.get_width(); j++) {
            double temp = input_image.get_data(i, j) + (k * (input_image.get_data(i, j) - BlurredImage.get_data(i, j)));
            SharpImg.set_data(i, j, temp);

            // Ensure pixel values are within the 0-255 range
            if (SharpImg.get_data(i, j) > 255) {
                SharpImg.set_data(i, j, 255);
            } else if (SharpImg.get_data(i, j) < 0) {
                SharpImg.set_data(i, j, 0);
            }
        }
    }

    return SharpImg;
}
