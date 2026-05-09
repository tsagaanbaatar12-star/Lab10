# Хийх ажил: 
Template буюу загвар класс ашиглан дурын төрлийн өгөгдөл хадгалдаг жагсаалтыг зохион байгуул.
1. Жагсаалт нь дараах функцуудтай байна:

void add(T t); // жагсаалтын сүүлд элемент нэмнэ
void insert(T t, int index); // index - дүгээрт элеменет оруулна
T get(int index); // i-р элементийн утгыг буцаана
void delete(int index); // i -р элементийг устгана
int length();    //жагсаалтын уртыг буцаана

2. Дээрх загвар класс ашигласан жагсаалт болон Lab07-д хийсэн дүрсийн классуудыг ашиглан дараах даалгаврыг гүйцэтгэнэ.

Үүнд: Санамсаргүй талын урттай, санамсаргүй тооны (20-30 орчим) гурвалжин, дөрвөлжин, тойргийн объектуудыг үүсгэ. Үүсгэсэн гурвалжин дөрвөлжин тойрог дүрсүүдийг төрөл харгалзалгүйгээр талбайгаар нь эрмбэлж хэвлэ.

C++ хэлэнд template ашигласан Vector гэдэг класс байдаг ба дараах хэлбэрээр ашигладаг. Дээх даалгаварын үр дүнд дараах жишээтэй ижил ашиглаж болохуйц LinkedList үүсгэнэ.


## Динамик өгөгдлийн цувааг дараах жишээнд харуулсан динамик бүтцэд хадгалж болно.

Загвар класст Primitive өгөгдлийн төрөл ашигласан жишээ.
#include <vector>
#include <iostream>
int main()
{
vector<int> list_of_ints; // Create new list
list_of_ints.push_back(3); // Insert item
list_of_ints.push_back(23);
cout << list_of_ints.size() << endl; // How many?
cout << list_of_ints[1] << endl; // Get item number 1
return 0;
}


Загвар класст Үүсмэл өгөгдлийн төрөл буюу класс ашигласан жишээ.
#include <vector>
#include <iostream>
int main()
{
Circle c1, c2, c3;
Triangle t1, t2, t3;
Square s1, s2, s3;

vector<2D> list_of_shapes; // Create new list

list_of_shapes.push_back(c1); // Insert item circle
list_of_shapes.push_back(c2); // Insert item circle
list_of_shapes.push_back(c3); // Insert item circle

list_of_shapes.push_back(t1); // Insert item triangle
list_of_shapes.push_back(t2); // Insert item triangle
list_of_shapes.push_back(t3); // Insert item triangle

list_of_shapes.push_back(s1); // Insert item square
list_of_shapes.push_back(s2); // Insert item square
list_of_shapes.push_back(s3); // Insert item square

cout << list_of_shapes.size() << endl; // How many?
cout << list_of_shapes[1].print() << endl; // Get item number 1 and calls member function
return 0;
}