#include "GameController.h"

#include "GameSettings.h"
#include "IDeckShuffler.h"
#include "IGameModel.h"
#include "IGameView.h"
#include "IPlayer.h"
#include "RoundResult.h"

namespace texasHolderPoker
{

GameController::~GameController() = default;

GameController::GameController(std::unique_ptr<IGameModel> gameModel)
  : gameModel{std::move(gameModel)}
{
    // empty
}

void GameController::setDeckShuffler(std::unique_ptr<IDeckShuffler> deckShuffler)
{
    this->deckShuffler = std::move(deckShuffler);
}

void GameController::addPlayer(std::shared_ptr<IPlayer> player)
{
    players.push_back(std::move(player));
}

void GameController::addView(std::shared_ptr<IGameView> view)
{
    views.push_back(std::move(view));
}

bool GameController::startGame(const GameMoneyRules& moneyRules)
{
    const auto minimalPlayersCount = 2;
    if (players.size() < minimalPlayersCount) {
        return false;
    }
    if (!deckShuffler) {
        return false;
    }
    GameSettings settings;
    settings.playerCount = players.size();
    settings.moneyRules = moneyRules;

    gameModel->startGame(settings);
    for (const auto view : views) {
        view->onGameStart(settings);
    }

    while (!gameModel->isGameEnded()) {
        const auto roundResult = playRound();
        informViewsAboutRoundResult(roundResult);
    }
    informViewsAboutGameEnd();
    return true;
}

void GameController::informViewsAboutGameEnd() const
{
    const auto winningGamePlayer = gameModel->getLastWinningPlayer();
    for (const auto view : views) {
        view->onGameEnd(winningGamePlayer);
    }
}

RoundResult GameController::playRound() const
{
    const auto roundSetup = gameModel->startRound(deckShuffler->shuffleDeck());

    informViewsAboutRoundStart(roundSetup);
    informPlayersAboutDrawnCards();

    auto roundStep = gameModel->getCurrentRoundPhase();
    while (roundStep != RoundPhase::RoundEnded) {
        const auto currentPlayer = gameModel->getCurrentPlayer();
        const auto currentBet = gameModel->getCurrentBet();

        auto decision = players[currentPlayer]->getDecision(currentBet);

        const auto actionAccepted = gameModel->setCurrentPlayerDecision(decision);

        // if player cannot make valid decision, it means that he folds
        if (!actionAccepted) {
            constexpr Decision foldDecision = {DecisionKind::Fold, 0};
            decision = foldDecision;
            gameModel->setCurrentPlayerDecision(decision);
        }
        informViewAboutPlayerDecision(decision);

        const auto currentRoundStep = gameModel->getCurrentRoundPhase();
        if (currentRoundStep != roundStep && currentRoundStep != RoundPhase::RoundEnded) {
            informViewsAboutShownCards();
            roundStep = currentRoundStep;
        }
    }
    RoundResult roundResult;
    roundResult.winningPlayer = gameModel->getLastWinningPlayer();
    roundResult.playerMoney = gameModel->getPlayersMoney();

    return roundResult;
}

void GameController::informPlayersAboutDrawnCards() const
{
    const auto playersMoney = gameModel->getPlayersMoney();
    for (int playerNumber = 0; playerNumber < players.size(); ++playerNumber) {
        players[playerNumber]->onRoundStarted(playersMoney[playerNumber],
                                              gameModel->getPlayerHand(playerNumber));
    }
}

void GameController::informViewsAboutRoundResult(const RoundResult& roundResult) const
{
    // @TODO
}

void GameController::informViewAboutPlayerDecision(const Decision& decision) const
{
    // @TODO
}

void GameController::informViewsAboutShownCards() const
{
    // @TODO
}

void GameController::informViewsAboutRoundStart(const RoundSetup& roundSetup) const
{
    // @TODO
}

} // namespace texasHolderPoker
