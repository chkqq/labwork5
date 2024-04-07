#include <iostream>
#include <limits>
#include "Vector3D.h"

using namespace std;

void DisplayMenu() {
    cout << "Menu:" << endl
        << "1. Calculate the length of a vector" << endl
        << "2. Normalize a vector" << endl
        << "3. Calculate dot product of two vectors" << endl
        << "4. Calculate cross product of two vectors" << endl
        << "5. Check if two vectors are equal" << endl
        << "6. Add two vectors" << endl
        << "7. Subtract two vectors" << endl
        << "8. Multiply a vector by a scalar" << endl
        << "9. Divide a vector by a scalar" << endl
        << "10. Exit" << endl;
}

bool InputErrorHandler()
{
    if (cin.fail()) 
    {
        cout << "Invalid input. Please enter numeric values." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return true;

    }
    return false;
}

void CalculateVectorLength(CVector3D& vec, double& x, double& y, double& z) 
{
    cout << "Enter the coordinates of the vector (x, y, z): ";
    cin >> x >> y >> z;
    if (InputErrorHandler())
    {
        vec = CVector3D(x, y, z);
        cout << "Length of the vector: " << vec.GetLength() << endl;
    }
}

void NormalizeVector(CVector3D& vec, double& x, double& y, double& z) 
{
    cout << "Enter the coordinates of the vector (x, y, z): ";
    cin >> x >> y >> z;
    if (InputErrorHandler())
    {
        vec = CVector3D(x, y, z);
        vec.Normalize();
        cout << "Normalized vector: " << vec << endl;
    }
}

void CalculateDotProduct(CVector3D& vec1, CVector3D& vec2, double& x, double& y, double& z) 
{
    cout << "Enter the coordinates of the first vector (x1, y1, z1): ";
    cin >> x >> y >> z;
    if (InputErrorHandler())
    {
        vec1 = CVector3D(x, y, z);
        cout << "Enter the coordinates of the second vector (x2, y2, z2): ";
        cin >> x >> y >> z;
        if (InputErrorHandler())
        {
            vec2 = CVector3D(x, y, z);
            cout << "Dot product of the vectors: " << DotProduct(vec1, vec2) << endl;
        }
    }
}

void CalculateCrossProduct(CVector3D& vec1, CVector3D& vec2, double& x, double& y, double& z) 
{
    cout << "Enter the coordinates of the first vector (x1, y1, z1): ";
    cin >> x >> y >> z;
    if (InputErrorHandler())
    {
        vec1 = CVector3D(x, y, z);
        cout << "Enter the coordinates of the second vector (x2, y2, z2): ";
        cin >> x >> y >> z;
        if (InputErrorHandler())
        {
            vec2 = CVector3D(x, y, z);
            cout << "Cross product of the vectors: " << CrossProduct(vec1, vec2) << endl;
        }
    }
    
}

void CheckVectorsEquality(CVector3D& vec1, CVector3D& vec2, double& x, double& y, double& z) 
{
    cout << "Enter the coordinates of the first vector (x1, y1, z1): ";
    cin >> x >> y >> z;
    if (InputErrorHandler())
    {      
        vec1 = CVector3D(x, y, z);
        cout << "Enter the coordinates of the second vector (x2, y2, z2): ";
        if (InputErrorHandler())
        {
            vec2 = CVector3D(x, y, z);
            if (vec1 == vec2)
            {
                cout << "The vectors are equal." << endl;
            }
            else
            {
                cout << "The vectors are not equal." << endl;
            }
        }

    }
}

void AddVectors(CVector3D& vec1, CVector3D& vec2, double& x, double& y, double& z) 
{
    cout << "Enter the coordinates of the first vector (x1, y1, z1): ";
    cin >> x >> y >> z;
    if (InputErrorHandler())
    {
        vec1 = CVector3D(x, y, z);
        cout << "Enter the coordinates of the second vector (x2, y2, z2): ";
        cin >> x >> y >> z;
        if (InputErrorHandler()) 
        {
            vec2 = CVector3D(x, y, z);
            cout << "Sum of the vectors: " << (vec1 + vec2) << endl;
        }
    }
}

void SubtractVectors(CVector3D& vec1, CVector3D& vec2, double& x, double& y, double& z) 
{
    cout << "Enter the coordinates of the first vector (x1, y1, z1): ";
    cin >> x >> y >> z;
    if (InputErrorHandler())
    {
        vec1 = CVector3D(x, y, z);
        cout << "Enter the coordinates of the second vector (x2, y2, z2): ";
        cin >> x >> y >> z;
        if (InputErrorHandler())
        {
            vec2 = CVector3D(x, y, z);
            cout << "Difference of the vectors: " << (vec1 - vec2) << endl;
        }
    }
}

void MultiplyVectorByScalar(CVector3D& vec, double& x, double& y, double& z, double scalar) 
{
    cout << "Enter the coordinates of the vector (x, y, z): ";
    cin >> x >> y >> z;
    if (InputErrorHandler())
    {
        vec = CVector3D(x, y, z);
        cout << "Enter the scalar: ";
        cin >> scalar;
        if (InputErrorHandler()) 
        {
            cout << "Product of the vector and the scalar: " << (vec * scalar) << endl;
        }
    }
}

void DivideVectorByScalar(CVector3D& vec, double& x, double& y, double& z, double scalar)
{
    cout << "Enter the coordinates of the vector (x, y, z): ";
    cin >> x >> y >> z;
    if (InputErrorHandler())
    {
        vec = CVector3D(x, y, z);
        cout << "Enter the scalar: ";
        cin >> scalar;
        if (InputErrorHandler()) 
        {
            cout << "Division of the vector by the scalar: " << (vec / scalar) << endl;
        }
    }
}

int main() 
{
    int choice = 0;
    CVector3D vec1, vec2;
    double x, y, z, scalar;
    scalar = 0;
    while (choice != 10)
    {
        
        cout << "> ";
        cin >> choice;

        if (cin.fail())
        {
            cout << "Invalid command. Type 'help' or '0' for the list of commands." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (choice) 
        {
        case 0:
            DisplayMenu();
            break;
        case 1:
            CalculateVectorLength(vec1, x, y, z);
            break;
        case 2:
            NormalizeVector(vec1, x, y, z);
            break;
        case 3:
            CalculateDotProduct(vec1, vec2, x, y, z);
            break;
        case 4:
            CalculateCrossProduct(vec1, vec2, x, y, z);
            break;
        case 5:
            CheckVectorsEquality(vec1, vec2, x, y, z);
            break;
        case 6:
            AddVectors(vec1, vec2, x, y, z);
            break;
        case 7:
            SubtractVectors(vec1, vec2, x, y, z);
            break;
        case 8:
            MultiplyVectorByScalar(vec1, x, y, z, scalar);
            break;
        case 9:
            DivideVectorByScalar(vec1, x, y, z, scalar);
            break;
        case 10:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid command. Type 'help' or '0' for the list of commands." << endl;
            break;
        }
    }

    return 0;
}
