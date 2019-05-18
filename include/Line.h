#pragma once

#include "Frame.h"
#include <vector>

namespace bowling {

	class Line :public IBloc {
	public:
		/// <summary>Default constructor</summary>
		Line();
		/// <summary>Constructor by an input string</summary>
		Line(const string& input);

		/// <summary> Destructor </summary>
		virtual ~Line();

		/// <summary>compute the score for the given line<summary>
		/// <returns>the score of the line</returns>
		int getLineScore()const;

		/// <summary> defines the line results based on the input string</summary>
		/// <param name='s'>the input string</param>
		/// <returns><c>true</c>if no error where found, false in case of an error</returns>
		///
		/// the string is split into small string for each frame
		/// error are returned if any frame definition is in error (see Frame::setFromString for details)
		/// error are returned if the number of frame mismatch the rules:
		///     standard line is 10 frames long.
		///     in case of a spare at the 10th frame, the line is then 11 frames long
		///     in case of a strike at the 10th frame, the line is then 12 frames long
		bool setFromString(const string& s);


		/// <summary>output stream operator</summary>
		/// <param name='os'> input stream</param>
		/// <param name='l'> line to stream</param>
		/// <returns>output stream</returns>
		friend ostream& operator<<(ostream& os, const Line& l);
	private:
		/// <summary>helper function that checks if the number of frame correspond to the bowling rules</summary>
		/// <returns><c>true</c> if the size is in good shape</returns>
		bool ckeckSize();
		/// <summary>list of the frames for this line</summary>
		vector<Frame> frames;
	};

}
