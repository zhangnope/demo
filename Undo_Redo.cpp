#include"Undo_Redo.h"


//Chess�еĺ���ʵ��
int Chess::GetX(){
	return cX;
}

int Chess::GetY(){
	return cY;
}

Chess::~Chess(){

}



//Spot�еĺ���ʵ��
Spot::~Spot(){

}

Chess* Spot::Redo(){
	if (!CnRedo()){
		std::cout << "�޷�ִ��redo����" << std::endl;
		exit(1);
	}

	Chess *temp = sRedo.Pop();	//Redoջ��ջ
	this->DecRedoTimes();

	sUndo.Push(temp);	//Undoջѹջ
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
		std::cout << "�޷�ִ��undo����" << std::endl;
		exit(1);
	}

	Chess *temp = sUndo.Pop();	//Redoջ��ջ
	this->DecUndoTimes();

	sRedo.Push(temp);	//Undoջѹջ
	this->IncRedoTimes();
	if (this->GetRedoTimes() > MAXT){
		this->SetRedoTimes(MAXT);
	}
	//else{
	//redoTimes++;
	//}
	return temp;
}

//��ÿ�ִ��redo����
int Spot::GetRedoTimes(){
	return redoTimes;
}

//��ÿ�ִ��undo����
int Spot::GetUndoTimes(){
	return undoTimes;
}

//redo������һ
void Spot::IncRedoTimes(){
	redoTimes++;
}

//undo������һ
void Spot::IncUndoTimes(){
	undoTimes++;
}

//redo������һ
void Spot::DecRedoTimes(){
	redoTimes--;
}

//undo������һ
void Spot::DecUndoTimes(){
	undoTimes--;
}

//�ж��Ƿ����ִ��redo����
bool Spot::CnRedo(){
	return this->GetRedoTimes() > 0;
}

//�ж��Ƿ����ִ��undo����
bool Spot::CnUndo(){
	return this->GetUndoTimes() > 0;
}

//undoջѹջ
void Spot::UndoPush(Chess* item){
	sUndo.Push(item);
	IncUndoTimes();
}

//undoջ��ջ
Chess* Spot::UndoPop(){
	Chess *temp = sUndo.Pop();
	DecUndoTimes();
	return temp;
}

//redoջѹջ
void Spot::RedoPush(Chess* item){
	sRedo.Push(item);
	IncRedoTimes();
}

//redoջ��ջ
Chess* Spot::RedoPop(){
	Chess *temp = sRedo.Pop();
	DecRedoTimes();
	return temp;
}

//��õ�ǰ��ִ��redo����
void Spot::SetRedoTimes(int temp){
	redoTimes = temp;
}

//��õ�ǰ��ִ��undo����
void Spot::SetUndoTimes(int temp){
	undoTimes = temp;
}


//ChessStack�еĺ���ʵ��
template<class type>
void ChessStack<type>::Push(const type& item){
	//��ջ��,�����;����itemѹջ
	if (this->Full()){
		std::cout << "ջ��,�޷�ѹջ" << std::endl;
		exit(1);
	}
	//����λ,�ٲ���
	top++;

	cstack[top] = item;
}

template<class type>
type ChessStack<type>::Pop(){
	if (this->Empty()){
		std::cout << "��ջ" << std::endl;
		exit(1);
	}
	type data = cstack[top];
	top--;
	return data;
}

template<class type>
type ChessStack<type>::GetTop(){
	if (this->Empty()){
		std::cout << "��ջ" << std::endl;
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
