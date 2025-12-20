# keebs

A place for my keyboard keymaps and configurations.

I'm using vanilla QMK firmware on a rev1 [Corne](https://github.com/foostan/crkbd) and rev6 Planck (which I hardly use now).

## Setup

I build and flash using the [External QMK Userspace](https://docs.qmk.fm/newbs_external_userspace) feature.

The `flake.nix` is only to supply some utils that I otherwise don't have installed globally on my system. This is very far from being a hermetic setup.

Firstly, on NixOS the following sets up `udev` rules for non-root access to the firmware.

```nix
hardware.keyboard.qmk.enable = true;
```

One can use `nix develop` to get a nix dev shell, but I generally use nix-direnv and `direnv allow` once.

More one-time setup:

```sh
qmk setup -H ~/code/external/qmk_firmware
qmk config user.overlay_dir="$(realpath .)"
qmk config user.keymap=willbush
```

## Compile and flash

```sh
qmk compile -kb crkbd/rev1 -km willbush
qmk compile -kb planck/rev6 -km willbush
```

The `-km` can be omitted if `user.keymap` is set.

Replace `compile` with `flash` to flash.
