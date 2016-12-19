#include"Undo_Redo.h"
#include<stdlib.h>

using std::cin;
using std::cout;
using std::endl;


#define SizeSpot 5 

//���̳�ʼ��
void Init(char ChessSpot[][SizeSpot],int ChessSizeX){
	
	if (ChessSizeX <= 0 || SizeSpot <= 0){
		cout << "�Ƿ����̴�С" << endl;
		return;
	}
	
	for (int i = 0; i < ChessSizeX; i++){
		for (int j = 0; j < SizeSpot; j++){
			ChessSpot[i][j] = '*';
		}
	}
}

//��ʾ��ǰ����
void Display(char ChessSpot[][SizeSpot], int ChessSizeX){
	if (ChessSizeX <= 0 || SizeSpot <= 0){
		cout << "�Ƿ����̴�С" <<endl;
		return;
	}

	for (int i = 0; i < ChessSizeX; i++){
		for (int j = 0; j < SizeSpot; j++){
			std::cout << ChessSpot[i][j] << ' ';
		}
		cout << endl;
	}
}

//������ѡ��
bool Introduce(){
	cout << "#===========================================================#" << endl;
	cout << "����h�Բ鿴����,����g����������ֱ������" << endl;


	char type;		//�����ַ�
	cin >> type;

	if (type == 'h'){
		cout << "����Ϊ��СΪ5*5,������δ���Ӵ���*��ʾ,�����Ӵ���0��ʾ" << endl;
		cout << "��������ʾ��,�û����Խ���ѡ��:" << endl;
		cout << "1��ʾ����,2��ʾundo����,3��ʾredo����,4��ʾ�˳�" << endl;
		cout << "#===========================================================#" << endl;
		return true;
	}

	if (type == 'g'){
		cout << "#===========================================================#" << endl;
		return true;
	}

	//�Ƿ��ַ���ת
	cout << "������Ϸ��ַ�" << endl;
	cout << "��лʹ�ñ�ϵͳ" << endl;
	cout << "#===========================================================#" << endl;
	return false;
}

int main(){

	//��������
	char Ch[SizeSpot][SizeSpot];

	//����Ƿ��ַ����˳�����
	if (!Introduce()){
		getchar();
		return 0;
	}

	Init(Ch, SizeSpot);
	getchar();

	Display(Ch, SizeSpot);
	cout << "#===========================================================#" << endl;
	cout << "1��ʾ����,2��ʾundo����,3��ʾredo����,4��ʾ�˳�" << endl;
	Spot *stest = new Spot();
	
	//�ֱ���Ϊ���ӵĺ�������
	int x;
	int y;

	int temp;

	//Undo/Redo����
	while (1){
		cout << "#===========================================================#" << endl;
		cout << "��ִ��undo����:" << stest->GetUndoTimes() << '	' << "��ִ��redo����" << stest->GetRedoTimes() << endl;
		cout << "���������ѡ��" << endl;
		cin >> temp;
		system("cls");
		if (temp == 1){
			//����,��������Undo��
			cout << "�벻Ҫ��������������" << endl;
			cout << "������x����(1,5)";
			cin >> x;
			cout << "������y����(1,5)";
			cin >> y;

			system("cls");
			if (x > 5 || x < 1){
				cout << "������Ϸ�x����" << endl;
				continue;
			}

			if (y > 5 || y < 1){
				cout << "������Ϸ�y����" << endl;
				continue;
			}

			Chess *temp = new Chess(x, y);
			if (Ch[x - 1][y - 1] == '0'){
				exit(1);
			}
			Ch[x - 1][y - 1] = '0';
			
			stest->UndoPush(temp);


			//��ʾ��ǰ����
			Display(Ch,SizeSpot);
		}

		if (temp == 2){
			int ic;
			cout << "��������Ҫ��ת�Ĳ���" <<"0-"<<stest->GetUndoTimes()<<endl;
			cin >> ic;
			if (ic > stest->GetUndoTimes() || ic <= 0){
				cout << "�Ƿ�����,��ִ��һ������" << endl;
				//ִ��undo����,undoջ��ջ,redoջѹջ
				Chess *temp = stest->Undo();
				x = temp->GetX();
				y = temp->GetY();
				Ch[x - 1][y - 1] = '*';
			}
			else
			{
				for (int i = 1; i <= ic; i++){
					//ִ��undo����,undoջ��ջ,redoջѹջ
					Chess *temp = stest->Undo();
					x = temp->GetX();
					y = temp->GetY();
					Ch[x - 1][y - 1] = '*';
				}

			}

			//��ʾ��ǰ����
			Display(Ch, SizeSpot);
		}

		if (temp == 3){
			int ic;
			cout << "��������Ҫ��ת�Ĳ���" << "0-" << stest->GetRedoTimes() << endl;
			cin >> ic;
			if (ic > stest->GetRedoTimes() || ic <= 0){
				cout << "�Ƿ�����,��ִ��һ������" << endl;
				//ִ��undo����,undoջ��ջ,redoջѹջ
				Chess *temp = stest->Redo();
				x = temp->GetX();
				y = temp->GetY();
				Ch[x - 1][y - 1] = '0';
			}
			else
			{
				for (int i = 1; i <= ic; i++){
					//ִ��undo����,undoջ��ջ,redoջѹջ
					Chess *temp = stest->Redo();
					x = temp->GetX();
					y = temp->GetY();
					Ch[x - 1][y - 1] = '0';
				}

			}

			//��ʾ��ǰ����
			Display(Ch, SizeSpot);
		}
		
		if (temp>=4){
			break;
		}

		cout << "#===========================================================#" << endl;
		cout << "1��ʾ����,2��ʾundo����,3��ʾredo����,4��ʾ�˳�" << endl;
		cout << "��ѡ�����" << endl;

	}

	cout << "��лʹ�ñ�ϵͳ" << endl;
	getchar();

	return 0;
}