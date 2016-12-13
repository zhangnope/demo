#ifndef OBSERVER_H
#define OBSERVER_H

#include<list>
using std::list;
typedef int STATE;

class Observer;

//�������Subject
//���ں�����h�ļ��ж���,��������Ϊ��������,ͨ��h�ļ�����,��ֹ�������
class Subject
{
public:
	Subject() :m_SubjectState(-1){}	//���캯��
	virtual ~Subject();	//�û������������ʱ,��ֹ������ʱֻ�����������������������������

	void Notify();	//���ڹ㲥���ı����״̬
	void Attach(Observer *tObserver);	//��Ӷ���
	void Detach(Observer *tObserver);	//ɾ������

	//�麯��,Ĭ�Ͻӿ�,������ʵ��
	virtual void SetState(STATE nState);	//���õ�ǰ״̬
	virtual STATE GetState();	//�õ���ǰ״̬

protected:
	STATE m_SubjectState;	//���浱ǰSubject״̬
	list<Observer*> m_ListObserver;	//����Observerָ���list��
};


//�������Observer
class Observer
{
public:
	Observer() :m_ObserverState(-1){}	//���캯��
	virtual ~Observer();	//�û������������ʱ,��ֹ������ʱֻ�����������������������������
	
	//����֪ͨObserver״̬�����ı�
	virtual void Update(Subject *pSubject)=0;	

protected:
	STATE m_ObserverState;
};

//�̳���Subject��public
class ConcreateSubject : public Subject
{
public:
	ConcreateSubject() :Subject(){}
	virtual ~ConcreateSubject();

	virtual void SetState(STATE nState);	//���õ�ǰ״̬
	virtual STATE GetState();	//�õ���ǰ״̬
private:

};


//�̳���Observer��public
class ConcreateObserver : public Observer
{
public:
	ConcreateObserver() :Observer(){}
	virtual ~ConcreateObserver();

	virtual void Update(Subject *pSubject);
private:
};

#endif