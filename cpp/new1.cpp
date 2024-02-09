#include<iostream>
using namespace std;

#define max 10

class polygon
{
    public:
    int number_of_sides;
    string name;
    float dimensions[max];
    private:
    string database[8]={"Triangle","Quadrilateral","Pentagon","Hexagon","Heptagon","Octagon","Nonagon","Decagon"};
    public:polygon()
    {
        cout<<"\nEnter Number of sides: ";
        while(1)
        {
            
            cin>>number_of_sides;
            if((number_of_sides==0)||(number_of_sides==1)||(number_of_sides==2))
            {
                cout<<"\nThats not a polygon, enter again: ";
            }
            else
            {
                break;
            }


        }
        int i;
        for(i=0;i<8;i++)
        {
            if(i==(number_of_sides-3))
            {
                name = database[i];
            }
        }
        cout<<"\nEnter dimensions of sides in units: "<<endl;
        for(i=0;i<number_of_sides;i++)
        {
            cout<<"\nSide"<<i+1<<":";
            float temp;
            do
            {
                cin>>temp;
                if(temp==0)
                {
                    cout<<"Dimension cant be zero enter again:";
                }
                else
                break;
                
            } while (1);
            dimensions[i]=temp;

        }
    }


};

int main()
{
    polygon p1;
    cout<<"\nName of polygon is:"<<p1.name<<endl;
    int i;
    for ( i = 0; i < p1.number_of_sides; i++)
    {
        cout<<"\nSide"<<i<<":"<<p1.dimensions[i];
    }
    
    return 0;
}