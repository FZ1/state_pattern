#include "gtest/gtest.h"
#include "../src/state_pattern.h"

TEST(StatePatternTest, initialize) {
	initialize();
	ASSERT_STREQ("IDLE", getCurrentState());
}


TEST(StatePatternTest, onPlayOrPauseAtIDLE) {
	initialize();
	onPlayOrPause();
	ASSERT_STREQ("PLAY", getCurrentState());
}

TEST(StatePatternTest, onStopAtIDLE) {
	initialize();
	onStop();
	ASSERT_STREQ("IDLE", getCurrentState());
}


TEST(StatePatternTest, onPlayOrPauseAtPLAY) {
	initialize();
	onPlayOrPause();
	ASSERT_STREQ("PLAY", getCurrentState());

	onPlayOrPause();
	ASSERT_STREQ("PAUSE", getCurrentState());
}

TEST(StatePatternTest, onStopAtPLAY) {
	initialize();
	onPlayOrPause();
	ASSERT_STREQ("PLAY", getCurrentState());

	onStop();
	ASSERT_STREQ("IDLE", getCurrentState());
}


TEST(StatePatternTest, onPlayOrPauseAtPAUSE) {
	initialize();
	onPlayOrPause();
	ASSERT_STREQ("PLAY", getCurrentState());
	onPlayOrPause();
	ASSERT_STREQ("PAUSE", getCurrentState());

	onPlayOrPause();
	ASSERT_STREQ("PLAY", getCurrentState());
}

TEST(StatePatternTest, onStopAtPAUSE) {
	initialize();
	onPlayOrPause();
	ASSERT_STREQ("PLAY", getCurrentState());
	onPlayOrPause();
	ASSERT_STREQ("PAUSE", getCurrentState());

	onStop();
	ASSERT_STREQ("IDLE", getCurrentState());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

