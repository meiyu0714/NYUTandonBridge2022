#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
const int ROW = 20;
const int COLUMN = 20;
const int TOTAL = 400;
const int ANTS_INITIAL = 100;
const int DOODLEBUGS_INITIAL = 5;
class Organism
{
private:

int x_axis;
int y_axis;
int time_step;
char symbol;
void check_data();//remember to include this as a private function

public:

//constructors
Organism():x_axis(0),y_axis(0),time_step(0),symbol(' '){}
//not sreu if symbol works
Organism(int x, int y, int t, char s):
x_axis(x),y_axis(y),time_step(t),symbol(s){check_data();}

//accessors and mutators
int get_x() const{return x_axis;}
int get_y() const{return y_axis;}
int get_time() const{return time_step;}
char get_symbol() const{return symbol;}
void set_x(int x);
void set_y(int y);
void set_time_step(int t){time_step = t;}
void set_symbol(char s){symbol = s;}

//fuctions
virtual void move(Organism* grid[][COLUMN], int size_dimension_1){}//change the location of Organism
virtual void breed(){cout<<"something is wrong with breed function, CHECK!\n";}
};

class Ants: public Organism
{
private:

public:
//constructors;
Ants():Organism(0,0,0,'o'){}
Ants(int x, int y, int t):Organism(x,y,t,'o'){}
//'o' represents ants  

//accessors and mutators 
//pubic functions are inherited

//functions
virtual void move(Organism* grid[][COLUMN], int size_dimension_1);
virtual void breed(){};//暂时啥也不干 后续修改
};
class Doodlebugs: public Organism
{
public:
//constructors;
Doodlebugs():Organism(0,0,0,'X'){}
Doodlebugs(int x, int y, int t):Organism(x,y,t,'X'){}
//'X' represents Doodlebugs

//accessors and mutators 
//pubic functions are inherited

//functions
virtual void move(Organism* grid[][COLUMN], int size_dimension_1){};//暂时啥也不干 后续修改
virtual void breed(){};//暂时啥也不干 后续修改
};
int main()
{
    //declare the grid in multidimensional array
    Organism* grid[ROW][COLUMN]; //=>方便后续使用virtual function
    //row = column = 20 the range is 0 - 19.
    
    cout<<"Welcome to the Game: Round #0\n";
    int t_step = 0, ants_count = 0, doodlebug_count = 0;
    int x_temp, y_temp;
    
    //char[][]的赋值不能 char[][]='-'要俩个loop一个一个的做
    for(int index_x = 0; index_x < ROW; index_x ++)
    {
        for(int index_y = 0; index_y < COLUMN; index_y ++)
          grid[index_x][index_y] = nullptr;
    }
    
    srand(time(0));
    
    //put doodlebugs in
    Doodlebugs dbugs_arr[400];
    while(doodlebug_count < 5)
    {
        x_temp = (rand()%20);
        y_temp = (rand()%20);
        ////rand()%20 => random number from 0 to 19
        if(grid[x_temp][y_temp] == nullptr)
        {
            grid[x_temp][y_temp] = &dbugs_arr[doodlebug_count];
            dbugs_arr[doodlebug_count].set_x(x_temp);
            dbugs_arr[doodlebug_count].set_y(y_temp);
            doodlebug_count ++;
        } 
    }
    
    //put ants in
    Ants ants_arr[400];  //后期测试后数字要用const 替换
    while(ants_count < 100)
    {
        x_temp = (rand()%20);
        y_temp = (rand()%20);
        ////rand()%20 => random number from 0 to 19
        if(grid[x_temp][y_temp] == nullptr)
        {
            grid[x_temp][y_temp] = &ants_arr[ants_count];
            ants_arr[ants_count].set_x(x_temp);
            ants_arr[ants_count].set_y(y_temp);
            ants_count ++;
        }    
    }
    
    //display the first setup;
    for(int index_x = 0; index_x < ROW; index_x ++)
    {
        for(int index_y = 0; index_y < COLUMN; index_y ++)
        {
            if(grid[index_x][index_y] == nullptr)
                cout<<'-'<<' ';
            else
                cout<<grid[index_x][index_y] -> get_symbol()<<' '; 
        }
        cout<<endl;  
    }
    
    cout<<"Press Enter to Continue.\n"; //检测：是否需要\n功能
    while (cin.get() =='\n')
    {
        t_step ++; //time_step 0 to 1 -> distinguish from the Organism time_step
        cout<<"Round #"<<t_step<<endl;
        
        for(int index_x = 0; index_x < ROW; index_x ++)
    {
        for(int index_y = 0; index_y < COLUMN; index_y ++){
            if(grid[index_x][index_y] != nullptr)
            grid[index_x][index_y]->move(grid, ROW);
        }
    }
    
    for(int index_x = 0; index_x < ROW; index_x ++)
    {
        for(int index_y = 0; index_y < COLUMN; index_y ++)
        {
            if(grid[index_x][index_y] == nullptr)
                cout<<'-'<<' ';
            else
                cout<<grid[index_x][index_y] -> get_symbol()<<' '; 
        }
        cout<<endl;  
    }
    
    cout<<"Press Enter to Continue.";
    }

    return 0;
}
//besure to check it before write in.
void Organism::set_x(int x)
{
    if(x < 0 || x > 19)
    {
        cout<<"X-axis input error, please check\n";
        exit(1);
    }
    else x_axis = x;
}

void Organism::set_y(int y){
    if(y < 0 || y > 19)
    {
        cout<<"Y-axis input error, please check\n";
        exit(1);
    }
    else y_axis = y;
}

void Organism::check_data()
{
    if(x_axis < 0 || x_axis > 19|| y_axis < 0 || y_axis > 19)
    {
        cout<<"Please check x and y axis value\n";
        exit(1);
    }
}

void Ants::move(Organism* grid[][COLUMN], int size_dimension_1)
{
    int x_temp = get_x(), y_temp = get_y();
    srand(time(0));
    int num_random = (rand()%4 + 1);
    switch(num_random){
        case 1: 
          y_temp ++;
          break;
        case 2:
          x_temp --;
          break;
        case 3: 
          y_temp --;
          break;
        case 4:
          x_temp ++;
          break;
    }
    if(y_temp >= 0 && y_temp <= 19 && x_temp >= 0 && x_temp <= 19){
        if(grid[x_temp][y_temp] == nullptr){
            grid[get_x()][get_y()] = nullptr;
            grid[x_temp][y_temp] = this;
            set_x(x_temp);
            set_y(y_temp);
        }
    }
    int a = get_time();
    set_time_step(a ++);
}