#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;
vector<pair<string, int>> four_maximum(const map<string, int> &frq)
{
    vector<pair<string, int>> frequencyVector(frq.begin(), frq.end());

    sort(frequencyVector.begin(), frequencyVector.end(), [](const auto &a, const auto &b)
         { return a.second > b.second; });
    cout << "\t\t\t\tWord suggestions: ";
    for (int i = 0; i < min(4, static_cast<int>(frequencyVector.size())); ++i)
    {
        cout << i + 1 << ". " << frequencyVector[i].first <<" ";
    }

    return frequencyVector;
}
int main()
{
    vector<pair<string, int>> frequencyVector;
    int choice;
    string input = "";
    string word = "";
    vector<string> sentence;
    int i = 0;
    map<string, int> frequency;
    cout<<"\nEnter a sentence: ";
    while (true )
    {  
        getline(cin, input);
        sentence.push_back(input);
        istringstream iss(input);
        while (iss >> word)
        {
            frequency[word] += 1;
        }
        i++;
        if (i >= 4)
        {
            frequencyVector = four_maximum(frequency);
            cin >> choice;
             cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if(choice==5){
                input="";
                sentence.empty();
                continue;
            }
           
            sentence.push_back(frequencyVector[choice - 1].first);
            for (int j = 0; j < sentence.size(); j++)
            {
                cout << sentence[j] << " ";
            }
        }
        
    }
}