#include "InputHandlerRaw.hpp"

#include <termios.h>
#include <unistd.h>

InputEvent InputHandlerRaw::readKey() {
    unsigned char c;
    read(STDIN_FILENO, &c, 1);

    if (c == 27) {
        unsigned char seq[2];
        read(STDIN_FILENO, &seq[0], 1);
        read(STDIN_FILENO, &seq[1], 1);

        if (seq[0] == '[') {
            switch (seq[1]) {
                case 'A': return {Key::Up};
                case 'B': return {Key::Down};
                case 'C': return {Key::Right};
                case 'D': return {Key::Left};
            }
        }
        return {Key::Unknown};
    }

    if (c >= '1' && c <= '9') {
        return {Key::Number, c - '0'};
    }

    if (c == 127) {
        return {Key::Delete};
    }

    if (c == '\n' || c == '\r') {
        return {Key::Confirm};
    }

    if (c == 'q') {
        return {Key::Quit};
    }

    return {Key::Unknown};
}
