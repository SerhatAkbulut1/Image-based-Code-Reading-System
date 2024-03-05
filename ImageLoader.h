#ifndef IMAGE_LOADER_H
#define IMAGE_LOADER_H

#include <string>
#include <vector>

// Class `ImageLoader`: Provides the functionality to load image data from a file.
class ImageLoader {
public:
    // Constructors and destructors
    ImageLoader(const std::string& filepath); // Constructor for loading an image from a file
    ImageLoader(const ImageLoader &other); // Copy constructor
    ImageLoader& operator=(const ImageLoader &other); // Copy assignment operator

    // Destructor
    ~ImageLoader();

    // Getter functions to obtain image height, width, and data
    int getHeight() const;
    int getWidth() const;
    double** getImageData() const;

private:
    int height;          // Height of the loaded image
    int width;           // Width of the loaded image
    double** imageData;  // Image data stored in a 2D matrix
};

#endif // IMAGE_LOADER_H
