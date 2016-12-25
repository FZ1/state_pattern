#include <stdio.h>
#include "state_pattern.h"

// イベント発生時に呼び出す関数のプロトタイプ
typedef struct State {
	const struct State* (* const stop)(const struct State* pThis);
	const struct State* (* const playOrPause)(const struct State* pThis);
	const char* currentState;
} State;

// 現在の状態オブジェクトを保持する
static const State* pCurrentState;

static const State* ignore(const State* pThis);
static const State* startPlay(const State* pThis);
static const State* stopPlay(const State* pThis);
static const State* pausePlay(const State* pThis);
static const State* resumePlay(const State* pThis);

// アイドル状態オブジェクトの作成
const State IDLE = {
	ignore,
	startPlay,
	"IDLE"
};

// 再生状態オブジェクトの作成
const State PLAY = {
	stopPlay,
	pausePlay,
	"PLAY"
};

// 一時停止状態オブジェクトの作成
const State PAUSE = {
	stopPlay,
	resumePlay,
	"PAUSE"
};

// 初期状態への初期化
void initialize(void) {
	pCurrentState = &IDLE;
}

// 停止ボタンイベント処理
void onStop(void) {
	pCurrentState = pCurrentState->stop(pCurrentState);
}

// 再生ボタンイベント処理
void onPlayOrPause(void) {
	pCurrentState = pCurrentState->playOrPause(pCurrentState);
}

// 現在状態取得
const char* getCurrentState(void) {
	return pCurrentState->currentState;
}

static const State* ignore(const State* pThis) {
	return pCurrentState;
}

static const State* stopPlay(const State* pThis) {
	return &IDLE;
}

static const State* pausePlay(const State* pThis) {
	return &PAUSE;
}

static const State* resumePlay(const State* pThis) {
	return &PLAY;
}

static const State* startPlay(const State* pThis) {
	return &PLAY;
}
