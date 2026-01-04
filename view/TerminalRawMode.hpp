#ifndef TERMINAL_RAW_MODE_HPP
#define TERMINAL_RAW_MODE_HPP

#include <termios.h>
#include <unistd.h>
#include <stdexcept>

class TerminalRawMode {
public:
    TerminalRawMode() {

        if (tcgetattr(STDIN_FILENO, &orig_) == -1) {
            throw std::runtime_error("tcgetattr failed");
        }

        raw_ = orig_;
        cfmakeraw(&raw_);

        if (tcsetattr(STDIN_FILENO, TCSANOW, &raw_) == -1) {
            throw std::runtime_error("tcsetattr failed");
        }
    }

    ~TerminalRawMode() {
        tcsetattr(STDIN_FILENO, TCSANOW, &orig_);
    }

private:
    termios orig_;
    termios raw_;
};

#endif
