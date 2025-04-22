#include<stdio.h>
#include<stdlib.h>

int main() {

char src[256], dest[256];

printf("Enterthe source file path:"); scanf("%s", src); printf("Enter the destination file path:");

scanf("%s", dest);

if(rename(src, dest)==0){

printf("File moved successfully from %s to %s.\n", src, dest); }

else{

perror("Error moving file");

}
return 0;
}