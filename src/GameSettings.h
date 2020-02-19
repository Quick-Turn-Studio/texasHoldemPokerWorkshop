#pragma once

#include "MoneyRules.h"

namespace texasHolderPoker
{

struct GameSettings
{
    unsigned int playerCount = 2;
    GameMoneyRules moneyRules;
};

} // namespace texasHolderPoker
