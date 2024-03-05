#include "ImageProcessor.h"

// Default constructor
ImageProcessor::ImageProcessor() {
    // Constructor, no specific initialization needed here
}

// Destructor
ImageProcessor::~ImageProcessor() {
    // Destructor, no specific cleanup needed here
}

// Decode a hidden message from the provided image
std::string ImageProcessor::decodeHiddenMessage(const ImageMatrix &img) {
    DecodeMessage message;
    ImageSharpening ImageSharpen;
    EdgeDetector EdgeDetector;

    // Sharpen the input image
    ImageMatrix ımage = ImageSharpen.sharpen(img, 2);

    // Detect edges in the sharpened image
    std::vector<std::pair<int, int>> positionVector = EdgeDetector.detectEdges(ımage);

    // Decode the hidden message from the image
    std::string Message = message.decodeFromImage(ımage, positionVector);

    return Message;
}

// Encode a hidden message into the provided image
ImageMatrix ImageProcessor::encodeHiddenMessage(const ImageMatrix &img, const std::string &message) {
    EncodeMessage encodeMessage;
    ImageSharpening ImageSharpen;
    EdgeDetector EdgeDetector;

    // Sharpen the input image
    ImageMatrix ımage = ImageSharpen.sharpen(img, 2);

    // Detect edges in the sharpened image
    std::vector<std::pair<int, int>> positionVector = EdgeDetector.detectEdges(ımage);

    // Encode the message into the image using detected edges
    ImageMatrix lastImage = encodeMessage.encodeMessageToImage(img, message, positionVector);

    return lastImage;
}
