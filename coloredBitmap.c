#include <string.h>
#include "config/coloredBitmap.h"

// Parameters:
//   w: width of the image
//   h: height of the image
//   unit: Unit of the output value. It could be 'bt' bits, 'ko' kilobits, 'mo' megabits, 'go' gigabits

// Return value
//   Colored image size Bitmap (based on the unit passed parameter)
float coloredBitmap(int w, int h, char* unit) {
    int coloredBitmapSize = w * h * 3; 


        // Converting to bits
    if (strcmp(unit, "bt") == 0) {
        return coloredBitmapSize * 8;

        // Converting to kilobits
    } else if (strcmp(unit, "ko") == 0) {
        return coloredBitmapSize / 1024.0;

        // Converting to megabits
    } else if (strcmp(unit, "mo") == 0) {
        return (coloredBitmapSize /1024.0 ) / 1024.0;

        // Converting to gigabits
    } else if (strcmp(unit, "go") == 0) {
        return ((coloredBitmapSize /1024.0 )/1024.0) /1024.0;
    }
    return coloredBitmapSize;

    return 0;
}


  