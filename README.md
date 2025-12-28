# keebs

A place for my keyboard keymaps and configurations.

I'm using vanilla QMK firmware on a rev1 [Corne](https://github.com/foostan/crkbd) and rev6 Planck (rarely use now).

## Architecture

- Using [External QMK Userspace](https://docs.qmk.fm/newbs_external_userspace)
- `qmk_firmware` repo pinned as a git submodule

## Setup

Pull `qmk_firmware` git submodule:

```sh
git submodule update --init --recursive
```

Configure with [qmk cli](https://github.com/qmk/qmk_cli) installed (using dev shell or otherwise):

```sh
qmk config user.keymap=willbush \
  user.overlay_dir="$(realpath .)" \
  user.qmk_home="$(realpath ./qmk_firmware)"
```

Verify:

```sh
qmk doctor
```

Ignore `qmk doctor` warning:

>QMK home does not appear to be a Git repository! (no .git folder)

## Compile and flash

```sh
qmk flash -kb crkbd/rev1
```

```sh
qmk flash -kb planck/rev6
```

Replace `flash` with `compile` to just compile.

## Dev shell

The `flake.nix` is only to supply some utils that I otherwise don't have installed globally on my system. This is very far from being a hermetic setup.

One can use `nix develop` to get a nix dev shell, but I generally use nix-direnv and `direnv allow` once.

## NixOS

On NixOS the following sets up `udev` rules for non-root access to the firmware.

```nix
hardware.keyboard.qmk.enable = true;
```
