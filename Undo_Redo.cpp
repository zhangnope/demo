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


//Spot中的函数实现
Spot::~Spot(){

}

Chess* Spot::Redo(){
	if (!CnRedo()){
		std::cout << "无法执行redo操作" << std::endl;
		exit(1);
	}

	Chess *temp=sRedo.Pop();	//Redo栈出栈
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

int Spot::GetRedoTimes(){
	return redoTimes;
}

int Spot::GetUndoTimes(){
	return undoTimes;
}

void Spot::IncRedoTimes(){
	redoTimes++;
}

void Spot::IncUndoTimes(){
	undoTimes++;
}

void Spot::DecRedoTimes(){
	redoTimes--;
}

void Spot::DecUndoTimes(){
	undoTimes--;
}

bool Spot::CnRedo(){
	return this->GetRedoTimes() > 0;
}

bool Spot::CnUndo(){
	return this->GetUndoTimes() > 0;
}

void Spot::UndoPush(Chess* item){
	sUndo.Push(item);
	IncUndoTimes();
}

Chess* Spot::UndoPop(){	
	Chess *temp=sUndo.Pop();
	DecUndoTimes();
	return temp;
}

void Spot::RedoPush(Chess* item){
	sRedo.Push(item);
	IncRedoTimes();
}

Chess* Spot::RedoPop(){
	Chess *temp = sRedo.Pop();
	DecRedoTimes();
	return temp;
}

void Spot::SetRedoTimes(int temp){
	redoTimes = temp;
}

void Spot::SetUndoTimes(int temp){
	undoTimes = temp;
}