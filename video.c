#include <string.h>
#include "config/video.h"

// Parameters:
//   w: width of the image
//   h: height of the image
//   durationMovie: duration in seconds of the color section
//   durationCredits: duration in seconds of the black-and-white section
//   fps: Frames Per Second of the video
//   unit: Unit of the output value. Could be 'bt' (bytes), 'ko' (kilobits), 'mo' (megabits), 'go' (gigabits)
// Return value:
//   Video size (based on the unit passed parameter)

float video(int w, int h, int durationMovie, int durationCredits, int fps, char* unit) {
   //size of colored image (3 Bytes)
    int colorFrameSizeBytes = w * h * 3;   
   //size of black and white image (1 Byte)
    int bwFrameSizeBytes = w * h * 1;     

    // Total frames in the video
    //colored
    int colorFrames = durationMovie * fps;
    //black and white
    int bwFrames = durationCredits * fps;

   //total size in bytes 
    int totalSizeBytes = (colorFrames * colorFrameSizeBytes) + (bwFrames * bwFrameSizeBytes);

     //converting depending on specified unit

     //bytes
    if (strcmp(unit, "bt") == 0) {
        return totalSizeBytes;


     //Kilobits
    } else if (strcmp(unit, "ko") == 0) {
        return (totalSizeBytes * 8) / 1024.0;


      //Megabits
    } else if (strcmp(unit, "mo") == 0) {
        return (totalSizeBytes * 8) / (1024.0 * 1024.0);


      //gigabits
    } else if (strcmp(unit, "go") == 0) {
        return (totalSizeBytes * 8) / (1024.0 * 1024.0 * 1024.0);
    }

    return 0;
}
