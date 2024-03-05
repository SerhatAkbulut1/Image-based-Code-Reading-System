#include <iostream>

#include "Convolution.h"

// Default constructor 
Convolution::Convolution()  {
// Initialize default values for the class members
this->kernelHeight = 0;
this->kernelWidth = 0;
this->stride = 1;
this->padding = false ;
this->kernel = nullptr;
}


// Parametrized constructor for custom kernel and other parameters
Convolution::Convolution(double** customKernel, int kh, int kw, int stride_val, bool pad){
    // Initialize the class members with provided values
    this->kernelHeight = kh;
    this->kernelWidth = kw;
    this->stride = stride_val;
    this->padding = pad;
    this->kernel = new double*[kh];
    for (int i = 0; i < kh; ++i) {
        this->kernel[i] = new double[kw];
        for (int j = 0; j < kw; ++j) {
            this->kernel[i][j] = customKernel[i][j];
        }
    }
}

// Destructor
Convolution::~Convolution() {
    // Check if the kernel is not null and deallocate memory
    if (kernel != nullptr) {
        for (int i = 0; i < kernelHeight; ++i) {
            delete[] kernel[i];
        }
        delete[] kernel;
    }
}

Convolution::Convolution(const Convolution &other) {
    // Copy values from another Convolution object
    this->kernelHeight = other.kernelHeight;
    this->kernelWidth = other.kernelWidth;
    this->padding = other.padding;
    this->stride = other.stride;

    if (other.kernel) {
        // Deep copy the kernel array
        kernel = new double*[kernelHeight];
        for (int i = 0; i < kernelHeight; ++i) {
            kernel[i] = new double[kernelWidth];
            for (int j = 0; j < kernelWidth; ++j) {
                kernel[i][j] = other.kernel[i][j];
            }
        }
    }
}

// Copy assignment operator
Convolution& Convolution::operator=(const Convolution &other) {
    if (this == &other) {
        return *this;
    }
    // Copy values from another Convolution object
    kernelHeight = other.kernelHeight;
    kernelWidth = other.kernelWidth;
    stride = other.stride;
    padding = other.padding;
    // Deep copy the kernel array
    if (other.kernel) {
        kernel = new double*[kernelHeight];
        for (int i = 0; i < kernelHeight; ++i) {
            kernel[i] = new double[kernelWidth];
            for (int j = 0; j < kernelWidth; ++j) {
                kernel[i][j] = other.kernel[i][j];
            }
        }
    } else {
        kernel = nullptr;
    }
    return *this;
}
// Convolve Function: Responsible for convolving the input image with a kernel and return the convolved image.
ImageMatrix Convolution::convolve(const ImageMatrix& input_image) const {
    int inputHeight = input_image.get_height();
    int inputWidth = input_image.get_width();
    int x_coordinate; // Position of first kernel element x coordinate
    int y_coordinate; // Position of first kernel element y coordinate

    if(this->padding){
        // Calculate output dimensions with padding
        int outputHeight = (inputHeight - kernelHeight + 2) / stride + 1; // Calculation formula of output height
        int outputWidth =(inputWidth - kernelWidth + 2) / stride + 1;     // Calculation formula of output width
        ImageMatrix outputImage(outputHeight, outputWidth);
        ImageMatrix paddingImage(inputHeight+2, inputWidth+2);

        // Code block of creating padding image
        for (int i = 0; i < inputHeight+2; i++) {
            for (int j = 0; j < inputWidth+2; j++) {
                if(i==0||i== inputHeight+1){                    // Adding zeros to first and last rows of image
                    paddingImage.set_data(i,j,0);
                }
                else if(j==0||j== inputWidth+1){                // // Adding zeros to first and last columns of image
                    paddingImage.set_data(i,j,0);
                }else{
                    paddingImage.set_data(i,j,input_image.get_data(i-1,j-1));
                }

            }
        }
        // Calculate new values of output image
        x_coordinate = 0;
        for(int i = 0; i <outputHeight; i++){
            y_coordinate = 0;
            for (int j = 0; j < outputWidth; j++){
                double result = 0.0;
                for (int k = 0; k < kernelHeight; k++) {
                    for (int l = 0; l < kernelWidth; l++) {
                        double imageValue = paddingImage.get_data(x_coordinate + k, y_coordinate + l);
                        double kernelValue = kernel[k][l];
                        result += kernelValue*imageValue;
                    }
                }
                outputImage.set_data(i, j, result);
                y_coordinate += stride;
            }
            x_coordinate+=stride;
        }
        return outputImage;
    }else{
        // Calculate output dimensions without padding
        int outputHeight = ((inputHeight - kernelHeight)/stride)+1; // Calculation formula of output height
        int outputWidth =((inputWidth - kernelWidth)/stride)+1;     // Calculation formula of output width
        ImageMatrix outputImage1=input_image;
        ImageMatrix outputImage(outputHeight, outputWidth);
        // Calculate new values of output image
        x_coordinate = 0;
        for(int i = 0; i < outputHeight; i++){
            y_coordinate = 0;
            for (int j = 0; j < outputWidth; j++){
                double result = 0.0;
                for (int k = 0; k < kernelHeight; k++) {
                    for (int l = 0; l < kernelWidth; l++) {
                        double imageValue = outputImage1.get_data(x_coordinate + k, y_coordinate + l);
                        double kernelValue = kernel[k][l];
                        result += kernelValue*imageValue;
                    }
                }
                outputImage.set_data(i, j, result);
                y_coordinate += stride;
            }
            x_coordinate += stride;
        }
        return outputImage;
    }

}
