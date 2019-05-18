#pragma once

#include "Line.h"
#include <fstream>

namespace bowling {
	/// <summary>Main class of the bowling application</summary>
	class Bowling {
	public:
		/// <summary>Default constructor</summary>
		Bowling();
		/// <summary>constructor with program argument</summary>
		/// <param name='argc'>number of argument</param>
		/// <param name='argv'>list of arguments</param>
		Bowling(int argc, char** argv);
		/// <summary>Destructor</summary>
		~Bowling();
		/// <summary>Main program execution</summary>
		void run();
	private:
		/// <summary>Parse the input parameters</summary>
		/// <param name='argc'>number of argument</param>
		/// <param name='argv'>list of arguments</param>
		void parseInput(int argc,char** argv);
		/// <summary>Print a help message in the console</summary>
		void printHelp();

		/// <summary>List of bowling line to score</summary>
		vector<Line> lines;

		/// <summary>File stream for outpout</summary>
		ofstream file;
		/// <summary>Output stream</summary>
		ostream os;
	};

}
