#include <iostream>
#include <iomanip> 
using namespace std;

const double GET_ONE_HALF_DISCOUNT = 0.5;
const double CLUB_DISCOUNT = 0.1;
int main()
{
    double price_1, price_2, tax;
    double total_price, base_price, price_one_half, price_discount;
    char card;
    
    //get the inputs
    cout<<"Enter price of first item: ";
    cin>>price_1;
    
    cout<<"Enter price of second item: ";
    cin>>price_2;
    
    cout<<"Does customer have a club card?(Y/N): ";
    cin>>card;
    
    cout<<"Enter tax rate, e.g. 5.5 for 5.5% tax: ";
    cin>>tax;
    
    //base price
    base_price = price_1 + price_2; 
    //calculate price after buy one get one half price.
    if(price_1 >= price_2)
      price_one_half = price_1 + (1 - GET_ONE_HALF_DISCOUNT) * price_2;
    else
      price_one_half = price_2 + (1 - GET_ONE_HALF_DISCOUNT) * price_1;
    //price after club card discount  
    if(card == 'y' || card == 'Y')
      price_discount = (1 - CLUB_DISCOUNT) * price_one_half;
    else if(card == 'N'||card == 'n')
      price_discount = price_one_half;
    else{
      cout<<"Invalid Input for club card.";
      return 0;
    }
      
    //price after tax
    total_price = price_discount * (1 + tax/100);
    
    //program displays
    cout<<"Base price: "<<fixed<<setprecision(1)<<base_price<<endl;
    cout<<"Price after discount: "<<price_discount<<endl;
    cout<<"Total price: "<<fixed<<setprecision(5)<<total_price<<endl;

    return 0;
}
