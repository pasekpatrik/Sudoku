#include "InputHandlerRaw.hpp"

#include <unistd.h>

InputEvent InputHandlerRaw::readKey() {
    unsigned char c;

    ssize_t n = read(STDIN_FILENO, &c, 1);
    if (n <= 0)
        return {Key::Unknown};

    if (c == 27) {
        unsigned char seq[2];

        if (read(STDIN_FILENO, &seq[0], 1) <= 0) return {Key::Unknown};
        if (read(STDIN_FILENO, &seq[1], 1) <= 0) return {Key::Unknown};

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

    if (c >= '1' && c <= '9')
        return {Key::Number, c - '0'};

    if (c == 'q' || c == 'Q')
        return {Key::Quit};

    return {Key::Unknown};
}
