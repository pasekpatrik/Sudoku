#pragma once
#include <unistd.h>

enum class Key {
    Up,
    Down,
    Left,
    Right,
    Number,
    Delete,
    Confirm,
    Quit,
    Unknown
};

struct InputEvent {
    Key key;
    int number = 0;
};

class InputHandlerRaw {
public:
    InputEvent readKey();
};
