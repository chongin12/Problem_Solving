#include <iostream>
#include <algorithm>
#include <ctime>
#include <cstdlib>
using namespace std;

int main(){
  srand(time(NULL));
  int arr[10];
  for(int i=0; i<10; ++i){
    arr[i]=rand();
  }
  for(int i=0; i<10; ++i){
    cout << arr[i] << "xk"[i==9]; // 랜덤으로 값 넣어주기
  }
}