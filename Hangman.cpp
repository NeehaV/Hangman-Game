#include <iostream>
#include <ctime>
#include <string>

std::string getWord(std::string &sectionName);
void printWord(char *resultArray, std::string answer);
void showHangman(int errorCount);
bool checkGuess(char guessedCharacter, std::string answer, char *resultArray, char *guessChoices);
bool checkGameStatus(char *resultArray, std::string answer);

int main()
{
    bool guessStatus, gameStatus;
    std::string answer, sectionName;
    char guessedCharacter;
    char choice = 'Y';
    int errorCount;
    int wordLength;

    do
    {
        errorCount = 0;
        gameStatus = false;
        char guessChoices[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

        answer = getWord(sectionName);
        wordLength = answer.length();

        char resultArray[wordLength];
        for (int i = 0; i < wordLength; i++)
        {
            resultArray[i] = '_';
        }

        while (true)
        {
            system("CLS");
            std::cout << "**********************************************" << '\n';
            std::cout << '\t' << '\t' << "HANGMAN GAME" << '\n';
            std::cout << "**********************************************" << '\n';

            std::cout << '\t' << '\t' << sectionName << '\n'
                      << '\n';

            printWord(resultArray, answer);
            showHangman(errorCount);

            std::cout << "**********************************************" << '\n';

            for (int i = 0; i < 26; i++)
            {
                std::cout << guessChoices[i] << "  ";
                if (i == 12)
                {
                    std::cout << '\n';
                }
            }

            std::cout << '\n'
                      << "**********************************************" << '\n';

            gameStatus = checkGameStatus(resultArray, answer);

            if (errorCount == 8)
            {
                std::cout << "YOU FAILED!" << '\n';
                std::cout << "Answer: " << answer << '\n';
                break;
            }
            else if (gameStatus == true)
            {
                std::cout << "YOU WON, CONGRAGULATIONS !!!!!!" << '\n';
                break;
            }
            else
            {
                bool available = true;
                do
                {
                    std::cout << '\n'
                              << "Enter your guess: ";
                    std::cin >> guessedCharacter;
                    guessedCharacter = toupper(guessedCharacter);
                    for (int i = 0; i < 26; i++)
                    {
                        if (guessedCharacter == guessChoices[i])
                        {
                            available = false;
                            break;
                        }
                    }
                } while (available);

                guessStatus = checkGuess(guessedCharacter, answer, resultArray, guessChoices);
                if (guessStatus != true)
                {
                    errorCount++;
                }
            }
        }

        std::cout << "Do you want to play again(Y/N): ";
        std::cin >> choice;
        choice = toupper(choice);
    } while (choice != 'N');

    return 0;
}
void printWord(char *resultArray, std::string answer)
{
    std::cout << '\t';
    for (int i = 0; i < answer.length(); i++)
    {
        if (answer[i] == ' ')
        {
            resultArray[i] = ' ';
            std::cout << " ";
        }
        std::cout << resultArray[i] << " ";
    }
    std::cout << '\n';
}
bool checkGameStatus(char *resultArray, std::string answer)
{

    int countOfCharacters = 0;
    for (int i = 0; i < answer.length(); i++)
    {
        if (answer[i] == resultArray[i])
        {
            countOfCharacters++;
        }
    }

    if (countOfCharacters == answer.length())
    {
        return true;
    }

    else
    {
        return false;
    }
}
bool checkGuess(char guessedCharacter, std::string answer, char *resultArray, char *guessChoices)
{
    bool status = false;

    for (int i = 0; i < 26; i++)
    {
        if (guessedCharacter == guessChoices[i])
        {
            guessChoices[i] = '_';
        }
    }

    for (int i = 0; i < answer.length(); i++)
    {
        if (answer[i] == guessedCharacter)
        {
            resultArray[i] = guessedCharacter;
            status = true;
        }
    }
    return status;
}
std::string getWord(std::string &sectionName)
{

    std::string ANIMAL[10] = {"ANACONDA", "ASIAN ELEPHANT", "BENGAL TIGER", "BUTTERFLY", "CRAYFISH", "EAGLE", "FLAMINGO", "FOX SQUIRREL", "SHEPHERD", "HEDGEHOG"};
    std::string PROFESSION[10] = {"BUTCHER", "DENTIST", "FACTORY WORKER", "LIFEGUARD", "BRICKLAYER", "ASTRONOMER", "POLITICIAN", "VETERINARY DOCTOR", "SCIENTIST", "NEWSREADER"};
    std::string FRUITS[5] = {"APRICOT", "PISTACHIO", "POPPY SEEDS", "CRANBERRY", "NECTARINES"};
    std::string VEGETABLES[5] = {"CAULIFLOWER", "BOTTLE GOURD", "DRUMSTICK", "ZUCCHINI", "BROCCOLI"};

    std::string word;
    int section, size;
    int position;
    do
    {
        srand(time(NULL));
        section = rand() % 4 + 1;

        switch (section)
        {
        case 1:
            sectionName = "Animal or bird";
            srand(time(NULL));
            size = sizeof(ANIMAL) / sizeof(ANIMAL[0]);
            position = rand() % size;
            word = ANIMAL[position];
            break;
        case 2:
            sectionName = "Profession";
            srand(time(NULL));
            size = sizeof(PROFESSION) / sizeof(PROFESSION[0]);
            position = rand() % size;
            word = PROFESSION[position];
            break;
        case 3:
            sectionName = "Fruit";
            srand(time(NULL));
            size = sizeof(FRUITS) / sizeof(FRUITS[0]);
            position = rand() % size;
            word = FRUITS[position];
            break;
        case 4:
            sectionName = "Vegetable";
            srand(time(NULL));
            size = sizeof(VEGETABLES) / sizeof(VEGETABLES[0]);
            position = rand() % size;
            word = VEGETABLES[position];
            break;
        Default:
            word = " ";
            break;
        }
    } while (word == " ");

    return word;
}
void showHangman(int errorCount)
{

    switch (errorCount)
    {
    case 0:
        std::cout << '\n'
                  << '\t' << '\t' << "----" << '\n';
        std::cout << '\n'
                  << '\n'
                  << '\n'
                  << '\n'
                  << '\n';
        break;
    case 1:
        std::cout << '\n'
                  << '\t' << '\t' << "----" << '\n';
        std::cout << '\t' << '\t' << "   "
                  << "|"
                  << '\n'
                  << '\n'
                  << '\n'
                  << '\n'
                  << '\n';
        break;

    case 2:
        std::cout << '\n'
                  << '\t' << '\t' << "----" << '\n';
        std::cout << '\t' << '\t' << "   "
                  << "|"
                  << '\n'
                  << '\t' << '\t' << "   "
                  << "O"
                  << '\n'
                  << '\n'
                  << '\n'
                  << '\n';
        break;
    case 3:
        std::cout << '\n'
                  << '\t' << '\t' << "----" << '\n';
        std::cout << '\t' << '\t' << "   "
                  << "|"
                  << '\n'
                  << '\t' << '\t' << "   "
                  << "O"
                  << '\n'
                  << '\t' << '\t' << "  "
                  << "/"
                  << '\n'
                  << '\n'
                  << '\n';
        break;
    case 4:
        std::cout << '\n'
                  << '\t' << '\t' << "----" << '\n';
        std::cout << '\t' << '\t' << "   "
                  << "|"
                  << '\n'
                  << '\t' << '\t' << "   "
                  << "O"
                  << '\n'
                  << '\t' << '\t' << "  "
                  << "/|"
                  << '\n'
                  << '\n'
                  << '\n';
        break;
    case 5:
        std::cout << '\n'
                  << '\t' << '\t' << "----" << '\n';
        std::cout << '\t' << '\t' << "   "
                  << "|"
                  << '\n'
                  << '\t' << '\t' << "   "
                  << "O"
                  << '\n'
                  << '\t' << '\t' << "  "
                  << "/|\\"
                  << '\n'
                  << '\n'
                  << '\n';
        break;
    case 6:
        std::cout << '\n'
                  << '\t' << '\t' << "----" << '\n';
        std::cout << '\t' << '\t' << "   "
                  << "|"
                  << '\n'
                  << '\t' << '\t' << "   "
                  << "O"
                  << '\n'
                  << '\t' << '\t' << "  "
                  << "/|\\"
                  << '\n'
                  << '\t' << '\t' << "   "
                  << "|"
                  << '\n'
                  << '\n';
        break;

    case 7:
        std::cout << '\n'
                  << '\t' << '\t' << "----" << '\n';
        std::cout << '\t' << '\t' << "   "
                  << "|"
                  << '\n'
                  << '\t' << '\t' << "   "
                  << "O"
                  << '\n'
                  << '\t' << '\t' << "  "
                  << "/|\\"
                  << '\n'
                  << '\t' << '\t' << "   "
                  << "|"
                  << '\n'
                  << '\t' << '\t' << "  "
                  << "/"
                  << '\n';
        break;
    case 8:
        std::cout << '\n'
                  << '\t' << '\t' << "----" << '\n';
        std::cout << '\t' << '\t' << "   "
                  << "|"
                  << '\n'
                  << '\t' << '\t' << "   "
                  << "O"
                  << '\n'
                  << '\t' << '\t' << "  "
                  << "/|\\"
                  << '\n'
                  << '\t' << '\t' << "   "
                  << "|"
                  << '\n'
                  << '\t' << '\t' << "  "
                  << "/ \\"
                  << '\n';
        break;
    }
}