#pragma once

#include <iostream>

class A {
public:
	A();
	~A();
	virtual void grass();

};


class B : public A{
public:
	B();
	~B();
	virtual void grass();
};
