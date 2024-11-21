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
    float colorFrameSize = w * h * 3*durationMovie * fps;   
   //size of black and white image (1 Byte)
    float bwFrameSize = w * h * 1*durationCredits * fps;     

   //total size in bytes 
    float totalSizeBytes = colorFrameSize *8 + bwFrameSize*1;

     //converting depending on specified unit

     //bytes
    if (strcmp(unit, "bt") == 0) {
        return totalSizeBytes/8;


     //Kilobits
    } else if (strcmp(unit, "ko") == 0) {
        return (totalSizeBytes / 8) / 1024.0;


      //Megabits
    } else if (strcmp(unit, "mo") == 0) {
        return ((totalSizeBytes /8)/1024)/1024;


      //gigabits
    } else if (strcmp(unit, "go") == 0) {
        return (((totalSizeBytes /8) /1024)/ 1024)/1024;
    }

    return 0;
}
float video(int w, int h, int durationMovie, int durationCredits, int fps, char* unit) {
   // YOUR CODE HERE - BEGIN
  // Calculer la taille d'un frame en bits pour chaque section
    float colorFrameSize = w * h * 3 *fps*durationMovie; // Section couleur : 3 octets/pixel
    float bwFrameSize = w * h* fps*durationCredits;    // Section noir et blanc : 1 octet/pixel
    // Taille totale de la video
    float totalSize = colorFrameSize *8 + bwFrameSize*1;

    // Conversion en fonction de l'unité
    if (strcmp(unit, "bt") == 0) {
        return totalSize / 8; // Convertir en octets
    } else if (strcmp(unit, "ko") == 0) {
        return (totalSize /8)/1024; // Convertir en kilooctets
    } else if (strcmp(unit, "mo") == 0) {
        return ((totalSize /8)/1024)/1024; // Convertir en mégaoctets
    } else if (strcmp(unit, "go") == 0) {
        return (((totalSize /8) /1024)/ 1024)/1024; // Convertir en gigaoctes
    }else 
    return totalSize;
   // YOUR CODE HERE - END
   return 0;
}