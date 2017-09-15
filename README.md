# libomniradar
C++ library bindings for Omniradar's RIC60 FMCW radar

The [Omniradar RIC60](http://www.omniradar.com/products/) is a 60Ghz, 7GHz bandwidth UWB FMCW radar with integrated on-chip antennas.

`libomniradar` is a C++ library that implements an interface which was strongly inspired by Omniradar's Matlab MEX driver for Windows.
This library is cross-platform and works on windows, unix and x86/arm architeture.  
Other than the language, the main difference is that the `AcquireEcho` function returns a _packed_ echo signal for performance reasons. The library provides a utility function that can unpack this echo signals.

There are also udev rules (you need both) that enable automatic [switchover](https://stackoverflow.com/a/44529377/5559867) from the standard linux VCP to `ftdi_sio`, which is necessary to use the driver's [FTDI D2XX](http://www.ftdichip.com/Drivers/D2XX.htm) interface.

If you want to use this library install the files somewhere where your compiler/linker can find them. Suggested locations are:

| File | Location |
| ---- | -------- |
| omniradar.h | /usr/local/include |
| libomniradar.so | /usr/local/lib |
| 51-omniradar.rules, <br/>52-omniradar.rules | /etc/udev/rules.d/ |
