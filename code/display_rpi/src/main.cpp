/* Titel: Turbo Display
*  Beschreibung: Ein LED Band rotiert so schnell, dass ein Bild entsteht!
*  Autor: Joel Flepp
*  Erstellungsdatum:14.10.2022
*  Änderungen:
*  28.11.2022 Erste Tests und Pinabänderungen
*  01.09.2023 Weiterentwcklung
*  13.09.2023 cpp Programm entwickelt für Raspberypi
*/

/*******************************************
 * Positionierung x und y
 *
 * (conector)left    right
 *       0 1 2 3 4   5 6 7 8 9
 *
 *       o o o o o x o o o o o
 *
 *  /\
 *  |
 *  |_____>
 *  (0;0)
 * *****************************************/

 //Includes
#include "hardware_controller.hpp"
#include "rpi_dotstar.hpp"
#include "rotation_controller.hpp"
#include "image_processor.hpp"

#include <unistd.h> 
#include <iostream>

//Pin Defines
enum class Pin {
    HALL_SENSOR = 4,
};

//Programm const
const unsigned ledCount = 58;
const char brightness = 20;    // Brightness in percent

//Functions
void setup(RpiDotStar& strip);

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "include the path to the image as an argument!" << std::endl;
        return 1;
    }

    ImageProcessor imageProcessor(argv[1]);
    HardwareController hardwareController;
    RotationController rotationController;
    RpiDotStar strip(ledCount, &hardwareController);
    hardwareController.setInterrupt(static_cast<unsigned>(Pin::HALL_SENSOR), &rotationController);
    setup(strip);
    strip.loadImage(imageProcessor.getImage());

    while (1) {
        double currentAngle = rotationController.getCurrentAngle(hardwareController.getCurrentTick());
        strip.updatePixelPositionsCartesian(currentAngle);
        strip.setStripColor();
        strip.show();
    }

}

void setup(RpiDotStar& strip) {
    strip.setBrightness(brightness);
    strip.clear();
    strip.show();
    usleep(10000);
}

