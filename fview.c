#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
int main(int argc, char *argv[]) {
	int i;

	for(i=1;i<argc;i++){
		struct stat sb;
		printf("%s: is ", argv[i]);
		if(stat(argv[i], &sb)!=0) {
				perror("stat");
				exit(1);
		}
		//ファイルの種類に応じた処理
		if(S_ISREG(sb.st_mode))			printf("a normal file.");
		if(S_ISDIR(sb.st_mode))			printf("a directory.");
		if(S_ISBLK(sb.st_mode))			printf("a block device.");
		if(S_ISFIFO(sb.st_mode))		printf("a FIFO.");
		if(S_ISLNK(sb.st_mode))			printf("a symbolic link.");
		if(S_ISSOCK(sb.st_mode))		printf("a symbolic link.");
		
		printf(" FILESIZE: %d", (int)sb.st_size);		//ファイルサイズの表示
		printf(" Last Modified: %s", ctime(&sb.st_mtime));	//最終変更時間の表示
	}

	return 0;
}
