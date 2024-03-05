#include "ImageMatrix.h"
#include <iostream>

// Default constructor
ImageMatrix::ImageMatrix() {
    // Constructor, no specific initialization needed here
}

// Parameterized constructor for creating a blank image of given size
ImageMatrix::ImageMatrix(int imgHeight, int imgWidth) {
    this->height = imgHeight;
    this->width = imgWidth;

    // Allocate memory for the data matrix and initialize with zeros
    data = new double*[height];
    for (int i = 0; i < height; ++i) {
        data[i] = new double[width];
        for (int j = 0; j < width; ++j) {
            data[i][j] = 0.0;
        }
    }
}

// Parameterized constructor for loading an image from a file (provided for convenience)
ImageMatrix::ImageMatrix(const std::string &filepath) {
    // Create an ImageLoader object and load the image
    ImageLoader imageLoader(filepath);

    // Get the dimensions of the loaded image
    height = imageLoader.getHeight();
    width = imageLoader.getWidth();

    // Allocate memory for the data matrix
    data = new double*[height];
    for (int i = 0; i < height; ++i) {
        data[i] = new double[width];
    }

    // Copy data from imageLoader to data
    double** imageData = imageLoader.getImageData();
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; j++) {
            data[i][j] = imageData[i][j];
        }
    }
}

// Destructor
ImageMatrix::~ImageMatrix() {
    // Deallocate memory for the data matrix
    for (int i = 0; i < height; i++) {
        delete[] data[i];
    }
    delete[] data;
}

// Parameterized constructor - direct initialization with a 2D matrix
ImageMatrix::ImageMatrix(const double** inputMatrix, int imgHeight, int imgWidth) {
    this->height = imgHeight;
    this->width = imgWidth;

    data = new double*[height];
    for (int i = 0; i < height; i++) {
        data[i] = new double[width];
        for (int j = 0; j < width; j++) {
            data[i][j] = inputMatrix[i][j];
        }
    }
}

// Copy constructor
ImageMatrix::ImageMatrix(const ImageMatrix &other) {
    this->height = other.height;
    this->width = other.width;
    data = new double*[height];

    for (int i = 0; i < height; i++) {
        data[i] = new double[width];
        for (int j = 0; j < width; j++) {
            data[i][j] = other.data[i][j];
        }
    }
}

// Copy assignment operator
ImageMatrix& ImageMatrix::operator=(const ImageMatrix &other) {
    if (this == &other) {
        return *this;
    }

    height = other.height;
    width = other.width;

    // Allocate memory for the data matrix and copy data
    data = new double*[height];
    for (int i = 0; i < height; i++) {
        data[i] = new double[width];
        for (int j = 0; j < width; j++) {
            data[i][j] = other.data[i][j];
        }
    }
    return *this;
}

// Overloaded operators

// Overloaded operator + to add two matrices
ImageMatrix ImageMatrix::operator+(const ImageMatrix &other) const {
    ImageMatrix result(this->get_height(), this->get_width());

    // Perform element-wise addition
    for (int i = 0; i < this->get_height(); i++) {
        for (int j = 0; j < this->get_width(); j++) {
            result.data[i][j] = get_data(i, j) + other.get_data(i, j);
        }
    }

    return result;
}

// Overloaded operator - to subtract two matrices
ImageMatrix ImageMatrix::operator-(const ImageMatrix &other) const {
    ImageMatrix result(get_height(), get_width());

    // Perform element-wise subtraction
    for (int i = 0; i < get_height(); i++) {
        for (int j = 0; j < get_width(); j++) {
            result.data[i][j] = get_data(i, j) - other.get_data(i, j);
        }
    }

    return result;
}

// Overloaded operator * to multiply a matrix by a scalar
ImageMatrix ImageMatrix::operator*(const double &scalar) const {
    ImageMatrix result(get_height(), get_width());

    // Perform scalar multiplication
    for (int i = 0; i < get_height(); i++) {
        for (int j = 0; j < get_width(); j++) {
            result.data[i][j] = get_data(i, j) * scalar;
        }
    }
    return result;
}

// Getter functions for height, width, and data
int ImageMatrix::get_height() const {
    return this->height;
}

int ImageMatrix::get_width() const {
    return this->width;
}

double** ImageMatrix::get_data() const {
    return this->data;
}

// Getter function to access the data at a specific index (i, j)
double ImageMatrix::get_data(int i, int j) const {
    return data[i][j];
}

// Setter function to set the data at a specific index (i, j)
void ImageMatrix::set_data(int row, int col, double value) {
    data[row][col] = value;
}

// Function to print the image data
void ImageMatrix::print() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            std::cout << get_data(i, j) << "\t";
        }
        std::cout << "\n";
    }
}
