%: %.cpp rss.cpp rss.h
	g++ `xml2-config --cflags` -O2 -g $< rss.cpp `xml2-config --libs` -lm -o $@
