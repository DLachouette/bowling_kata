
#include "Line.h"

namespace bowling {

	Line::Line() : IBloc() 
	{
		frames.clear();
	}

	Line::Line(const string& input) : IBloc() 
	{
		frames.clear();
		setFromString(input);
	}

	Line::~Line()
	{
	}

	int Line::getLineScore() const
	{
		return 0;
	}

	bool Line::setFromString(const string& s)
	{
		return false;
	}

	bool Line::ckeckSize()
	{
		return false;
	}

	ostream& operator<<(ostream& os, const Line& l)
	{
		for (auto& f : l.frames)
			os << f;
		return(os);
	}
}
