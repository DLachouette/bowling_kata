#include "gtest/gtest.h"
#include "bowling.h"

TEST(BowlingSimple, BOWLING_COMPUTATION)
{
	stringstream buffer;
	streambuf* old = std::cout.rdbuf(buffer.rdbuf());
	bowling::Bowling* bowling1, * bowling2, * bowling3, *bowling4, *bowling5;
	char* argv1[2];
	argv1[0] = (char*)"bowling_kata";
	argv1[1] = (char*)"XXXXXXXXXXXX";
	bowling1 = new bowling::Bowling(2, argv1);
	bowling1->run();
	EXPECT_STREQ(buffer.str().c_str(), "XXXXXXXXXXXX score: 300\n");
	buffer.str("");
	delete bowling1;

	char* argv2[2];
	argv2[0] = (char*)"bowling_kata";
	argv2[1] = (char*)"9-9-9-9-9-9-9-9-9-9-";
	bowling2 = new bowling::Bowling(2, argv2);
	bowling2->run();
	EXPECT_STREQ(buffer.str().c_str(), "9-9-9-9-9-9-9-9-9-9- score: 90\n");
	buffer.str("");
	delete bowling2;

	char* argv3[2];
	argv3[0] = (char*)"bowling_kata";
	argv3[1] = (char*)"5/5/5/5/5/5/5/5/5/5/5";
	bowling3 = new bowling::Bowling(2, argv3);
	bowling3->run();
	EXPECT_STREQ(buffer.str().c_str(), "5/5/5/5/5/5/5/5/5/5/5 score: 150\n");
	buffer.str("");
	delete bowling3;

	char* argv4[2];
	argv4[0] = (char*)"bowling_kata";
	argv4[1] = (char*)"5/5/5/5/5/5/5/5/5/X53";
	bowling4 = new bowling::Bowling(2, argv4);
	bowling4->run();
	EXPECT_STREQ(buffer.str().c_str(), "5/5/5/5/5/5/5/5/5/X53 score: 158\n");
	buffer.str("");
	delete bowling4;

	char* argv5[2];
	argv5[0] = (char*)"bowling_kata";
	argv5[1] = (char*)"5/5/5/X5/5/5/5/5/12";
	bowling5 = new bowling::Bowling(2, argv5);
	bowling5->run();
	EXPECT_STREQ(buffer.str().c_str(), "5/5/5/X5/5/5/5/5/12 score: 144\n");
	buffer.str("");
	delete bowling5;

	std::cout.rdbuf(old);
}

int main(int argc, char ** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
