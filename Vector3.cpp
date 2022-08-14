#include <iostream>
#include <cmath>
#include <iostream>
using namespace std;

struct Vector3D
{
    float x,y,z;

    Vector3D() = default;

    Vector3D(float a, float b, float c)
    {
     x = a;
     y = b;
     z = c;
    }

    float& operator [](int i)
    {
        return ((&x)[i]);
    }

    const float& operator [](int i) const
    {
        return ((&x)[i]);
    }

    Vector3D& operator *=(float s)
    {
        x *= s;
        y *= s;
        z *= s;

        return (*this);
    }

    Vector3D& operator /=(float s)
    {
        s = 1.0F / s;
        x *= s;
        y *= s;
        z *= s;

        return (*this); 
    }
    Vector3D& operator +=(const Vector3D& v)
    {
        x += v.x;
        y += v.y;
        z += v.z;
        return (*this);
    }
    Vector3D& operator -=(const Vector3D v)
    {
        x -= v.x;
        y -=v.y;
        z -= v.z;
        return (*this);
    }
};

inline Vector3D operator *(const Vector3D& v, float s)
{
    return (Vector3D(v.x *s, v.y * s, v.z * s));
}
inline Vector3D operator /(const Vector3D& v, float s)
{
    s = 1.0F / s;
    return (Vector3D(v.x * s, v.y * s, v.z * s));
}
inline Vector3D operator -(const Vector3D& v)
{
    return (Vector3D(-v.x, -v.y, -v.z));
}
inline float Magnitude(const Vector3D& v)
{
    return (sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
}
inline Vector3D Normalize(const Vector3D& v)
{
    return (v / Magnitude(v));
}
inline Vector3D operator +(const Vector3D& a, const Vector3D& b)
{
    return (Vector3D(a.x + b.x, a.y + b.y, a.z + b.z));
}
inline Vector3D operator -(const Vector3D& a, const Vector3D& b)
{
    return (Vector3D(a.x - b.x, a.y - b.y, a.z - b.z));
}
 ostream& operator<<(ostream& os, const Vector3D& v) {
    return os << "x: " << v.x << ", "
              << "y: " << v.y << ", "
              << "z: " << v.z << ", " << '\n';
}

void VectorTest()
{
    Vector3D vectorA;
    vectorA.x = (1.0f);
    vectorA.y = (2.0f);
    vectorA.z = (3.0f);
    Vector3D vectorB;
    vectorB.x = (1.0f);
    vectorB.y = (2.0f);
    vectorB.z = (3.0f);
    Vector3D vectorAdd = vectorA + vectorB;
    cout << "Vector A + Vector B = " << vectorAdd << '\n';
    Vector3D vectorSub = vectorA - vectorB;
    cout << "Vector A - Vector B = " << vectorSub << '\n';
    Vector3D vectorMult = vectorA * 2;
    cout << "Vector A * 2 = " << vectorMult << '\n';
    Vector3D vectorDiv = vectorA / 2;
    cout << "Vector A / 2 = " << vectorDiv << '\n';
    float vectorMag = Magnitude(vectorA);
    cout << "Vector A Magnitude = " << vectorMag << '\n';
    Vector3D vectorNorm = Normalize(vectorA);
    cout << "Vector A Normalized  = " << vectorNorm << '\n';
}

int main()
{
    VectorTest();
    cout << "Compiled Successfully" << '\n';
    return 0;
}