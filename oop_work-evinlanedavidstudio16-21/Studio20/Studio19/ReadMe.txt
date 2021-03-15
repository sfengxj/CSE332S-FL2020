1) Evin Jaff, Lane Bohrer, David Moon

2) The pointer needs to be deleted because it's dynamically allocated, but if it's left after the proxy ends then there will be a memory leak.

3) 