#include<iostream>
#include<vector>
using namespace std;
int main()
{
   vector<int> vec{10,20,30,40,50};
   cout<<"Vector elements are: "<<endl;
   for(auto &num:vec)
   {
    cout<<num<<endl;
   }
    return 0;
}
