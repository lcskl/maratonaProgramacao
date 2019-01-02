/*
  UVa11995 - I Can Guess the Data Structure!
  How to solve it? Just keep all possible data structures
*/

#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main (){
  int n;
  stack<int> stack; bool can_be_stack;
  queue<int> queue; bool can_be_queue;
  priority_queue<int> p_queue; bool can_be_p_queue;
  while(cin >> n && !cin.eof()){
    while(!queue.empty())queue.pop();
    while(!stack.empty())stack.pop();
    while(!p_queue.empty())p_queue.pop();
    can_be_queue = can_be_stack = can_be_p_queue = true;


    int op,num;
    for(int i=0;i<n;i++){
      cin >> op >> num;
      if(op == 1){
        if(can_be_queue)
          queue.push(num);
        if(can_be_stack)
          stack.push(num);
        if(can_be_p_queue)
          p_queue.push(num);
      }else{
        if(can_be_queue){
          if(!queue.empty() && queue.front() == num)
            queue.pop();
          else
            can_be_queue = false;
        }

        if(can_be_stack){
          if(!stack.empty() && stack.top() == num)
            stack.pop();
          else
            can_be_stack = false;
        }

        if(can_be_p_queue){
          if(!p_queue.empty() && p_queue.top() == num)
            p_queue.pop();
          else
            can_be_p_queue = false;
        }
      }
    }

    int solution = can_be_queue + can_be_stack + can_be_p_queue;
    if(solution == 0)
      cout << "impossible\n";
    else if(solution > 1)
      cout << "not sure\n";
    else{
      if(can_be_queue)
        cout << "queue\n";
      if(can_be_stack)
        cout << "stack\n";
      if(can_be_p_queue)
        cout << "priority queue\n";
    }
  }

  return 0;
}
