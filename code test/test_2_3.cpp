#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves)
{
    int count = 0;
    stack<int> bucket;

    for (int i = 0; i < moves.size(); i++)
    {
        int pos = moves[i] - 1; // for index
        int depth = 0;

        // crane move
        while (depth < board.size() && board[depth][pos] == 0)
        {
            depth++;
        }

        if (depth == board.size())
        {
            continue;
        }

        // bucket act
        if (!bucket.empty() && bucket.top() == board[depth][pos])
        {

            bucket.pop();
            count += 2;
        }
        else
        {
            bucket.push(board[depth][pos]);
        }

        // remove element from board
        board[depth][pos] = 0;
    }

    return count;
}