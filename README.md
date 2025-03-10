# Barcode Reader & Writer

A cross-platform application for reading and generating barcodes, built with Qt and the Dynamsoft Barcode Reader SDK.

## Features

- Read barcodes from images and camera streams
- Generate barcodes in various formats
- Support for multiple barcode types (QR, Code128, EAN, etc.)
- Cross-platform compatibility (Windows, potentially other platforms)

## Technologies Used

- C/C++ (95.0%)
- C++ (3.3%)
- Qt Framework for UI
- Dynamsoft Barcode Reader SDK for barcode scanning functionality
- ZXing-CPP library for additional barcode operations

## Project Structure

- `Include/` - Header files for the application
- `Lib/Windows/` - Platform-specific library files
- `Main.qml` - Main QML file for the UI
- `ReadBarcode.qml` - QML component for barcode reading
- `BarcodeWriter.qml` - QML component for barcode generation
- `barcodereader.cpp/h` - C++ implementation of barcode reading functionality
- `barcodewriter.cpp/h` - C++ implementation of barcode writing functionality
- `frameprocessor.cpp/h` - Frame processing for video/camera input
- `imageprocessor.cpp/h` - Image processing utilities

## Prerequisites

- Qt 5.15 or higher
- CMake 3.14 or higher
- C++ compiler with C++11 support
- Dynamsoft Barcode Reader SDK (license required for production use)

## Building the Application

1. Clone the repository:
   ```
   git clone https://github.com/GilbertAshivaka/BarcodeReaderAndWriter.git
   ```

2. Navigate to the project directory:
   ```
   cd BarcodeReaderAndWriter
   ```

3. Create a build directory:
   ```
   mkdir build && cd build
   ```

4. Configure with CMake:
   ```
   cmake ..
   ```

5. Build the project:
   ```
   cmake --build .
   ```

## Usage

### Reading Barcodes

1. Launch the application
2. Select the "Read Barcode" option
3. Choose to scan from an image file or camera
4. If using camera, point it at the barcode
5. The application will display the decoded barcode information

### Generating Barcodes

1. Launch the application
2. Select the "Generate Barcode" option
3. Enter the data to encode
4. Select the barcode format (QR, Code128, etc.)
5. Configure additional options if needed
6. Save or export the generated barcode

## License

This project uses the Dynamsoft Barcode Reader SDK, which requires a license for production use. Please visit [Dynamsoft's website](https://www.dynamsoft.com/barcode-reader/overview/) for licensing information.

The remaining code is available under [specify your license, e.g., MIT, GPL, etc.]

## Acknowledgments

- [Dynamsoft](https://www.dynamsoft.com/) for their Barcode Reader SDK
- [Qt](https://www.qt.io/) for the application framework

## Contact

Gilbert Ashivaka - [GitHub Profile](https://github.com/GilbertAshivaka)

Project Link: [https://github.com/GilbertAshivaka/BarcodeReaderAndWriter](https://github.com/GilbertAshivaka/BarcodeReaderAndWriter)
