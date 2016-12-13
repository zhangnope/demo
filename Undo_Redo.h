#ifndef UNDO_REDO_H
#define UNDO_REDO_H

#include<iostream>

#define MAXSIZE 0xFFFF
#define MAXT 5

//Chess类,用于显示每步的棋子
class Chess
{
public:
	Chess() :cX(-1),cY(-1){}
	Chess(int x, int y) :cX(x), cY(y){}
	virtual ~Chess();

	int GetX();
	int GetY();


private:
	int cX;	//棋子的x坐标
	int cY;	//棋子的y坐标
};


//Redo/Undo栈
template<class type>
class ChessStack
{
public:
	//无参数构造函数
	ChessStack() :top(-1), maxsize(MAXSIZE){
		cstack = new type[maxsize];
		if (cstack == NULL){
			std::cout << "动态存储分配失败" << std::endl;
			exit(1);
		}
	}

	//带size的构造函数
	ChessStack(int size) :top(-1), maxsize(size){
		cstack = new type[maxsize];
		if (cstack == NULL){
			std::cout << "动态存储分配失败" << std::endl;
			exit(1);
		}
	}
	
	//带size和值的构造函数
	ChessStack(type data[], int size) :top(-1), maxsize(size){
		cstack = new type[maxsize];
		if (cstack == NULL){
			std::cout << "动态存储分配失败" << std::endl;
			exit(1);
		}

		for (int i = 0; i < maxsize; i++){
			cstack[i] = data[i];
		}
		top += maxsize;
	}


	virtual ~ChessStack();

	void Push(const type& item);	//item压栈
	type Pop();						//出栈
	type GetTop();					//得到栈顶元素

	bool Empty()const;
	bool Full()const;

	void Clear();

private:
	int top;		//栈顶
	type *cstack;	//数组名
	int maxsize;	//最大元素

};


//用于判定是否可执行Redo/Undo指令
class Spot
{
public:
	Spot() :undoTimes(0), redoTimes(0){}
	virtual ~Spot();


	Chess* Redo();	//用于sRedo栈弹栈和sUndo栈压栈
	Chess* Undo();	//用于sUndo栈弹栈和sRedo栈压栈
	
	//void Choose();	//用于用户选择操作
	//void Display();	//用于打印当前棋盘

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