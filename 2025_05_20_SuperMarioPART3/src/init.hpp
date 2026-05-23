#pragma once

const int MAPHEIGHT = 25;
const int MAPWIDTH = 80;

enum Status {
    LOSE = -1,
    NOTHING = 0,
    KILL = 1,
    SPAWN_COIN = 2,
    WIN = 3,
    EXIT = 4
};
// namespace {
// }

// m4rkrly::Level Lvl1(
//     // Здесь используем конструктор от этих указателей и получаем готовый уровень!
// );
// // Возможно стоит создать объект Game, который будет хранить все части вместе
