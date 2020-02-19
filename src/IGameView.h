#pragma once

namespace texasHolderPoker
{

struct Card;
struct GameSettings;
struct RoundSetup;
struct Decision;
struct RoundResult;

class IGameView
{
public:
    virtual void onPlayerDecision(const Decision& decision) = 0;
    virtual void onCardsShow(const std::vector<Card> showCards) = 0;

    virtual void onGameStart(const GameSettings& gameSettings) = 0;
    virtual void onGameEnd(int winningPlayer) = 0;

    virtual void onRoundStart(const RoundSetup& roundSetup) = 0;
    virtual void onRoundEnd(const RoundResult& roundResult) = 0;
};

} // namespace texasHolderPoker
