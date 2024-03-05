// EdgeDetector.cpp

#include "EdgeDetector.h"
#include <cmath>

// Default constructor
EdgeDetector::EdgeDetector() {
    // Constructor, nothing specific to initialize here
}

// Destructor
EdgeDetector::~EdgeDetector() {
    // Destructor, nothing specific to clean up
}

// Detect Edges using the given algorithm
std::vector<std::pair<int, int>> EdgeDetector::detectEdges(const ImageMatrix& input_image) {
    // Initialize convolution filters for gradient calculations
    Convolution GxConv(Gx, 3, 3, 1, true);
    Convolution GyConv(Gy, 3, 3, 1, true);

    // Apply convolution to the input image with Gx and Gy filters
    ImageMatrix Ix = GxConv.convolve(input_image);
    ImageMatrix Iy = GyConv.convolve(input_image);
    ImageMatrix Copy(input_image.get_height(), input_image.get_width());

    // Calculate gradient magnitude for each pixel
    for (int i = 0; i < input_image.get_height(); i++) {
        for (int j = 0; j < input_image.get_width(); j++) {
            double gradientX = Ix.get_data(i, j);
            double gradientY = Iy.get_data(i, j);

            double result = sqrt(gradientX * gradientX + gradientY * gradientY);
            Copy.set_data(i, j, result);
        }
    }

    double sum = 0.0;
    double number = 0.0;

    // Calculate the magnitude and element number
    for (int i = 0; i < Copy.get_height(); i++) {
        for (int j = 0; j < Copy.get_width(); j++) {
            sum += Copy.get_data(i, j);
            number = number + 1.0;
        }
    }

    // Calculate the average
    double average = sum / number;
    std::vector<std::pair<int, int>> positionVector;

    // Find positions where magnitude is above average
    for (int i = 0; i < Copy.get_height(); i++) {
        for (int j = 0; j < Copy.get_width(); j++) {
            if (Copy.get_data(i, j) > average) {
                positionVector.push_back(std::make_pair(i, j));
            }
        }
    }

    return positionVector;
}
