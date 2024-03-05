#ifndef IMAGE_PROCESSOR_H
#define IMAGE_PROCESSOR_H

#include "ImageSharpening.h"
#include "EdgeDetector.h"
#include "DecodeMessage.h"
#include "ImageMatrix.h"
#include "EncodeMessage.h"

#include <vector>
#include <utility>

class ImageProcessor {
public:
    // Constructors and destructor
    ImageProcessor(); // Default constructor
    ~ImageProcessor(); // Destructor

    // Public member functions

    // Decode a hidden message from the provided image
    std::string decodeHiddenMessage(const ImageMatrix &img);

    // Encode a hidden message into the provided image
    ImageMatrix encodeHiddenMessage(const ImageMatrix &img, const std::string &message);

private:
    // Any private helper functions or variables if necessary

};

#endif // IMAGE_PROCESSOR_H
