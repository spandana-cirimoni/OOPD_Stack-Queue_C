#include "Array_Base.h"
#include "Stack.h"
#include "Queue.h"
#include <iostream>
using namespace std;

int main (int argc, char * argv [])
{
  // TODO Add code here to test your Array class.
  Array_Base<char> a(10);
  a.fill('A');
  cout<<a[2];
  Stack<char> s;
  s.push('B');
  s.push('V');
  cout<<s.size()<<endl;
  cout<<s.top()<<"Hi"<<endl;
  s.pop();
  cout<<s.top()<<endl;
  Stack<char> p;
  p=s;
  p.push('L');
  p.push('N');
  cout<<p.size()<<endl;
  cout<<p.top()<<"Hi"<<endl;
  p.pop();
  cout<<p.top()<<endl;
  cout<<p.is_empty()<<endl;
  p.clear();
  cout<<p.is_empty()<<endl;
  cout<<"...................................................................."<<endl;
  Queue<char> q;
  q.enqueue('A');
  cout<<q.size()<<endl;
  q.enqueue('B');
  cout<<q.size()<<endl;
  cout<<q.dequeue();
  cout<<q.size()<<endl;
  q.clear();
  cout<<q.size();
  return 0;
}