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

}
int main()
{
  vector<int> array = {0,1,2,3,4,1,0};
  int k, search, i;

  cout << "ARRAY: ";
  for(int i: array){
      cout << i << ", ";
  }
  
  cout << "POSIÇÃO NO ARRAY É = " << maxHill(array, 0, array.size()-1) << "\n";
  return 0;
}
