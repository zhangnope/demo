#include"Composite.h"

int main(){
	
	cout << "making root entries..." << endl;

	Composite *rootdir = new Composite("root");
	Composite *bindir = new Composite("bin");
	Composite *tmpdir = new Composite("tmp");
	Composite *usrdir = new Composite("usr");

	rootdir->add(bindir);
	rootdir->add(tmpdir);
	rootdir->add(usrdir);

	bindir->add(new Leaf("vi", 10000));
	bindir->add(new Leaf("latex", 20000));
	rootdir->printList("");


	cout << "making user entries..."<<endl;

	Composite *yuki = new Composite("yuki");
	Composite *hanako = new Composite("hanako");
	Composite *tomura = new Composite("tomura");
	usrdir->add(yuki);
	usrdir->add(hanako);
	usrdir->add(tomura);

	yuki->add(new Leaf("diary.html", 100));
	yuki->add(new Leaf("Composite.java", 200));
	hanako->add(new Leaf("memo.tex", 300));
	tomura->add(new Leaf("game.doc", 400));
	tomura->add(new Leaf("junk.mail", 500));
	rootdir->printList("");

	getchar();

	return 0;
}
