#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int num, sum = 0;
    vector<int> nums;
    cout << "please enter integers:\n";
    while (cin >> num)
        nums.push_back(num);
    for (int i = 0; i < nums.size(); i++)
        sum += nums[i];
    double avg = 1.0 * sum / nums.size();
    cout << "sum: "
         << sum
         << "\n"
         << "avg: "
         << avg
         << endl;

    return 0;
}
