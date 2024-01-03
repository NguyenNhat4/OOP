/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
struct
###End banned keyword*/
#include <iostream>
using namespace std;

template <class T>
class MyArray
{
private:
    T *pElement;
    int iLength;
    string name;
    int iNumber; // thêm số lượng phần tử của mảng, số đối tượng(giá trị) thực đang chứa trong mảng

public:
    // ###INSERT CODE HERE -

    MyArray(string s = "");        // thêm đối mặc định cho 3.2
    MyArray(int n, string s = ""); // thêm đối mặc định cho 3.2
    int GetLength() const;
    T &ElementAt(const int &iIndex);  // nếu bỏ & thì hàm chỉ return giống như trả về 1 giá trị để đọc, chứ không truy cập vào vùng nhớ của phần thử để gán
    T &operator[](const int &iIndex); // Kết quả trả về là tham chiếu để phần tử trả về, có thể đứng ở bên trái của phép toán gán.
    // bổ sung cho bài 2
    MyArray(int n, T value, string name = ""); // thêm đối mặc định cho 3.2
    void PrintArray() const;
    T ElementAt(const int &iIndex) const;  // phiên bản dành riêng cho đối tượng hằng
    T operator[](const int &iIndex) const; // phiên bản dành riêng cho đối tượng hằng
    // bổ sung cho bài 3
    ~MyArray();
    MyArray(const MyArray &b, string s = ""); // thêm đối mặc định cho 3.2
    MyArray &operator=(const MyArray &b);     // toán tử gán
    // bổ sung cho bài 4
    void InputArray(int n);
    void InputArray();
    int GetSize();
    template <class u>
    friend ostream &operator<<(ostream &os, MyArray<u> &a);
    template <class u>
    friend istream &operator>>(istream &in, MyArray<u> &a);
};
template <class T>
int MyArray<T>::GetSize()
{
    return iNumber;
}

template <class T>
void MyArray<T>::InputArray(int n)
{
    if (n <= 0)
    {
        cout << "\nSo luong phan tu khong hop le, ket thuc viec nhap";
        return;
    }
    if (pElement == nullptr)
    {
        return;
    }

    if (n > iLength)
    {
        cout << "\nSo luong phan tu (" << n << ") nhieu hon suc chua cua mang (" << iLength << ") nen chi nhap duoc " << iLength << " gia tri";
        iNumber = iLength;
    }
    else
    {
        iNumber = n;
    }

    if (name == "")
    {
        cout << "\nNhap mang voi " << iNumber << " gia tri: ";
    }
    else
    {
        cout << "\nNhap mang " << name << " voi " << iNumber << " gia tri: ";
    }

    for (size_t i = 0; i < iNumber; i++)
    {
        cin >> pElement[i];
    }
}

template <class T>
T &MyArray<T>::ElementAt(const int &x)
{
    if (x < 0 || x >= iLength)
    {
        cout << "\nLoi: truy xuat phan tu ngoai pham vi mang";
    }
    return pElement[x];
}
template <class T>
int MyArray<T>::GetLength() const
{
    return iLength;
}

template <class T>
T MyArray<T>::operator[](const int &x) const
{
    return ElementAt(x);
}
template <class T>
T &MyArray<T>::operator[](const int &x)
{
    return ElementAt(x);
}
template <class T>
MyArray<T> &MyArray<T>::operator=(const MyArray &b)
{

    if (pElement == nullptr)
    {
        cout << "\nCap phat bo nho truoc khi gan";
        iLength = b.iLength;
        pElement = new T[iLength];
    }
    if (iLength != b.iLength)
    {
        cout << "\nPhep gan khong tuong thich, khong gan duoc";
        return *this;
    }
    iNumber = b.iNumber;
    for (int i = 0; i < iLength; i++)
    {
        ElementAt(i) = b.pElement[i];
    }

    return *this;
}

template <class T>
void MyArray<T>::PrintArray() const
{
    if (name == "")
    {
        cout << "\nXuat mang: ";
    }
    else
    {
        cout << "\nXuat mang " << name << ": ";
    }

    if (iLength == 0 || iNumber == 0)
    {
        cout << "Mang rong";
        return;
    }
    for (size_t i = 0; i < iNumber; i++)
    {
        cout << pElement[i] << " ";
    }
}
template <class T>
istream &operator>>(istream &in, MyArray<T> &a)
{
    a.InputArray(a.iLength);
    return in;
}

template <class T>
ostream &operator<<(ostream &cin, MyArray<T> &a)
{
    a.PrintArray();
    return cin;
}

template <class T>
MyArray<T>::MyArray(string s) : pElement(nullptr), iLength(0), name(s) {}

template <class T>
MyArray<T>::MyArray(int a, string s)
{
    iNumber = 0;
    name = s;
    if (a <= 0)
    {
        iLength = 0;

        pElement = nullptr;
        cout << "\nLoi: chieu dai mang la so am";
    }
    if (a > 0)
    {

        iLength = a;
        pElement = new T[a];
    }
}
template <class T>
MyArray<T>::MyArray(int a, T b, string s)
{

    if (a <= 0)
    {

        name = s;
        iNumber = iLength = 0;
        pElement = nullptr;
        cout << "\nLoi: chieu dai mang la so am";
    }
    else
    {
        name = s;
        iNumber = iLength = a;
        pElement = new T[iLength];
        for (size_t i = 0; i < iLength; i++)
        {
            pElement[i] = b;
        }
    }
}

template <class T>
MyArray<T>::MyArray(const MyArray &p, string s) : iLength{p.iLength}, name{s}, iNumber{p.iNumber}
{

    pElement = new T[iLength];
    for (size_t i = 0; i < iLength; i++)
    {
        pElement[i] = p.pElement[i];
    }
}

template <class T>
MyArray<T>::~MyArray()
{
    if (pElement != nullptr)
    {
        delete[] pElement;
    }
}

int main()
{
    string test;
    cin >> test;

    cout << "\nNhap kich thuoc cua mang b: ";
    int m;
    cin >> m;
    MyArray<float> b(m, "b");
    cout << "\nNhap so luong phan tu cua mang b: ";
    int n;
    cin >> n;        // user nhập theo ý thích
    b.InputArray(n); /* b có kích thước là m nhưng user muốn nhập n giá trị, có 2 tình huống xảy ra:
                        TH1: n<m, tiếp tục nhập n giá trị
                        TH2: n>m, số lượng nhiều hơn sức chứa, thông báo và cho nhập m giá trị
                    */
    cout << b;
    cout << "\nSo luong phan tu cua mang b: " << b.GetSize();
    cout << "\nKich thuoc cua mang b: " << b.GetLength();

    return 0;
}
