#include <iostream>
#include <fstream>
#include <vector>
#include <cstdint>

#pragma pack(push, 1) // Ensure structures are packed tightly

// BMP file header
struct BMPFileHeader {
    uint16_t bfType = 0x4D42; // "BM"
    uint32_t bfSize = 0;
    uint16_t bfReserved1 = 0;
    uint16_t bfReserved2 = 0;
    uint32_t bfOffBits = 54; // Header size (14 + 40)
};

// BMP info header
struct BMPInfoHeader {
    uint32_t biSize = 40;
    int32_t biWidth = 0;
    int32_t biHeight = 0;
    uint16_t biPlanes = 1;
    uint16_t biBitCount = 24; // 24 bits per pixel (RGB)
    uint32_t biCompression = 0;
    uint32_t biSizeImage = 0;
    int32_t biXPelsPerMeter = 2835;
    int32_t biYPelsPerMeter = 2835;
    uint32_t biClrUsed = 0;
    uint32_t biClrImportant = 0;
};

#pragma pack(pop)

// Function to generate the BMP file
void createEnglandFlagBMP(const std::string& filename, int width, int height) {
    // Validate dimensions
    if (width <= 0 || height <= 0) {
        std::cerr << "Invalid dimensions!\n";
        return;
    }

    // Define colors
    const uint8_t white[3] = {255, 255, 255};
    const uint8_t red[3] = {0, 0, 255};

    // Dimensions of the cross
    int crossThickness = std::min(width, height) / 5; // Thickness of the cross
    int horizontalStart = (height - crossThickness) / 2;
    int verticalStart = (width - crossThickness) / 2;

    // Padding for each row (BMP rows must be a multiple of 4 bytes)
    int rowPadding = (4 - (width * 3) % 4) % 4;

    // File and info headers
    BMPFileHeader fileHeader;
    BMPInfoHeader infoHeader;

    infoHeader.biWidth = width;
    infoHeader.biHeight = -height; // Negative to store the image in top-down order
    infoHeader.biSizeImage = (width * 3 + rowPadding) * height;
    fileHeader.bfSize = fileHeader.bfOffBits + infoHeader.biSizeImage;

    // Open file for binary writing
    std::ofstream outFile(filename, std::ios::binary);
    if (!outFile) {
        std::cerr << "Could not open file for writing!\n";
        return;
    }

    // Write headers
    outFile.write(reinterpret_cast<const char*>(&fileHeader), sizeof(fileHeader));
    outFile.write(reinterpret_cast<const char*>(&infoHeader), sizeof(infoHeader));

    // Write pixel data
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            // Determine color of the pixel
            if ((y >= horizontalStart && y < horizontalStart + crossThickness) ||
                (x >= verticalStart && x < verticalStart + crossThickness)) {
                outFile.write(reinterpret_cast<const char*>(red), 3);
            } else {
                outFile.write(reinterpret_cast<const char*>(white), 3);
            }
        }
        // Write padding
        outFile.write("\0\0\0", rowPadding);
    }

    outFile.close();
    std::cout << "BMP file created: " << filename << "\n";
}

int main() {
    int width, height;
    std::cout << "Enter the width of the flag: ";
    std::cin >> width;
    std::cout << "Enter the height of the flag: ";
    std::cin >> height;

    createEnglandFlagBMP("england_flag.bmp", width, height);
    return 0;
}
