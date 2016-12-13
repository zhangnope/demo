#include"Observer.h"
#include<iostream>

int main(){
	Observer *o1 = new ConcreateObserver;
	Observer *o2 = new ConcreateObserver;

	Subject *s = new ConcreateSubject;

	s->Attach(o1);
	s->Attach(o2);
	s->SetState(6);
	s->Notify();
	std::cout << "=============================" << std::endl;
	s->Detach(o1);
	s->SetState(66);
	s->Notify();

	delete s;
	//delete o1;
	//delete o2;

	getchar();

	return 0;
}