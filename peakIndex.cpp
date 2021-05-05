#include <iostream>
#include <vector>
using namespace std;

int maxHill(vector<int> &a, int start, int end)
{
    if(end >= start)
    {
        int n = start +(end - start) / 2;
        if(n <= a.size() || n >= 0){
            if(a[n] > a[n+1] and a[n] > a[n-1]) return n;
            else if(a[n] < a[n+1]) return maxHill(a, n + 1, end);
            else if(a[n] < a[n-1]) return maxHill(a, start, n-1);
        }
        else if(n == a.size())
        {
            if(a[n] > a[n-1]) return n;
        }
        else if(n == 0)
        {
            if(a[n] > a[n+1]) return n;
        }
        
    }
    // return -1;

}
int main()
{
  vector<int> array = {};
  int k, search, i;
//   for(i=0; i<5; i++)
//   {
//    array.push_back(i);
//  }
//  for(i=3; i>=0; i--)
//  {
//      array.push_back(i);
//  }

  cout << "ARRAY: ";
  for(int i: array){
      cout << i << ", ";
  }
  // while(true){
      
    // cout << "Press -1 to exit.\n";
    // cout << "To search: ";
    // cin >> search;
    
    // if(search == -1) break;
    cout << "POSIÇÃO NO ARRAY É = " << maxHill(array, 0, array.size()-1) << "\n";
  //}
  return 0;
}
