
#ifndef STATE_PATTERN_H
#define STATE_PATTERN_H

#ifdef __cplusplus
extern "C" {
#endif

void initialize(void);
void onStop(void);
void onPlayOrPause(void);
const char* getCurrentState(void);

#ifdef __cplusplus
}
#endif

#endif

