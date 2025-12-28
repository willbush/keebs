#pragma once

#define TAPPING_TERM 200
#define QUICK_TAP_TERM 0
#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY

// Not using music mode
#define NO_MUSIC_MODE

#ifdef AUDIO_ENABLE
#    define STARTUP_SONG SONG(PLANCK_SOUND)
#    define DEFAULT_LAYER_SONGS \
        { SONG(COLEMAK_SOUND) }
#endif
