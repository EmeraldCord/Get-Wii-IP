#include <stdio.h>
#include <cstdlib>
#include <network.h>
#include <wiiuse/wpad.h>

static void *xfb = NULL;
static GXRModeObj *rmode = NULL;

int main (int argc, char **argv) {
    
s32 ret;

char localip[16] = {0};
char gateway[16] = {0};
char netmask[16] = {0};

	VIDEO_Init();

	WPAD_Init();

	rmode = VIDEO_GetPreferredMode(NULL);

	xfb = MEM_K0_TO_K1(SYS_AllocateFramebuffer(rmode));

	console_init(xfb,20,20,rmode->fbWidth,rmode->xfbHeight,rmode->fbWidth*VI_DISPLAY_PIX_SZ);

	VIDEO_Configure(rmode);

	VIDEO_SetNextFramebuffer(xfb);

	VIDEO_SetBlack(FALSE);

	VIDEO_Flush();

	VIDEO_WaitVSync();
	if(rmode->viTVMode&VI_NON_INTERLACE) VIDEO_WaitVSync();

 printf ("Get Wii IP \n Press the Home button to exit");

    printf ("\n \n \nGetting IP...");

    ret = if_config(localip, netmask, gateway, TRUE, 20);
printf("%s.\n \n", localip);
printf("\nThat is your Wii's IP");


while(1) {

		WPAD_ScanPads();

		u32 pressed = WPAD_ButtonsDown(0);
if ( pressed && WPAD_BUTTON_HOME ) exit(0);

	VIDEO_WaitVSync ();
}
return 0;
}
