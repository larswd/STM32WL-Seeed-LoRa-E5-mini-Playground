# Setup Instructions.
## Necessary software and compiling the executable
Download Visual Studio Code <https://code.visualstudio.com>, then navigate to the extensions tab and download the PlatformIO extension.t Once downloaded, navigate to the ```.platformio``` folder within the terminal window of your choice. On ubuntu, this should be located in your home directory, while on windows it is found in ```C:\Users\my_user>```. In here, create a platforms folder if it does not already exist. Then, type the following 

```bash
cd platforms
git clone https://github.com/platformio/platform-ststm32
```
If you don't have git installed, you can find instructions on how to download it here: <https://github.com/git-guides/install-git>. Then, after installing git, try the above commands once more.

After evverything is downloaded, clone this repository to your computer. Then, in PlatformIO home, click Open Project and navigate to the WioPlayground folder within this directory and click 'Open "WioPlayground"'. In this project, we have a small ```main.cpp``` script which both writes to Serial and makes the built in LED flash, a small ```platformio.ini``` file specifying the board, platform, framework and crucially an instruction to run the python script ```extra_script.py``` after compilation. This script, made by Maximilian Gerhardt at the PlatformIO forums makes sure a .hex file, named ```firmware.hex``` is created during compilation. This file, which you will find in the ```.pio/build/nucleo_wl55jc/``` directory is the file that can be uploaded to the LoRa-E5-mini board. 

## Upload Instructions
To upload the board, we used the STM32 Cube Programmer, which can be downloaded here <https://www.st.com/en/development-tools/stm32cubeprog.html>, and a [ST Link V2 from Adafruit](https://www.adafruit.com/product/2548). The procedure for uploading is as follows: 
Open your STM32 programmer and set the following options shown in the image below

![bilde](https://user-images.githubusercontent.com/26024129/225601105-ae07751d-0471-4248-9f39-d06709f9ad06.png)

If the image does not show, or you are using a text-to-speech program, the options we use are:
Port: SWD 
Frequency (kHz): 4000 
Mode: Normal 
Access port: 0 
Reset Mode: Software Reset 
Speed: Reliable 
And whatever option of shared that makes your board show up in the Serial Number tab. For me this was "Enabled". 
Debug in low power mode: Yes

Now, connect the following four pins of the LoRa-E5-Mini to the ST-LINK V2: 

GND to GND 

DIO to SWDIO 

CLK to SWCLK 

RST to RST

Then plug both into the computer. If the following steps don't work, try rebooting the computer with both the ST-LINK and Wio-E5 still connected to the PC. On the Wio-E5-Mini press and hold the RST button, then click Connect in the STM32CubeProgrammer before releasing the RST button. Now, go into the Option bytes tab and verify that Read Out Protection is set to AA, as shown in the image below.  
![bilde](https://user-images.githubusercontent.com/26024129/225601551-cbef9a50-5d17-42a6-be6a-e81258ae6088.png)

After the write protection is disabled, navigate to the Erasing and Programming tab. Here, check both the "Verify programming" and "Run after programming" buttons, then in File Path navigate to your compiled hex-file in the platformio-project. Select the .hex-file in the menu and verify that it shows up in the File Path-line afterwards, as shown in the following image. 
![bilde](https://user-images.githubusercontent.com/26024129/225601899-6bd51291-44eb-4ea4-b44d-849f68cb8d72.png)

 Then, click *Start programming* and if everything works as intended the built in LED should start flashing.
