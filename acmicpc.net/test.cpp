#include <iostream>
using namespace std;

class Stack {
    int size;
    int* mem; // 동적 메모리 할당. 스택 공간
    int tos; // top of stack. -1이면 스택이 비었음
public:
    Stack(int size = 10) {
        this->size = size;
        mem = new int [size]; // int [10] 동적 할당.
        tos = -1; // 스택이 비어있음
    }
    ~Stack() { delete [] mem; } // 배열 반환
    Stack& operator << (int n);
    Stack& operator >> (int& n);
    bool operator ! ();
};

Stack& Stack::operator << (int n) { // 푸시
    if(tos == size-1) {
        return this;
    }
    tos++; // 스택 탑을 증가
    mem[tos] = n;
    return this;
} 

Stack& Stack::operator >> (int& n) { // 팝
    if(tos == -1) {
        return this;
    } 
    n = mem[tos]; // top에 있는 스택 값 리턴
    tos--; // 스택 top 감소
    return this;
} 

bool Stack::operator ! () { // 비어 있으면 true 리턴
    if(tos == -1)
        return true;
    else
        return false;
}

int main() {
    Stack stack;
    stack << 3 << 5 << 10; // 3, 5, 10을 순서대로 푸시
    while(true) {
        if(!stack) break; // 스택 empty
        int x;
        stack >> x; // 스택의 탑에 있는 정수 팝
        cout << x << ' ';
    }
    cout << endl;
}