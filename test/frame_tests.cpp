/**
 * \file frame_tests.h
 * \brief definition of unit tests for the class Frame
 * \date 16 mai 2019
 * \author: dla
 */

#ifndef FRAME_TESTS_CPP_
#define FRAME_TESTS_CPP_

#include "gtest/gtest.h"
#include <Frame.h>

TEST(BowlingFrame, BAD_FRAME_DEFINITION)
{
	bowling::Frame frame;
	// bad input : empty string
	EXPECT_FALSE(frame.setFromString(""))
			<< "Frame::setFromString : Empty string should return an error";
	EXPECT_FALSE(frame.isOk())
			<< "Frame::isOk : Empty string should return an error";
	// bad input long string
	EXPECT_FALSE(frame.setFromString("5-1"))
			<< "Frame::setFromString : too long string should return an error";
	EXPECT_FALSE(frame.isOk())
			<< "Frame::isOk : too long string should return an error";
	// bad input bad char
	EXPECT_FALSE(frame.setFromString("A7"))
			<< "Frame::setFromString : bad char in string should return an error";
	EXPECT_FALSE(frame.isOk())
			<< "Frame::isOk : bad char in string should return an error";
	// bad input strike with 2 chars
	EXPECT_FALSE(frame.setFromString("X1"))
			<< "Frame::setFromString : length 2 after strike string should return an error";
	EXPECT_FALSE(frame.isOk())
			<< "Frame::isOk : length 2 after strike string should return an error";
	// bad input strike on position 2
	EXPECT_FALSE(frame.setFromString("1X"))
			<< "Frame::setFromString : strike char at position 2 should return an error";
	EXPECT_FALSE(frame.isOk())
			<< "Frame::isOk : strike char at position 2 should return an error";
	// bad input strike on position 2
	EXPECT_FALSE(frame.setFromString("/1"))
			<< "Frame::setFromString : spare char at position 1 should return an error";
	EXPECT_FALSE(frame.isOk())
			<< "Frame::isOk : spare char at position 1 should return an error";
	// bad input sum of score is >10
	EXPECT_FALSE(frame.setFromString("84"))
			<< "Frame::setFromString : score sum >10 should return an error";
	EXPECT_FALSE(frame.isOk())
			<< "Frame::isOk : score sum >10 should return an error";
	// bad input sum of score is ==10 without spare char
	EXPECT_FALSE(frame.setFromString("82"))
			<< "Frame::setFromString : score sum ==10 without spare char should return an error";
	EXPECT_FALSE(frame.isOk())
			<< "Frame::isOk : score sum ==10 without spare char should return an error";
	// bad input bad definition of a miss '0'
	EXPECT_FALSE(frame.setFromString("80"))
			<< "Frame::setFromString : '0' instead of '-' for a miss should return an error";
	EXPECT_FALSE(frame.isOk())
			<< "Frame::isOk : '0' instead of '-' for a miss should return an error";
}

TEST(BowlingFrame, GOOD_FRAME_DEFINITION)
{
	bowling::Frame frame;
	// good input of spare
	EXPECT_TRUE(frame.setFromString("1/"))
		<< "Frame::setFromString : \"1/\" definition of a spare should be OK";
	EXPECT_TRUE(frame.isOk())
		<< "Frame::isOk : \"1/\" definition of a spare should be OK";
	// good input of spare
	EXPECT_TRUE(frame.setFromString("14"))
		<< "Frame::setFromString : \"14\" definition of a standard score should be OK";
	EXPECT_TRUE(frame.isOk())
		<< "Frame::isOk : \"14\" definition of a standard score should be OK";
	// good input of spare
	EXPECT_TRUE(frame.setFromString("1-"))
		<< "Frame::setFromString : \"1-\" definition of a miss in second position should be OK";
	EXPECT_TRUE(frame.isOk())
		<< "Frame::isOk : \"1-\" definition of a miss in second position should be OK";
	// good input of spare
	EXPECT_TRUE(frame.setFromString("-5"))
		<< "Frame::setFromString : \"-5\" definition of a miss in first position should be OK";
	EXPECT_TRUE(frame.isOk())
		<< "Frame::isOk : \"-5\" definition of a miss in first position should be OK";
}

