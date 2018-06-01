#include "Main_Thread.h"



Main_Thread::Main_Thread(bool run, int width, int height) : MainView(width, height)
{
	std::cout << "Hello, World!" << endl;
	Run = run;

	//check for fps limit
	ShowCursor(false);
	//while (Run) {
		//get cursor change
		//adjust camera and view
		//run physics
		//calculate rays
		//display to screen


		/*FILE * fp = fopen("file.bmp", "wb");
		fwrite(bmpfile_header, sizeof(bmpfile_header), 1, fp);
		fwrite(bmp_dib_v3_header, sizeof(bmp_dib_v3_header_t), 1, fp);

		for (int i = 0; i < 200; i++) {
			for (int j = 0; j < 200; j++) {
				fwrite(&image[j][i][2], 1, 1, fp);
				fwrite(&image[j][i][1], 1, 1, fp);
				fwrite(&image[j][i][0], 1, 1, fp);
			}
		}

		fclose(fp);*/

	//}
	ShowCursor(true);

}

Main_Thread::~Main_Thread()
{

}
