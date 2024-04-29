// Hangman Game
#include<iostream>
class Player
{
    public:
    std::string name;
    int score;
    Player(std::string name)
    {
        this->name = name;
        this->score = 0;
    }
};

class Figure{
    public:
    int wrong_guesses;
    Figure()
    {
        this->wrong_guesses = 0;
    }
    void drawFigure()
    {
        switch(wrong_guesses)
        {
            case 0:
                std::cout << "  +---+" << std::endl;
                std::cout << "  |   |" << std::endl;
                std::cout << "      |" << std::endl;
                std::cout << "      |" << std::endl;
                std::cout << "      |" << std::endl;
                std::cout << "      |" << std::endl;
                std::cout << "=========" << std::endl;
                break;
            case 1:
                std::cout << "  +---+" << std::endl;
                std::cout << "  |   |" << std::endl;
                std::cout << "  O   |" << std::endl;
                std::cout << "      |" << std::endl;
                std::cout << "      |" << std::endl;
                std::cout << "      |" << std::endl;
                std::cout << "=========" << std::endl;
                break;
            case 2:
                std::cout << "  +---+" << std::endl;
                std::cout << "  |   |" << std::endl;
                std::cout << "  O   |" << std::endl;
                std::cout << "  |   |" << std::endl;
                std::cout << "      |" << std::endl;
                std::cout << "      |" << std::endl;
                std::cout << "=========" << std::endl;
                break;
            case 3:
                std::cout << "  +---+" << std::endl;
                std::cout << "  |   |" << std::endl;
                std::cout << "  O   |" << std::endl;
                std::cout << " /|   |" << std::endl;
                std::cout << "      |" << std::endl;
                std::cout << "      |" << std::endl;
                std::cout << "=========" << std::endl;
                break;
            case 4:
                std::cout << "  +---+" << std::endl;
                std::cout << "  |   |" << std::endl;
                std::cout << "  O   |" << std::endl;
                std::cout << " /|\\  |" << std::endl;
                std::cout << "      |" << std::endl;
                std::cout << "      |" << std::endl;
                std::cout << "=========" << std::endl;
                break;
            case 5:
                std::cout << "  +---+" << std::endl;
                std::cout << "  |   |" << std::endl;
                std::cout << "  O   |" << std::endl;
                std::cout << " /|\\  |" << std::endl;
                std::cout << " /    |" << std::endl;
                std::cout << "      |" << std::endl;
                std::cout << "=========" << std::endl;
                break;
            case 6:
                std::cout << "  +---+" << std::endl;
                std::cout << "  |   |" << std::endl;
                std::cout << "  O   |" << std::endl;
                std::cout << " /|\\  |" << std::endl;
                std::cout << " / \\  |" << std::endl;
                std::cout << "      |" << std::endl;
                std::cout << "=========" << std::endl;
                std::cout << std::endl;
                std::cout << std::endl;
                std::cout << std::endl;
                std::cout << "Game Over!" << std::endl;
                break;
}};
};

int main()
{
    std::string guess_words[] = { 
        "hello", "world", "hangman", "computer", "programming", 
        "language", "science", "mathematics", "engineering", "medicine",
        "business", "networking", "security", "database", "software",
        "hardware", "electronics", "mechanics", "civil", "architecture",
        "design", "art", "music", "literature", "history", "geography",
        "economics", "politics", "philosophy", "psychology", "sociology",
        "anthropology", "biology", "chemistry", "physics", "astronomy",
        "geology", "meteorology", "environment", "ecology", "agriculture",
        "forestry", "fishery", "mining", "manufacturing", "construction",
        "transportation", "communication", "telecommunication", "internet",
        "web", "mobile", "cloud", "big data", "analytics", "machine learning",
        "artificial intelligence", "robotics", "automation", "blockchain",
        "cryptocurrency", "bitcoin", "ethereum", "ripple", "litecoin",
        "monero", "dash", "nem", "neo", "stellar", "tron", "cardano",
        "iota", "tezos", "zcash", "vechain", "ontology", "qtum", "lisk",
        "icon", "nano", "decred", "siacoin", "bytecoin", "steem", "waves",
        "stratis", "komodo", "ark", "aeternity", "pivx", "reddcoin", "verge",
        "dogecoin", "digibyte", "syscoin", "factom", "basic attention token",
        };
    std::string player;
    std::cout << "Enter your name: ";
    std::getline(std::cin >> std::ws , player);
    Player player1(player);
    int random = rand() % 100;
    std::string guess_word = guess_words[random];
    std::string hidden_word = guess_word;
    for(int i = 0; i < hidden_word.length(); i++)
    {
        if(hidden_word[i] != ' ')
        {
            hidden_word[i] = '_';
        }
    }
    Figure figure;

    while(figure.wrong_guesses < 6)
    {
        std::cout << "Word: " << hidden_word << std::endl;
        std::cout << "Enter a letter: ";
        char letter;
        std::cin >> letter;
        bool found = false;
        for(int i = 0; i < guess_word.length(); i++)
        {
            if(guess_word[i] == letter)
            {
                hidden_word[i] = letter;
                found = true;
            }
        }
        if(!found)
        {
            figure.wrong_guesses++;
        }
        figure.drawFigure();
        if(hidden_word == guess_word)
        {
            std::cout << "Congratulations! You guessed the word!" << std::endl;
            break;
        }
    }


    return 0;
}