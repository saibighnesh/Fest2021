#include <iostream>
using namespace std;
int set_bit_count(int x) {
   unsigned int bit_count = 0;
   while (x != 0) {
      x &= (x - 1);
      bit_count++;
   }
   return bit_count;
}
bool isBleakNumber(int n) {
   for (int i = 1; i < n; i++)
   if (i + set_bit_count(i) == n)
      return false;
      return true;
}
int main() {
    int n;
    cin>>n;
   isBleakNumber(n) ? cout << "Yes\n" : cout << "No\n";
   
}
