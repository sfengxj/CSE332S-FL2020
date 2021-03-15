1. Evin Jaff (473830), Lane Bohrer (475736), David Moon 

push_back vs push_forward
forward list needs to be pushed forward.
list: push forward or backward
deque: push forward or backward

to use std::sort, random access is needed. therefore, it will only work for vectors and deques.
to use std::reverse, random access or previous pointers are needed. the only one that can't use 
	reverse is a foward list.