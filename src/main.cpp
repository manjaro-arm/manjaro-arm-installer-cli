#include <iostream>
#include <unistd.h> // for chroot
#include <cerrno> // errno variable

int main(int argc, char** argv) {
    std::cout << "Note: this program must be run as root\n";
    int result = chroot("/home/owner/Downloads/chroot-env/");

    if (result == 0) {
        std::cout << "Chroot success." << std::endl;
    } else {
        std::cout << "Chroot failure: " << result << " " << errno << std::endl;
    }
    return 0;
}