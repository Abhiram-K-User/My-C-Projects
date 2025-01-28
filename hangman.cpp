#include<bits/stdc++.h>
using namespace std;

class game
{
    public: string curr_word,ini_word;
            int it;
            const int life=8;
    void game_start()
    {
        srand(time(0));
        string words[100] = {"apple", "banana", "cherry", "orange", "grape", "lemon", "mango", "peach", "pear", "plum",
        "apricot", "blueberry", "blackberry", "strawberry", "raspberry", "watermelon", "pineapple", "kiwi", "lime", "coconut",
        "avocado", "papaya", "dragonfruit", "fig", "pomegranate", "guava", "lychee", "nectarine", "passionfruit", "tangerine",
        "cranberry", "durian", "elderberry", "grapefruit", "jackfruit", "kumquat", "longan", "mandarin", "persimmon", "quince",
        "almond", "cashew", "hazelnut", "pecan", "pistachio", "walnut", "chestnut", "macadamia", "acorn", "hickory",
        "sunflower", "pumpkin", "squash", "zucchini", "cucumber", "carrot", "tomato", "potato", "onion", "garlic",
        "broccoli", "cauliflower", "spinach", "lettuce", "celery", "kale", "asparagus", "artichoke", "rhubarb", "beet",
        "radish", "turnip", "parsnip", "yam", "sweetpotato", "eggplant", "mushroom", "pepper", "okra", "ginger",
        "turmeric", "parsley", "cilantro", "basil", "thyme", "oregano", "rosemary", "sage", "chive", "mint",
        "dill", "lavender", "tarragon", "bayleaf", "lemongrass", "vanilla", "saffron", "cinnamon", "nutmeg", "clove"};
        it=rand()%100;
        cout<<"Welcome to Hangman!\nGuess the word given below.Incorrect guesses will result in the loss of a life.\nOnly vowels will be displayed in the beginning.\n"<<"\n";
        ini_word=words[it];
        curr_word=ini_word;
        for(int i=0;i<curr_word.size();i++)
        {
            switch(curr_word[i])
            {
                case 'a':
                case 'e':
                case 'i':
                case 'o':
                case 'u': 
                break;
                default:curr_word[i]='_';
            }
        }
    }
    void inp_checker(char inp)
    {
        bool res=false;
        for(int i=0;i<curr_word.size();i++)
        {
            if(ini_word[i]==inp)
            {
                curr_word[i]=inp;
                res=true;
            }
        }
        if(!res)
        {
        cout<<"Incorrect!"<<"\n";
        life-=1;
        }
    }
    void word_display()
    {
        game_start();
        char guess;
        while(curr_word!=ini_word&&life>0)
        {
        cout<<"The word currently is: "<<curr_word<<"\n";
        cout<<"The number of lives remaining "<<life<<"\n";
        cout<<"Enter your guess: ";
        cin>>guess;
        cout<<"\n";
        inp_checker(tolower(guess));
        }
        if(life!=0)
        {
            cout<<"You won the game!"<<"\n";
        }
        else
        {
            cout<<"The word was"<<ini_word<<"\n";
            cout<<"Skill Issue"<<"\n";
        }
    }
};
int main()
{
    game obj;
    obj.word_display();
    return 0;
}