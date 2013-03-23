#ifndef STEREO_IMU_OBSTACLES_HPP
#define STEREO_IMU_OBSTACLES_HPP


#include <iostream>


using namespace std;


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <signal.h>
#include <time.h>
#include <sys/time.h>
#include <mutex>
#include <math.h>

#include "opencv2/opencv.hpp"

#include <Eigen/Dense>

#include <GL/gl.h>
#include <bot_lcmgl_client/lcmgl.h>
#include <bot_core/rotations.h>
#include <bot_frames/bot_frames.h>
#include <bot_param/param_client.h>
#include <lcmtypes/octomap_raw_t.h>

#include <octomap/OcTree.h>

#include "../../LCM/lcmt_stereo.h"

#include "TrajectoryLibrary.hpp"
#include "Trajectory.hpp"

static void usage(void);
void sighandler(int dum);

int64_t getTimestampNow();

void stereo_handler(const lcm_recv_buf_t *rbuf, const char* channel, const lcmt_stereo *msg, void *user);


void InsertPointsIntoOctree(const lcmt_stereo *msg, BotTrans *toOpenCv, BotTrans *bodyToLocal);

void PublishOctomap();


#endif
