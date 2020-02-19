#pragma once

namespace texasHolderPoker
{

enum class DecisionKind
{
    Fold,
    Call,
    Raise,
};

struct Decision
{
    DecisionKind decisionKind;
    int money = 0;
};

} // namespace texasHolderPoker
