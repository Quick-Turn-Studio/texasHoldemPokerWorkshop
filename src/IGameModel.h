#pragma once

#include "Hand.h"
#include "RoundSetup.h"

namespace texasHolderPoker
{

struct GameSettings;
struct Decision;
struct Card;

enum class RoundPhase
{
    HiddenPhase,
    ThreeCardsShowPhase,
    FourCardsShowPhase,
    FiveCardsShowPhase,
    RoundEnded,
};

class IGameModel
{
public:
    /// Starts game
    /// \param gameSettings game settings
    virtual void startGame(const GameSettings& gameSettings) = 0;

    /// Start new round
    /// \return round settings
    virtual RoundSetup startRound(const std::vector<Card>& deck) = 0;

    /// Perform action for current player
    /// \param decision decision
    /// \return If given decision was applied returns true.
    ///         If player cannot make that decision returns false.
    virtual bool setCurrentPlayerDecision(const Decision& decision) = 0;

    /// Returns current round phase
    /// \return current round phase
    virtual RoundPhase getCurrentRoundPhase() = 0;

    /// Returns player number who needs to make a decision
    /// \return
    virtual int getCurrentPlayer() const = 0;

    ///
    /// \param playerNumber player number
    /// \return Hands of given player numerb
    virtual Hand getPlayerHand(int playerNumber) const = 0;

    /// Returns all current players' money
    /// \return players' money
    virtual std::vector<int> getPlayersMoney() const = 0;

    /// Return player number, who won last game. If no game was ended returns -1
    /// \return last winning player
    virtual int getLastWinningPlayer() const = 0;

    /// Returns list of current shown cards
    /// \return vectors of cards
    virtual std::vector<Card> getShownCards() const = 0;

    /// Returns true if game is ended.
    /// \return true if game is ended. Otherwise false.
    virtual bool isGameEnded() const = 0;

    /// Return current money bet that player needs to call to keep play in current
    /// round. \return Current money bet
    virtual int getCurrentBet() const = 0;
};

} // namespace texasHolderPoker
