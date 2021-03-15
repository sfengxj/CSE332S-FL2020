#pragma once

class detector {
	unsigned int ID;
	static unsigned int detector_count;
	bool operator ==(const detector& a);
public:
	detector();
	detector(const detector& d);
	detector& operator=(const detector& a);
	detector(detector&& d);
	detector& operator=(const detector && a);
	~detector();
	unsigned int getID();
	unsigned int get_detector_count();

};


class wrapper {
	detector* d;
	bool b;
public:
	wrapper();
	~wrapper();
};