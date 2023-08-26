// BHOPAL METRO
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <list>
#include <string>
#include <array>
#include <stack>
#include <math.h>
#include <queue>
#include <vector>
#include <utility>

#define STATION 53
#define INFINITE INT16_MAX

using namespace std;

class CompareByValue
{
public:
  bool operator()(pair<int, int> &num1, pair<int, int> &num2)
  {
    if (num1.second >= num2.second)
      return true;
    else
      return false;
  }
};

class Metro
{
private:
  list<int> *start;
  int root[STATION];
  string stationName[53] = {"Gandhi Nagar", "Karond", "Berasia", "Budhwara", "Jahangirabad",
                            "Mr.Road", "Kotra Sultanabad", "Nehru Nagar", "Syamla Hills", "Van Vihar", "Jawahar Chowk", "Rangmahal",
                            "Vidhan Sabha", "MP Nagar", "6 no Stop", "Shivaji Nagar", "Char Imli", "Bittan Market", "Shahpura", "Gulmohar",
                            "Akriti Eco City", "Saliya", "Chandbad", "Ashoka Garden", "Govindpura", "Minal", "Piplani", "Ayodhya Bypass",
                            "Anand Nagar", "Awadhpuri", "Barkheda Pathani", "Saket Nagar", "AIIMS", "Barkatullah University", "Misrod",
                            "Ratanpur", "Bairagarh", "Lalghati", "Tazul Masjid", "Hamidia Hospital", "Kamla Park", "Polytechnic Square",
                            "Roushanpura", "New Market", "Mata Mandir", "MANIT Square", "Patrakar Colony", "Chuna Bhatti", "Sarvdharm",
                            "Bima Kunj", "Danish Kunj", "Nayapura", "Bairagarh Chichli"};

protected:
  int weight(int, int);

public:
  Metro();
  void showStation();
  void SetStation();
  string NameOfStation(int);
  void TellMeRoute(int, int);
  array<int, STATION> AllPossibleDestination(int);
  int ToDestination(int, int);
  void ToAll(int);
};

Metro::Metro()
{
  start = new list<int>[STATION];

  for (int i = 0; i < STATION; i++)
    root[i] = -1;
  // stationName = new string[STATION];
}

int Metro::weight(int u, int v)
{
  return u == v ? 0 : 1;
}

void Metro::TellMeRoute(int source, int destination)
{
  stack<int> s;
  array<int, STATION> flag = AllPossibleDestination(source);
  int x = destination;
  while (root[x] != -1)
  {
    s.push(x);
    x = root[x];
  }
  while (!s.empty())
  {
    cout << stationName[s.top()] << "(" << s.top() << ") ";
    if (s.size() > 1)
      cout << "-->";
    s.pop();
  }
  cout << endl;
}
string Metro::NameOfStation(int index)
{
  try
  {
    if (index >= STATION || index < 0)
      throw exception();
  }
  catch (const std::exception &e)
  {
    std::cerr << e.what() << '\n';
  }
  return stationName[index];
}
void Metro::SetStation()
{
  start[0].push_front(1);
  for (int i = 1; i <= 4; i++)
  {
    start[i].push_front(i - 1);
    start[i].push_front(i + 1);
  }

  start[5].push_front(4);
  start[5].push_front(42);

  start[6].push_front(42);
  start[6].push_front(7);

  start[7].push_front(6);
  start[7].push_front(8);

  start[8].push_front(7);

  start[9].push_front(10);

  start[10].push_front(9);
  start[10].push_front(11);

  start[11].push_front(10);
  start[11].push_front(43);

  start[12].push_front(43);
  start[12].push_front(13);

  start[13].push_front(12);
  start[13].push_front(23);
  start[13].push_front(24);
  start[13].push_front(14);

  for (int i = 14; i <= 20; i++)
  {
    start[i].push_front(i - 1);
    start[i].push_front(i + 1);
  }

  start[21].push_front(20);
  start[21].push_front(52);

  start[22].push_front(23);

  start[23].push_front(22);
  start[23].push_front(13);

  start[24].push_front(13);
  start[24].push_front(25);

  for (int i = 25; i <= 34; i++)
  {
    start[i].push_front(i - 1);
    start[i].push_front(i + 1);
  }

  start[35].push_front(34);

  start[36].push_front(37);

  for (int i = 37; i <= 41; i++)
  {
    start[i].push_front(i - 1);
    start[i].push_front(i + 1);
  }

  start[42].push_front(5);
  start[42].push_front(6);
  start[42].push_front(41);
  start[42].push_front(43);

  start[43].push_front(11);
  start[43].push_front(12);
  start[43].push_front(42);
  start[43].push_front(44);

  for (int i = 44; i <= 51; i++)
  {
    start[i].push_front(i - 1);
    start[i].push_front(i + 1);
  }

  start[52].push_front(51);
  start[52].push_front(21);
}
void Metro::showStation()
{
  for (int i = 0; i < 10; i++)
    cout << i << "  |  " << stationName[i] << endl;
  for (int i = 10; i < STATION; i++)
    cout << i << " |  " << stationName[i] << endl;

  cout << "-------------------------" << endl
       << endl;
}
array<int, STATION> Metro::AllPossibleDestination(int source)
{
  // Dijkstra Algo implemented
  bool vis[STATION] = {0};
  bool inHeap[STATION] = {0};

  array<int, STATION> arr;
  for (int i = 0; i < STATION; i++)
    arr[i] = INFINITE;

  arr[source] = 0;
  vis[source] = true;

  priority_queue<pair<int, int>, vector<pair<int, int>>, CompareByValue> temp;

  // pair(index,arr[index])
  pair<int, int> p(source, 0);
  temp.push(p);
  inHeap[source] = true;

  int u = source;
  while (!temp.empty())
  {
    pair<int, int> t = temp.top();
    temp.pop();
    int index = t.first;
    u = index;
    vis[index] = true;
    list<int>::iterator it;
    for (it = start[u].begin(); it != start[u].end(); it++)
    {
      int v = *it;
      if (arr[u] + weight(u, v) < arr[v])
      {
        arr[v] = arr[u] + weight(u, v);
        root[v] = u;
      }

      if (!vis[v] && !inHeap[v])
      {
        pair<int, int> pt(v, arr[v]);
        temp.push(pt);
        inHeap[v] = true;
      }
    }
  }
  return arr;
}
int Metro::ToDestination(int source, int destination)
{
  try
  {
    if (destination >= STATION || source < 0)
      throw exception();
    else
    {
      array<int, STATION> newArr = AllPossibleDestination(source);
      return newArr[destination];
    }
  }
  catch (const exception &e)
  {
    std::cerr << e.what() << '\n';
  }
}

void Metro::ToAll(int source)
{
  array<int, STATION> newArr = AllPossibleDestination(source);
  cout << "Minimum Number Of Station Between Source Station :" << source;

  for (int i = 0; i < STATION; i++)
    cout << endl
         << "To Destination Station :" << i << " is " << newArr[i];
}
