# Ryan Miller's Planck Layout

## Building

Run:

```
$ git clone https://github.com/qmk/qmk_firmware.git
$ cd qmk_firmware
$ git clone https://github.com/ryanmillerc/planck.git \
            keyboards/planck/keymaps/ryanmillerc
$ make planck/rev4:ryanmillerc
```

## Flashing

Turn on keyboard RESET mode, then run:

```
$ make planck/rev4:ryanmillerc:dfu
```
