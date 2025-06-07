#include<iostream>
#include<string>
#include<stdlib.h>
#include<time.h>
#include<unordered_map>
using namespace std;
void game();

int main()
{
    game();
}

string word_chooser()
{ 
    srand(time(0));
    const string words[250] = {
    "amber", "apple", "banjo", "basil", "beach", "beast", "bland", "blaze", "bloom", "bluff",
    "boast", "brave", "brick", "brink", "broom", "brush", "cable", "candy", "cargo", "carve",
    "catch", "cello", "chalk", "chant", "chair", "charm", "chase", "chess", "click", "climb",
    "cloud", "cigar", "cabin", "crown", "crane", "crank", "crave", "creek", "creep", "cried",
    "crisp", "crush", "dense", "daisy", "ditch", "dodge", "doubt", "drape", "drink", "drill",
    "drake", "elite", "eagle", "eject", "elope", "faith", "fable", "fizzy", "flair", "flame",
    "flock", "flute", "flush", "freak", "frost", "funny", "fuzzy", "giddy", "gleam", "glean",
    "gloom", "glide", "glint", "globe", "glove", "grace", "grape", "grasp", "grill", "grind",
    "grove", "groom", "gruff", "happy", "haste", "hatch", "hasty", "honey", "hoist", "jelly",
    "jolly", "knife", "knead", "kneel", "laugh", "laser", "latch", "laden", "lemon", "light",
    "linen", "liver", "lodge", "loyal", "lunar", "lunch", "meaty", "match", "macho", "minor",
    "mimic", "mirth", "moist", "mossy", "mourn", "mover", "noble", "novel", "orbit", "paint",
    "patch", "piano", "plant", "plank", "plaza", "plump", "prawn", "press", "pride", "prank",
    "proud", "punch", "query", "quest", "quake", "quiet", "realm", "rebel", "reign", "ridge",
    "rider", "rhyme", "roast", "rocky", "rover", "rumor", "sassy", "scarf", "scent", "shade",
    "shack", "shard", "sheep", "shine", "shiny", "siren", "skate", "sling", "slate", "slope",
    "smile", "snack", "sniff", "spark", "spend", "spice", "spike", "spank", "spoon", "spore",
    "splat", "spore", "spunk", "stack", "sting", "stomp", "stone", "storm", "sugar", "sweep",
    "sweet", "swoop", "swamp", "swirl", "sword", "table", "tally", "tempo", "tidal", "tiger",
    "token", "trace", "train", "tramp", "troop", "trope", "trick", "trout", "twine", "twist",
    "vague", "vapor", "vigor", "vital", "vivid", "vowel", "wacky", "whirl", "weepy", "witty",
    "wrist", "zebra", "zesty"
};
    int word_index=rand()%250;
    return words[word_index];
}
unordered_map<char,int> char_counter(string str1)
{
    unordered_map<char,int> m1;
    for(int i=0;i<str1.length();i++)
    {
        m1[str1[i]]+=1;
    }
    return m1;
}

void game()
{
    string main_word=word_chooser();
    string guess_word="";
    unordered_map<char,int> m1;
    int guesses=6,i,j;
    while(guesses>0&&guess_word!=main_word)
    {
        m1=char_counter(main_word);
        string colours[5]={"\033[0m","\033[0m","\033[0m","\033[0m","\033[0m"};
        do
        {
        cout<<"Enter the guess. "<<guesses<<" guesses remaining. Ensure the word is 5 characters long.\n";
        cin>>guess_word;
        if(guess_word.length()!=5)
        cout<<"The word is not of 5 characters\n";
        } while (guess_word.length()!=5);
        
        
        for(i=0;i<5;i++)
        {
            if(guess_word[i]==main_word[i])
            {
            colours[i]="\033[32m";
            m1[guess_word[i]]-=1;
            }
        }
        for(i=0;i<5;i++)
        {
            if(m1[guess_word[i]]>0)
            {
                colours[i]="\033[33m"; //Yellow
            }
            else if(colours[i]!="\033[32m")
            {
                colours[i]="\033[31m"; //Red
            }
            m1[guess_word[i]]-=1;
        }
        for(i=0;i<5;i++)
        {
            cout<<colours[i]<<guess_word[i];
        }
    
        cout<<"\033[0m"<<"\n";
        guesses-=1;
    }
    if(guesses>0)
    {
        cout<<"You won the game!\n";
    }
    else
    {
        cout<<"You lost! The word was "<<main_word<<"\n";
    }
    cout<<"\033[0m"<<"\n";
}