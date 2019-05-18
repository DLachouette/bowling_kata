#include "Frame.h"

namespace bowling {

	Frame::Frame():IBloc()
	{
		additional = false;
		results = make_pair(0, 0);
	}

	Frame::Frame(const string& s, const bool& add):IBloc()
	{
		additional = false;
		results = make_pair(0, 0);
		setFromString(s, add);
	}

	Frame::~Frame()
	{
	}

	int Frame::getFrameScore()
	{
		if (results.first == 10)
			return(-2);
		int score = results.first + results.second;
		if (score == 10)
			return(-1);
		return score;
	}

	int Frame::getFirstTryScore()
	{
		return results.first;
	}

	int Frame::getSecondTryScore()
	{
		return results.second;
	}

	bool Frame::setFromString(const string& s, const bool& add)
	{
		additional = add;
		errorStatus = EStatus::None;
		if (s == "X") // particular case of the Strike
		{
			results = make_pair(10, 0);
			return isOk();
		}
		// control the length of the string
		if (add) // particular case of and additionnal frame
		{
			if (s.size() != 1)
			{
				errorStatus = EStatus::BadStringLength;
				return isOk();
			}
		}
		else
		{
			if (s.size() != 2)
			{
				errorStatus = EStatus::BadStringLength;
				return isOk();
			}
		}
		// analysing first char
		char c = s[0];
		if (c >= '1' && c <= '9') // this is a number
		{
			results.first = c - '0';
		}
		else if (c == '-') // this is a miss
		{
			results.first = 0;
		}
		else // any other case is an error
		{
			errorStatus = EStatus::BadFrameFirstChar;
			return isOk();
		}
		if (additional) // if this is an additional frame, the treatment is over
			return isOk();
		// analysing the second char
		c = s[1];
		if (c >= '1' && c <= '9') // this is a number
		{
			results.second = c - '0';
			if (results.first + results.second >= 10)
			{
				errorStatus = EStatus::BadFrameSecondChar;
				return isOk();
			}
		}
		else if (c == '-') // this is a miss
		{
			results.second = 0;
		}
		else if (c == '/') // this is a spare
		{
			results.second = 10 - results.first;
		}
		else // any other case is an error
		{
			errorStatus = EStatus::BadFrameSecondChar;
			return isOk();
		}
		return isOk();
	}

	ostream& operator<<(ostream& os, const Frame& f)
	{
		if (f.results.first == 10)
		{
			os << "X";
			return(os);
		}
		if (f.results.first == 0)
		{
			os << "-";
		}
		else
		{
			os << f.results.first;
		}
		if (f.additional)
			return(os);
		if (f.results.first + f.results.second == 10)
		{
			os << "/";
		}
		else if (f.results.second == 0)
		{
			os << "-";
		}
		else
		{
			os << f.results.second;
		}
		return(os);
	}

}