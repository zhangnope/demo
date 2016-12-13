#ifndef COMPOSITE_H
#define COMPOSITE_H

#include<string>
#include<sstream>
#include<list>
#include<iostream>
using std::string;
using std::stringstream;
using std::list;
using std::cout;
using std::endl;

//����Component��
class Component
{
public:
	virtual ~Component();	//����������������,��ֹ����������ʱ����������

	virtual string getName();	//��ȡ��ǰĿ¼������
	virtual int getSize();	//��ȡ��ǰĿ¼�Ĵ�С,leaf��composite��ͬ�ļ��㷽��

	virtual void add(Component *pChild);	//����ļ���Ŀ¼
	virtual void remove(Component *pChild);	//ɾ���ļ���Ŀ¼
	
	virtual void printList(string prefix);	//��ӡ��ǰĿ¼�������ļ���Ŀ¼

	string toString();	//����Ŀ¼���ֺʹ�С
protected:
private:
};


//����Leaf,"������"
class Leaf :public Component
{
public:
	Leaf(string name, int size) :lName(name), lSize(size) {}	//���캯��
	~Leaf();

	string getName();
	int getSize();

	void printList(string prefix);

protected:
	string lName;
	int lSize;
private:
};

//����Composite,"������"
class Composite :public Component
{
public:
	Composite(string name) :cName(name){}
	virtual ~Composite();

	virtual string getName();
	virtual int getSize();

	virtual void add(Component *pChild);
	virtual void remove(Component *pChild);
	virtual void printList(string prefix);

private:
	string cName;
	list<Component*> m_ListOfComponent;
};





#endif