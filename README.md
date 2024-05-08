# usbDacVolumeAndroid

Simple application to set the USB DAC volume on UNROOTED Android Devices

# Why
The vast majority of high end android smartphones sold today do not contain a 3.5mm headphone jack. To remedy this, most people will use a USB-C to 3.5mm DAC. However, there are certian DACs (namely the Apple USB- C DAC) that do not default to their highest output setting. On most platforms (Windows, Linux, macOS, iOS), this isn't an issue because they either force the highest DAC volume and adjust their own mixer volume, or they control the DAC volume explicitly. Android does neither, so as a result, some DACs are quieter than they possibly can be.

# Usage
Launch the application, and connect your DAC. 
You should recieve a prompt asking to give USB Permission to the application. Press OK.
![image](https://github.com/guyman624/usbDacVolumeAndroid/assets/82007920/48d92739-bc2a-406b-853c-a14bf6f1228a)

Once you have accepted, you should see this:
![image](https://github.com/guyman624/usbDacVolumeAndroid/assets/82007920/565c040a-b112-43c2-bfd9-eef9f068121c)

- The top text input is the HEXADECIMAL value to send to the dongle. Leave this as 0000 for 100% volume.

- Auto Apply on Start means that the new value will be sent to the dongle immidiately upon detection.

- Apply will set the volume on the device.

- The bottom is the name of the detected USB Device.

You will temporarily lose sound during the setting of volume, however you should be able to restart playback after it has beens set. Please be aware that this setting is only saved until you unplug the headphones.


# Special thanks to:
[ibaiGorordo](https://github.com/ibaiGorordo/libusbAndroidTest) for most of the code :>
