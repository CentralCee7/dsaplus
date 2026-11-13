#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <utility> // For std::pair
using namespace std;

// Comparator for sort: should a come before b?
// a.first = name, a.second = submission count
bool byCount(pair<string, int> a, pair<string, int> b) {
  if (a.second != b.second)
    return a.second > b.second; // more submissions first
  return a.first < b.first;     // tie: alphabetical order
}

int main() {
  // 1) The judge's log: one name per submission
  vector<string> logbook = {"Rafi", "Nadia", "Rafi", "Tanvir", "Nadia", "Rafi"};

  // 2) Containers for Q1 and Q2
  set<string> students; // Q1: each name once, sorted A-Z
  map<string, int> cnt; // Q2: name -> count

  // 3) One pass over the log fills both
  for (string name : logbook) {
    students.insert(name); // already inside? set ignores it
    cnt[name]++;           // new key starts at 0, then +1
  }
  cout << "Unique students: " << students.size() << "\n";

  // 4) Q3: copy the map into a vector so we can re-order it
  vector<pair<string, int>> board(cnt.begin(), cnt.end());

  // 5) Sort using our own rule (byCount)
  sort(board.begin(), board.end(), byCount);

  // 6) Print the leaderboard
  for (auto p : board)
    cout << p.first << " : " << p.second << "\n";
  return 0;
}
