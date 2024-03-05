# Image-based-Code-Reading-System

## Introduction

The Image Processing Assignment aims to familiarize participants with C++ programming and basic data structures, particularly high-dimensional matrices. It provides hands-on experience with classes, constructors, destructors, and various matrix operations, with a focus on real-world applications such as image processing tasks.

## Prerequisites

Participants need not have prior experience in image processing, as the assignment includes step-by-step guidance through the relevant terminology and operations. Key concepts covered include:

1. **Image Matrix Representation:** Grayscale and colored images are represented as matrices, with each element corresponding to the intensity of a pixel.

2. **Convolution:** A mathematical operation used in image processing for modifying image appearance through the application of filters.

3. **Sobel Operator:** A discrete differentiation operator employed for edge detection by convolving images with specific kernels.

4. **Image Sharpening:** An image enhancement technique used to highlight edges by subtracting a blurred image from the original.

5. **Edge Detection:** The process of identifying edges in an image using gradient magnitude calculations and thresholding.

## Your Quest

Participants will embark on a quest to decode hidden messages concealed within celestial images. Tasks include:

1. **Image Processing:** Implementing algorithms for image sharpening, edge detection, and decoding hidden messages.
2. **Message Decoding and Encoding:** Deciphering hidden messages using LSB steganography and embedding updated messages back into the image.
3. **Class Implementation:** Developing classes to handle different aspects of image processing, including image loading, matrix operations, convolution, edge detection, and message encoding/decoding.

## Problem Statements and Classes

The assignment involves working with several classes to handle various tasks:

1. **ImageLoader:** Simplifies image loading from a specified path.
2. **ImageMatrix:** Encapsulates pixel data of an image and provides functionalities for matrix operations.
3. **Convolution:** Performs convolution operations on an image.
4. **ImageSharpening:** Applies a basic image sharpening algorithm to an input image.
5. **EdgeDetector:** Detects edges in an image using Sobel operators.
6. **DecodeMessage:** Decodes a binary string into its ASCII representation.
7. **EncodeMessage:** Embeds a binary message back into an image matrix.
8. **ImageProcessor:** Utilizes all classes to decode and encode hidden messages in images.

Participants are encouraged to refer to the provided problem statements and class implementations for detailed instructions and specifications.

## Instructions for Implementation

1. Participants should ensure they follow the provided specifications for each class and method.
2. Implement the given functions in the template files without changing their names.
3. Pay attention to memory management and ensure dynamic memory allocation is handled properly.
4. Use the provided algorithms and pseudocode as guidelines for implementing the functionalities.
5. Thoroughly test each method in each class to ensure correctness and robustness.
