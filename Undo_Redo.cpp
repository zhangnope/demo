#include"Undo_Redo.h"


//Chess中的函数实现
int Chess::GetX(){
	return cX;
}

int Chess::GetY(){
	return cY;
}

Chess::~Chess(){

}



//Spot中的函数实现
Spot::~Spot(){

}

Chess* Spot::Redo(){
	if (!CnRedo()){
		std::cout << "无法执行redo操作" << std::endl;
		exit(1);
	}

	Chess *temp = sRedo.Pop();	//Redo栈出栈
	this->DecRedoTimes();

	sUndo.Push(temp);	//Undo栈压栈
	this->IncUndoTimes();
	if (this->GetUndoTimes() > MAXT){
		this->SetUndoTimes(MAXT);
	}
	//else{ 
	//undoTimes++;
	//}
	return temp;
}

Chess* Spot::Undo(){
	if (!CnUndo()){
		std::cout << "无法执行undo操作" << std::endl;
		exit(1);
	}

	Chess *temp = sUndo.Pop();	//Redo栈出栈
	this->DecUndoTimes();

	sRedo.Push(temp);	//Undo栈压栈
	this->IncRedoTimes();
	if (this->GetRedoTimes() > MAXT){
		this->SetRedoTimes(MAXT);
	}
	//else{
	//redoTimes++;
	//}
	return temp;
}

//获得可执行redo次数
int Spot::GetRedoTimes(){
	return redoTimes;
}

//获得可执行undo次数
int Spot::GetUndoTimes(){
	return undoTimes;
}

//redo次数加一
void Spot::IncRedoTimes(){
	redoTimes++;
}

//undo次数加一
void Spot::IncUndoTimes(){
	undoTimes++;
}

//redo次数减一
void Spot::DecRedoTimes(){
	redoTimes--;
}

//undo次数减一
void Spot::DecUndoTimes(){
	undoTimes--;
}

//判断是否可以执行redo操作
bool Spot::CnRedo(){
	return this->GetRedoTimes() > 0;
}

//判断是否可以执行undo操作
bool Spot::CnUndo(){
	return this->GetUndoTimes() > 0;
}

//undo栈压栈
void Spot::UndoPush(Chess* item){
	sUndo.Push(item);
	IncUndoTimes();
}

//undo栈出栈
Chess* Spot::UndoPop(){
	Chess *temp = sUndo.Pop();
	DecUndoTimes();
	return temp;
}

//redo栈压栈
void Spot::RedoPush(Chess* item){
	sRedo.Push(item);
	IncRedoTimes();
}

//redo栈出栈
Chess* Spot::RedoPop(){
	Chess *temp = sRedo.Pop();
	DecRedoTimes();
	return temp;
}

//获得当前可执行redo次数
void Spot::SetRedoTimes(int temp){
	redoTimes = temp;
}

//获得当前可执行undo次数
void Spot::SetUndoTimes(int temp){
	undoTimes = temp;
}


//ChessStack中的函数实现
template<class type>
void ChessStack<type>::Push(const type& item){
	//若栈满,则出错;否则将item压栈
	if (this->Full()){
		std::cout << "栈满,无法压栈" << std::endl;
		exit(1);
	}
	//先移位,再操作
	top++;

	cstack[top] = item;
}

template<class type>
type ChessStack<type>::Pop(){
	if (this->Empty()){
		std::cout << "空栈" << std::endl;
		exit(1);
	}
	type data = cstack[top];
	top--;
	return data;
}

template<class type>
type ChessStack<type>::GetTop(){
	if (this->Empty()){
		std::cout << "空栈" << std::endl;
		exit(1);
	}

	return cstack[top];
}

template<class type>
bool ChessStack<type>::Empty()const{
	return top == -1;
}

template<class type>
bool ChessStack<type>::Full()const{
	return top == maxsize-1;
}

template<class type>
void ChessStack<type>::Clear(){
	return top = -1;
}

template<class type>
ChessStack<type>::~ChessStack(){
	delete[]cstack;
};
