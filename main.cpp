#include <iostream>

#include <GameController.h>
#include <GameSettings.h>

int main()
{
    /* TASKS create:
     * - RandomPlayer class inheriting IPlayer
     * - StandardGameModel class inheriting IGameModel, try to use IHandComparator class
     * - StandardDeckShuffler class inheriting IDeckShuffler
     * - ConsoleView class inheriting IViewClass
     * - fill inform*** methods in GameController marked as TODO
     *
     * other options, create:
     * - AIPlayer - class with Artifical inteligence
     * - ConsolePlayer - class taking decisions from console
     * - other view class
     * - other game model class, eg. NetworkGameModel
     */

    // auto gameModel = std::make_unique<StandardGameModel>();
    // texasHolderPoker::GameController gameController{std::move(gameModel)};
    // auto consoleView = std::make_shared<ConsoleView>();
    // gameController->addView(consoleView);
    // gameController->addPlayer(std::make_shared<RandomPlayer>());
    // gameController->addPlayer(std::make_shared<RandomPlayer>());
    // gameController->addPlayer(std::make_shared<RandomPlayer>());
    // texasHolderPoker::GameMoneyRules rules;
    // gameController->startGame(rules);

    return 0;
}