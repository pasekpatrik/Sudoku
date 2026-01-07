#include "InputHandlerRaw.hpp"
#include <iostream>

InputEvent InputHandlerRaw::readKey() {
    char c;
    if (!std::cin.get(c))
        return {Key::Unknown};

    if (c == 27) {
        char seq1, seq2;

        if (!std::cin.get(seq1)) return {Key::Unknown};
        if (!std::cin.get(seq2)) return {Key::Unknown};

        if (seq1 == '[') {
            switch (seq2) {
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
