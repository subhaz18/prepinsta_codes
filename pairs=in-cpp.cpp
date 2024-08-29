#include<utility>
#include<iostream>
using namespace std;
int main(){
    std::pair<int, int> p1;
    std::pair<int, int> p2;
    p1=std:: make_pair(10,20);
    p2=std:: make_pair(10.5,'A');
    std::cout<<p1.first<<","<<p1.second<<endl;
    std::cout<<p2.first<<","<<p2.second;

    return 0;


}