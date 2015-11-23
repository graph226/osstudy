#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]){
	int fd;		//開いたファイル
	int fdw;	//書き込むファイル
	char buf[BUFSIZ];
	int len;

	fdw = creat("concat.txt", 0644);	//書き込み用ファイルを作成する
	if(fd < 0){
		perror("Cannot Create");
		return(-1);
	}
	if((fdw=open("concat.txt",O_WRONLY))==-1) {	//書き込み用ファイルを開けないとき
		perror("Cannnot Open concat.txt");
		return -1;
	}

	int i;
	for(i=1;i<argc;i++){	//コマンドライン引数の数だけループ
		if((fd=open(argv[i],O_RDONLY))==-1) {	//ファイルを開けない場合
			perror("open");
			exit(1);
		}
	
		for(;;) {			//行が終了するまでループ
			len = read(fd,buf,sizeof(buf));	//fdから読みだしてくる

			if(len>0){
				write (1,buf,len);	//0以上ならば画面に書き出す
				write (fdw,buf,len);	//0以上ならばファイルに書き出す
			}else if (len==0) {		//最終行ならば抜ける
				break;
			}else{		//エラー処理
				perror("read");
				return 1;
			}
		}
		close(fd);		//読み込んだファイルを閉じる

	}
	close(fdw);	//書き込み用ファイルを閉じる
	return 0;
}
