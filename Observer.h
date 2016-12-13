#ifndef OBSERVER_H
#define OBSERVER_H

#include<list>
using std::list;
typedef int STATE;

class Observer;

//抽象基类Subject
//类内函数在h文件中定义,将其设置为内联函数,通过h文件保护,防止恶意更改
class Subject
{
public:
	Subject() :m_SubjectState(-1){}	//构造函数
	virtual ~Subject();	//用基类操作派生类时,防止在析构时只析构基类而不析构派生类的情况发生

	void Notify();	//用于广播并改变对象状态
	void Attach(Observer *tObserver);	//添加对象
	void Detach(Observer *tObserver);	//删除对象

	//虚函数,默认接口,派生类实现
	virtual void SetState(STATE nState);	//设置当前状态
	virtual STATE GetState();	//得到当前状态

protected:
	STATE m_SubjectState;	//储存当前Subject状态
	list<Observer*> m_ListObserver;	//保存Observer指针的list表
};


//抽象基类Observer
class Observer
{
public:
	Observer() :m_ObserverState(-1){}	//构造函数
	virtual ~Observer();	//用基类操作派生类时,防止在析构时只析构基类而不析构派生类的情况发生
	
	//用于通知Observer状态发生改变
	virtual void Update(Subject *pSubject)=0;	

protected:
	STATE m_ObserverState;
};

//继承自Subject的public
class ConcreateSubject : public Subject
{
public:
	ConcreateSubject() :Subject(){}
	virtual ~ConcreateSubject();

	virtual void SetState(STATE nState);	//设置当前状态
	virtual STATE GetState();	//得到当前状态
private:

};


//继承自Observer的public
class ConcreateObserver : public Observer
{
public:
	ConcreateObserver() :Observer(){}
	virtual ~ConcreateObserver();

	virtual void Update(Subject *pSubject);
private:
};

#endif