#include"Observer.h"
#include<iostream>
#include<algorithm>
using std::cout;
using std::endl;
using std::iterator;

//Observer成员函数的实现
Observer::~Observer(){
	//保证虚构函数的定义,防止出现无法解析的外部链接
}


//Subject成员函数的实现
Subject::~Subject(){
	list<Observer*>::iterator iter1, iter2, temp;

	iter1 = m_ListObserver.begin();
	iter2 = m_ListObserver.end();

	for (; iter1 != iter2;){
		temp = iter1;
		iter1++;
		Detach(*temp);
	}

	m_ListObserver.clear();
}

void Subject::Attach(Observer *tObserver){
	cout << "Attach an Observer" << endl;
	m_ListObserver.push_back(tObserver);
}

void Subject::Detach(Observer *tObserver){
	list<Observer*>::iterator iter;
	iter = find(m_ListObserver.begin(), m_ListObserver.end(), tObserver);

	//如果不唯一
	if (m_ListObserver.end() != iter){
		m_ListObserver.erase(iter);
	}

	cout << "Detach an Observer" << endl;
}

void Subject::Notify(){
	cout << "Notify Observers' State as fellows" << endl;

	list<Observer*>::iterator iter1, iter2;

	iter1 = m_ListObserver.begin();
	iter2 = m_ListObserver.end();

	for (; iter1 != iter2; iter1++){
		(*iter1)->Update(this);
	}
}

void Subject::SetState(STATE nState){
	cout << "SetState by Subject" << endl;
	m_SubjectState = nState;
}

STATE Subject::GetState(){
	cout << "GetState by Subject" << endl;
	return m_SubjectState;
}


//ConcreateSubject中成员函数实现
ConcreateSubject::~ConcreateSubject(){
	
}

void ConcreateSubject::SetState(STATE nState){
	cout << "SetState by ConcreateSubject" << endl;
	m_SubjectState = nState;
}

STATE ConcreateSubject::GetState(){
	cout << "GetState by ConcreateSubject" << endl;
	return m_SubjectState;
}


//ConcreateObserver中成员函数实现
ConcreateObserver::~ConcreateObserver(){

}
void ConcreateObserver::Update(Subject *psubject){
	if (psubject == NULL){
		return;
	}

	m_ObserverState = psubject->GetState();
	cout << "The ObserverState is " << m_ObserverState << endl;
}





