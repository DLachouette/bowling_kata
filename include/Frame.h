#pragma once

#include "IBloc.h"
#include <iostream>
#include <utility>

namespace bowling {

	///<summary>Class to handle a single bowling frame</summary>
	class Frame :public IBloc {
	public:
		/// <summary>default constructor</summary>
		Frame();

		/// <summary>Constructor using input string</summary>
		/// <param name='s'>the input string</param>
		/// <param name='add'><c>false</c>: this is a standard frame (that may have 2 try) if <c>true</c>, this is an additional frame with only 1 char</param>
		///
		/// this constructor call the <c>setFromString</c> method to initialize the Frame
		Frame(const string& s,const bool& add=false);

		/// <summary>destructor</summary>
		~Frame();

		/// <summary>compute the score for the frame</summary>
		/// <returns>-2 for a Strike, -1 for a Spare, else a positive number for the score<returns>
		int getFrameScore();

		/// <summary>return the number of pins down at the first try</summary>
		/// <returns>the pins down at first try<returns>
		int getFirstTryScore();
		
		/// <summary>return the number of pins down at the second try</summary>
		/// <returns>the pins down at second try<returns>
		int getSecondTryScore();

		/// <summary>virtual method that set the data of the class based on the given status</summary>
		/// <param name='s'>the string used to set the data</param>
		/// <param name='add'><c>false</c>: this is a standard frame (that may have 2 try) if <c>true</c>, this is an additional frame with only 1 char</param>
		/// <returns><c>true</c> if the class is curently not in error, else <c>false</c></returns>
		/// the class with be in error for any unexpected thing in the input string
		///
		/// the input string should be 2 char long or be "X" for a strike
		/// the char '1' to '9' represent the pins knocked down '-' represent a miss(i.e. 0 pin knocked down)
		/// the second char only could be '/' which means Spare then the number of knocked pins at the second try is 10 - "first try"
		/// the sum of the fallen pins should be < 10 (except for the Strike and Spare case)
		bool setFromString(const string& s,const bool& add=false);

		///<summary>streaming out operator</summary>
		/// <param name='os'>stream to input</param>
		/// <param name='f'>the frame to stream</param>
		/// <returns>output stream</returns>
		friend ostream& operator<<(ostream& os, const Frame& f);
	private:
		/// <summary>first and second try result: the number of knocked down pins</summary>
		pair<int, int> results;
		/// <summary>store whether the frame is an additional one</summary>
		bool additional;
	};

}