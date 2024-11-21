/*
common conventioin
*/

#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal)
{
    string answer;
    int index1 = 0;
    int index2 = 0;
    for (int i = 0; i < goal.size(); i++)
    {
        string target = goal[i];
        string cmp1 = cards1[index1];
        string cmp2 = cards2[index2];
        cout << "cmp1 : " << cmp1 << endl;
        cout << "cmp2 : " << cmp2 << endl;

        if (target.compare(cmp1) == 0)
        {
            if (index1 != cards1.size() - 1)
                index1++;
        }
        else if (target.compare(cmp2) == 0)
        {
            if (index2 != cards2.size() - 1)
                index2++;
        }
        else
        {
            return "No";
        }
    }
    return "Yes";
}

int main()
{
    vector<string> cards1;
    cards1.push_back("I");
    cards1.push_back("drink");
    cards1.push_back("water");

    vector<string> cards2;
    cards2.push_back("want");
    cards2.push_back("to");

    vector<string> goal;
    goal.push_back("I");
    goal.push_back("want");
    goal.push_back("to");
    goal.push_back("drink");
    goal.push_back("water");
    cout << solution(cards1, cards2, goal);
}