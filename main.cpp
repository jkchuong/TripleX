#include <iostream>

void PrintIntroduction(int LevelDifficulty)
{
    // Print welcome messages
    std::cout << "You are a secret agent breaking into a level " << LevelDifficulty << " secure server room" << std::endl;
    std::cout << "Enter the correct code to continue..." << std::endl;
}

bool PlayGame()
{
    const int A = 4;
    const int B = 3;
    const int C = 2;

    const int Sum = A + B + C;
    const int Product = A * B * C;

    std::cout << "There are 3 numbers in the code" << std::endl;
    std::cout << "The code adds up to " << Sum << std::endl;
    std::cout << "The code multiplies to " << Product << std::endl;

    int Guess1, Guess2, Guess3;

    std::cin >> Guess1 >> Guess2 >> Guess3;

    int GuessSum = Guess1 + Guess2 + Guess3;
    int GuessProduct = Guess1 * Guess2 * Guess3;

    // Check player input
    if (GuessSum == Sum && GuessProduct == Product)
    {
        std::cout << "You were right! You win!" << std::endl;
        return true;
    }
    else
    {
        std::cout << "You guessed wrong! You suck haha!" << std::endl;
        return false;
    }
}

int main()
{
    int LevelDifficulty = 1;

    while (LevelDifficulty <= 3)
    {
        bool LevelComplete;

        PrintIntroduction(LevelDifficulty);
        LevelComplete = PlayGame();

        if (!LevelComplete)
        {
            std::cout << "Exiting game because you lost." << std::endl;
            return 0;
        }

        std::cin.clear();
        std::cin.ignore();

        LevelDifficulty++;
    }

    return 0;
}