# Steganography in C++

A simple project that demonstrates how to hide and extract secret messages within BMP image files using Least Significant Bit (LSB) manipulation in C++. This project encodes messages into images and decodes them back, showcasing basic steganography techniques.

## Table of Contents
- [Introduction](#introduction)
- [Features](#features)
- [How it Works](#how-it-works)
- [Usage](#usage)
- [Requirements](#requirements)
- [Screenshots](#screenshots)
- [Conclusion](#conclusion)
- [References](#references)

## Introduction
This project is a basic steganography implementation using the Least Significant Bit (LSB) method in C++. It allows users to encode a message into a BMP image by modifying the least significant bits of the pixel values, and decode the message later from the image. 

## Features
- **Encode Messages in Images**: Hides secret messages within the pixel data of BMP files.
- **Decode Messages from Images**: Extracts hidden messages from modified BMP files.
- **Simple Console-Based Interface**: Users can choose to encode or decode messages through simple terminal commands.

## How it Works
The project manipulates the least significant bit (LSB) of each byte in the BMP image file. This process is used to encode a message by converting it into binary and embedding it in the image. During decoding, the program reads the LSBs to reconstruct the original message.

- **Encoding**: Converts each character of the message into an 8-bit binary form and replaces the LSB of the image pixels with these bits.
- **Decoding**: Reads the LSBs of the image pixels, reconstructs the binary sequence, and converts it back to the original message.

## Usage

### 1. Clone the Repository
```bash
git clone https://github.com/champst2004/steganography-cpp.git
cd steganography-cpp
```
### 2. Compile the Program
```bash
g++ main.cpp -o steganography
```
### 3. Run the Program
```bash
./steganography
```
### 4. Follow the On-Screen Prompts
Encode: Enter the message you want to hide in the image.
Decode: Extract the hidden message from the encoded image.
### 5. Example
```bash
1. Encode
Enter the message: Hello, World!
Message encoded in output.bmp
```
```bash
2. Decode
The message in the image is: Hello, World!
```
## Requirements
C++11 or higher  
Any C++ compiler (e.g., g++, clang++)  
BMP image file for testing  
## Screenshots

## Conclusion
This project demonstrates how to implement basic steganography using C++ and bit manipulation. While it's a simple LSB technique, the project lays the foundation for more advanced steganography and cryptography techniques.
## References
[C++ Documentation](https://cplusplus.com/)  
[Bit Manipulation in C++](https://www.geeksforgeeks.org/bit-manipulation-in-c/)  
[Steganography - Wikipedia](https://en.wikipedia.org/wiki/Steganography)  
