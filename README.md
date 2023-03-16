# Setup Instructions.
Download Visual Studio Code https://code.visualstudio.com/, then navigate to the extensions tab and download the PlatformIO extension.t Once downloaded, navigate to the ```.platformio``` folder within the terminal window of your choice. On ubuntu, this should be located in your home directory, while on windows it is found in ```C:\Users\my_user>```. In here, create a platforms folder if it does not already exist. Then, type the following 

```bash
cd platforms
git clone https://github.com/nobodywasishere/platform-ststm32.git
```
If you don't have git installed, you can find instructions on how to download it here: https://github.com/git-guides/install-git. Then, after installing git, try the above commands once more.

After evverything is downloaded, clone this repository to your computer. Then, in PlatformIO home, click Open Project and navigate to the WioPlayground folder within this directory.

Now, when you build your program, you should find a firmware.hex file within the .pio/build/nucleo_wl55jc directory. Remember this location. Open your STM32 programmer and set the following options: Port: SWD Frequency (kHz): 4000 Mode: Normal Access port: 0 Reset Mode: Software Reset Speed: Reliable And whatever option of shared that makes your board show up, for me this was Enabled. Debug in low power mode: Yes

Now, connect the following four pins of the Wio-E5-Mini to the ST-LINK V2: GND to GND DIO to SWDIO CLK to SWCLK RST to RST

Then plug both into the computer. If the following steps don't work, try rebooting the computer with both the ST-LINK and Wio-E5 still connected to the PC. On the Wio-E5-Mini press and hold the RST button, then click Connect in the STM32CubeProgrammer before releasing the RST button. Now, go into the Option bytes tab and verify that Read Out Protection is set to AA. Then, navigate to the Erasing and Programming tab.

Here, check both the "Verify programming" and "Run after programming" buttons, then in File Path navigate to your compiled hex-file in the platformio-project. Select the .hex-file in the menu and verify that it shows up in the File Path-line afterwards. Then, click start programming and the builtin led should start flashing.
