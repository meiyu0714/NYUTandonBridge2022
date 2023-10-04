#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
struct info {
	char name;
	int move;
	int step;
	int visit;
} a[20][20];
class Organism {
	public:
		virtual void Move()=0;
};
void start() {
	for(int p=0; p<20; p++)
		for(int q=0; q<20; q++) {
			a[p][q].visit=0;
			a[p][q].name='-';
			a[p][q].step=0;

		}
	int i,b,count1=0,count2=0;
	for(; count1<5;) {//5x
		i=rand()%20;
		b=rand()%20;
		if(a[i][b].visit==0) {
			a[i][b].visit=1;
			a[i][b].name='X';
			count1++;
		}
	}
	for(; count2<100;) {//200o
		i=rand()%20;
		b=rand()%20;
		if(a[i][b].visit==0) {
			a[i][b].visit=1;
			a[i][b].name='o';
			count2++;
		}
	}
}
void print() {
	cout<<"-------------------------------------------"<<endl;
	int count1=0;
	int count2=0;
	for(int i=0; i<20; i++) {
		for(int j=0; j<20; j++) {
			cout<<a[i][j].name<<' ';
			if(a[i][j].name=='X')count1++;
			if(a[i][j].name=='o')count2++;
		}
		cout<<endl;
	}
	cout<<count1<<" Doodlebugs"<<'\t'<<count2<<" Ants"<<endl<<endl;
	cout<<"Press Enter to Continue.\n";

}
class Ant:public Organism {
	public:
		virtual void Move();
		void Breed();
};
void Ant::Move() {
	bool flag;
	int c1,c2,c3,c4;
	for(int i=0; i<20; i++)
		for(int j=0; j<20; j++)
			if(a[i][j].name=='o'&&a[i][j].move==0) {
				flag = true;
				c1=1,c2=1,c3=1,c4=1; 
				while(flag) {
					int k= 1 + rand()%4;
					switch(k) {
						case 1: {
							if(c1==0) break;
							if(i!=0) {
								if(!a[i-1][j].visit) {

									a[i][j].visit=0;
									a[i-1][j].visit=1;
									flag=0;
									a[i][j].name=' ';
									a[i-1][j].name='o';
									a[i-1][j].move=1;
									break;
								} else c1=0;
								break;
							} else c1=0;
							break;
						}
						case 2: {
							if(c2==0) break 	;
							if(i!=19) {
								if(!a[i+1][j].visit) {
									a[i][j].visit=0;
									a[i+1][j].visit=1;
									flag=0;
									a[i][j].name=' ';
									a[i+1][j].name='o';
									a[i+1][j].move=1;
									break;
								} else c2=0;
								break;
							} else c2=0;
							break;
						}
						case 3: {
							if(c3==0) break;
							if(j!=0) {
								if(!a[i][j-1].visit) {
									a[i][j].visit=0;
									a[i][j-1].visit=1;
									flag=0;
									a[i][j].name=' ';
									a[i][j-1].name='o';
									a[i][j-1].move=1;
									break;
								} else c3=0;
								break;
							} else c3=0;
							break;
						}
						case 4: {
							if(c4==0) break;
							if(j!=19) {
								if(!a[i][j+1].visit) {
									a[i][j].visit=0;
									a[i][j+1].visit=1;
									flag=0;
									a[i][j].name=' ';
									a[i][j+1].name='o';
									a[i][j+1].move=1;
									break;
								} else c4=0;
								break;
							} else c4=0;
							break;
						}
					}
					if(c1==0&&c2==0&&c3==0&&c4==0) flag=0;
				}

			}
}
void Ant::Breed() { 
	bool flag;
	int c1,c2,c3,c4;;
	int i,j,k;
	for( i=0; i<20; i++)
		for( j=0; j<20; j++)
			if(a[i][j].name=='o'&&a[i][j].move==0) {
				flag=0;
				c1=1,c2=1,c3=1,c4=1;
				while(!flag) {
					k=1+rand()%4;
					switch(k) {
						case 1: {
							if(c1==0) break;
							if(i!=0) {
								if(!a[i-1][j].visit) {
									a[i-1][j].visit=1;
									flag=1;
									a[i-1][j].name='o';
									a[i-1][j].move=1;
									break;
								} else c1=0;
							} else c1=0;
							break;
						}
						case 2: {
							if(c2==0) break;
							if(i!=19) {
								if(!a[i+1][j].visit) {
									a[i+1][j].visit=1;
									flag=1;
									a[i+1][j].name='o';
									a[i+1][j].move=1;
									break;
								} else c2=0;
							} else c2=0;
							break;
						}
						case 3: {
							if(c3==0) break;
							if(j!=0) {
								if(!a[i][j-1].visit) {
									a[i][j-1].visit=1;
									flag=1;
									a[i][j-1].name='o';
									a[i][j-1].move=1;
									break;
								} else c3=0;
							} else c3=0;
							break;
						}
						case 4: {
							if(c4==0) break;
							if(j!=19) {
								if(!a[i][j+1].visit)

								{
									a[i][j+1].visit=1;
									flag=1;
									a[i][j+1].name='o';
									a[i][j+1].move=1;
									break;
								} else c4=0;
							} else c4=0;
							break;
						}
					}
					if(c1==0&&c2==0&&c3==0&&c4==0) flag=1;
				}
			}
}
class Doudlebug:public Organism {
	public:
		virtual void Move();
		void Breed();
		void Starve();
};
void Doudlebug::Move() {
	{
		bool flag;
		int i,j,k;
		int c1,c2,c3,c4,c5,c6,c7,c8;
		for( i=0; i<20; i++)
			for( j=0; j<20; j++)
				if(a[i][j].name=='X'&&a[i][j].move==0) {
					flag=0;
					c1=1,c2=1,c3=1,c4=1,c5=1,c6=1,c7=1,c8=1;	
					while(!flag) {
						k=1+rand()%4;
						switch(k) {
							case 1: {
								if(c1==0) break;
								if(i!=0) {
									if(a[i-1][j].name=='o') {
										a[i][j].visit=0;
										a[i-1][j].visit=1;
										flag=1;
										a[i][j].name='-';
										a[i-1][j].name='X';
										a[i-1][j].move=1;
										a[i-1][j].step=0;
										break;
									} else c1=0;
								} else c1=0;
								break;
							}
							case 2: {
								if(c2==0) break;
								if(i!=19) {
									if(a[i+1][j].name=='o') {
										a[i][j].visit=0;
										a[i+1][j].visit=1;
										flag=1;
										a[i][j].name='-';
										a[i+1][j].name='X';
										a[i+1][j].move=1;
										a[i+1][j].step=0;
										break;
									} else c2=0;
								} else c2=0;
								break;
							}
							case 3: {
								if(c3==0) break;
								if(j!=0) {
									if(a[i][j-1].name=='o') {
										a[i][j].visit=0;
										a[i][j-1].visit=1;
										flag=1;
										a[i][j].name='-';
										a[i][j-1].name='X';
										a[i][j-1].move=1;
										a[i][j-1].step=0;
										break;
									} else c3=0;
								} else c3=0;
								break;
							}
							case 4: {
								if(c4==0) break;
								if(j!=19) {
									if(a[i][j+1].name=='o') {
										a[i][j].visit=0;
										a[i][j+1].visit=1;
										flag=1;
										a[i][j].name='-';
										a[i][j+1].name='X';
										a[i][j+1].move=1;
										a[i][j+1].step=0;
										break;
									} else c4=0;
								} else c4=0;
								break;
							}
						}
						if(c1==0&&c2==0&&c3==0&&c4==0) {
							switch(k) {
								case 1: {
									if(c5==0) break;
									if(i!=0) {
										if(!a[i-1][j].visit) {
											a[i][j].visit=0;
											a[i-1][j].visit=1;
											flag=1;
											a[i][j].name='-';
											a[i-1][j].name='X';
											a[i-1][j].move=1;
											a[i-1][j].step=a[i][j].step+1;
											break;
										} else c5=0;
									} else c5=0;
									break;
								}
								case 2: {
									if(c6==0) break;
									if(i!=19) {

										if(!a[i+1][j].visit) {
											a[i][j].visit=0;
											a[i+1][j].visit=1;
											flag=1;
											a[i][j].name='-';
											a[i+1][j].name='X';
											a[i+1][j].move=1;
											a[i+1][j].step=a[i][j].step+1;
											break;
										} else c6=0;
									} else c6=0;
									break;
								}
								case 3: {
									if(c7==0) break;
									if(j!=0) {

										if(!a[i][j-1].visit) {
											a[i][j].visit=0;
											a[i][j-1].visit=1;
											flag=1;
											a[i][j].name='-';
											a[i][j-1].name='X';
											a[i][j-1].move=1;
											a[i][j-1].step=a[i][j].step+1;
											break;
										} else c7=0;
									} else c7=0;
									break;
								}
								case 4: {
									if(c8==0) break;
									if(j!=19) {

										if(!a[i][j+1].visit) {
											a[i][j].visit=0;
											a[i][j+1].visit=1;
											flag=1;
											a[i][j].name='-';
											a[i][j+1].name='X';
											a[i][j+1].move=1;
											a[i][j+1].step=a[i][j].step+1;
											break;
										} else c8=0;
									} else c8=0;
									break;
								}
							}
							if(c5==0&&c6==0&&c7==0&&c8==0) flag=1;
						}
					}
					if(a[i][j].step==2&&a[i-1][j].step==3) {
						a[i-1][j].move=0;
						a[i-1][j].name='-';
						a[i-1][j].step=0;
						a[i-1][j].visit=0;
					} else if(a[i][j].step==2&&a[i+1][j].step==3) {
						a[i+1][j].move=0;
						a[i+1][j].name='-';
						a[i+1][j].step=0;
						a[i+1][j].visit=0;
					} else if(a[i][j].step==2&&a[i][j-1].step==3) {
						a[i][j-1].move=0;
						a[i][j-1].name='-';
						a[i][j-1].step=0;
						a[i][j-1].visit=0;
					} else if(a[i][j].step==2&&a[i][j+1].step==3) {
						a[i][j+1].move=0;
						a[i][j+1].name='-';
						a[i][j+1].step=0;
						a[i][j+1].visit=0;
					}
				}
	}
}
void Doudlebug::Breed() {
	bool flag;
	int c1,c2,c3,c4;
	for(int i=0; i<20; i++)
		for(int j=0; j<20; j++)
			if(a[i][j].name=='X'&&a[i][j].move==0) {
				flag=0;	
				while(!flag) {
					k=1+rand()%4;
					switch(k) {
						case 1: {
							if(c1==0) break;
							if( i!=0) {
								if(!a[i-1][j].visit) {
									a[i-1][j].visit=1;
									flag=1;
									a[i-1][j].name='X';
									a[i-1][j].move=1;
									a[i][j].step=a[i][j].step+1;
									break;
								} else c1=0;
							} else c1=0;
							break;
						}
						case 2: {
							if(c2==0) break;
							if(i!=19) {
								if(!a[i+1][j].visit) {
									a[i+1][j].visit=1;
									flag=1;
									a[i+1][j].name='X';
									a[i+1][j].move=1;
									a[i][j].step=a[i][j].step+1;
									break;
								} else c2=0;
							} else c2=0;
							break;
						}
						case 3: {
							if(c3==0) break;
							if(j!=0) {
								if(!a[i][j-1].visit) {
									a[i][j-1].visit=1;
									flag=1;
									a[i][j-1].name='X';
									a[i][j-1].move=1;
									a[i][j].step=a[i][j].step+1;
									break;
								} else c3=0;
							} else c3=0;
							break;
						}
						case 4: {
							if(c4==0) break;
							if(j!=19) {
								if(!a[i][j+1].visit) {
									a[i][j+1].visit=1;
									flag=1;
									a[i][j+1].name='X';
									a[i][j+1].move=1;
									a[i][j].step=a[i][j].step+1;
									break;
								} else c4=0;
							} else c4=0;
							break;
						}
					}
					if (c1==0&&c2==0&&c3==0&&c4==0) {
						flag=1;
						a[i][j].step++;

					}
					if(a[i][j].step==3) {
						a[i][j].move=0;
						a[i][j].name='-';
						a[i][j].step=0;
						a[i][j].visit=0;
					}
				}
			}
		}
int main() {
	start();
	print();
	int count=0;
	Ant ant;
	Doudlebug doudlebug;
	while(1) {
		getchar();
		for(int p=0; p<20; p++)
			for(int q=0; q<20; q++)
				a[p][q].move=0;
		if((count+1)%8==0) doudlebug.Breed();
		else doudlebug.Move();
		if((count+1)%3==0) ant.Breed();
		else ant.Move();
		count++;
		print();
		}
	}
