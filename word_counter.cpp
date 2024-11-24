#include <bits/stdc++.h>
using namespace std;
int main()
{
    unordered_map<string,int> m1;
    string inp="Lorem Ipsum is a placeholder text commonly used in graphic design, publishing, and web development to fill empty spaces in a layout that do not yet have content. It is typically a corrupted version of De finibus bonorum et malorum, a 1st-century BC text by the Roman statesman and philosopher Cicero, with words altered, added, and removed to make it nonsensical and improper Latin. the the the";
    
    stringstream ss(inp); //Used to convert the above string input to multiple strings
    string word; 
    while(ss>>word)
    m1[word]++;  //storing the string inside the hash map
    unordered_map<string,int>::iterator itr;
    //Iterating over the hash map and printing the words with their number of occurances
    for(auto itr=m1.begin();itr!=m1.end();itr++)
    {
        cout<<itr->first<<" "<<itr->second<<"\n";
    }
   
    return 0;
}