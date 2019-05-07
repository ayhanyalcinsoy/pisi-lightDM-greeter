cmake_minimum_required(VERSION 3.0.2 FATAL_ERROR)
project(pisi-lightdm-greeter)
add_subdirectory(src)


install(FILES  pisi-lightdm-greeter.desktop  DESTINATION /usr/share/xgreeters)
install(FILES pisi-lightdm-greeter.conf DESTINATION /usr/share/lightdm/lightdm-pisi-greeter.conf.d)

