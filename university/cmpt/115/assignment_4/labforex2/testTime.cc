using namespace std;
#include <iostream>
#include <cstdlib>
#include "myTime.h"

int main(){
  myTime *t;
  t = createTime();

  addHour(t);

  addMinute(t);

  printTime(t);

  destroyTime(t);

  //cout << "We are done here...";
  return EXIT_SUCCESS;
}
