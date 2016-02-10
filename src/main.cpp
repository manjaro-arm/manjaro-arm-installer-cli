#include "pstream.h"
#include <iostream>
#include <string>

// append 2>&1 to the command to get stderr output
void exec(std::string command){
    redi::ipstream proc(command, redi::pstreams::pstderr);
    std::string line;
    while (std::getline(proc.out(), line)) {
        std::cout << line << std::endl;
    }
}

void chrootExec(std::string command) {
    std::string targetFSPath("/home/owner/Downloads/chroot-env/");
    exec("chroot " + targetFSPath + " /qemu-arm-static " + command);
}

int main(int argc, char** argv) {
    std::cout << "Note: this program must be run as root\n";

    // TODO: Ask for tar.gz location
    // TODO: Extract tar.gz
    // TODO: Copy qemu-arm-static

    chrootExec("/bin/ls");
    return 0;
}