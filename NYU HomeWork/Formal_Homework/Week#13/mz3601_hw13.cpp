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
int o_move;
char symbol;
void check_data();//remember to include this as a private function

public:

//constructors
Organism():x_axis(0),y_axis(0),o_move(0),symbol(' '){}
//not sreu if symbol works
Organism(int x, int y, int t, char s):
x_axis(x),y_axis(y),o_move(t),symbol(s){check_data();}

//accessors and mutators
int get_x() const{return x_axis;}
int get_y() const{return y_axis;}
int get_move() const{return o_move;}
char get_symbol() const{return symbol;}
void set_x(int x);
void set_y(int y);
void set_move(int t){o_move = t;}
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
void breed(Organism* grid[][COLUMN], int size_dimension_1, Organism ants_arr[], int& ants_count);
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
virtual void move(Organism* grid[][COLUMN], int size_dimension_1);
void breed(Organism* grid[][COLUMN], int size_dimension_1, Organism dbugs_arr[], int& doodlebug_count);
void starve(Organism* grid[][COLUMN], int size_dimension_1);

};
int main()
{
    //declare the grid in multidimensional array
    Organism* grid[ROW][COLUMN]; 
    //row = column = 20 the range is 0 - 19.
    
    cout<<"Welcome to the Game: Round #0\n";
    int t_step = 0, ants_count = 0, doodlebug_count = 0;
    int x_temp, y_temp;
    
    for(int index_x = 0; index_x < ROW; index_x ++)
    {
        for(int index_y = 0; index_y < COLUMN; index_y ++)
          grid[index_x][index_y] = nullptr;
    }
    
    srand(time(0));
    
    //put doodlebugs in
    Doodlebugs dbugs_arr[TOTAL];
    while(doodlebug_count < DOODLEBUGS_INITIAL)
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
    Ants ants_arr[1000];  
    while(ants_count < ANTS_INITIAL)
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
    
    cout<<"Press Enter to Continue.\n"; 
    Ants ants;
    Doodlebugs doodlebugs;
    while (cin.get() =='\n')
    {
        t_step ++;
        cout<<"Round #"<<t_step<<endl;
        
        
        if(t_step != 0 && t_step %3 == 0){
            ants.breed(grid, ROW, ants_arr, ants_count);
            
        } 
        else{
            ants.move(grid, ROW);
            doodlebugs.starve(grid, ROW);
            doodlebugs.move(grid, ROW);}
        if(t_step != 0 && (t_step % 8 == 0))
          doodlebugs.breed(grid, ROW, dbugs_arr, doodlebug_count);  
          
    
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
    
    cout<<"Press Enter to Continue.\n";
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

void Ants::move(Organism* grid[][COLUMN], int size_dimension_1){
    for(int i = 0; i < size_dimension_1; i ++){
        for(int j = 0; j < COLUMN; j ++){
            if((grid[i][j] != nullptr)&&(grid[i][j]->get_symbol() == 'o')){
                        int k = rand() % 4; 
                        switch(k){
                            case 1: {
                                if((i != 0)&&(grid[i-1][j] == nullptr))
                                {
                                        grid[i-1][j] = grid[i][j];
                                        grid[i][j] = nullptr;
                                        grid[i-1][j]->set_x(i-1);
                                
                                }
                                break;
                                }
                            case 2: {
                                if((i != 19)&&(grid[i+1][j] == nullptr)){
                                        grid[i+1][j] = grid[i][j];
                                        grid[i][j] = nullptr;
                                        grid[i+1][j]->set_x(i+1);
                                    
                                    }
                                break;    
                                }
                            case 3: {
                                if((j != 0)&& (grid[i][j-1] == nullptr)){
                                        grid[i][j-1] = grid[i][j];
                                        grid[i][j] = nullptr;
                                        grid[i][j-1]->set_y(j-1);
                                        
                                    }
                               break;    
                                }
                            case 4:{
                                if((j != 19)&&(grid[i][j+1] == nullptr)){
                                        grid[i][j+1] = grid[i][j];
                                        grid[i][j] = nullptr;
                                        grid[i][j+1]->set_y(j+1);
                                       
                                    }
                                 break;    
                                }
                        }
                    }
                }
            }
        }

void Ants::breed(Organism* grid[][COLUMN], int size_dimension_1, Organism ants_arr[], int& ants_count){
    for(int i = 0; i < size_dimension_1; i ++){
        for(int j = 0; j < COLUMN; j ++){
            if((grid[i][j] != nullptr)&&(grid[i][j]->get_symbol() == 'o')){
                int k = rand()%4 +1;
                switch(k){
                    case 1:{
                        if((i != 0)&&(grid[i-1][j] == nullptr))
                        {
                            grid[i-1][j] = &ants_arr[ants_count];
                            ants_arr[ants_count].set_x(i-1);
                            ants_arr[ants_count].set_y(j);
                            ants_count ++;
                            
                        }
                        break;
                    }
                    case 2:{
                        if((i != 19)&&(grid[i+1][j] == nullptr))
                        {
                            grid[i+1][j] = &ants_arr[ants_count];
                            ants_arr[ants_count].set_x(i+1);
                            ants_arr[ants_count].set_y(j);
                            ants_count ++;
                            
                        }
                       break;
                    }
                    case 3:{
                        if((j != 0)&& (grid[i][j-1] == nullptr))
                        {
                            grid[i][j-1] = &ants_arr[ants_count];
                            ants_arr[ants_count].set_x(i);
                            ants_arr[ants_count].set_y(j-1);
                            ants_count ++;
                            
                        }
                        break;
                    }
                    case 4:{
                        if((j != 19)&&(grid[i][j+1] == nullptr))
                        {
                            grid[i][j+1] = &ants_arr[ants_count];
                            ants_arr[ants_count].set_x(i);
                            ants_arr[ants_count].set_y(j+1);
                            ants_count ++;
                            
                        }
                        break;
                    }
                }
            }
        }
    }
}

void Doodlebugs::move(Organism* grid[][COLUMN], int size_dimension_1){
    for(int i = 0; i < size_dimension_1; i++){
        for(int j = 0; j < COLUMN; j ++){
            if((grid[i][j] != nullptr) && (grid[i][j]->get_symbol() == 'X')){
                int k = rand()% 4 + 1;
                switch(k){
                case 1:
                {
                    if((i != 0) && (grid[i-1][j] == nullptr)){
                        grid[i][j]->set_move(grid[i][j]->get_move() +1);
                        grid[i-1][j] = grid[i][j];
                        grid[i][j] = nullptr;
                        grid[i-1][j] -> set_x(i-1);
                    }
                    else if((i !=0) && (grid[i-1][j]->get_symbol() == 'o')){
                        grid[i][j]->set_move(0);
                        grid[i-1][j]->set_x(0);
                        grid[i-1][j]->set_y(0);
                        grid[i-1][j] = grid[i][j];
                        grid[i][j] = nullptr;
                        grid[i-1][j]->set_x(i-1);
                    }
                    break;
                }
                case 2:
                {
                    if((i!=19) && (grid[i+1][j] == nullptr)){
                        grid[i][j]->set_move(grid[i][j]->get_move() +1);
                        grid[i+1][j] = grid[i][j];
                        grid[i][j] = nullptr;
                        grid[i+1][j] -> set_x(i+1);
                    }
                    else if((i!=19) && (grid[i+1][j]->get_symbol() == 'o')){
                        grid[i][j]->set_move(0);
                        grid[i+1][j]->set_x(0);
                        grid[i+1][j]->set_y(0);
                        grid[i+1][j] = grid[i][j];
                        grid[i][j] = nullptr;
                        grid[i+1][j]->set_x(i+1);
                    }
                    break;
                }
                case 3:
                {
                    if((j != 0) && (grid[i][j-1] == nullptr)){
                        grid[i][j]->set_move(grid[i][j]->get_move() +1);
                        grid[i][j-1] = grid[i][j];
                        grid[i][j] = nullptr;
                        grid[i][j-1] -> set_y(j-1);
                    }
                    else if((i!=0) && (grid[i][j-1]->get_symbol() == 'o')){
                        grid[i][j]->set_move(0);
                        grid[i][j-1]->set_x(0);
                        grid[i][j-1]->set_y(0);
                        grid[i][j-1] = grid[i][j];
                        grid[i][j] = nullptr;
                        grid[i][j-1]->set_y(j-1);
                    }
                    break;
                }
                case 4:
                {
                    if((j != 19) && (grid[i][j+1] == nullptr)){
                        grid[i][j]->set_move(grid[i][j]->get_move() +1);
                        grid[i][j+1] = grid[i][j];
                        grid[i][j] = nullptr;
                        grid[i][j+1] -> set_y(j+1);
                    }
                    else if((j!=19) && (grid[i][j+1]->get_symbol() == 'o')){
                        grid[i][j]->set_move(0);
                        grid[i][j+1]->set_x(0);
                        grid[i][j+1]->set_y(0);
                        grid[i][j+1] = grid[i][j];
                        grid[i][j] = nullptr;
                        grid[i][j+1]->set_y(j+1);
                    }
                    break;
                }
            }
            }
        }
    }
}

void Doodlebugs::breed(Organism* grid[][COLUMN], int size_dimension_1, Organism dbugs_arr[], int& doodlebug_count)
{
    for(int i = 0; i < size_dimension_1; i++){
        for(int j = 0; j < COLUMN; j++){
            if((grid[i][j] != nullptr) &&(grid[i][j]->get_symbol() == 'X')){
                int k = rand()%4 +1;
                switch(k){
                    case 1:{
                        if((i != 0) && (grid[i-1][j] == nullptr || (grid[i-1][j]->get_symbol() == 'o'))){
                            grid[i-1][j] =&dbugs_arr[doodlebug_count];
                            dbugs_arr[doodlebug_count].set_x(i-1);
                            dbugs_arr[doodlebug_count].set_y(j);
                            doodlebug_count ++;
                        }
                        break;
                    }
                    case 2:{
                        if((i != 19) && (grid[i+1][j] == nullptr|| grid[i+1][j]->get_symbol() == 'o')){
                            grid[i+1][j] =&dbugs_arr[doodlebug_count];
                            dbugs_arr[doodlebug_count].set_x(i+1);
                            dbugs_arr[doodlebug_count].set_y(j);
                            doodlebug_count ++;
                        }
                        break;
                    }
                    case 3:{
                        if((j != 0) && (grid[i][j-1] == nullptr || grid[i][j-1]->get_symbol() =='o')){
                            grid[i][j-1] =&dbugs_arr[doodlebug_count];
                            dbugs_arr[doodlebug_count].set_x(i);
                            dbugs_arr[doodlebug_count].set_y(j-1);
                            doodlebug_count ++;
                        }
                        break;
                    }
                    case 4:{
                        if((j != 19) && (grid[i][j+1] == nullptr|| grid[i][j+1]->get_symbol() =='o')){
                            grid[i][j+1] =&dbugs_arr[doodlebug_count];
                            dbugs_arr[doodlebug_count].set_x(i);
                            dbugs_arr[doodlebug_count].set_y(j+1);
                            doodlebug_count ++;
                        }
                        break;
                    }
                }
            }
        }
    }
}

void Doodlebugs::starve(Organism* grid[][COLUMN], int size_dimension_1){
    for(int i = 0; i < size_dimension_1; i ++){
        for(int j = 0; j < COLUMN; j ++)
        {
            if(grid[i][j] != nullptr && grid[i][j]->get_symbol() == 'X'){
                if(grid[i][j]->get_move() ==3)
                  grid[i][j] = nullptr;
            }
        }
    }
}

