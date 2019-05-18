
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

	int Line::getLineScore() 
	{
		if (isError())
			return 0;
		vector<int> framesScore;
		for (auto& f : frames)
			framesScore.emplace_back(f.getFrameScore());
		int score = 0;
		for (size_t i = 0; i < 10; ++i) {
			if (framesScore[i] >= 0) {
				score += framesScore[i];
				continue;
			}
			score += 10 + frames[i + 1].getFirstTryScore();
			if (framesScore[i] == -2)
			{
				if (framesScore[i + 1] == -2)
					score += frames[i + 2].getFirstTryScore();
				else
					score += frames[i + 1].getSecondTryScore();
			}
		}
		return(score);
	}

	bool Line::setFromString(const string& s)
	{
		size_t i = 0;
		errorStatus = EStatus::None;
		frames.clear();
		int addneeded = 0;
		while (i < s.size()) 
		{
			if (frames.size() >= 10 && addneeded == 0)
			{
				errorStatus = EStatus::BadLineSize;
				return isOk();
			}
			string currentFrame;
			currentFrame += s[i++];
			if (currentFrame == "X")
			{
				frames.emplace_back(currentFrame);
				if (frames.back().isError()) {
					errorStatus = EStatus::BadFrame;
					return isOk();
				}
				if (addneeded)
					--addneeded;
				if (frames.size() == 10)
					addneeded = 2;
				continue;
			}
			if (addneeded == 1) {
				frames.emplace_back(currentFrame, true);
				if (frames.back().isError()) {
					errorStatus = EStatus::BadFrame;
					return isOk();
				}
				--addneeded;
				continue;
			}
			if (i == s.size()) 
			{
				errorStatus = EStatus::BadLineSize;
				return isOk();
			}
			currentFrame += s[i++];
			frames.emplace_back(currentFrame);
			if (frames.back().isError()) {
				errorStatus = EStatus::BadFrame;
				return isOk();
			}
			if (addneeded)
				addneeded = 0;
			if ((frames.size() == 10) && (currentFrame[1]=='/'))
				addneeded = 1;
		}
		if (!ckeckSize())
			errorStatus = EStatus::BadLineSize;
		return isOk();
	}

	bool Line::ckeckSize()
	{
		if (frames.size() < 10 || frames.size() > 12)return false;
		for (auto& f : frames)
		{
			if (f.isError())
				return(false); // don't check for size in case of error
		}
		// check the score of the 10th frame
		int sc = frames[9].getFrameScore();
		if (sc > 0) // standard end: nu additional frame
			return (frames.size() == 10);
		if (sc == -1) // a Spare at the end: need one additional frame
			return (frames.size() == 11);
		// in case of strike: need 2 more tries
		if (frames.size() < 11)return false;
		sc = frames[10].getFrameScore();
		if (sc > -2) // if the first additional frame is not a Strike, 11 frames are the right size
			return (frames.size() == 11);
		// else we need 12 frames
		return (frames.size() == 12);
	}

	ostream& operator<<(ostream& os, const Line& l)
	{
		for (auto& f : l.frames)
			os << f;
		return(os);
	}
}
