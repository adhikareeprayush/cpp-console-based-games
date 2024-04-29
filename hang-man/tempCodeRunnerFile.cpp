
    int random = rand() % 10;
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