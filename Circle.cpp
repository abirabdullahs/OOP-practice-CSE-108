#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

// Circle class definition
class Circle
{
    double x, y;   // Coordinates of the center of the circle
    double radius; // Radius of the circle
    char *name;    // Name of the circle
    char *color;   // Color of the circle

public:
    // Default constructor to initialize a circle with default values
    Circle()
    {
        x = 0;
        y = 0;
        radius = 1;
        name = new char[10];
        color = new char[10];
        strcpy(name, "default");
        strcpy(name, "default");
    }

    // Constructor with parameters for a circle's name, coordinates, and radius
    Circle(const char *Name, double X, double Y, double R)
    {
        x = X;
        y = Y;
        radius = R;
        name = new char[10];
        color = new char[10];

        strcpy(name, Name);
        cout << name << endl;
    }

    // Create a new circle from an existing one
    Circle(const Circle &c)
    {
        radius = c.radius;
        x = c.x;
        y = c.y;
        name = new char[10];
        color = new char[10];
        strcpy(name, c.name);
        strcpy(color, c.color);
    }

    // Method to calculate and return the area of the circle
    double area()
    {

        return 3.1416 * radius * radius;
    }
    // Method to calculate and return the circumference of the circle
    double circumference()
    {

        return 2 * 3.1416 * radius;
    }

    // Method to check if a point (x, y) is inside the circle
    void contains(double X, double Y)
    {

        double value = (x - X) * (x - X) + (y - Y) * (y - Y) - radius * radius;
        if (value > 0)
            cout << "ponit in outside" << endl;
        if (value == 0)
            cout << "ponit in circle body" << endl;
        if (value > 0)
            cout << "point in inside" << endl;
    }

    // Method to check if another circle is inside, intersects, or outside this circle
    void contains(Circle c)
    {

        double value = sqrt((x - c.x) * (x - c.x) + (y - c.y) * (y - c.y));
        double rAdd = radius + c.radius;
        double rSub = (radius - c.radius >= 0) ? radius - c.radius : c.radius - radius;

        if (value > rAdd)
            cout << "circle is outside" << endl;
        else if (value < rAdd)
            cout << "circle is on the intersect" << endl;
        else if (value < rSub)
            cout << "circle is inside" << endl;
    }

    // Method to translate the circle's position by a distance (dx, dy)
    void translate(double dx, double dy)
    {

        x = x + dx;
        y = y + dy;
    }

    // Method to translate the circle in a given direction (up, down, left, right)
    void translate(string dir, double dist)
    {
        dir == "up" && (y = y + dist);
        dir == "down" && (y = y - dist);
        dir == "right" && (x = x + dist);
        dir == "left" && (x = x - dist);
    }

    // Method to scale the circle by a given factor
    void scale(double factor)
    {
        radius = radius * factor;
    }

    // Method to display circle properties (name, center, radius, area, cirumference, color.)
    void display()
    {
        cout << "name  : " << name << endl;
        cout << "center  : (" << x << "," << y << ")" << endl;
        cout << "radius  : " << radius << endl;
        cout << "area  : " << area() << endl;
        cout << "cirumference  : " << circumference() << endl;
        cout << "color  : " << color << endl;
    }

    // Setter method for the name of the circle
    void setName(const char *Name)
    {

        strcpy(name, Name);
    }

    // Setter method for the color of the circle
    void setColor(const char *Color)
    {

        strcpy(color, Color);
    }

    // Getter method for the circle's name
    char *getName()

    {
        cout << name << endl;
        return name;
    }

    // Getter method for the circle's color
    char *getColor()
    {
        cout << color << endl;
        return color;
    }

    // Destructor to clean up dynamically allocated memory
    ~Circle()
    {
        delete name;
        delete color;
    }
};

// Main function to test the Circle class
int main()
{
    Circle c1("C1", 0, 0, 5); // Create a circle with name C1 at (0,0) with radius 5
    Circle c2("C2", 6, 4, 1);
    Circle c3("C3", 2, 2, 3);
    Circle c4("C4", 1, 2, 2);

    c1.area();

    c1.setColor("Red"); // Set color of circle C1 to Red

    c2.setColor("Blue");

    c1.display(); // Display properties of circle C1
    cout << endl;
    c2.display();
    cout << endl;

    // Test
    c1.contains(3, 5); // Point (3, 5) should be outside circle C1
    c1.contains(2, 2); // Point (2, 2) should be inside circle C1
    c1.contains(c2);   // Check if circle C2 is inside, intersects, or outside circle C1
    c1.contains(c3);
    c1.contains(c4);

    // Translate circle C1 by (2, 3)
    c1.translate(2, 3);
    c1.display();
    cout << endl;

    // Translate circle C1 upwards by 2 units
    c1.translate("up", 2);
    c1.display();
    cout << endl;

    // Scale circle C1 by a factor of 2
    c1.scale(2);
    c1.display();
    return 0;
}

// Expected Output:
/*
Circle Name: C1
Center: (0, 0)
Radius: 5
Area: 78.5397
Circumference: 31.4159
Color: Red

Circle Name: C2
Center: (6, 4)
Radius: 1
Area: 3.14159
Circumference: 6.28318
Color: Blue

Point (3, 5) is outside the circle C1.
Point (2, 2) is inside the circle C1.
Circle C2 is outside the circle C1.
Circle C3 intersects with the circle C1.
Circle C4 is inside the circle C1.
Circle Name: C1
Center: (2, 3)
Radius: 5
Area: 78.5397
Circumference: 31.4159
Color: Red

Circle Name: C1
Center: (2, 5)
Radius: 5
Area: 78.5397
Circumference: 31.4159
Color: Red

Circle Name: C1
Center: (2, 5)
Radius: 10
Area: 314.159
Circumference: 62.8318
Color: Red
*/