#ifndef UNDO_REDO_H
#define UNDO_REDO_H

#include<iostream>

#define MAXSIZE 0xFFFF
#define MAXT 5

//Chess��,������ʾÿ��������
class Chess
{
public:
	Chess() :cX(-1),cY(-1){}
	Chess(int x, int y) :cX(x), cY(y){}
	virtual ~Chess();

	int GetX();
	int GetY();


private:
	int cX;	//���ӵ�x����
	int cY;	//���ӵ�y����
};


//Redo/Undoջ
template<class type>
class ChessStack
{
public:
	//�޲������캯��
	ChessStack() :top(-1), maxsize(MAXSIZE){
		cstack = new type[maxsize];
		if (cstack == NULL){
			std::cout << "��̬�洢����ʧ��" << std::endl;
			exit(1);
		}
	}

	//��size�Ĺ��캯��
	ChessStack(int size) :top(-1), maxsize(size){
		cstack = new type[maxsize];
		if (cstack == NULL){
			std::cout << "��̬�洢����ʧ��" << std::endl;
			exit(1);
		}
	}
	
	//��size��ֵ�Ĺ��캯��
	ChessStack(type data[], int size) :top(-1), maxsize(size){
		cstack = new type[maxsize];
		if (cstack == NULL){
			std::cout << "��̬�洢����ʧ��" << std::endl;
			exit(1);
		}

		for (int i = 0; i < maxsize; i++){
			cstack[i] = data[i];
		}
		top += maxsize;
	}


	virtual ~ChessStack();

	void Push(const type& item);	//itemѹջ
	type Pop();						//��ջ
	type GetTop();					//�õ�ջ��Ԫ��

	bool Empty()const;
	bool Full()const;

	void Clear();

private:
	int top;		//ջ��
	type *cstack;	//������
	int maxsize;	//���Ԫ��

};


//�����ж��Ƿ��ִ��Redo/Undoָ��
class Spot
{
public:
	Spot() :undoTimes(0), redoTimes(0){}
	virtual ~Spot();


	Chess* Redo();	//����sRedoջ��ջ��sUndoջѹջ
	Chess* Undo();	//����sUndoջ��ջ��sRedoջѹջ
	
	//void Choose();	//�����û�ѡ�����
	//void Display();	//���ڴ�ӡ��ǰ����

	void RedoPush(Chess* item);
	Chess* RedoPop();

	void UndoPush(Chess* item);
	Chess* UndoPop();


	bool CnRedo();
	bool CnUndo();

	int GetUndoTimes();
	int GetRedoTimes();

	void SetUndoTimes(int temp);
	void SetRedoTimes(int temp);

	void IncUndoTimes();
	void IncRedoTimes();
	void DecUndoTimes();
	void DecRedoTimes();

	//Chess GetTemp();

private:

	ChessStack<Chess*> sRedo;
	ChessStack<Chess*> sUndo;

	//Chess* temp;

	int undoTimes;
	int redoTimes;

};



#endif