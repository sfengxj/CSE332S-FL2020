#pragma once

class detector {
	unsigned int ID;
	static unsigned int detector_count;
public:
	detector();
	~detector();

	unsigned int getID();
};


class wrapper {
	detector* d;
	bool b;
public:
	wrapper();
	~wrapper();
};