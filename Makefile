
ed: main.cpp lib/string.o lib/line_node.o lib/text_list.o lib/editor_ui.o
	g++ main.cpp lib/string.o lib/line_node.o lib/text_list.o lib/editor_ui.o -o ed

string: lib/string.hpp lib/string.cpp
	g++ lib/string.cpp -c -o lib/string.o

line_node: lib/line_node.hpp lib/line_node.cpp
	g++ lib/line_node.cpp -c -o lib/line_node.o

text_list: lib/text_list.hpp lib/text_list.cpp
	g++ lib/text_list.cpp -c -o lib/text_list.o

editor_ui: lib/editor_ui.hpp lib/editor_ui.cpp
	g++ lib/editor_ui.cpp -c -o lib/editor_ui.o
