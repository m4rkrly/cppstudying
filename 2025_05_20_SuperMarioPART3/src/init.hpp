#pragma once

const int MAPHEIGHT = 25;
const int MAPWIDTH = 80;

enum Status {
    LOSE = -1,
    NOTHING = 0,
    KILL = 1,
    WIN = 2,
    EXIT = 3
};
// namespace {
// }

// m4rkrly::Level Lvl1(
//     // Здесь используем конструктор от этих указателей и получаем готовый уровень!
// );
// // Возможно стоит создать объект Game, который будет хранить все части вместе
