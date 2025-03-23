#include <iostream>
#include <string>

using namespace std;

int main() {
  double total_points = 0;
  unsigned total_credit = 0;

  for (int i = 0; i < 20; i++) {
    string name, grade;
    float credit;
    cin >> name >> credit >> grade;

    if (grade == "P") {
      continue;
    }

    if (grade == "A+") {
      total_points += credit * 4.5;
    } else if (grade == "A0") {
      total_points += credit * 4.0;
    } else if (grade == "B+") {
      total_points += credit * 3.5;
    } else if (grade == "B0") {
      total_points += credit * 3.0;
    } else if (grade == "C+") {
      total_points += credit * 2.5;
    } else if (grade == "C0") {
      total_points += credit * 2.0;
    } else if (grade == "D+") {
      total_points += credit * 1.5;
    } else if (grade == "D0") {
      total_points += credit * 1.0;
    }

    total_credit += credit;
  }

  cout << total_points / total_credit << '\n';
}
