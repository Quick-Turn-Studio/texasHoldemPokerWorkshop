#pragma once

#include <vector>

#include "Card.h"

namespace texasHolderPoker
{

class IDeckShuffler
{
public:
    ///
    /// \return Should return shuffle deck of cards
    virtual std::vector<Card> shuffleDeck() = 0;
};

} // namespace texasHolderPoker
