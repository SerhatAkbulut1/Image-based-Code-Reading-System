# Image-based-Code-Reading-System

## Introduction

Welcome to your first assignment! This assignment is designed to familiarize you with C++ programming and basic data structures, particularly high-dimensional matrices. You will gain hands-on experience with classes, constructors, destructors, and various matrix operations. Additionally, you will implement these concepts for a basic image processing task, combining theoretical knowledge with real-world applications.

## Prerequisites

If you’re unfamiliar with image processing, don't worry! We will guide you through the terminology and operations step by step. Here are a few key concepts you'll be delving into:

1. **Image Matrix Representation:** Grayscale and colored images are represented as matrices. Each element corresponds to the intensity of a pixel, ranging from 0 (black) to 255 (white).

2. **Convolution:** A mathematical operation used in image processing to modify image appearance by applying a filter (kernel). Convolution involves sliding the kernel over the image, multiplying neighboring pixels by corresponding kernel values, and summing the results.

3. **Sobel Operator:** A discrete differentiation operator used for edge detection. It involves convolving the image with two 3x3 kernels designed to respond maximally to vertical and horizontal edges.

4. **Image Sharpening:** An image enhancement technique involving subtracting a blurred image from the original and adding the result back to the original to highlight edges.

5. **Edge Detection:** A process of identifying edges in an image by calculating the gradient magnitude and thresholding the result.

## Your Quest

In this assignment, you'll embark on a quest to decode hidden messages concealed within celestial images. Your tasks involve:

1. **Image Processing:** Implementing algorithms for image sharpening, edge detection, and decoding hidden messages.
2. **Message Decoding and Encoding:** Deciphering hidden messages using LSB steganography and embedding updated messages back into the image.
3. **Class Implementation:** Developing classes to handle different aspects of image processing, including image loading, matrix operations, convolution, edge detection, and message encoding/decoding.

## Problem Statements and Classes

You'll be working with several classes to handle various tasks:

1. **ImageLoader:** Simplifies image loading from a specified path.
2. **ImageMatrix:** Encapsulates pixel data of an image and provides functionalities for matrix operations.
3. **Convolution:** Performs convolution operations on an image.
4. **ImageSharpening:** Applies a basic image sharpening algorithm to an input image.
5. **EdgeDetector:** Detects edges in an image using Sobel operators.
6. **DecodeMessage:** Decodes a binary string into its ASCII representation.
7. **EncodeMessage:** Embeds a binary message back into an image matrix.
8. **ImageProcessor:** Utilizes all classes to decode and encode hidden messages in images.

Please refer to the provided problem statements and class implementations for detailed instructions and specifications.

## Instructions for Implementation

1. Ensure that you follow the provided specifications for each class and method.
2. Implement the given functions in the template files without changing their names.
3. Pay attention to memory management and ensure that dynamic memory allocation is handled properly.
4. Use the provided algorithms and pseudocode as guidelines for implementing the functionalities.
5. Test each method in each class thoroughly to ensure correctness and robustness.

Happy coding!
