#include "bowling.h"

bowling::Bowling::Bowling():os(cout.rdbuf())
{
}

bowling::Bowling::Bowling(int argc, char** argv) : os(cout.rdbuf())
{
	parseInput(argc, argv);
}

bowling::Bowling::~Bowling()
{
	os.rdbuf(cout.rdbuf());
	if (file.is_open())
		file.close();
}

void bowling::Bowling::run()
{
	if (lines.empty()) {
		os << "No Input lines " << endl;
	}
	for (auto& l : lines)
	{
		os << l;
		if (l.isOk())
		{
			os << " score: " << l.getLineScore() << endl;
		}
		else
		{
			os << " : ERROR in the given line" << endl;
		}
	}
}

void bowling::Bowling::parseInput(int argc, char** argv)
{
	if (argc == 1) // when no arguments is given
	{
		printHelp();
		return;
	}
	string output = "", input = "", inputfile = "";
	for (int i = 1; i < argc; ++i) {
		if (string(argv[i]) == "-h")
		{
			printHelp();
			return;
		}
		if (string(argv[i]) == "-o")
		{
			if (i + 1 == argc || argv[i + 1][0] == '-') // parameter error
			{
				os << "ERROR: option '-o' need an argument" << endl;
				printHelp();
				return;
			}
			++i;
			output = argv[i];
			continue;
		}
		if (string(argv[i]) == "-i")
		{
			if (i + 1 == argc || argv[i + 1][0] == '-') // parameter error
			{
				os << "ERROR: option '-i' need an argument" << endl;
				printHelp();
				return;
			}
			if (input != "")
			{
				os << "ERROR: please not define both input file and input line." << endl;
				printHelp();
				return;
			}
			++i;
			inputfile = argv[i];
			continue;
		}
		if (input != "")
		{
			os << "ERROR: please define only one bowling." << endl;
			os << " for multiple lines please use an input file" << endl;
			printHelp();
			return;
		}
		if (inputfile != "")
		{
			os << "ERROR: please not define both input file and input line." << endl;
			printHelp();
			return;
		}
		input = argv[i];
	}
	if (input == "" && inputfile == "") {
		os << "ERROR: no input have been defined" << endl;
		printHelp();
		return;
	}
	if (output != "")
	{
		file.open(output, ios::out);
		if (!file.is_open()) {
			os << "ERROR while open the output file '" << output << "' check your credentials of sdisk size." << endl;
			return;
		}
		os.rdbuf(file.rdbuf());
	}

	if (input != "") {
		lines.emplace_back(input);
		return;
	}
	ifstream ifs(inputfile);
	if (!ifs.is_open())
	{
		os << "ERROR: could not open input file '" << inputfile << "'" << endl;
	}
	while (ifs >> input)
	{
		lines.emplace_back(input);
	}
}

void bowling::Bowling::printHelp()
{
	os << " BOWLING KATA USAGE " << endl;
	os << "--------------------" << endl;
	os << "bowling_kata [-h] [-o OUTPUT] BOWLING_LINE" << endl;
	os << "bowling_kata [-h] [-o OUTPUT] -i INPUT" << endl << endl;
	os << "BOWLING_LINE   is a simple string representing a bowling line" << endl;
	os << "OUTPUT         optional, allow to define an output file " << endl;
	os << "               where to print results" << endl;
	os << "INPUT          defines a text input file where each line " << endl;
	os << "               is a string representing a bowling line" << endl << endl;
	os << "A bowling line consists of a sequence of 10 frames" << endl;
	os << "In each frame, the bowler gets up to two tries to knock down all the pins. " << endl;
	os << "If in two tries, he fails to knock them all down, his score for that frame " << endl;
	os << "    is the total number of pins knocked down in his two tries." << endl;
	os << "If in two tries he knocks them all down, this is called a \"spare\" and his " << endl;
	os << "    score for the frame is ten plus the number of pins knocked down on his " << endl;
	os << "    next throw (in his next turn)." << endl;
	os << "If on his first try in the frame he knocks down all the pins, this is called" << endl;
	os << "    a \"strike\". His turn is over, and his score for the frame is ten plus " << endl;
	os << "    the simple total of the pins knocked down in his next two rolls." << endl;
	os << "If he gets a spare or strike in the last (tenth) frame, the bowler gets to " << endl;
	os << "    throw one or two more bonus balls, respectively. These bonus throws are" << endl;
	os << "    taken as part of the same turn. If the bonus throws knock down all the " << endl;
	os << "    pins, the process does not repeat: the bonus throws are only used to " << endl;
	os << "    calculate the score of the final frame." << endl << endl;
	os << "The game score is the total of all frame scores. More info on the rules at: " << endl;
	os << "   http://www.topendsports.com/sport/tenpin/scoring.htm." << endl << endl;
	os << "When scoring \"X\" indicates a strike, \"/\" indicates a spare, \"-\" indicates a miss" << endl;
}

