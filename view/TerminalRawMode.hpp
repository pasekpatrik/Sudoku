#ifndef TERMINAL_HPP
#define TERMINAL_HPP

inline void set_raw(const bool set) {
    if (set) {
        system("stty raw");
        system("stty -echo");
    } else {
        system("stty -raw");
        system("stty echo");
    }
}

#endif