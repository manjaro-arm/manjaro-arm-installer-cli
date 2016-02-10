This git repository includes a `qemu-arm-static` binary in `bin/`. This binary is required to emulate the arm executables in chroot. To compile this binary, you can install `qemu-user-static` from the AUR - it will be located in `/usr/bin/qemu-arm-static`. It is included in the repository pre-compiled so that all distributions can use it without any dependency issues. The intention is to include it in the `manjaro-arm-installer-cli` binary as a resource.

# Installer options

* username
* password
* environment to download (can support both manjaro and archlinux)
* hostname
* locale/language
* time-zone
* partitioning?
* keyboard layout?

# How to chroot an ARM filesystem on an x86 machine

1. Copy qemu-arm-static to the root of the target filesystem
2. Inside the target filesystem, run `sudo chroot . /qemu-arm-static /bin/bash`

# Build Instructions

You will need `cmake` installed

1. mkdir build
2. cd build
3. cmake ..
4. make

# Pull Requests

Please run format-code.sh before submitting a pull request. You will need the `clang-format` executable to run it. If you are on an Arch or Manjaro system, install the `clang-tools-extra` package to install clang-format.
