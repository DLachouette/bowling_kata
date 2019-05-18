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
	}

	Frame::~Frame()
	{
	}

	int Frame::getFrameScore()
	{
		return 0;
	}

	int Frame::getFirstTryScore()
	{
		return 0;
	}

	bool Frame::setFromString(const string& s, const bool& add)
	{
		return false;
	}

}