# pisi-lightdm-greeter 

[TÜRKÇE](https://github.com/ayhanyalcinsoy/pisi-lightDM-greeter/)

## Destination

pisi-lightdm-greeter is a login application for the lightdm displaymanager, written in c++ and qt5. This project forked from [hvl-lightdm-greeter](https://github.com/aciklab/Hvl-Lightdm-Greeter). 

This greeter provides to reset expired passwords (Tested with Windows active directory accounts and local accounts). If a password expired. greeter opens password reset page and prompt user to reset password.

Tested on Pisi GNU/Linux

## Installing

### Compile

For building, make sure you have; 
- qt5-default
- cmake
- qtwebengine5-dev 
- libqt5x11extras5-dev
- liblightdm-qt5-3-dev
- libxcursor-dev
- libxrandr-dev 
- lightdm
- qttools5-dev-tools

installed on your system

For running, dependencies are : lightdm, libqt5webenginewidgets5, liblightdm-qt5-3-0, libqt5webengine5, libx11-6, libxcursor1, libqt5x11extras5

To install, do:
    
```shell
git clone https://github.com/ayhanyalcinsoy/pisi-lightDM-greeter.git
cd pisi-lightDM-greeter
mkdir build
cd build
cmake ..
make 
sudo make install
```

Update or insert in(to) your `/etc/lightdm/lightdm.conf`, in the `SeatDefaults` section, this line:

    greeter-session=pisi-lightdm-greeter

If this file is not exist create new one.	

### on Pisi GNU/Linux
Installable using Package Manager or typing following command on terminal.

```
sudo pisi it pisi-lightdm-greeter

```
	
## Configuration

The file `/usr/share/lightdm/lightdm-pisi-greeter.conf.d/pisi-lightdm-greeter.conf` allows to configure pisi-lightdm-greeter. For example: 
	-background-image, 
	-positioning of loginform, settingsform and clockform. 
	-System services to wait etc.
The configuration options are documented in that file.

<img src="https://raw.githubusercontent.com/ayhanyalcinsoy/pisi-lightDM-greeter/master/ss/screen_shoot.jpg">
