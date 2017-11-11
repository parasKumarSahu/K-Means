#include<stdio.h>
#include<stdlib.h>

        int cImage [4000000];

int* ReadImage(char *path) {

        char cArray[100];
        int iWidth, iHeight, iRow, iCol;

                int i;

        unsigned int cTemp;

        FILE *filePointer = NULL;

        filePointer = fopen(path,"r");

        if (filePointer == NULL)
        {
            printf("cannot open file");

        }else
        {
            fgets (cArray, 99, filePointer);
            printf("%s\n", cArray);

            fgets (cArray, 99, filePointer);
            printf("%s\n", cArray);

            fscanf(filePointer,"%d %d\n", &iWidth, &iHeight);
            printf("%d %d \n", iWidth, iHeight);

            fgets (cArray, 99, filePointer);
            printf("gray scale Value read - %s\n", cArray);

            for (iRow = 0, i=0; iRow< iHeight; iRow++)
            {
                for (iCol = 0; iCol< iWidth; iCol++)
                {
                    fscanf(filePointer, "%d ", &cTemp);

                    if (cTemp != EOF)
                    {
                        cImage[i] = cTemp;
                        i++;
                    }

                }

            }
               cImage[3999997]=iWidth;
               cImage[3999998]=iHeight;
               cImage[3999999]=atoi(cArray);

                     fclose(filePointer);
          }

  //printf("returning to main %d\n",i);
 return cImage;
}

void WriteImage(char *path, int flag){

        char cArray[100];
        int i, j, size, grayscale, width, height;

        unsigned int cTemp;

        FILE *filePointer = NULL;

         filePointer = fopen(path,"w");

                width=cImage[3999997];
                height=cImage[3999998];
                grayscale=cImage[3999999];
                size=width*height;

 if(flag==1){

          fprintf(filePointer,"P2\n#created by seeraj\n%d %d\n%d\n", width, height, grayscale);
            for (i=0; i<size; i++)
            {
              fprintf(filePointer, "%d ",cImage[i]);
            }

  }

 if(flag==2){

          fprintf(filePointer,"P2\n#created by seeraj\n%d %d\n%d\n", width/2, height/2, grayscale);
            for (i=0; i<size; i+=2)
            {
              if((i%width)%2==0 && (i/width)%2==0)
                fprintf(filePointer, "%d ",cImage[i]);
            }

   }

 if(flag==3){

           fprintf(filePointer,"P2\n#created by seeraj\n%d %d\n%d\n", width*2, height*2, grayscale);
           for (i=0; i<size; i++)
            {
              fprintf(filePointer, "%d ",cImage[i]);
              fprintf(filePointer, "%d ",cImage[i]);

              if(i/width>=1 && i%width==0){
               for(j=0;j<width;j++){
                fprintf(filePointer, "%d ",cImage[i-width+j]);
                fprintf(filePointer, "%d ",cImage[i-width+j]);
               }
              }
            }
  }


         fclose(filePointer);
   //printf("returning to main second time\n");
}
