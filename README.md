# Ryan Miller's Planck Layout

Custom layout for building Planck keyboard [QMK Firmware](https://github.com/qmk/qmk_firmware). 

## Setup

Run:

```
$ git clone https://github.com/qmk/qmk_firmware.git
$ cd qmk_firmware
$ git clone https://github.com/ryanmillerc/planck.git \
            keyboards/planck/keymaps/ryanmillerc
$ make git-submodule
```

## Build

Run:

```
$ make planck/rev4:ryanmillerc
```

## Flash

Attach keyboard, enter RESET mode, then run:

```
$ make planck/rev4:ryanmillerc:dfu
```
