#include"Undo_Redo.h"
#include<stdlib.h>

using std::cin;
using std::cout;
using std::endl;


#define SizeSpot 5 

//棋盘初始化
void Init(char ChessSpot[][SizeSpot],int ChessSizeX){
	
	if (ChessSizeX <= 0 || SizeSpot <= 0){
		cout << "非法棋盘大小" << endl;
		return;
	}
	
	for (int i = 0; i < ChessSizeX; i++){
		for (int j = 0; j < SizeSpot; j++){
			ChessSpot[i][j] = '*';
		}
	}
}

//显示当前棋盘
void Display(char ChessSpot[][SizeSpot], int ChessSizeX){
	if (ChessSizeX <= 0 || SizeSpot <= 0){
		cout << "非法棋盘大小" <<endl;
		return;
	}

	for (int i = 0; i < ChessSizeX; i++){
		for (int j = 0; j < SizeSpot; j++){
			std::cout << ChessSpot[i][j] << ' ';
		}
		cout << endl;
	}
}

//引导及选择
bool Introduce(){
	cout << "#===========================================================#" << endl;
	cout << "键入h以查看帮助,键入g以跳过帮助直接运行" << endl;


	char type;		//引导字符
	cin >> type;

	if (type == 'h'){
		cout << "棋盘为大小为5*5,棋盘中未落子处用*显示,已落子处用0显示" << endl;
		cout << "当棋盘显示后,用户可以进行选择:" << endl;
		cout << "1表示落子,2表示undo操作,3表示redo操作,4表示退出" << endl;
		cout << "#===========================================================#" << endl;
		return true;
	}

	if (type == 'g'){
		cout << "#===========================================================#" << endl;
		return true;
	}

	//非法字符跳转
	cout << "请输入合法字符" << endl;
	cout << "感谢使用本系统" << endl;
	cout << "#===========================================================#" << endl;
	return false;
}

int main(){

	//设置棋盘
	char Ch[SizeSpot][SizeSpot];

	//输入非法字符则退出程序
	if (!Introduce()){
		getchar();
		return 0;
	}

	Init(Ch, SizeSpot);
	getchar();

	Display(Ch, SizeSpot);
	cout << "#===========================================================#" << endl;
	cout << "1表示落子,2表示undo操作,3表示redo操作,4表示退出" << endl;
	Spot *stest = new Spot();
	
	//分别作为棋子的横纵坐标
	int x;
	int y;

	int temp;

	//Undo/Redo测试
	while (1){
		cout << "#===========================================================#" << endl;
		cout << "可执行undo次数:" << stest->GetUndoTimes() << '	' << "可执行redo次数" << stest->GetRedoTimes() << endl;
		cout << "请输入你的选择" << endl;
		cin >> temp;
		system("cls");
		if (temp == 1){
			//落子,并保存在Undo中
			cout << "请不要输入已落子坐标" << endl;
			cout << "请输入x坐标(1,5)";
			cin >> x;
			cout << "请输入y坐标(1,5)";
			cin >> y;

			system("cls");
			if (x > 5 || x < 1){
				cout << "请输入合法x坐标" << endl;
				continue;
			}

			if (y > 5 || y < 1){
				cout << "请输入合法y坐标" << endl;
				continue;
			}

			Chess *temp = new Chess(x, y);
			if (Ch[x - 1][y - 1] == '0'){
				exit(1);
			}
			Ch[x - 1][y - 1] = '0';
			
			stest->UndoPush(temp);


			//显示当前棋盘
			Display(Ch,SizeSpot);
		}

		if (temp == 2){
			int ic;
			cout << "请输入需要跳转的步数" <<"0-"<<stest->GetUndoTimes()<<endl;
			cin >> ic;
			if (ic > stest->GetUndoTimes() || ic <= 0){
				cout << "非法输入,仅执行一步操作" << endl;
				//执行undo操作,undo栈弹栈,redo栈压栈
				Chess *temp = stest->Undo();
				x = temp->GetX();
				y = temp->GetY();
				Ch[x - 1][y - 1] = '*';
			}
			else
			{
				for (int i = 1; i <= ic; i++){
					//执行undo操作,undo栈弹栈,redo栈压栈
					Chess *temp = stest->Undo();
					x = temp->GetX();
					y = temp->GetY();
					Ch[x - 1][y - 1] = '*';
				}

			}

			//显示当前棋盘
			Display(Ch, SizeSpot);
		}

		if (temp == 3){
			int ic;
			cout << "请输入需要跳转的步数" << "0-" << stest->GetRedoTimes() << endl;
			cin >> ic;
			if (ic > stest->GetRedoTimes() || ic <= 0){
				cout << "非法输入,仅执行一步操作" << endl;
				//执行undo操作,undo栈弹栈,redo栈压栈
				Chess *temp = stest->Redo();
				x = temp->GetX();
				y = temp->GetY();
				Ch[x - 1][y - 1] = '0';
			}
			else
			{
				for (int i = 1; i <= ic; i++){
					//执行undo操作,undo栈弹栈,redo栈压栈
					Chess *temp = stest->Redo();
					x = temp->GetX();
					y = temp->GetY();
					Ch[x - 1][y - 1] = '0';
				}

			}

			//显示当前棋盘
			Display(Ch, SizeSpot);
		}
		
		if (temp>=4){
			break;
		}

		cout << "#===========================================================#" << endl;
		cout << "1表示落子,2表示undo操作,3表示redo操作,4表示退出" << endl;
		cout << "请选择操作" << endl;

	}

	cout << "感谢使用本系统" << endl;
	getchar();

	return 0;
}