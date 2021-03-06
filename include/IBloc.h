#pragma once
#include <string>

using namespace std;

/// <summary>base namespace for Bowling application</summary>
namespace bowling {

	enum class EStatus {
		None=0,
		BadStringLength,
		BadFrameFirstChar,
		BadFrameSecondChar,
		BadFrame,
		BadLineSize,
	};

	/// <summary>abstract class with the basic methods for the other class of the application</summary>
	class IBloc
	{
	public:
		/// <summary>default constructor</summary>
		IBloc()
		{
			errorStatus = EStatus::None;
		}

		/// <summary>Destructor</summary>
		virtual ~IBloc()
		{

		}

		/// <summary>return if this class is in error status</summary>
		/// <returns><c>true</c> if the class is curently in error, else <c>false</c></returns>
		bool isError()const
		{
			return(errorStatus != EStatus::None);
		}

		/// <summary>return if this class is in no-error status</summary>
		/// <returns><c>true</c> if the class is curently not in error, else <c>false</c></returns>
		bool isOk()const
		{
			return(errorStatus == EStatus::None);
		}

	protected:
		/// basic error code for this class. 0 means no error
		EStatus errorStatus;
	};

}
