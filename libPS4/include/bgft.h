#pragma once

#ifndef BGFT_H
#define BGFT_H

#include "debug.h"
#include "kernel.h"
#include "libc.h"
#include "network.h"
#include "types.h"

extern int (*sceBgftServiceIntInit)(struct bgft_init_params*);
extern int (*sceBgftServiceDownloadRegisterTask)(struct bgft_download_param*);
extern int (*sceBgftServiceIntDebugDownloadRegisterPkg)(struct bgft_download_param*);
extern int (*sceBgftServiceIntDownloadStartTask)(int);
extern int (*sceBgftFinalize)(void);

void initBgft(void);
