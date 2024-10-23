#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

typedef struct lecture
{
    bool operator()(lecture lhs, lecture rhs)
    {
        return lhs.deadline < rhs.deadline;
    }
    int profit, deadline;
} lecture;

int main()
{
    int n_lecture_req;
    cin >> n_lecture_req;

    vector<lecture> lectures;

    for (int i = 0; i < n_lecture_req; i++)
    {
        int profit, deadline;
        cin >> profit >> deadline;

        lecture lec = {profit, deadline};
        lectures.push_back(lec);
    }

    sort(lectures.begin(), lectures.end(), lecture());

    priority_queue<int, vector<int>, greater<int>> all_profit;
    for (int i = 0; i < n_lecture_req; i++)
    {
        all_profit.push(lectures[i].profit);
        if (lectures[i].deadline < all_profit.size())
        {
            all_profit.pop();
        }
    }

    int total_profit = 0;
    while (!all_profit.empty())
    {
        total_profit += all_profit.top();
        all_profit.pop();
    }

    cout << total_profit << endl;
}
