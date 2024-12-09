#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> answers)
{
    int a = 0;
    int b = 0;
    int c = 0;

    // generate answer list
    for (int i = 0; i < answers.size(); i++)
    {
        if (answers[i] == (i % 5 + 1))
        {
            a++;
        }

        int temp_b;
        if (i % 2 == 0)
        {
            temp_b = 2;
        }
        else
        {
            int check = i % 8;
            if (check == 1)
            {
                temp_b = 1;
            }
            else if (check == 3)
            {
                temp_b = 3;
            }
            else if (check == 5)
            {
                temp_b = 4;
            }
            else if (check == 7)
            {
                temp_b = 5;
            }
        }
        if (temp_b == answers[i])
        {
            b++;
        }

        int check = i % 10;
        int temp_c;
        if (check == 0 || check == 1)
        {
            temp_c = 3;
        }
        else if (check == 2 || check == 3)
        {
            temp_c = 1;
        }
        else if (check == 4 || check == 5)
        {
            temp_c = 2;
        }
        else if (check == 6 || check == 7)
        {
            temp_c = 4;
        }
        else if (check == 8 || check == 9)
        {
            temp_c = 5;
        }
        if (temp_c == answers[i])
        {
            c++;
        }
    }

    vector<int> answer;
    if (a >= b && a >= c)
    {
        answer.push_back(1);
    }
    if (b >= a && b >= c)
    {
        answer.push_back(2);
    }
    if (c >= a && c >= b)
    {
        answer.push_back(3);
    }
    cout << answer[0] << endl;
    cout << answer[1] << endl;
    cout << answer[2] << endl;
    return answer;
}

int main()
{
    vector<int> answers;
    answers.push_back(1);
    answers.push_back(2);
    answers.push_back(3);
    answers.push_back(4);
    answers.push_back(5);
    // vector<int> answers = {1, 3, 2, 4, 2};
    solution(answers);
}

/*
    cout << "a : ";
    for (int i = 0; i < len; i++)
    {
        cout << a[i] << " ";
    }
    cout << "\nb : ";
    for (int i = 0; i < len; i++)
    {
        cout << b[i] << " ";
    }
    cout << "\nc : ";
    for (int i = 0; i < len; i++)
    {
        cout << c[i] << " ";
    }
    cout << endl;
*/