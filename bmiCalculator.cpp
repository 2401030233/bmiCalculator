# include <iostream>
# include <cmath>
using namespace std;

class BMI
{
private:
    float weight, height, bmiVal;
    int ch;

public:
    int ID;
    string name;
    void getdata();
    void bmiCalculator();
    void showDetails();
};
void BMI::getdata()
{
    cout<<endl<<"\nInput your name\n";
    cin>>name;
    cout<<"Input your ID\n";
    cin>>ID;
    cout<<"\nChoose Unit system\n1.kg/(meter)^2\t2.lbs/(in)^2\n";
    cin>>ch;
    switch(ch)
    {
    case 1:
        cout<<"\nInput weight (kg)\n";
        cin>>weight;
        cout<<"Input height (meter)\n";
        cin>>height;
        break;
    case 2:
        cout<<"\nInput weight (lbs)\n";
        cin>>weight;
        cout<<"Input height (inches)\n";
        cin>>height;
        break;
    default:
        cout<<"\nERROR : Input valid choice!\n";
    }

}
void BMI::bmiCalculator()
{
    if (ch==1)
    {
        bmiVal=weight/pow(height, 2);
    }
    else if (ch==2)
    {
        bmiVal=(weight*703)/pow(height, 2);
    }
    cout<<"\nFor "<<name<<", having ID : "<<ID<<", BMI = "<< bmiVal;
    if (bmiVal<18.5)
    {
        cout<<". Hence, Underweight\nREMARKS: Possible Nutritional Deficiency.\n";
    }
    else if ( bmiVal>=18.5 &&  bmiVal<25)
    {
        cout<<". Hence, Normal weight\nREMARKS: Low (healthy range).\n";
    }
    else if ( bmiVal>=25&&  bmiVal<30)
    {
        cout<<". Hence, Overweight\nREMARKS: Increased risk of health problems.\n";
    }
    else if ( bmiVal>=30 &&  bmiVal<35)
    {
        cout<<". Hence, Obesity (Class I)\nREMARKS: Moderate risk of health issues.\n";
    }
    else if ( bmiVal>=35 &&  bmiVal<40)
    {
        cout<<". Hence, Obesity (Class II)\nREMARKS: Severe risk of health issues.\n";
    }
    else
    {
        cout<<". Hence, Obesity (Class III)\nREMARKS: Very severe (morbid obesity).\n";
    }
}
int main()
{
    int nos, r, Per_ID, ch1;

    string name;

    BMI b[5];
    cout<<"\nInput number of people (MAX 5)\n";
    cin>>nos;
    if (nos>5 || nos<=0)
    {
        cout<<"\nERROR : Input valid number of people\n";
        return 1;
    }
    else
    {
        for (int i=0; i<nos; i++)
        {
            b[i].getdata();
        }
        do
        {
            cout<<"\n1.Show Details of everyone\n2.Search by ID \n3.Exit\n";
            cout<<"\nInput choice\n";
            cin>>ch1;
            switch(ch1)
            {
            case 1:
                cout<<"\nDisplaying details of everyone\n";
                for (int i=0; i<nos; i++)
                {
                    b[i].bmiCalculator();
                }
                break;
            case 2:
            {
                int ID;
                int flag=0;
                cout<<"\nInput ID of person for BMI Calculations..\n";
                cin>>Per_ID;
                for (int i=0; i<nos; i++)
                {
                    if(Per_ID==b[i].ID)
                    {
                        flag=1;
                        r=i;
                        break;
                    }
                }
                if (!flag) //flag==0
                {
                    cout<<"\nERROR : Person with above ID not found!\n";
                }
                else
                {
                    b[r].bmiCalculator();
                }
            }
            break;
            case 3:
                cout<<"\n======[Exiting the program...]======\n";
                exit(0);
                break;
            default:
                cout<<"\nERROR : Input valid choice!\n";
            }
        }
        while(ch1!=3);
    }
    return 0;
}
