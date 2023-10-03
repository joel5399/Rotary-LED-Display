# Rotary-LED-Display

## Idea
The concept behind this project involves rapidly rotating a rod and synchronizing the LEDs to create a discernible image.

![3d-model](/documetation/system.png "")

## Hardware
The entire structure is 3D printed using an FDM printer and assembled using screws. The STL files can be found in the 'printables' folder. To provide both power and data to the LEDs, I employ a [slip ring](https://www.digikey.ch/de/products/detail/adafruit-industries-llc/775/5353617?utm_adgroup=General&utm_term=&productid=5353617https://www.digikey.ch/de/products/detail/adafruit-industries-llc/775/5353617?utm_adgroup=General&utm_term=&productid=5353617). For this project, I have opted for [Dotstar LEDs](https://www.digikey.ch/de/products/detail/adafruit-industries-llc/2241/5761263?utm_adgroup=&utm_term=&productid=5761263&utm_content=) from Adafruit Industries LLC.
To measure the speed at which the LEDs are rotating, I incorporated a [hall sensor](https://www.conrad.com/p/tru-components-hall-effect-sensor-ah3661ua-24-54-v-dc-reading-range-0007-0007-t-to-92-soldering-1569221), which is mounted on the stator, along with a magnet attached to the rotating component.
For achieving consistent rotation, I employed a [DC Motor](https://www.conrad.ch/de/p/motraxx-sr555shp-3247s-75-universal-brushed-elektromotor-5887-u-min-244478.html) along with a [timing belt](https://www.conrad.ch/de/p/reely-zahnflachriemen-aeusserer-umfang-380-mm-anzahl-zaehne-152-209524.html?refresh=true) to achieve the appropriate transmission. To secure the pinion to the motor shaft, I also utilized a [small pinion](https://www.conrad.ch/de/p/reely-motorritzel-modul-typ-48-dp-bohrungs-o-3-2-mm-anzahl-zaehne-12-220035.html) that can be easily mounted onto the motor shaft. To get smooth and frictionless rotation, I used two [bell-bearing](https://www.conrad.ch/de/p/ubc-bearing-61804-2z-rillenkugellager-radial-bohrungs-o-20-mm-aussen-durchmesser-32-mm-drehzahl-max-19000-u-min-197384.html).


Initially, I attempted to control the LEDs using an Arduino Uno. However, after conducting a few tests, I discovered that the operating speed of the Uno was insufficient. Consequently, I made the switch to a [Raspberry Pi 1b](https://www.sparkfun.com/products/retired/11546) for improved performance.

## Electronic
![schematic](/documetation/schematic.png "")

## Software
To compile the program, please copy the '/code/display_rpi' folder to your Raspberry Pi. You can use the following command for this task:
```
scp -r /path/to/your/local/directory pi@your.pi.ip.address:/path/on/remote/pi
```
Alternatively, you can also clone this repository to your Raspberry Pi.

Certain functionalities in the program rely on OpenCV. If OpenCV is not already installed on your Raspberry Pi, please run the following command to install it:
```
sudo apt-get install libopencv-dev
```
Additionally, the program utilizes the pigpio library for GPIO control. You can locate the required file for loading this library in the 'display_rpi/cmake' folder, and it should be automatically downloaded during the compilation process.

### Compilation
Begin by creating a "build" folder within your project directory. Navigate into this newly created "build" directory. To build the project, execute the following command:
```
cmake ..
```
If CMake is not installed, you can do this with this command:
```
sudo apt-get install cmake
```
Once all the files have been built, you can compile your project using the following command:
```
make
```

### Execution
Before you can execute the program, you will need to initiate the pigpio daemon with the command:
```
sudo pigiod
```
This step only needs to be performed once after startup.

Now, within the "build" folder, you can launch the program and witness its magic in action. The program expects the absolute path to the image you want to display as an argument:

```
./display_rpi ~/display_rpi/img-src/image.jpg

```
