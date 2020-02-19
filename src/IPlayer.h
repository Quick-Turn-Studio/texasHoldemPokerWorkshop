#pragma once

#include "Decision.h"

namespace texasHolderPoker
{

struct Hand;

class IPlayer
{
public:
    /// Sets player Hand
    /// \param hand Given hand cards
    virtual void onRoundStarted(int moneyCount, const Hand& hand) = 0;

    /// Returns decision about player action
    /// \param requiredMoney current game bet
    /// \return Players decision. If player wanna raise, decision needs to be
    /// filled by money count
    virtual Decision getDecision(int requiredMoney) = 0;
};

} // namespace texasHolderPoker
