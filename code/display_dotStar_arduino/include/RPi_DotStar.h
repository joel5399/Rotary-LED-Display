/*!
 * @file RPi_DotStar.h
 *
 */

#ifndef _RPI_DOT_STAR_H_
#define _RPI_DOT_STAR_H_

typedef unsigned char uint8_t;
typedef unsigned int uint16_t;


/*!
  @brief  Class that stores state and functions for interacting with
          Adafruit DotStars and compatible devices.
*/
class RPi_DotStar {
public:
    RPi_DotStar(const int numLeds, const int &spiChannel = 0, const int &spiSpeed = 1000000);

    int clear(void);
    
private:

  uint16_t numLEDs;                   ///< Number of pixels
  uint8_t brightness;                 ///< Global brightness setting

};

#endif // _RPI_DOT_STAR_H_
