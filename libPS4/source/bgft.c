#include "kernel.h"
#include "libc.h"
#include "module.h"
#include "syscall.h"

#include "bgft.h"

int bgftHandle;
int appInstUtilHandle;

int (*sceBgftServiceIntInit)(struct bgft_init_params*);
int (*sceBgftServiceDownloadRegisterTask)(struct bgft_download_param*);
int (*sceBgftServiceIntDebugDownloadRegisterPkg)(struct bgft_download_param*);
int (*sceBgftServiceIntDownloadStartTask)(int);
int (*sceBgftFinalize)(void);

int (*sceAppInstUtilInitialize)(void);

void initBgft(void) {
  if (!bgftHandle) {
    bgftHandle = sceKernelLoadStartModule("/system/common/lib/libSceBgft.sprx", 0, 0, 0, NULL, NULL);

    RESOLVE(bgftHandle, sceBgftServiceIntInit);
    RESOLVE(bgftHandle, sceBgftServiceDownloadRegisterTask);
    RESOLVE(bgftHandle, sceBgftServiceIntDebugDownloadRegisterPkg);
    RESOLVE(bgftHandle, sceBgftServiceIntDownloadStartTask);
    RESOLVE(bgftHandle, sceBgftFinalize);
  }
}

void initAppInstUtil(void) {
  if (!appInstUtilHandle) {
    appInstUtilHandle = sceKernelLoadStartModule("/system/common/lib/libSceAppInstUtil.sprx", 0, 0, 0, NULL, NULL);

    RESOLVE(appInstUtilHandle, sceAppInstUtilInitialize);
  }
}
