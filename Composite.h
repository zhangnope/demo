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

//定义Component类
class Component
{
public:
	virtual ~Component();	//基类析构函数设虚,防止派生类析构时不析构基类

	virtual string getName();	//获取当前目录的名字
	virtual int getSize();	//获取当前目录的大小,leaf和composite不同的计算方法

	virtual void add(Component *pChild);	//添加文件或目录
	virtual void remove(Component *pChild);	//删除文件或目录
	
	virtual void printList(string prefix);	//打印当前目录下所有文件及目录

	string toString();	//连接目录名字和大小
protected:
private:
};


//定义Leaf,"个别物"
class Leaf :public Component
{
public:
	Leaf(string name, int size) :lName(name), lSize(size) {}	//构造函数
	~Leaf();

	string getName();
	int getSize();

	void printList(string prefix);

protected:
	string lName;
	int lSize;
private:
};

//定义Composite,"复合物"
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