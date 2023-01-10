#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Square.h"
#include "Movable.h"

#include <string>

using namespace std;
using std::cout;

int main()
{
	string userCommand;
	vector <Shape*> shapes;     // shapes containers.
	vector <string> parameters; // command parameters.


	while (userCommand.compare("exit") != 0)
	{
		parameters.clear();
		userCommand.clear();


		cout << "Enter the command: ";

		getline(cin, userCommand);

		char* cstr = new char[userCommand.length() + 1];

		strcpy_s(cstr, userCommand.length() + 1, userCommand.c_str());

		// Tokenizer
		char* token = strtok_s(cstr, " ", &cstr);
		while (token != NULL)
		{
			parameters.push_back(token);
			token = strtok_s(NULL, " ", &cstr);
		}

		cstr = nullptr;
		token = nullptr;

		// If nothing entered was entered,
		// return back to start of loop to retrieve new command.
		if (parameters.size() == 0)
		{
			continue;
		}

		string command = parameters[0];
		int x, y = 0;
		if (parameters.size() >= 3)
		{
			try
			{
				x = stoi(parameters[1]);
				y = stoi(parameters[2]);
			}
			catch (exception)
			{
				cout << "Invalid coordinate parameter entered" << endl;
				continue;
			};
		}
		
		if (command.compare("addR") == 0) {

			if (parameters.size() != 5)
			{
				cout << "Invalid number of parameters" << endl;
				continue;
			}

			int h, w = 0;
			try
			{
				h = stoi(parameters[3]);
				w = stoi(parameters[4]);
			}
			catch (exception)
			{
				cout << "Invalid parameter given" << endl;
				continue;
			}

			Rectangle* r = new Rectangle(x, y, h, w);
			shapes.emplace_back(r);
			cout << *r << endl;
			//r = nullptr;
		}
		else if (command.compare("addS") == 0) {

			if (parameters.size() != 4)
			{
				cout << "Invalid number of parameters" << endl;
				continue;
			}

			int e = 0;
			try
			{
				e = stoi(parameters[3]);
			}
			catch (exception)
			{
				cout << "Invalid parameter given" << endl;
				continue;
			}

			Square* s = new Square(x, y, e);
			shapes.push_back(s);
			cout << *s << endl;
		}
		else if (command.compare("addC") == 0) {

			if (parameters.size() != 4)
			{
				cout << "Invalid number of parameters" << endl;
				continue;
			}

			int r = 0;
			try
			{
				r = stoi(parameters[3]);
			}
			catch (exception)
			{
				cout << "Invalid parameter given" << endl;
				continue;
			}

			Circle* c = new Circle(x, y, r);
			shapes.push_back(c);
			cout << *c << endl;
		}
		else if (command.compare("scale") == 0) {
			if (parameters.size() != 4)
			{
				cout << "Invalid number of parameters" << endl;
				continue;
			}

			int shapeIndex, xScale, yScale = 0;

			try
			{
				shapeIndex = stoi(parameters[1]) - 1;
				xScale = stoi(parameters[2]);
				yScale = stoi(parameters[3]);
			}
			catch (exception)
			{
				cout << "Invalid parameter given" << endl;
				continue;
			}

			if (shapeIndex >= shapes.size())
			{
				cout << "Invalid index; Shape does not exist." << endl;
				continue;
			}

			Movable* shape = dynamic_cast<Movable*>(shapes[shapeIndex]);
			shape->scale(xScale, yScale);
			cout << *shapes[shapeIndex] << endl;
		}
		else if (command.compare("move") == 0) {

			if (parameters.size() != 4)
			{
				cout << "Invalid number of parameters" << endl;
				continue;
			}

			int shapeIndex, newX, newY = 0;

			try
			{
				shapeIndex = stoi(parameters[1]) - 1;
				newX = stoi(parameters[2]);
				newY = stoi(parameters[3]);
			}
			catch (exception)
			{
				cout << "Invalid parameter given" << endl;
				continue;
			}

			if (shapeIndex >= shapes.size())
			{
				cout << "Invalid index; Shape does not exist." << endl;
				continue;
			}

			Movable* shape = dynamic_cast<Movable*>(shapes[shapeIndex]);
			shape->move(newX, newY);
			cout << *shapes[shapeIndex];
		}
		else if (command.compare("display") == 0) {
			cout << "There are " << shapes.size() << " shapes stored.\n";
			cout << "Displaying all shapes:" << endl;
			for (Shape* s : shapes)
			{
				cout << *s << endl;
			}
		}
		else if (command.compare("clear") == 0) {
			for (Shape* s : shapes)
			{
				delete s;
			}
			shapes.clear();
		}
		else if (command.compare("exit") == 0) {
			continue;
		}
		else {
			cout << "Unrecognised command" << endl;
		}

		cout << endl << endl;

	}

	cout << "Press any key to continue...";
	std::getchar();

	return 0;
}