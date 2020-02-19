#pragma once

namespace texasHolderPoker
{

enum class Color
{
    Hearts,
    Diamonds,
    Spades,
    Clubs,
};

enum class Figure
{
    Ace,
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Ten,
    Jack,
    Queen,
    King,
};

struct Card
{
    Figure figure;
    Color color;
};

} // namespace texasHolderPoker
