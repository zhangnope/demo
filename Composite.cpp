#include"Composite.h"

#include<sstream>
#include<iostream>
using std::stringstream;
using std::cout;
using std::endl;

//int��ת��Ϊstring��,�������Ӵ�С(int)������(string)
string getString(const int n){
	stringstream newstr;
	newstr << n;
	return newstr.str();
}



//Component��Ա������ʵ��
//�����麯������
Component::~Component(){

}

string Component::getName(){
	return "";
}

int Component::getSize(){
	return 0;
}

void Component::add(Component *pChild){

}

void Component::remove(Component *pChild){

}

string Component::toString(){
	return getName() + "(" + getString(getSize()) + ")";
}

void Component::printList(string prefix){
	cout << prefix << "/" << toString() << endl;
}


//Leaf��Ա������ʵ��,"������"
Leaf::~Leaf(){

}

string Leaf::getName(){
	return lName;
}

int Leaf::getSize(){
	return lSize;
}

void Leaf::printList(string prefix){
	cout << prefix << "/" << toString() << endl;
}

//Composite��Ա������ʵ��,"�ۺ���"
Composite::~Composite(){

}

string Composite::getName(){
	return cName;
}

int Composite::getSize(){
	int size = 0;
	list<Component*>::iterator iter1, iter2;
	iter1 = m_ListOfComponent.begin();
	iter2 = m_ListOfComponent.end();
	while (iter1 != iter2)
	{
		Component *component = *iter1;
		size += component->getSize();
		iter1++;
	}
	return size;
}


void Composite::add(Component *pChild){
	m_ListOfComponent.push_back(pChild);
}

void Composite::remove(Component *pChild){
	list<Component*>::iterator iter;
	iter = find(m_ListOfComponent.begin(), m_ListOfComponent.end(), pChild);
	if (m_ListOfComponent.end() != iter){
		m_ListOfComponent.erase(iter);
	}
}

void Composite::printList(string prefix){
	cout << prefix << "/" << toString() << endl;
	list<Component*>::iterator iter1, iter2;
	iter1 = m_ListOfComponent.begin();
	iter2 = m_ListOfComponent.end();
	while (iter1 != iter2)
	{
		Component *component = *iter1;
		component->printList(prefix + "/" + cName);
		iter1++;
	}
}



