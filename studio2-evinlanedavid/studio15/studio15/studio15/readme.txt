1) Evin, Lane, David

2) Code:
int a = 9;
int b = 32;

int& c = a;
int& d = b;

int && e = a + b;
//    int&& f = c; invalid line
int && f = a * b;

Terminal output:
a: 9
b: 32
c: 9
d: 32
e: 41
f: 288

3) Additional code:

int g = e;
int h = 0;
h = e;
int i = move(e);

Terminal output:

4) detector objects are being allocated and de-allocated correctly
We had to write an operator overload for == (comparing pointers, not ids)

detector constructor: 012FFEB0  3435973836
detector copy constructor: 012FFEA4  3435973836
detector destructor: 012FFEA4  3435973836
detector destructor: 012FFEB0  3435973836

