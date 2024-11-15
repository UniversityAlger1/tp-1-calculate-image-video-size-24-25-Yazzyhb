#include "config/grayScaleImage.h"
// Parameters:
//   w: width of the image
//   h: height of the image
// Return value
//   grayScale size of the image Bitmap (in byte)
float grayScaleImage(int w, int h) {
    // Each pixel is 1 byte in a grayscale image
    int grayScaleSize = w * h; 
    return grayScaleSize; 
}
