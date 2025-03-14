#pragma once

#ifndef BGFT_H
#define BGFT_H

#include "debug.h"
#include "kernel.h"
#include "libc.h"
#include "network.h"
#include "types.h"

enum bgft_task_option_t {
	BGFT_TASK_OPTION_NONE = 0x0,
	BGFT_TASK_OPTION_DELETE_AFTER_UPLOAD = 0x1,
	BGFT_TASK_OPTION_INVISIBLE = 0x2,
	BGFT_TASK_OPTION_ENABLE_PLAYGO = 0x4,
	BGFT_TASK_OPTION_FORCE_UPDATE = 0x8,
	BGFT_TASK_OPTION_REMOTE = 0x10,
	BGFT_TASK_OPTION_COPY_CRASH_REPORT_FILES = 0x20,
	BGFT_TASK_OPTION_DISABLE_INSERT_POPUP = 0x40,
	BGFT_TASK_OPTION_DISABLE_CDN_QUERY_PARAM = 0x10000,
};

struct bgft_download_param {
	int user_id;
	int entitlement_type;
	const char* id;
	const char* content_url;
	const char* content_ex_url;
	const char* content_name;
	const char* icon_path;
	const char* sku_id;
	enum bgft_task_option_t option;
	const char* playgo_scenario_id;
	const char* release_date;
	const char* package_type;
	const char* package_sub_type;
	unsigned long package_size;
};

struct bgft_init_params {
	void* mem;
	unsigned long size;
};

extern int (*sceBgftServiceIntInit)(struct bgft_init_params*);
extern int (*sceBgftServiceDownloadRegisterTask)(struct bgft_download_param*);
extern int (*sceBgftServiceIntDebugDownloadRegisterPkg)(struct bgft_download_param*);
extern int (*sceBgftServiceIntDownloadStartTask)(int);
extern int (*sceBgftFinalize)(void);

void initBgft(void);

#endif