TEST(BowlingFrame, BAD_FRAME_ADDITIONAL_DEFINITION)
{
	bowling::Frame frame;
	// bad input : empty string
	EXPECT_FALSE(frame.setFromString("",true))
			<< "Frame::setFromString : Empty string should return an error";
	EXPECT_FALSE(frame.isOk())
			<< "Frame::isOk : Empty string should return an error";
	// bad input long string
	EXPECT_FALSE(frame.setFromString("5-",true))
			<< "Frame::setFromString : too long string should return an error";
	EXPECT_FALSE(frame.isOk())
			<< "Frame::isOk : too long string should return an error";
	// bad input bad char
	EXPECT_FALSE(frame.setFromString("A",true))
			<< "Frame::setFromString : bad char in string should return an error";
	EXPECT_FALSE(frame.isOk())
			<< "Frame::isOk : bad char in string should return an error";
	// bad input spare
	EXPECT_FALSE(frame.setFromString("/",true))
			<< "Frame::setFromString : spare in string should return an error";
	EXPECT_FALSE(frame.isOk())
			<< "Frame::isOk : spare in string should return an error";
}

TEST(BowlingFrame, GOOD_FRAME_ADDITIONAL_DEFINITION)
{
	bowling::Frame frame;
	// good input of stricke
	EXPECT_TRUE(frame.setFromString("X", true))
		<< "Frame::setFromString : \"X\" definition of a strike should be OK";
	EXPECT_TRUE(frame.isOk())
		<< "Frame::isOk : \"X\" definition of a strike should be OK";
	// good input of number
	EXPECT_TRUE(frame.setFromString("1", true))
		<< "Frame::setFromString : \"1\" definition of a score should be OK";
	EXPECT_TRUE(frame.isOk())
		<< "Frame::isOk : \"1/\" definition of a spare should be OK";
	// good input of miss
	EXPECT_TRUE(frame.setFromString("-", true))
		<< "Frame::setFromString : \"-\" definition of a miss should be OK";
	EXPECT_TRUE(frame.isOk())
		<< "Frame::isOk : \"-5\" definition of a miss in first position should be OK";
}

TEST(BowlingFrame, FRAME_SCORE)
{
	bowling::Frame frame;

	frame.setFromString("X");
	EXPECT_EQ(frame.getFrameScore(),-2)
			<< "Frame::getFrameScore() : input \"X\" for strike should score -2";

	frame.setFromString("1/");
	EXPECT_EQ(frame.getFrameScore(),-1)
			<< "Frame::getFrameScore() : input \"1/\" for spare should score -1";

	frame.setFromString("14");
	EXPECT_EQ(frame.getFrameScore(),5)
			<< "Frame::getFrameScore() : input \"15\" should score 5";

	frame.setFromString("1-");
	EXPECT_EQ(frame.getFrameScore(),1)
			<< "Frame::getFrameScore() : input \"1-\" with a miss should score 1";

	frame.setFromString("-5");
	EXPECT_EQ(frame.getFrameScore(),5)
			<< "Frame::getFrameScore() : input \"-2\" with a miss should score 5";
}

TEST(BowlingFrame, FRAME_FIRST_TRY_SCORE)
{
	bowling::Frame frame;

	frame.setFromString("X");
	EXPECT_EQ(frame.getFirstTryScore(), 10)
		<< "Frame::getFirstTryScore() : input \"X\" for strike should score 10";

	frame.setFromString("1/");
	EXPECT_EQ(frame.getFirstTryScore(), 1)
		<< "Frame::getFirstTryScore() : input \"1/\" for spare should score 1";

	frame.setFromString("14");
	EXPECT_EQ(frame.getFirstTryScore(), 1)
		<< "Frame::getFirstTryScore() : input \"15\" should score 1";

	frame.setFromString("1-");
	EXPECT_EQ(frame.getFirstTryScore(), 1)
		<< "Frame::getFirstTryScore() : input \"1-\" with a miss should score 1";

	frame.setFromString("-5");
	EXPECT_EQ(frame.getFirstTryScore(), 0)
		<< "Frame::getFirstTryScore() : input \"-5\" with a miss should score 0";
}

TEST(BowlingFrame, FRAME_SECOND_TRY_SCORE)
{
	bowling::Frame frame;

	frame.setFromString("1/");
	EXPECT_EQ(frame.getSecondTryScore(), 9)
		<< "Frame::getFirstTryScore() : input \"1/\" for spare should score 9";

	frame.setFromString("14");
	EXPECT_EQ(frame.getSecondTryScore(), 4)
		<< "Frame::getFirstTryScore() : input \"15\" should score 4";

	frame.setFromString("1-");
	EXPECT_EQ(frame.getSecondTryScore(), 0)
		<< "Frame::getFirstTryScore() : input \"1-\" with a miss should score 0";

	frame.setFromString("-5");
	EXPECT_EQ(frame.getSecondTryScore(), 5)
		<< "Frame::getFirstTryScore() : input \"-5\" with a miss should score 5";
}

#endif /* FRAME_TESTS_CPP_ */
