#pragma once

#include <memory>
#include <vector>

#include "Decision.h"
#include "RoundResult.h"
#include "RoundSetup.h"

namespace texasHolderPoker
{

class IPlayer;
class IDeckShuffler;
class IGameView;
class IGameModel;

struct GameMoneyRules;

class GameController
{
public:
    explicit GameController(std::unique_ptr<IGameModel> gameModel);
    ~GameController();

    void setDeckShuffler(std::unique_ptr<IDeckShuffler> deckShuffler);
    void addPlayer(std::shared_ptr<IPlayer> player);
    void addView(std::shared_ptr<IGameView> view);

    bool startGame(const GameMoneyRules& moneyRules);

private: // methods
    RoundResult playRound() const;

    void informViewsAboutRoundStart(const texasHolderPoker::RoundSetup& roundSetup) const;
    void informViewsAboutShownCards() const;
    void informViewsAboutRoundResult(const RoundResult& roundResult) const;
    void informViewAboutPlayerDecision(const texasHolderPoker::Decision& decision) const;

private: // members
    std::unique_ptr<IDeckShuffler> deckShuffler;
    std::vector<std::shared_ptr<IGameView>> views;
    std::vector<std::shared_ptr<IPlayer>> players;
    std::unique_ptr<IGameModel> gameModel;
    void informViewsAboutGameEnd() const;
    void informPlayersAboutDrawnCards() const;
};

} // namespace texasHolderPoker
