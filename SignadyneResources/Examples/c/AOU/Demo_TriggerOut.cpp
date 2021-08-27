#include <stdlib.h>
#include <stdio.h>
// Must include Signayne application folder in global include path (example: "C:\Program Files (x86)\Signadyne\")
#include <Libraries\include\c\SD_Module.h>
#include <Libraries\include\c\SD_AOU.h>

void flushKeys();

int main()
{
	int slot;
	int moduleAOU;

	printf("---- Demo Trigger ----\n");
	printf("Enter the Module Slot: ");
	scanf("%d",&slot);

	flushKeys();

	// Open module with slot
	moduleAOU = SD_Module_openWithSlot("SD-PXE-AOU",0,slot);						
	
	if(moduleAOU<=0)
	{
		printf("Error opening module\n");
		return 1;
	}
  
	// Set external trigger as output
	SD_AOU_triggerIOdirection(moduleAOU,AOU_TRG_OUT);

	printf("Module configuration successfull. Press any key to set the trigger.");
	getchar();

	SD_AOU_triggerIOwrite(moduleAOU,1);

	printf("Trigger set. Press any key to clear.");
	getchar();

	SD_AOU_triggerIOwrite(moduleAOU,0);

	printf("Trigger cleared. Press any key to finish.");
	getchar();

	// Free all objects
	SD_Module_close(moduleAOU);

    return 0;
} 

void flushKeys()
{
	char ch;
	while ((ch = getchar()) != '\n' && ch != EOF);
}