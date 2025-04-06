#pragma once
// Player.h
#pragma once

class Player {
public:
    Player(char mark);
    char getMark() const;

private:
    char mark;
};