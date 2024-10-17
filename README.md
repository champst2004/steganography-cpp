# Steganography in C++

A simple project that demonstrates how to hide and extract secret messages within BMP image files using Least Significant Bit (LSB) manipulation in C++. This project encodes messages into images and decodes them back, showcasing basic steganography techniques.

## Table of Contents
- [Introduction](#introduction)
- [Features](#features)
- [Project Structure](#project-structure)
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

## Project Structure
