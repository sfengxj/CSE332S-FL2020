#pragma once

#include <iostream>

class Socks {
	int x;
	int y;
	const int fixed;
	
	
	public:
		Socks();
		int getX() const;
		int getY() const;
		int getFixed() const;
		void setX(int a);
		void setY(int a);
		void setFixed(int a);
		Socks retsocks();
	

};