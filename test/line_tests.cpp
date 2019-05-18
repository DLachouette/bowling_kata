/**
 * \file frame_tests.h
 * \brief definition of unit tests for the class Frame
 * \date 16 mai 2019
 * \author: dla
 */

#ifndef FRAME_TESTS_H_
#define FRAME_TESTS_H_

#include "gtest/gtest.h"
#include <Line.h>

TEST(BowlingLine, BAD_LINE_DEFINITION)
{
	bowling::Line line;
    // bad input : empty string
    EXPECT_FALSE(line.setFromString("")) 
		<< "Line::setFromString : Empty string should return an error";
    // bad input long sequence
    EXPECT_FALSE(line.setFromString("5-5-5-5-5-5-5-5-5-5-5-")) 
		<< "Line::setFromString : too long sequence of frames should return an error";
    // bad input short sequence
    EXPECT_FALSE(line.setFromString("5-5-5-5-5-5-5-5-5-")) 
		<< "Line::setFromString : too short sequence of frames should return an error";
    // bad input long sequence with spare
    EXPECT_FALSE(line.setFromString("5-5-5-5-5-5-5-5-5-5/5-")) 
		<< "Line::setFromString : too long sequence of frames with a spare at 10th position should return an error";
    // bad input short sequence with spare
    EXPECT_FALSE(line.setFromString("5-5-5-5-5-5-5-5-5-5/")) 
		<< "Line::setFromString : too short sequence of frames with a spare at 10th position should return an error";
    // bad input long sequence with strike
    EXPECT_FALSE(line.setFromString("5-5-5-5-5-5-5-5-5-X5-7")) 
		<< "Line::setFromString : too long sequence of frames with a strike at 10th position should return an error";
    // bad input short sequence with strike
    EXPECT_FALSE(line.setFromString("5-5-5-5-5-5-5-5-5-X1")) 
		<< "Line::setFromString : too short sequence of frames with a strike at 10th position should return an error";
    // bad input badly defined frame
    EXPECT_FALSE(line.setFromString("5-5-5-5-5-/-5-5-5-X1")) 
		<< "Line::setFromString : badly defined frame should return an error";
}

TEST(BowlingLine, GOOD_LINE_DEFINITION)
{
	bowling::Line line;
	// good example 1 full of strike
	EXPECT_TRUE(line.setFromString("XXXXXXXXXXXX")) 
		<< "Line::setFromString : line full of strikes should be OK";
	// good example 2
	EXPECT_TRUE(line.setFromString("9-9-9-9-9-9-9-9-9-9-")) 
		<< "Line::setFromString : line full of 'nine,miss' strikes should be OK";
	// good example 3 with a spare
	EXPECT_TRUE(line.setFromString("5/5/5/5/5/5/5/5/5/5/5")) 
		<< "Line::setFromString : line full of spares should be OK";

}

TEST(BowlingLine, LINE_SCORING)
{
	bowling::Line line;

	line.setFromString("XXXXXXXXXXXX");
	EXPECT_EQ(line.getLineScore(),300) 
		<< "Line::getLineScore() : input \"XXXXXXXXXXXX\" should score 300";

	line.setFromString("9-9-9-9-9-9-9-9-9-9-");
	EXPECT_EQ(line.getLineScore(),90) 
		<< "Line::getLineScore() : input \"9-9-9-9-9-9-9-9-9-9-\" should score 90";

	line.setFromString("5/5/5/5/5/5/5/5/5/5/5");
	EXPECT_EQ(line.getLineScore(),150) 
		<< "Line::getLineScore() : input \"5/5/5/5/5/5/5/5/5/5/5\" should score 150";

}

#endif /* FRAME_TESTS_H_ */
