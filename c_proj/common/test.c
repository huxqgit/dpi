#include<stdio.h>
#include<dirent.h>
#include<time.h>

void main(int argc, char *argv[])
{
	const int BUF_SIZE = 1024 ;
	char buf[BUF_SIZE];

	char ch, infile[50], outfile[50];
	struct dirent *ptr = NULL;
	DIR *dir = NULL;
	dir = opendir("./Data");
	while((ptr = readdir(dir)) != NULL)
	{
		//跳过 . ..
		if(ptr->d_name[0] == '.')
		{
			continue;
		}

		time_t start, end;
		start =  clock();
		//printf("%s is ready...\n", ptr->d_name);
		//sprintf(infile, "./Data/%s\n", ptr->d_name);
		int len = 0;
		char *fileName = malloc(strlen("./Data/")+strlen(ptr->d_name)+1);
		strcpy(fileName, "./Data/");
    	strcat(fileName, ptr->d_name);
		FILE *fp = fopen(fileName, "rb");
		do
		{
			len = fread(buf,1,BUF_SIZE,fp);
		}while(len != 0);
    	end = clock();
    	fclose(fp);
    	printf("%s is ready: %d ms\n", ptr->d_name, end - start);
	}
}

/*
int GetFileList(char *path)
{
	DIR *dir = NULL;
	struct dirent *ptr = NULL;

	if ((dir = opendir(path)) == NULL)
	{
		perror("Open dir error...");
	    exit(1);
	}
	//其中d_type表明该文件的类型：文件(8)、目录(4)、链接文件(10)等。
	while((ptr = readdir(dir)) != NULL)
	{
		if(strcmp(ptr->d_name,".") == 0 || strcmp(ptr->d_name,"..") ==0 )
		{
			continue;
		}
		else if (ptr->d_type == 8)
		{

		}

		printf("ready file:%s/%s\n", path, ptr->d_name);
	}
}
*/

char **getFileList(const char *path, int* fileCount)
{
    int count = 0;
    DIR *dir = NULL;
	struct dirent *ptr = NULL;
    char **fileList = NULL;
    char file[512];
    struct stat statbuf;

    //打开目录
    if ((dir = opendir(path)) == NULL)
	{
		perror("Open dir error..."); //记录日志
	    return NULL;
	}

    while((ptr = readdir(dir)) != NULL)
    {
        //其中d_type表明该文件的类型：文件(8)、目录(4)、链接文件(10)等。
        if (ptr->d_type == 8)
        {
            count++;
        }
    }    

    //关闭目录
    closedir(dir);

    //开辟字符指针数组，用于下一步的开辟容纳文件名字符串的空间
    if(fileList == (char**))
        
}

