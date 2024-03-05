#ifndef EDGE_DETECTOR_H
#define EDGE_DETECTOR_H

#include "ImageMatrix.h"
#include "Convolution.h"
#include <vector>

// Class `EdgeDetector`: Provides the functionality to detect edges in an image.
class EdgeDetector {
public:
    // Constructors and destructors
    EdgeDetector(); // Default constructor
    ~EdgeDetector(); // Destructor

    // Detect edges in the input image and return a vector of edge pixel positions
    std::vector<std::pair<int, int>> detectEdges(const ImageMatrix& input_image);

private:
    // Private member variables for defining convolution kernels
    double* Gx[3] = {
            new double[3]{-1.0, 0.0, 1.0},
            new double[3]{-2.0, 0.0, 2.0},
            new double[3]{-1.0, 0.0, 1.0}
    };

    double* Gy[3] = {
            new double[3]{-1.0, -2.0, -1.0},
            new double[3]{0.0, 0.0, 0.0},
            new double[3]{1.0, 2.0, 1.0}
    };
};

#endif // EDGE_DETECTOR_H
