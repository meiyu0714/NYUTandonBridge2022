#include <iostream>
#include <string>
using namespace std;

const double POUND_TO_KG = 0.453592;
const double INCH_TO_METER = 0.0254;
int main()
{
    double bim, weight_pd, weight_kg, height_inch, height_meter;
    string status;
    
    //get the inputs. Calculate height and weight 
    //in kilograms and meters.
    cout<<"Please enter weight(in pounds): ";
    cin>>weight_pd;
    weight_kg = weight_pd * POUND_TO_KG;
    
    cout<<"Please enter height(in inches): ";
    cin>>height_inch;
    height_meter = height_inch * INCH_TO_METER;
    
    //calculate BIM
    bim = weight_kg / (height_meter * height_meter);
    
    //determine the status by BIM
    if(bim < 18.5)
     status = "Underweight";
    else if(bim >= 18.5 && bim < 25)
     status = "Normal";
    else if(bim >=25 && bim < 30)
     status = "Overweight";
    else
     status = "Obese";
    
    cout<<"The weight status is: "<<status; 
    
    return 0;
}