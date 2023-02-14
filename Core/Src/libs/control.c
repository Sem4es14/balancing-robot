#include "../constants.h"
#include "control.h"

static int prevAngErr = 0;
static int prevFiltAngErr = 0;
static int integAng = 0;

static int prevSpeed = 0;
static int prevSpeedErr = 0;
static int integSpeed = 0;

int angleRegulation(int pitch, int setAng) {
    int angErr = pitch + setAng;
    int filtAngErr = (1 - ANG_DIFF_FILT)*prevAngErr + ANG_DIFF_FILT*angErr;
    prevAngErr = filtAngErr;

    int prop = angErr;
    integAng += (angErr * DELTA_TIME);
    if (integAng > 700) {
    	integAng = 700;
    }
    if (integAng < -700) {
    	integAng = -700;
    }
    int diff = (filtAngErr - prevFiltAngErr) / DELTA_TIME;
    prevFiltAngErr = filtAngErr;
    if (angErr > MAX_ANGLE || angErr < -MAX_ANGLE) {
    	return 0;
    }

    return ((int)(prop*K_ANG_PROP) + (int)(integAng*K_ANG_INTEG) + (int)(diff*K_ANG_DIFF)) / 10;

}

int speedRegulation(int speed, int setSpeed) {
	//filtSpeed = (1-SPEED_FILT)*prevSpeed + SPEED_FILT*speed;
	//prevSpeed = filtSpeed;
	int speedErr = speed - setSpeed;
	int filtSpeedErr = (1-SPEED_FILT)*prevSpeed + SPEED_FILT*speedErr;
	prevSpeed = filtSpeedErr;
	int prop = filtSpeedErr;
	int diff = filtSpeedErr - prevSpeedErr;
	prevSpeedErr = filtSpeedErr;
	integSpeed += speed - setSpeed;
	if (integSpeed > 400000) {
		integSpeed = 400000;
	}
	if (integSpeed < -400000) {
		integSpeed = -400000;
	}

	return prop*K_SPEED_PROP + integSpeed*K_SPEED_INTEG + diff*K_SPEED_DIFF;
	//return prop*kpv + integSpeed*kiv + diff*kdv;
}
