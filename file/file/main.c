#include <stdio.h>

main() {
   FILE *fp;
   int i;
   
   fp = fopen("/home/jorge/Desktop/test.txt", "w+");
	for(i=0;i<3;i++){
   fprintf(fp, "This is testing for fprintf... %d\n", i+1);
   fputs("This is testing for fputs...\n", fp);
   }
   fclose(fp);
   }