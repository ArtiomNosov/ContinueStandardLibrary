#include "pch.h"
#include "..\StringProcessors\StringProcessors.cpp"
//class HelloWordTest : public ::testing::Test {
//protected:
//	void SetUp() override {
//		//
//	}
//
//	// void TearDown() override {}
//
//	char* str = "Hello";
//};
TEST(TestEmptyWords, TestStringProcessors) {
	char* res = addZeros(" Ha  Ha ", 3);
	EXPECT_TRUE(strcmp("000 0Ha  0Ha 000", res) == 0);
	free(res);
}

TEST(TestOneWordHello, TestStringProcessors) {
	char* res = addZeros("Hello", 6);
  EXPECT_TRUE( strcmp("0Hello", res) == 0);
  free(res);
}

TEST(TestHelloWorld, TestStringProcessors) {
	char* res = addZeros("Hello World!", 7);
	EXPECT_TRUE(strcmp("00Hello 0World!", res) == 0);
	free(res);
}

TEST(TestLongString, TestStringProcessors) {
	char* res = addZeros("Hello! I am a big fun of programming language C! Ha ha!", 7);
	EXPECT_TRUE(strcmp("0Hello! 000000I 00000am 000000a 0000big 0000fun 00000of programming language 00000C! 00000Ha 0000ha!", res) == 0);
	free(res);
}

