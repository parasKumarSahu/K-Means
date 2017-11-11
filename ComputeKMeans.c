#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "image.h"

int size, *member, k, *cImageTmp;


void Kmean(int *cImage){

 int *seed, i, j, *d, min, *sum_members, *no_members, matches, l;
 seed=malloc(k*sizeof(int));
 d=malloc(k*size*sizeof(int));
 member=malloc(size*sizeof(int));
 sum_members=malloc(k*sizeof(int));
 no_members=malloc(k*sizeof(int));

 srand(time(NULL));

 for(i=0; i<k; i++){
  seed[i]=rand()%256;
 }

for(l=0; l<50; l++){

 for(i=0; i<k; i++){
  sum_members[i]=0;
 }

  for(i=0; i<size; i++){

       for(j=0; j<k; j++){
              d[i*k+j]=(seed[j]-cImage[i])*(seed[j]-cImage[i]);
       }
  }

 for(i=0; i<k; i++){
   no_members[i]=0;
 }

  for(i=0; i<size; i++){
   min=255;
       for(j=0; j<k; j++){
            if(min>d[i*k+j])
            {
              min=cImage[i*k+j];
              member[i]=j;
            }
       }
   no_members[member[i]]++;
  }

  for(i=0; i<size; i++){
   sum_members[member[i]]+=cImage[i];
  }

  for(i=0; i<k; i++){
   seed[i]=sum_members[i]/no_members[i];
  }
}
 free(seed);
 free(d);
 free(sum_members);
 free(no_members);
}


void selectCluster(int *cImage, int s){

 int i;
 for(i=0; i<size; i++){
  if(member[i]!=s){
   cImage[i]=255;
  }
  else
  {
   cImage[i]=0;
  }
 }
}


void backup(int *cImage){
 int i;
 cImageTmp=malloc(size*sizeof(int));
 for(i=0; i<size; i++){
  cImageTmp[i]=cImage[i];
 }
}

void restore(int *cImage){
 int i;
 for(i=0; i<size; i++){
  cImage[i]=cImageTmp[i];
 }
}

int main(int argc, char** argv)
{

 char output_file_path[200];
 int i, *cImage, *cImageTmp;
 k=atoi(argv[2]);


 if(argc!=4)
 {

  printf("exactly 3 input arguments reqired\n");

  exit(0);

 }


 cImage=ReadImage(argv[1]);
 size=cImage[3999997]*cImage[3999998];
 Kmean(cImage);
 backup(cImage);

 for(i=0; i<k; i++){
  if (i>0)
  {
   restore(cImage);
  }
  selectCluster(cImage,i);
  snprintf ( output_file_path, 200, "%s-%d.pgm",argv[3],i);
  printf ("Creating image %s\n",output_file_path,i);
  WriteImage(output_file_path,1);
 }

 return 0;
}
