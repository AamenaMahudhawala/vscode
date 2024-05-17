//CLASSES IN OOP ARE LIKE BLUEPRINTS WHICH CONTAIN DATA MEMBERS AND METHODS ALL UNDER ONE BLOCK OF CODE.
//THIS IS ENCAPSULATION

import java.util.Scanner;

class Circle
{
    private double radius;


    Circle()
    {
        
        Scanner myObj = new Scanner(System.in);
        this.radius = myObj.nextDouble();
    }

    Circle(double r)
    {
        this.radius = r;
    }

    void showRadius()
    {
        System.out.println(radius);
    }
    


}

public class Encapsulation_in_JAVA {

    public static void main(String args[])
    {
        Circle c1 = new Circle();
        Circle c2= new Circle(9.5);

        c1.showRadius();
        c2.showRadius();
        System.out.println(c2.count);
        
    }
    
}
